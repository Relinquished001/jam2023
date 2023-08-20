#pragma once


#include <GL/gl.h>
#include "types.hpp"

union Color {
public:
  /* attributes */
  struct PACK {
    unit r, g, b, a;
  };
  unit rgba [4];
  
  /* constructors */
  Color(): r(0.0), g(0.0), b(0.0), a(1.0) {}
  
  Color(
    const unit p_r,
    const unit p_g,
    const unit p_b
  ): r(p_r), g(p_g), b(p_b), a(1.0) {}
  
  Color(
    const unit p_r,
    const unit p_g,
    const unit p_b,
    const unit p_a
  ): r(p_r), g(p_g), b(p_b), a(p_a) {}
  
  Color(const usize value);


  //explicit operator uint32_t() const {}
  
  
  /* OpenGL */
  inline void gl_color() const {glColor3f   (r, g, b);}
  inline void gl_clear() const {glClearColor(r, g, b, a);}
  
};

