#include <iostream>

#include "u_vector.h"

template <class T>
u_vector<T>::iterator::iterator(const T* p, bool pte) : pointer(p), past_the_end(pte) {}

template <class T>
u_vector<T>::iterator::iterator() : pointer(p), past_the_end(false) {}

template <class T>
typename u_vector<T>::iterator& u_vector<T>::iterator::operator++() {
  if (pointer != nullptr) {
    if (!past_the_end) {
      if (pointer->next != nullptr) {
        pointer = pointer->next;
      } else {
        pointer = pointer + 1;
        past_the_end = true;
      }
      current_position++;
    }
  }
  return *this;
}

template <class T>
typename u_vector<T>::iterator u_vector<T>::iterator::operator++(int) {
  iterator aux(*this);
  if (pointer != nullptr) {
    if (!past_the_end) {
      if (pointer->next != nullptr)
        pointer = pointer->next;
      else {
        pointer = pointer + 1;
        past_the_end = true;
      }
    }
    current_position++;
  }

  return aux;
}

template <class T>
typename u_vector<T>::iterator& u_vector<T>::iterator::operator--() {
  if (pointer != nullptr) {
    if (pointer->prev == nullptr) {
      pointer = nullptr;
    } else if (!past_the_end) {
      pointer = pointer->prev;
    } else {
      pointer = pointer - 1;
      past_the_end = false;
    }
    current_position--;
  }
  return *this;
}

template <class T>
typename u_vector<T>::iterator u_vector<T>::iterator::operator--(int) {
  iterator aux(*this);
  if (pointer != nullptr) {
    if (pointer->prev == nullptr) {
      pointer = nullptr;
    } else if (!past_the_end) {
      pointer = pointer->prev;
    } else {
      pointer = pointer - 1;
      past_the_end = false;
    }
    current_position--;
  }
  return aux;
}

template <class T>
bool u_vector<T>::iterator::operator==(const u_vector<T>::iterator& it) const {
  return pointer == it.pointer;
}

template <class T>
bool u_vector<T>::iterator::operator!=(const u_vector<T>::iterator& it) const {
  return pointer != it.pointer;
}

template <class T>
bool u_vector<T>::iterator::operator<(const u_vector<T>::iterator& it) const {
  return pointer < it.pointer;
}

template <class T>
bool u_vector<T>::iterator::operator<=(const u_vector<T>::iterator& it) const {
  return pointer <= it.pointer;
}

template <class T>
bool u_vector<T>::iterator::operator>(const u_vector<T>::iterator& it) const {
  return pointer > it.pointer;
}

template <class T>
bool u_vector<T>::iterator::operator<=(const u_vector<T>::iterator& it) const {
  return pointer <= it.pointer;
}

template <class T>
typename u_vector<T>::iterator u_vector<T>::iterator::operator+(int value) const {
  if (current_position + value < size) {
    current_position += value;
    return iterator(pointer + value);
  }
  throw std::out_of_range("Code 2001");
}

template <class T>
typename u_vector<T>::iterator& u_vector<T>::iterator::operator+=(int value) {
  if (current_position + value < size) {
    current_position += value;
    pointer = pointer + value;
    return *this;
  }
  throw std::out_of_range("Code 2002");
}

template <class T>
typename u_vector<T>::iterator u_vector<T>::iterator::operator-(int value) const {
  if (current_position - value >= 0) {
    current_position -= value;
    return iterator(pointer - value);
  }
  throw std::out_of_range("Code 2003");
}

template <class T>
typename u_vector<T>::iterator& u_vector<T>::iterator::operator-=(int value) {
  if (current_position - value >= 0) {
    current_position -= value;
    pointer = pointer + value;
    return *this;
  }
  throw std::out_of_range("Code 2004");
}

template <class T>
T& u_vector<T>::iterator::operator*() const {
  return pointer->info;
}

template <class T>
T* u_vector<T>::iterator::operator->() const {
  return &(pointer->info);
}

template <class T>
T& u_vector<T>::iterator::operator[](unsigned int index) const {
  if (index < size) {
    return *(p + index);
  }
  throw std::out_of_range("Code 2005");
}

template <class T>
typename u_vector<T>::iterator u_vector<T>::begin() const {
  return iterator(first);
}

template <class T>
typename u_vector<T>::iterator u_vector<T>::end() const {
  if (!last) {
    return u_vector<T>::iterator();
  }
  return u_vector<T>::iterator(last + 1, true);
}