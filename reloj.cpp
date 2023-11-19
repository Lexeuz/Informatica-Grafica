#include <GL/glut.h>
#include <math.h>

const int windowWidth = 800;
const int windowHeight = 800;

void drawClock() {
    // Dibuja el círculo del reloj
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0);
    for (int i = 0; i <= 360; i++) {
        float angle = 3.14159265f * i / 180;
        glVertex2f(50 * cos(angle), 50 * sin(angle));
    }
    glEnd();

    // Dibuja las marcas de las horas
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 12; i++) {
        float angle = 3.14159265f * (i * 30) / 180;
        glVertex2f(40 * cos(angle), 40 * sin(angle));
    }
    glEnd();

    // Dibuja las manecillas
    glRotatef(90, 0.0, 0.0, 1.0); // Alinea las manecillas con la parte superior
    glRotatef(-90, 0.0, 0.0, 1.0); // Corrige la rotación previa
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);

    // Manecilla de las horas
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(20.0, 0.0);
    glEnd();

    // Manecilla de los minutos
    glColor3f(0.0, 0.0, 1.0); // Manecilla azul para los minutos
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(30.0, 0.0);
    glEnd();

    // Manecilla de los segundos
    glColor3f(1.0, 0.0, 0.0); // Manecilla roja para los segundos
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(35.0, 0.0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawClock();
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-windowWidth / 2, windowWidth / 2, -windowHeight / 2, windowHeight / 2, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Reloj Analógico");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(1.0, 1.0, 1.0, 0.0); // Fondo blanco

    glutMainLoop();

    return 0;
}
