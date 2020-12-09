#include <iostream>

#include "u_vector.h"

template <class T>
u_vector<T>::const_iterator::const_iterator(const T* p, bool pte) : pointer(p), past_the_end(pte), current_position(0) {}

template <class T>
u_vector<T>::const_iterator::const_iterator() : pointer(p), past_the_end(false), current_position(0) {}

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
      current_position++;
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
    current_position++;
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
    current_position--;
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
    current_position--;
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
bool u_vector<T>::const_iterator::operator<(const u_vector<T>::const_iterator& it) const {
  return pointer < it.pointer;
}

template <class T>
bool u_vector<T>::const_iterator::operator<=(const u_vector<T>::const_iterator& it) const {
  return pointer <= it.pointer;
}

template <class T>
bool u_vector<T>::const_iterator::operator>(const u_vector<T>::const_iterator& it) const {
  return pointer > it.pointer;
}

template <class T>
bool u_vector<T>::const_iterator::operator<=(const u_vector<T>::const_iterator& it) const {
  return pointer <= it.pointer;
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_iterator::operator+(int value) const {
  if (current_position + value < size) {
    current_position += value;
    return const_iterator(pointer + value);
  }
  throw std::out_of_range("Code 1001");
}

template <class T>
typename u_vector<T>::const_iterator& u_vector<T>::const_iterator::operator+=(int value) {
  if (current_position + value < size) {
    current_position += value;
    pointer = pointer + value;
    return *this;
  }
  throw std::out_of_range("Code 1002");
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_iterator::operator-(int value) const {
  if (current_position - value >= 0) {
    current_position -= value;
    return const_iterator(pointer - value);
  }
  throw std::out_of_range("Code 1003");
}

template <class T>
typename u_vector<T>::const_iterator& u_vector<T>::const_iterator::operator-=(int value) {
  if (current_position - value >= 0) {
    current_position -= value;
    pointer = pointer + value;
    return *this;
  }
  throw std::out_of_range("Code 1004");
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
const T& u_vector<T>::const_iterator::operator[](unsigned int index) const {
  if (index < size) {
    return *(p + index);
  }
  throw std::out_of_range("Code 1005");
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_begin() const {
  return const_iterator(first);
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_end() const {
  if (!last) {
    return u_vector<T>::const_iterator();
  }
  return u_vector<T>::const_iterator(last + 1, true);
}