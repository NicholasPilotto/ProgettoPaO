#include <iostream>

#include "u_vector.h"

template <class T>
u_vector<T>::const_iterator::const_iterator(const T* p, bool pte) : pointer(p), past_the_end(pte) {}

template <class T>
u_vector<T>::const_iterator::const_iterator() : pointer(p), past_the_end(false) {}

template <class T>
typename u_vector<T>::const_iterator& u_vector<T>::const_iterator::operator++() {
  if (pointer != nullptr) {
    if (!past_the_end) {
      if (pointer->next != nullptr) {
        pointer = pointer->next;
      } else {
        pointer = pointer + 1;
        past_the_end = true;
      }
    }
  }
  return *this;
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_iterator::operator++(int) {
  const_iterator aux(*this);
  if (pointer != nullptr) {
    if (!past_the_end) {
      if (pointer->next != nullptr)
        pointer = pointer->next;
      else {
        pointer = pointer + 1;
        past_the_end = true;
      }
    }
  }

  return aux;
}

template <class T>
typename u_vector<T>::const_iterator& u_vector<T>::const_iterator::operator--() {
  if (pointer != nullptr) {
    if (pointer->prev == nullptr) {
      pointer = nullptr;
    } else if (!past_the_end) {
      pointer = pointer->prev;
    } else {
      pointer = pointer - 1;
      past_the_end = false;
    }
  }
  return *this;
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_iterator::operator--(int) {
  const_iterator aux(*this);
  if (pointer != nullptr) {
    if (pointer->prev == nullptr) {
      pointer = nullptr;
    } else if (!past_the_end) {
      pointer = pointer->prev;
    } else {
      pointer = pointer - 1;
      past_the_end = false;
    }
  }
  return aux;
}

template <class T>
bool u_vector<T>::const_iterator::operator==(const u_vector<T>::const_iterator& it) const {
  return pointer == it.pointer;
}

template <class T>
bool u_vector<T>::const_iterator::operator!=(const u_vector<T>::const_iterator& it) const {
  return pointer != it.pointer;
}

template <class T>
const T& u_vector<T>::const_iterator::operator*() const {
  return pointer->info;
}

template <class T>
const T* u_vector<T>::const_iterator::operator->() const {
  return &(pointer->info);
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_begin() const {
  return const_iterator(first);
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_end() const {
  if (!last) {
    return dList<T>::const_iterator();
  }
  return dList<T>::const_iterator(last + 1, true);  // attenzione: NON e' past the end
}