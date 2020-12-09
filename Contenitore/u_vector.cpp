#include "u_vector.h"

template <class T>
u_vector<T>::u_vector(unsigned int size) : array(new T[size]), size(size) {}

template <class T>
u_vector<T>::u_vector(const u_vector& uv) : array(deep_copy(uv.array)), size(uv.size) {}

template <class T>
T* u_vector<T>::deep_copy(const T* a) {
  if (this != &a) {
    if (a != nullptr) {
      deep_copy(a + 1);
    }
    return new T(a);
  } else {
    return a;
  }
}

template <class T>
u_vector<T>::~u_vector() {
  if (array) {
    delete array;
  }
}

template <class T>
u_vector<T>& u_vector<T>::push_back(const T& object) {
  if (object.size != 0) {
    T* aux = new T[size + object.size]();
    for (unsigned int i = 0; i < size; i++) {
      aux[i] = array[i];
    }
    for (unsigned int i = 0; i < object.size; i++) {
      aux[size + i] = object.array[i];
    }
    size += object.size;
    delete[] array;
    array = aux;
  }
  return *this;
}