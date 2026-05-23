#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <cmath>

float angle = 0.0f;

void drawCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);

    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159f / 180;

        float x = r * cos(theta);
        float y = r * sin(theta);

        glVertex2f(x + cx, y + cy);
    }

    glEnd();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    // =========================
    // Rotating colorful triangle
    // =========================

    glPushMatrix();

        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        glBegin(GL_TRIANGLES);

            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(0.0f, 0.5f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(-0.5f, -0.5f);

            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(0.5f, -0.5f);

        glEnd();

    glPopMatrix();

    // =========================
    // Yellow Circle
    // =========================

    glColor3f(1.0f, 1.0f, 0.0f);

    drawCircle(0.7f, 0.7f, 0.15f);

    glutSwapBuffers();
}

void update(int value) {

    angle += 1.0f;

    if (angle > 360)
        angle = 0.0f;

    glutPostRedisplay();

    glutTimerFunc(16, update, 0);
}

void init() {

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 800);

    glutCreateWindow("Advanced OpenGL Demo");

    init();

    glutDisplayFunc(display);

    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}