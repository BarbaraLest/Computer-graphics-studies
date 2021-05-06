
#include <GL/gl.h>
#include <GL/glut.h>


GLfloat rotaciona = 0.0f;
GLfloat transladaX = 0.0f;
GLfloat transladaY = 0.0f;

float velocidadeRotacao = 5.0;
float velocidadeTranslacao = 0.1;

//para o timer
GLfloat xT = 100.0f;
GLfloat yT = 150.0f;
GLfloat windowWidth;
GLfloat windowHeight;
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
GLsizei rsize = 50;
GLsizei angulo = 0;

void Teclado(unsigned char tecla, int x, int y);
void Desenha(void);
void DesenhaFoguete(void);
void Init (void);
void Timer(int value);

void Teclado(unsigned char tecla, int x, int y){
  switch (tecla){
  //teclas para controle do foguete
  case 'a':
    transladaX -= velocidadeTranslacao;
    break;

  case 'd':
    transladaX += velocidadeTranslacao;
    break;

  case 'w':
    transladaY += velocidadeTranslacao;
    break;

  case 's':
    transladaY -= velocidadeTranslacao;
    break;

  case ',':
    rotaciona -= velocidadeRotacao;
    break;

  case '.':
    rotaciona += velocidadeRotacao;
    break;

    case 0:
    exit(0);
    break;

  default:
    break;
  }
}

void Desenha(void){
glMatrixMode(GL_MODELVIEW);
glClear(GL_COLOR_BUFFER_BIT);
DesenhaFoguete();
glutSwapBuffers();
}

void Bico(){
glColor3ub(128, 0, 128);
glBegin(GL_QUADS);
glVertex2f(0.0,0.0);
glVertex2f(0.20,0.0);
glVertex2f(0.10,0.20);
glVertex2f(0.0,0.0);
glEnd();
}

void Corpo(){
glColor3ub(255, 0, 127);
glBegin(GL_QUADS);
glVertex2f(0.0,0.0);
glVertex2f(0.2,0.0);
glVertex2f(0.2,-0.4);
glVertex2f(0.0,-0.4);
glVertex2f(0.0,0.0);
glEnd();
}

void AsaEsquerda(){
glColor3ub(107, 38, 75);
glBegin(GL_QUADS);
glVertex2f(0.0,-0.4);
glVertex2f(-0.1,-0.4);
glVertex2f(0.0,-0.2);
glVertex2f(0.0,-0.4);
glEnd();
}

void AsaDireita(){
glColor3ub(107, 38, 75);
glBegin(GL_QUADS);
glVertex2f(0.2,-0.4);
glVertex2f(0.3,-0.4);
glVertex2f(0.2,-0.2);
glVertex2f(0.2,-0.4);
glEnd();
}

void Fogo1(){
glColor3ub(255,0,0);
glBegin(GL_QUADS);
glVertex2f(0.0,-0.4);
glVertex2f(0.2,-0.4);
glVertex2f(0.1,-0.6);
glVertex2f(0.0,-0.4);
glEnd();
}

void Fogo2(){
glColor3ub(255,165,0);
glBegin(GL_QUADS);
glVertex2f(0.0,-0.4);
glVertex2f(0.2,-0.4);
glVertex2f(0.1,-0.5);
glVertex2f(0.0,-0.4);
glEnd();
}

void DesenhaFoguete(void){
  glLoadIdentity();

  glTranslatef(transladaX, transladaY, 0.0);
  glRotatef(rotaciona,0,0,1);

  Bico();
  Corpo();
  AsaEsquerda();
  AsaDireita();
  Fogo1();
  Fogo2();

  glLoadIdentity();
}

void Init (void){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Timer(int value){

  if(xT > windowWidth-rsize || xT < 0)
    xstep = -xstep;
  if(yT > windowHeight-rsize || yT < 0)
    ystep = -ystep;

  if(xT > windowWidth-rsize)
    xT= windowWidth-rsize-1;
  if(yT > windowHeight-rsize)
    yT = windowHeight-rsize-1;

  xT += xstep;
  yT += ystep;
  glutPostRedisplay();
  glutTimerFunc(33,Timer, 1);
}

int main(int argc, char *argv[]){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Foguetinho");
  glutDisplayFunc(Desenha);
  glutTimerFunc(33, Timer, 1);
  glutKeyboardFunc(Teclado);
  Init();
  glutMainLoop();
}


