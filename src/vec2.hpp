#pragma once


#include <math.h>
#include <GL/gl.h>
#include "types.hpp"

union Vec2 {
public:
  /* attributes */
  struct PACK {
    real x, y;
  };
  real coord[2];

  /* constructors */
  Vec2(): x(0.0), y(0.0) {}
  Vec2(const real p_x, const real p_y):
    x(p_x), y(p_y) {}

  /* accessors */
  inline       real& operator[](const usize i)       {return coord[i];}
  inline const real& operator[](const usize i) const {return coord[i];}

  inline real sqr_len() const {return x * x + y * y;}
  inline real     len() const {return sqrt(sqr_len());}

  inline Vec2 normal() const {
    const real l = len();
    return Vec2(x / l, y / l);
  }

  /* assign operators */
  inline void neg() {
    x = -x;
    y = -y;
  }
  inline void normalize() {
    const real l = len();
    x /= l;
    y /= l;
  }
  inline void operator+=(const Vec2&o) {
    x += o.x;
    y += o.y;
  }
  inline void operator-=(const Vec2&o) {
    x -= o.x;
    y -= o.y;
  }
  inline void operator*=(const Vec2&o) {
    x *= o.x;
    y *= o.y;
  }
  inline void operator/=(const Vec2&o) {
    x /= o.x;
    y /= o.y;
  }

  /* operators */
  inline Vec2 operator-() const {
    return Vec2(-x, -y);
  }
  inline Vec2 operator+(const Vec2&o) const {
    return Vec2(x + o.x, y + o.y);
  }
  inline Vec2 operator-(const Vec2&o) const {
    return Vec2(x - o.x, y - o.y);
  }
  inline Vec2 operator*(const Vec2&o) const {
    return Vec2(x * o.x, y * o.y);
  }
  inline Vec2 operator/(const Vec2&o) const {
    return Vec2(x / o.x, y / o.y);
  }
  inline real dot(const Vec2&o) const {
    return x * o.x + y * o.y;
  }
  inline real cross(const Vec2&o) const {
    return x * o.y - y * o.x;
  }

  inline Vec2 min(const Vec2&o) const {
    return Vec2(
      x < o.x ? x : o.x,
      y < o.y ? y : o.y
    );
  }

  inline Vec2 max(const Vec2&o) const {
    return Vec2(
      x > o.x ? x : o.x,
      y > o.y ? y : o.y
    );
  }


  /* OpenGL */
  inline void gl_vertex() const {glVertex2f(x, y);}

  inline void gl_texcoord () const {glTexCoord2f (x, y);}
  //inline void gl_evalcoord() const {glEvalCoord2f(x, y);} // unsupported
};