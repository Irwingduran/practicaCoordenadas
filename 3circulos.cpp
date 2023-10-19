#include <GL/glut.h>
#include <cmath>

const int windowWidth = 800;
const int windowHeight = 600;
const float radius = 100.0;

void drawPolarCircle() {
    glPushMatrix();
    glTranslatef(200, 200, 0); // Trasladamos el círculo a una posición específica
    glBegin(GL_LINE_LOOP);

    for (int angle = 0; angle <= 360; ++angle) {
        float theta = angle * M_PI / 180.0;
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(x, y);
    }

    glEnd();
    glPopMatrix();
}

void drawParametricCircle() {
    glPushMatrix();
    glTranslatef(-200, -200, 0); // Trasladamos el círculo a otra posición
    glBegin(GL_LINE_STRIP);

    for (int i = 0; i <= 100; ++i) {
        float t = static_cast<float>(i) / 100.0;
        float x = radius * cos(2.0 * M_PI * t);
        float y = radius * sin(2.0 * M_PI * t);
        glVertex2f(x, y);
    }

    glEnd();
    glPopMatrix();
}

void drawBezierCircle() {
    glPushMatrix();
    glTranslatef(0, 0, 0); // El círculo de Bézier estará en el centro
    glBegin(GL_LINE_STRIP);

    for (int i = 0; i <= 100; ++i) {
        float t = static_cast<float>(i) / 100.0;
        float x = radius * cos(2.0 * M_PI * t);
        float y = radius * sin(2.0 * M_PI * t);
        glVertex2f(x, y);
    }

    glEnd();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Color blanco

    drawPolarCircle();
    drawParametricCircle();
    drawBezierCircle();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-windowWidth / 2, windowWidth / 2, -windowHeight / 2, windowHeight / 2);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Círculos con OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
