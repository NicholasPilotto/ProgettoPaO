#include "u_vector.h"

template <class T>
u_vector<T>::u_vector(unsigned int __size) : array(new T[__size]), __size(__size) {}

template <class T>
u_vector<T>::u_vector(const u_vector& uv) : array(deep_copy(uv.array)), __size(uv.__size) {}

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
  if (object.__size != 0) {
    T* aux = new T[__size + object.__size]();
    for (unsigned int i = 0; i < __size; i++) {
      aux[i] = array[i];
    }
    for (unsigned int i = 0; i < object.__size; i++) {
      aux[__size + i] = object.array[i];
    }
    __size += object.__size;
    delete[] array;
    array = aux;
  }
  return *this;
}

template <class T>
unsigned int u_vector<T>::size() const {
  return __size;
}

template <class T>
bool u_vector<T>::empty() const {
  return !__size;
}

template <class T>
void u_vector<T>::clear() {
  erase(begin(), end());
}

template <class T>
u_vector<T>& u_vector<T>::operator=(const u_vector<T>& v) {
  if (this != &v) {
    delete[] array;
    array = (v.__size == 0) ? nullptr : new int[__size]();
    for (unsigned int i = 0; i < v.__size; i++) {
      array[i] = v.array[i];
    }
  }

  return *this;
}