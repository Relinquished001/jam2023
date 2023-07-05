#pragma once

#include "types.hpp"
#include "vec2.hpp"

union Vec3 {
public:
  /* attributes */
  struct {
    real x, y, z;
  };
  real coord[3];
  
  /* constructors */
  Vec3(): x(0.0), y(0.0), z(0.0) {}
  Vec3(const real p_x, const real p_y, const real p_z):
    x(p_x), y(p_y), z(p_z) {}
  
  /* accessors */
  inline       real& operator[](const usize i)       {return coord[i];}
  inline const real& operator[](const usize i) const {return coord[i];}
  
  inline real sqr_len() const {return x * x + y * y + z * z;}
  inline real     len() const {return sqrt(sqr_len());}
  
  inline Vec3 normal() const {
    const real l = len();
    return Vec3(x / l, y / l, z / l);
  }
  
  /* assign operators */
  inline void neg() {
    x = -x;
    y = -y;
    z = -z;
  }
  inline void normalize() {
    const real l = len();
    x /= l;
    y /= l;
    z /= l;
  }
  inline void operator+=(const Vec3&o) {
    x += o.x;
    y += o.y;
    z += o.z;
  }
  inline void operator-=(const Vec3&o) {
    x -= o.x;
    y -= o.y;
    z -= o.z;
  }
  inline void operator*=(const Vec3&o) {
    x *= o.x;
    y *= o.y;
    z *= o.z;
  }
  inline void operator/=(const Vec3&o) {
    x /= o.x;
    y /= o.y;
    z /= o.z;
  }
  
  /* operators */
  inline Vec3 operator-() const {
    return Vec3(-x, -y, -z);
  }
  inline Vec3 operator+(const Vec3&o) const {
    return Vec3(x + o.x, y + o.y, z + o.z);
  }
  inline Vec3 operator-(const Vec3&o) const {
    return Vec3(x - o.x, y - o.y, z - o.z);
  }
  inline Vec3 operator*(const Vec3&o) const {
    return Vec3(x * o.x, y * o.y, z * o.z);
  }
  inline Vec3 operator/(const Vec3&o) const {
    return Vec3(x / o.x, y / o.y, z / o.z);
  }
  inline real dot(const Vec3&o) const {
    return x * o.x + y * o.y + z * o.z;
  }
  inline Vec3 cross(const Vec3&o) const {
    return Vec3(
        y * o.z - z * o.y,
        z * o.x - x * o.z,
        x * o.y - y * o.x
    );
  }
  
  /* conversion */
  inline Vec2 xy() const {return Vec2(x, y);}
  inline Vec2 yx() const {return Vec2(y, x);}
  inline Vec2 xz() const {return Vec2(x, z);}
  inline Vec2 zx() const {return Vec2(z, x);}
  inline Vec2 yz() const {return Vec2(y, z);}
  inline Vec2 zy() const {return Vec2(z, y);}
};