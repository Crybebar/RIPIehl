//
// Created by mckoala on 15/12/15.
//

#ifndef RIPIEHL_SCENE_H
#define RIPIEHL_SCENE_H

#include <GL/gl.h>

void drawOrigin(){

    glBegin(GL_LINES);

    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(0.f, 0.f, 0.f);
    glVertex3f(1.f, 0.f, 0.f);

    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.f, 0.f, 0.f);
    glVertex3f(0.f, 1.f, 0.f);

    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.f, 0.f);
    glVertex3f(0.f, 0.f, 1.f);

    glEnd();
}

#endif //RIPIEHL_SCENE_H
