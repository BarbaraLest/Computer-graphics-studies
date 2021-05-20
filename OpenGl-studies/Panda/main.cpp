#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include "SOIL.h"
//#include <gl\glaux.h>
//#include "utilTextura.cpp"

float ang = 0;
float ang2 = 0;
float ang3 = 0;

GLuint texture[3];

int LoadGLTextures(){
    /* load an image file directly as a new OpenGL texture */
     texture[0]= SOIL_load_OGL_texture("D:\\Imagens\\img_test.bmp",
        SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);


  if(texture[0] == 0  || texture[1] == 0  || texture[2] == 0){
        return false;
    }
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glEnable(GL_TEXTURE_2D);                // Enable Texture Mapping ( NEW )
    glShadeModel(GL_SMOOTH);                // Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   // Black Background
    glClearDepth(1.0f);                        // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);                // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);                    // The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);    // Really Nice Perspective Calculations

    return true; // Return Success
}

void display();


class Osso
{
public:
    Osso(float a, float l) : largura(l), altura(a), conexcao(0) {}
    void desenha();

    void setConexcao(Osso *osso, float ang) { conexcao = osso, angulo = ang; }

    void setAngulo(float ang) { angulo = ang; }
    float getAngulo() { return angulo; }

protected:
    float largura;
    float altura;

    float angulo;
    Osso *conexcao;
};

void Osso::desenha()
{
    glPushMatrix(); //salva o contexto(1)

    glTranslatef(0.0, altura / 2.0, 0.0); //vai para o meio do osso

    glPushMatrix();                     //salva o contexto(2)
    glScalef(largura, altura, largura); //escala para o tamanho do osso

    glutSolidCube(largura); //desenha o osso
    glPopMatrix();          //restaura o contexto(2)

    glTranslatef(0.0, altura / 2.0, 0.0); // vai para a ponta do osso

    glutSolidSphere(1.25 * largura, 8, 8); //desenha a bolinha

    if (conexcao)
    {
        glRotatef(angulo, 1.0, 0.0, 0.0); //rotaciona para o angulo da conexcao
        conexcao->desenha();              //desenha recursivamente
    }

    glPopMatrix(); //restaura o contexto(1)
};

////////////////////////////////////////////////////////////

class Braco
{
public:
    Braco(float comprimento, float largura);
    void desenha() { a.desenha(); }
    void setCurvatura(float curvatura, bool reto, int tipo);
    float getCurvatura() { return a.getAngulo() * 100 / 90; }
    void setBracoReto(float curvatura);
    float getBracoReto() { return a.getAngulo() * 100 / 90; }

protected:
    Osso a, b;
};

Braco::Braco(float comprimento, float largura)
    : a(comprimento * 0.3, largura), b(comprimento * 0.4, largura)
{
    a.setConexcao(&b, 0.0);
}

void Braco::setCurvatura(float curvatura, bool reto, int tipo)
{ //0= normal, 1=ossoA, 2=ossoB

    if (reto)
    {
        a.setAngulo(1);
    }
    else
    {
        if (tipo == 0)
        {
            a.setAngulo(curvatura * 0.9);
            b.setAngulo(curvatura * 0.9);
        }
        else if (tipo == 1)
        {
            b.setAngulo(90);
        }
        else if (tipo == 2)
        {
            a.setAngulo(-10);
        }
    }
}
////////////////////////////////////////////////////////////
class Perna
{
public:
    Perna(float comprimento, float largura);
    void desenha() { a.desenha(); }
    void setCurvatura(float curvatura, bool reto, int tipo);
    float getCurvatura() { return a.getAngulo() * 100 / 90; }
    void setBracoReto(float curvatura);
    float getBracoReto() { return a.getAngulo() * 100 / 90; }

protected:
    Osso a, b;
};

Perna::Perna(float comprimento, float largura)
    : a(comprimento * 0.4, largura), b(comprimento * 0.35, largura)
{
    a.setConexcao(&b, 0.0);
}

void Perna::setCurvatura(float curvatura, bool reto, int tipo)
{ //0= normal, 1=ossoA, 2=ossoB

    if (reto)
    {
        a.setAngulo(1);
    }
    else
    {
        if (tipo == 0)
        {
            a.setAngulo(curvatura * 0.9);
            b.setAngulo(curvatura * 0.9);
        }
        else if (tipo == 1)
        {
            b.setAngulo(90);
        }
        else if (tipo == 2)
        {
            a.setAngulo(90);
        }
    }
}
/////////////////////////////////////////////////////

////////////////////////////////////////////////////

