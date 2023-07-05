#pragma once

#include <libdragon.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "vec3.hpp"

class Camera {
public:
  Vec3 eye, target;
  
  Camera() {}
  
  Camera(const Vec3&p_eye, const Vec3&p_target):
    eye(p_eye), target(p_target) {}
  
  inline void trs() const {
    glLoadIdentity();
    gluLookAt(
        eye.x   , eye.y   , eye.z   ,
        target.x, target.y, target.z,
        0.0     , 1.0     , 0.0
    );
  }
};
