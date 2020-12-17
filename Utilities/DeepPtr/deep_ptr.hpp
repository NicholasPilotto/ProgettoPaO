#ifndef DEEP_PTR_H_
#define DEEP_PTR_H_
template <class T>
class deep_ptr {
 private:
  T* ptr;
  static void destroy(T*);
  static T* deep_copy(T*);

 public:
  deep_ptr(const T&);
  ~deep_ptr();
  deep_ptr(const deep_ptr&);
  deep_ptr& operator=(const deep_ptr&);
  bool operator==(const deep_ptr&) const;
  bool operator!=(const deep_ptr&) const;
  bool operator<(const deep_ptr&) const;
  bool operator<=(const deep_ptr&) const;
  bool operator>(const deep_ptr&) const;
  bool operator>=(const deep_ptr&) const;
  explicit operator bool() const;
  T& operator*() const;
  T* operator->() const;
  T& operator[](unsigned int) const;
};

// Costruttore

template <class T>
deep_ptr<T>::deep_ptr(const T&) : ptr(nullptr) {}

//Funzioni statiche deep_copy, destroy da fare
template <class T>
T* deep_ptr<T>::deep_copy(T* p){
  if(!p)
    return nullptr;
  for(auto )
}

template <class T>
void deep_ptr<T>::destroy(T*p){
  
}
//Costruttore di copia, distruttore, assegnazione

template <class T>
deep_ptr<T>::deep_ptr(const deep_ptr& dp) : ptr(deep_copy(dp.ptr)) {}

template <class T>
deep_ptr<T>::~deep_ptr() {
  if (ptr)
    delete ptr; // o destroy???
}

template <class T>
deep_ptr<T>& deep_ptr<T>::operator=(const deep_ptr& dp) {
  if (this != &dp) {
    destroy(ptr);
    dp = deep_copy(db.ptr);
  }
  *this;
}

//Overloading operatori di confronto

template <class T>
bool deep_ptr<T>::operator==(const deep_ptr& dp) const {
  return ptr == dp.ptr;
}

template <class T>
bool deep_ptr<T>::operator!=(const deep_ptr& dp) const {
  return ptr != dp.ptr;
}

template <class T>
bool deep_ptr<T>::operator<(const deep_ptr& dp) const {
  return ptr < dp.ptr;
}

template <class T>
bool deep_ptr<T>::operator<=(const deep_ptr& dp) const {
  return ptr <= dp.ptr;
}

template <class T>
bool deep_ptr<T>::operator>(const deep_ptr& dp) const {
  return ptr > dp.ptr;
}

template <class T>
bool deep_ptr<T>::operator>=(const deep_ptr& dp) const {
  return ptr >= dp.ptr;
}

// Operatore bool, *, ->, []

template <class T>
deep_ptr<T>::operator bool() const {
  return *this != nullptr;
}

template <class T>
T& deep_ptr<T>::operator*() const {
  return *ptr;
}

template <class T>
T* deep_ptr<T>::operator->() const {
  return &ptr;
}

template <class T>
T& deep_ptr<T>::operator[](unsigned int i) const {
  return *(ptr + i);
}
#endif
