#pragma once


#include "types.hpp"
#include "vec3.hpp"


/* Physics Shape */
struct Shape {
public:
  // check if a point is inside of the shape
  virtual bool contains(const Vec3&) const = 0;
  
  // check if two shapes intersect
  virtual bool intersect(const Shape*const) const = 0;
};


/* Axis Aligned Bounding Box  */
struct Box : public Shape {
public:
  Vec3 min, max;

  Box(const Vec3&p_min, const Vec3&p_max):
    min(p_min), max(p_max)
  {}

  // check if a point is inside of the shape
  bool contains(const Vec3&) const override;
  
  // check if two shapes intersect
  bool intersect(const Shape*const) const override;
  
  // intersect another box
  bool intersect(const Box&) const;
  
  Vec3 clamp(const Vec3&) const;
};


/* Sphere */
struct Sphere : public Shape {
public:
  Vec3 center;
  real radius;

  Sphere(const Vec3&p_center, const real p_radius):
    center(p_center), radius(p_radius)
  {}

  // check if a point is inside of the shape
  bool contains(const Vec3&) const override;

  // check if two shapes intersect
  bool intersect(const Shape*const) const override;
  
  // intersect another sphere
  bool intersect(const Sphere&) const;
  
  // intersect a box
  bool intersect(const Box&) const;
};

