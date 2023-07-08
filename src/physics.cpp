#include "physics.hpp"
#include "vec3.hpp"

#define IN(_pt, _min, _max) (_min <= _pt and _pt <= _max)

#define CAST(_type, _var, _from) _type*const _var = dynamic_cast<_type*>(_from)

/* Axis Aligned Bounding Box  */
bool Box::contains(const Vec3&point) const {
  return
    IN(point.x, min.x, max.x) and
    IN(point.y, min.y, max.y) and
    IN(point.z, min.z, max.z);
}


// try casting to a known shape type
bool Box::intersect(const Shape*const o) const {
  
  CAST(const Box, box, o);
  if (box) return intersect(*box);
  
  CAST(const Sphere, sphere, o);
  if (sphere) return sphere->intersect(*this);
  
  return false;
}


bool Box::intersect(const Box&o) const {
  return
    (min.x <= o.max.x and o.min.x <= max.x) and
    (min.y <= o.max.y and o.min.y <= max.y) and
    (min.z <= o.max.z and o.min.z <= max.z);
}

Vec3 Box::clamp(const Vec3&point) const {
  return point.min(max).max(min);
}


/* Sphere */
bool Sphere::contains(const Vec3&point) const {
  return (point - center).sqr_len() <= radius * radius;
}


// try casting to a known shape type
bool Sphere::intersect(const Shape*const o) const {
  
  CAST(const Sphere, sphere, o);
  if (sphere) return intersect(*sphere);
  
  CAST(const Box, box, o);
  if (box) return intersect(*box);
  
  return false;
}


bool Sphere::intersect(const Sphere&o) const {
  return (o.center - center).len() <= radius + o.radius;
}

bool Sphere::intersect(const Box&o) const {
  contains(o.clamp(center));
}