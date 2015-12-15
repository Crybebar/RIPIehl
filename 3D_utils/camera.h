//
// Created by mckoala on 14/12/15.
//

#ifndef RIPIEHL_CAMERA_H
#define RIPIEHL_CAMERA_H

#include "../Math/Mat4.h"
class Camera{

public :

    Mat4 model;
    Mat4 view;
    Mat4 projection;

    //Constructor
    Camera() : model(), view(), projection(){};
    Camera(const Mat4 & m, const Mat4 & v, const Mat4 & p) : model(m), view(v), projection(p){}
    Camera(const Camera & c) : model(c.model), view(c.view), projection(c.projection){}

    //everything is public, don't need to do getters or setters

    inline void movX(const float & f){view.mat[3] += f;}
    inline void movY(const float & f){view.mat[7] += f;}
    inline void movZ(const float & f){view.mat[11] += f;}

    inline void turnX(const float & f){view.RotateX(f);}
    inline void turnY(const float & f){view.RotateY(f);}
    inline void turnZ(const float & f){view.RotateZ(f);}

    /*
    inline void setGLModelView(GLfloat * modelView){
        Mat4 tmp = (model * view).transposed();
        for(int i = 0; i < 16; ++i)
            modelView[i] = (GLfloat) (tmp[i]);
    }
    */

};

#endif //RIPIEHL_CAMERA_H