class Panda
{
public:
    Panda(float grossura);
    void desenha();
    void setCurvatura(int dedo, float curv, bool reto, int tipo);
    float getCurvatura(int dedo) { return curvatura[dedo]; }
    void home();
    void deita();
    void anda();
    void corre();
    void equilibra();
    void luta();

protected:
    float grossura;

    Braco bEsquerdo;
    Braco bDireito;
    Perna pEsquerda;
    Perna pDireita;
    float curvatura[5];
    float curvaturaZ[3];
};

Panda::Panda(float gros)
    : grossura(gros),
      bEsquerdo(6 * grossura, grossura),
      bDireito(6 * grossura, grossura),
      pEsquerda(6 * grossura, grossura),
      pDireita(6 * grossura, grossura)
{
    for (int i = 0; i < 5; i++)
    {
        curvatura[i] = 0;
        curvaturaZ[i] = 0;
    }
}

void Panda::desenha()
{
    glPushMatrix();
    //1-  , 2-altura,
    glTranslatef(0, 8.0 * grossura, 0.0);
    glPushMatrix();

    //braco esquerdo
    glTranslatef(-4.0 * grossura, -3, 1);
    glRotatef(120, 0.0, 0.0, 1.0);
    glRotatef(-20, 0.0, 1.0, 0.0);
    glRotatef(curvatura[0] * 0.9, 1.0, 0.0, 0.0);
    glRotatef(curvaturaZ[0] * 0.9, 0.0, 0.0, 1.0);
    glutSolidSphere(1.5 * grossura, 8, 8);
    bEsquerdo.desenha();

    glPopMatrix();
    glPushMatrix();

    //cabeça
    glTranslatef(-1 * grossura, 0.0, 0.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexCoord2f(1.0f, 0.0f);
    glutSolidSphere(4 * grossura, 8, 8);
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    glPushMatrix();

    //orelhinha esquerda
    glTranslatef(-3 * grossura, 4 * grossura, 0.0);
    glutSolidSphere(1.5 * grossura, 8, 8);

    glPopMatrix();
    glPushMatrix();

    //orelhinha direita
    glTranslatef(1 * grossura, 4 * grossura, 0.0);
    glutSolidSphere(1.5 * grossura, 8, 8);

    glPopMatrix();
    glPushMatrix();

    //rabinho
    glTranslatef(-1, -8 * grossura, -2);
    glutSolidSphere(0.75 * grossura, 8, 8);

    glPopMatrix();
    glPushMatrix();

    //braco direiro
    glTranslatef(2.5 * grossura, -3, 1);
    glRotatef(-120, 0.0, 0.0, 1.0);
    glRotatef(20, 0.0, 1.0, 0.0);
    glRotatef(curvatura[1] * 0.9, 1.0, 0.0, 0.0);
    glRotatef(curvaturaZ[1] * 0.9, 0.0, 0.0, 1.0);
    glutSolidSphere(1.5 * grossura, 8, 8);
    bDireito.desenha();

    glPopMatrix();
    glPushMatrix();

    //perna esquerda
    glTranslatef(-2.8 * grossura, -9 * grossura, 0);
    glRotatef(-180, 0.0, 0.0, 1.0);
    glRotatef(20, 0.0, 1.0, 0.0);
    glRotatef(curvatura[2] * 0.9, 1.0, 0.0, 0.0);
    glRotatef(curvaturaZ[2] * 0.9, 0.0, 0.0, 1.0);
    glutSolidSphere(1.5 * grossura, 8, 8);
    pEsquerda.desenha();

    glPopMatrix();
    glPushMatrix();

    //perna direita
    glTranslatef(1 * grossura, -9 * grossura, 0);
    glRotatef(-180, 0.0, 0.0, 1.0);
    glRotatef(20, 0.0, 1.0, 0.0);
    glRotatef(curvatura[3] * 0.9, 1.0, 0.0, 0.0);
    glRotatef(curvaturaZ[3] * 0.9, 0.0, 0.0, 1.0);
    glutSolidSphere(1.5 * grossura, 8, 8);
    pDireita.desenha();

    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.75 * grossura, 3.0 * grossura, 0.0);
    glScalef(4.5 * grossura, 6.0 * grossura, 4 * grossura);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    GLUquadricObj* q = gluNewQuadric();
    gluQuadricTexture(q, true);
    glTexCoord2f(0.0f, 0.0f);
    gluSphere(q, 0.75 * grossura, 30, 10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



  //  glEnable(GL_TEXTURE_GEN_S);
   // glEnable(GL_TEXTURE_GEN_T);
   // glBindTexture(GL_TEXTURE_GEN_T, texture[0]);
  //  glTexCoord2f(1.0f, 0.0f);
  //  glutSolidSphere( 0.75 * grossura, 30, 10);
  //  glDisable(GL_TEXTURE_GEN_T);
  //  glDisable(GL_TEXTURE_GEN_S);

   // glPopMatrix();
}

void Panda::setCurvatura(int membro, float curv, bool reto, int tipo)
{
    curvatura[membro] = curv;

    switch (membro)
    {
    case 0:
        bEsquerdo.setCurvatura(curv, reto, tipo);
        break;
    case 1:
        bDireito.setCurvatura(curv, reto, tipo);
        break;
    case 2:
        pEsquerda.setCurvatura(curv, reto, tipo);
        break;
    case 3:
        pDireita.setCurvatura(curv, reto, tipo);
        break;
    }
}

//////////////////////////////////////////////////////////////
void Panda::home()
{

    if (ang < 0)
        ang += 360;

    if (ang2 < 0)
        ang2 += 360;

    if (ang3 < 0)
        ang3 += 360;

    while (ang > 0)
    {
        ang -= 10;
        display();
    }
    ang = 0;
    while (ang2 > 0)
    {
        ang2 -= 10;
        display();
    }
    ang2 = 0;
    while (ang3 > 0)
    {
        ang3 -= 10;
        display();
    }
    ang3 = 0;
    display();
    setCurvatura(2, 0, false, 0);
    setCurvatura(3, 0, false, 0);
    setCurvatura(0, 0, false, 0);
    setCurvatura(1, 0, false, 0);
    display();
}

void Panda::deita()
{
    home();

    for (int i = 0; i < 180; i += 20)
    {
        ang += 20;
        ang2 -= 10;
        display();
    }

    ang = 90;
    display();
}


void Panda::corre(){
    ang += 50;
    for (int k = 0; k < 5; k++)
    {
        for (int j = 0; j < 5; j++)
        {
            setCurvatura(2, getCurvatura(2) - 10, false, 0);
            setCurvatura(3, getCurvatura(3) + 10, false, 0);
            setCurvatura(0, getCurvatura(0) + 10, false, 0);
            setCurvatura(1, getCurvatura(1) - 10, false, 0);
            ang2 = 2;
            display();
            Sleep(40);
        }

        for (int j = 0; j < 5; j++)
        {
            setCurvatura(2, getCurvatura(2) + 10, false, 0);
            setCurvatura(3, getCurvatura(3) - 10, false, 0);
            setCurvatura(0, getCurvatura(0) - 10, false, 0);
            setCurvatura(1, getCurvatura(1) + 10, false, 0);
            ang2 = 0;
            display();
            Sleep(40);
        }
    }

    setCurvatura(2, 0, false, 0);
    setCurvatura(3, 0, false, 0);
    setCurvatura(0, 0, false, 0);
    setCurvatura(1, 0, false, 0);
    display();
}

void Panda::anda(){

 ang += 50;
    for (int k = 0; k < 10; k++)
    {
        for (int j = 0; j < 2; j++)
        {
            setCurvatura(2, getCurvatura(2) - 5, false, 0);
            setCurvatura(3, getCurvatura(3) + 5, false, 0);
            ang2 = 2;
            display();
            Sleep(100);
        }

        for (int j = 0; j < 2; j++)
        {
            setCurvatura(2, getCurvatura(2) + 5, false, 0);
            setCurvatura(3, getCurvatura(3) - 5, false, 0);
            ang2 = 0;
            display();
            Sleep(100);
        }
    }

    setCurvatura(2, 0, false, 0);
    setCurvatura(3, 0, false, 0);
    setCurvatura(0, 0, false, 0);
    setCurvatura(1, 0, false, 0);
    display();

}

void Panda::equilibra(){

 home();
 display();


 setCurvatura(2, -85, false, 0);
 display();

 for(int i=0; i<6; i++){

    ang3 = 2;
    display();
    Sleep(200);

    ang2 = 2;
    display();
    Sleep(200);

    ang3 = -2;
    display();
    Sleep(200);

    ang2 = -2;
    display();
    Sleep(200);

 }

 }

void Panda::luta(){
home();
display();

setCurvatura(3, -10 , false, 0);
setCurvatura(2, 10 , false, 0);
setCurvatura(0, 70 , false, 0);
setCurvatura(1, 100 , false, 0);
display();
Sleep(30);

//setCurvatura(0, getCurvatura(0) , false, 2);
//setCurvatura(1, getCurvatura(0) , false, 2);
//display();


    setCurvatura(0, getCurvatura(0) , false, 1);
     setCurvatura(0, getCurvatura(0) , false, 2);
    display();
    Sleep(200);
    setCurvatura(0, 100, false, 0);
    display();

    setCurvatura(1, getCurvatura(0) , false, 2);
    display();
    Sleep(200);
    setCurvatura(1, 100, false, 0);
    display();



}

/////////////////////////////////////////////////////////////
Panda p(1.0);

///////////////////////////////////////////////////
void init(void)
{
    //LoadGLTextures();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);       // Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LEQUAL);  // The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST); // Enables Depth Testing
    glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading
}

void displaychao() {

    glColor3f(1.0, 1.0, 1.0);
//    glTranslatef(dx, 1.0, 0.0); // A cada passada do cavalo movimenta
   // glEnable(GL_TEXTURE_2D);
   // glBindTexture (GL_TEXTURE_2D, texture[0]);
    glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);glVertex3f(-250.0, -31.0, -100.0);
            glTexCoord2f(1.0f, 0.0f);glVertex3f(-250.0, -31.0, 100.0);
            glTexCoord2f(1.0f, 1.0f);glVertex3f(250.0, -31.0, 100.0);
            glTexCoord2f(0.0f, 1.0f);glVertex3f(250.0, -31.0, -100.0);
        glEnd();
   // glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    return;

}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glBindTexture(GL_TEXTURE_2D, texture[0]);

    //////////////ISSO AQUI EH PRA LUZ///////////E EU AINDA N SEI COMO FUNCA/////
    GLfloat diffuseLight[] = {1.0f, 1.0f, 1.0f, 1.0};
    GLfloat ambientLight[] = {0.2f, 0.2f, 0.4f, 1.0};
    GLfloat lightPos[] = {0.0f, 500.0f, 100.0f, 1.0f};
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, diffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0f, 1.0f, 1.0f);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, diffuseLight);
    glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 50);
    //////////////////////////////////////////////////////////////////////////

    glPushMatrix();

    glTranslatef(0.0, -5.0, -15.0);
    glRotatef(ang3, 0.0, 0.0, 1.0);
    glRotatef(ang, 0.0, 1.0, 0.0);
    glRotatef(ang2, 1.0, 0.0, 0.0);
    glColor3f(1.0, 0.8, 0);


    p.desenha();
    glPopMatrix();
    //glPushMatrix();
    //displaychao();
    //glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(55.0, (GLfloat)w / (GLfloat)h, 1.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
}

