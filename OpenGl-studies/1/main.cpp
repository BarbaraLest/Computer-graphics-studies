#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
int posx = 200;

void desenha(void){
  glClear(GL_COLOR_BUFFER_BIT);

  glFlush();
}

void teclado (unsigned char tecla, int x, int y){
  switch(tecla){
    case 27 : printf("Tchau");
              exit(0);
              break;
    case 'a' : glutFullScreen();
              break;
    case 's' : glutReshapeWindow(200,200);
               glutPositionWindow (50, 199);
              break;
    default: printf ("vc apertour a tecla %c na coordenada %d, %d\n", tecla, x, y);
  }
}

void teclasEspeciais(int tecla, int x, int y){
    switch(tecla){
      case GLUT_KEY_LEFT :
          if (posx > 50) posx -= 50;
          glutPositionWindow (posx, 199);
          break;
      case GLUT_KEY_RIGHT :
          if (posx < 500) posx += 50;
          glutPositionWindow (posx, 199);
          break;
    }
}

void inicializa(void){
  glClearColor(0,0,0,0);
}

void menuCor(int opcao){
  switch(opcao){
    case 0:
      glClearColor(1,0,0,1);
      break;
    case 1:
      glClearColor(0,1,0,1);
      break;
    case 2:
      glClearColor(0,0,1,1);
      break;
    case 3:
      glClearColor(0,0,0,1);
      break;
  }
  glutPostRedisplay();
}

void criaMenu(){
    int menu = glutCreateMenu(menuCor);
    glutAddMenuEntry("Vermelho", 0);
    glutAddMenuEntry("Verde", 1);
    glutAddMenuEntry("Azul", 2);
    glutAddMenuEntry("Preto", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    inicializa();
    glutCreateWindow("Hello World");
    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(teclasEspeciais);
    criaMenu();
    glutMainLoop();
}
