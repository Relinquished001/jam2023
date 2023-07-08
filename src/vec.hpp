#pragma once


#include "types.hpp"


template<typename T> struct Vec {
  usize size, capacity;
  T*data;
  
  Vec<T>(const usize p_capacity):
    size(0), capacity(p_capacity),
    data(new T[p_capacity])
  {}
  
  
  /* accessors */
  inline       T& operator[](const usize i)       {return data[i];}
  inline const T& operator[](const usize i) const {return data[i];}  
  
  
  /* stack */
  // push the element to the end of the array
  inline void push(const T&e) {data[size++] = e;}
  // pop the element from the end of the array
  inline T pop() {return data[--size];}
  
  
  /* cast */
  template<typename C> inline       C* cast()       {return (C*)(data);}
  template<typename C> inline const C* cast() const {return (C*)(data);}
  
};