void idle()
{
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
        if (p.getCurvatura(0) < 100)
            p.setCurvatura(0, p.getCurvatura(0) + 5, false, 0);
        break;

    case 'a':
        if (p.getCurvatura(0) > 0)
            p.setCurvatura(0, p.getCurvatura(0) - 5, false, 0);
        break;

    case 'w':
        if (p.getCurvatura(1) < 100)
            p.setCurvatura(1, p.getCurvatura(1) + 5, false, 0);
        break;

    case 's':
        if (p.getCurvatura(1) > 0)
            p.setCurvatura(1, p.getCurvatura(1) - 5, false, 0);
        break;

    case 'e':
        if (p.getCurvatura(2) < 100)
            p.setCurvatura(2, p.getCurvatura(2) + 5, false, 0);
        break;

    case 'd':
        if (p.getCurvatura(2) > -50)
            p.setCurvatura(2, p.getCurvatura(2) - 5, false, 0);
        break;

    case 'r':
        if (p.getCurvatura(3) < 100)
            p.setCurvatura(3, p.getCurvatura(3) + 5, false, 0);
        break;

    case 'f':
        if (p.getCurvatura(3) > -50)
            p.setCurvatura(3, p.getCurvatura(3) - 5, false, 0);
        break;

    case '.': //>
        ang += 5;
        if (ang > 360)
            ang -= 360;
        break;

    case ',': //<
        ang -= 5;
        if (ang < 0)
            ang += 360;
        break;

    case ']':
        ang2 += 5;
        if (ang2 > 360)
            ang2 -= 360;
        break;

    case '[':
        ang2 -= 5;
        if (ang2 < 0)
            ang2 += 360;
        break;

    case 'h':
        p.home();
        break;

    case 'j':
        p.deita();
        break;

    case 'm':
        p.corre();
        break;

    case 'n':
        p.anda();
        break;

    case 'b':
        p.equilibra();
        break;

    case 'v':
        p.luta();
        break;

    default:
        return;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow(argv[0]);
    init();

    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    if (!LoadGLTextures()) {
        return 1;
    }

    return 0;
}
