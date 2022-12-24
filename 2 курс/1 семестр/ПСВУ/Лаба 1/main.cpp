//
//  main.cpp
//  PSVU
//
//  Created by Карим Музафаров on 09.09.2022.
//

#include <cmath>
#include <GLUT/GLUT.h>//Подключениебиблиотекиglut.h
void Initialize()
{
//Выбрать фоновый (очищающий) цвет
    glClearColor(1.0,1.0,1.0, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Установитьпроекцию
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}
void drawRectangle(){
    glColor3f(.5f,.5f,.0f);
    glBegin(GL_POLYGON);
    glVertex2f(.45,.9);
    glVertex2f(.55,.9);
    glVertex2f(.55,.85);
    glVertex2f(.45,.85);
    glEnd();
    glFlush();
}

void drawEllipse(float x, float y, float rx, float ry, float color1, float color2, float color3) {
    glColor3f(color1,color2,color3);
    float i = 0.0f;
    
    glBegin(GL_TRIANGLE_FAN);
    
    glVertex2f(x, y); // Центр
    for(i = 0.0f; i <= 360; i++)
        glVertex2f(rx*cos(M_PI * i / 180.0) + x, ry*sin(M_PI * i / 180.0) + y);
    
    glEnd();
    glFlush();
}


void drawSnowman(){
    drawRectangle();
    drawEllipse(.5, .785, .065, .065 , .5f,.5f,.0f);
    drawEllipse(.5, .785, .06, .06 ,.5f,.8f,1.0f);
    drawEllipse(.5, .625, .095, .095 ,.5f,.5f, .0f);
    drawEllipse(.5, .625, .09, .09 ,.5f,.8f,1.0f);
    drawEllipse(.5, .395, .155, .135,.5f,.5f, .0f);
    drawEllipse(.5, .395, .15, .13,.5f,.8f,1.0f);
}
//Войти в главный цикл
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400); //Указываемразмерокна
    glutInitWindowPosition(100,100); //Позицияокна
    glutCreateWindow("Polygon");
    Initialize();
    glutDisplayFunc(drawSnowman);
    glutMainLoop();
return 0; }
//Имяокна
//Вызовфункции Initialize
//Вызовфункцииотрисовки
