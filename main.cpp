#include<GL/glew.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "SDL2/SDL.h"

#include <iostream>

#include "Math/Mat4.h"

using namespace std;

int main() {
    //https://openclassrooms.com/courses/developpez-vos-applications-3d-avec-opengl-3-3/creer-une-fenetre-avec-la-sdl-2-0

    // Notre fenêtre
    SDL_Window* fenetre(0);
    SDL_GLContext contexteOpenGL(0);

    SDL_Event evenements;
    bool terminer(false);

    // Initialisation de la SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Création de la fenêtre
    fenetre = SDL_CreateWindow("RIPIehl alpha", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if(fenetre == 0){
        std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Création du contexte OpenGL
    contexteOpenGL = SDL_GL_CreateContext(fenetre);
    if(contexteOpenGL == 0){
        std::cout << SDL_GetError() << std::endl;
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
        return -1;
    }

    // Version d'OpenGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    // Double Buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //1 pour actif
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24); //24 pour la precisiona 24 bits

    while(!terminer){
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        {
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(0.0f, 1.0f);
            glVertex2f(-1.0f, -1.0f);
            glVertex2f(1.0f, -1.0f);
        }
        glEnd();

        glFlush();

        SDL_WaitEvent(&evenements);
        if(evenements.window.event == SDL_WINDOWEVENT_CLOSE) {
            terminer = true;
        }

        // Nettoyage de l'écran
        SDL_GL_SwapWindow(fenetre);

    }

    // On quitte la SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
} 