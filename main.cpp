#include<GL/glew.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "SDL2/SDL.h"

#include <iostream>

#include "Math/Mat4.h"
#include "3D_utils/camera.h"
#include "3D_utils/Scene.h"

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
    fenetre = SDL_CreateWindow("RIPIehl alpha", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

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


    glViewport(0 ,0 , 800, 800);

    Camera camera;
    camera.movZ(-10);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(30,1, 0.1, 1000);

    while(!terminer){

        //if any event catch
        if( SDL_PollEvent(&evenements) == 1) {
            if (evenements.window.event == SDL_WINDOWEVENT_CLOSE) {
                terminer = true;
            }

            if (evenements.type == SDL_KEYDOWN){
                switch(evenements.key.keysym.sym) {
                    case SDLK_z:
                        camera.movZ(0.1);
                        break;

                    case SDLK_s:
                        camera.movZ(-0.1);
                        break;

                    case SDLK_q:
                        camera.movX(0.1);
                        break;

                    case SDLK_d:
                        camera.movX(-0.1);
                        break;

                    case SDLK_UP:
                        camera.turnX(0.1);
                        break;

                    case SDLK_DOWN:
                        camera.turnX(-0.1);
                        break;

                    case SDLK_LEFT:
                        camera.turnY(0.1);
                        break;

                    case SDLK_RIGHT:
                        camera.turnY(-0.1);
                        break;

                    default:
                        break;

                }
            }

        }

        //on dessine
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadMatrixf((camera.model * camera.view).transposed());

        //camera.projection.RotateX(0.1);
        //std :: cout << camera.projection << std :: endl;

        drawOrigin();

        glFlush();

        // Nettoyage de l'écran
        SDL_GL_SwapWindow(fenetre);

    }

    // On quitte la SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
} 