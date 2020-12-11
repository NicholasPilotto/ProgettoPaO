#ifndef __U_VECTOR_H__
#define __U_VECTOR_H__

#include <iostream>

/**
 * @brief universal vector
 * @tparam T è un tipo generico, che verrà salvato nel vettore
*/
template <class T>
class u_vector {
 public:
  class iterator;
  class const_iterator;

 private:
  T* array;
  unsigned int __capacity;
  unsigned int __size;
  static void destroy(T* v);

  /**
   * @brief medoto per la copia profonda di un oggetto T*
   * @param a: const T*, puntatore costante alla prima cella dell'array da copiare
   */
  T* deep_copy(unsigned int, unsigned int) const;

 public:
  //* ---------- CONST_ITERATOR ----------
  /**
   * @brief classe const_iterator che identifica l'iteratore costante della classe u_vector
   * @tparam T è un tipo generico, salvato in u_vector
   */
  class const_iterator {
    friend class u_vector<T>;

   private:
    const T* pointer;

    /**
     * @brief costruttore di const_iterator
     * @param p: const T*, puntatore con cui inizializzare `pointer`
     * @param pte: bool, valore indicante se è past the end, di default = false
     */
    const_iterator(const T*);

   public:
    /**
     * @brief operator++ prefisso
     * @return const_iterator&, indirizzo dell'oggetto di invocazione + 1
     */
    const_iterator& operator++();

    /**
     * @brief operator++ postfisso
     * @return const_iterator, oggetto di invocazione + 1
     */
    const_iterator operator++(int);

    /**
     * @brief operator-- prefisso
     * @return const_iterator&, indirizzo dell'oggetto di invocazione - 1
     */
    const_iterator& operator--();

    /**
     * @brief operator-- postfisso
     * @return const_iterator, oggetto di invocazione - 1
     */
    const_iterator operator--(int);

    /**
     * @brief operatore di confronto di uguaglianza
     * @param it: const const_iterator&, iteratore con la quale eseguire il confronto
     * @return bool, `true` se i due valori sono uguali, `false` altrimenti
     */
    bool operator==(const const_iterator&) const;

    /**
     * @brief operatore di confronto di disuguaglianza
     * @param it: const const_iterator&, iteratore con la quale eseguire il confronto
     * @return bool, `true` se i due valori sono disuguali, `false` altrimenti
     */
    bool operator!=(const const_iterator&) const;

    /**
     * @brief operatore minore
     * @param it: const const_iterator&, iteratore con la quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è minore di it
     */
    bool operator<(const const_iterator&) const;

    /**
     * @brief operatore minore-uguale
     * @param it: const const_iterator&, iteratore con la quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è minore oppure uguale di it
     */
    bool operator<=(const const_iterator&) const;

    /**
     * @brief operatore maggiore
     * @param it: const const_iterator&, iteratore con la quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è maggiore di it
     */
    bool operator>(const const_iterator&) const;

    /**
     * @brief operatore maggiore-uguale
     * @param it: const const_iterator&, iteratore con la quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è maggiore oppure uguale di it
     */
    bool operator>=(const const_iterator&) const;

    /**
     * @brief operatore somma
     * @param value: int, numero di posizioni da avanzare
     * @return const_iterator, oggetto di invocazione + `value`
     * @throw out_of_range, se current_index + value >= __size
     */
    const_iterator operator+(int) const;

    /**
     * @brief operatore somma-uguale
     * @param value: int, numero di posizioni da avanzare
     * @return const_iterator&, indirizzo dell'oggetto di invocazione + `value`
     * @throw out_of_range, se current_index + value >= __size
     */
    const_iterator& operator+=(int);

    /**
     * @brief operatore differenza
     * @param value: int, numero di posizioni da arretrare
     * @return const_iterator, oggetto di invocazione - `value`
     * @throw out_of_range, se current_index + value < 0
     */
    const_iterator operator-(int) const;

    /**
     * @brief operatore differenza-uguale
     * @param value: int, numero di posizioni da arretrare
     * @return const_iterator&, indirizzo dell'oggetto di invocazione - `value`
     * @throw out_of_range, se current_index + value < 0
     */
    const_iterator& operator-=(int);

    /**
     * @brief operatore di subscripting
     * @param index: unsigned int, indice dell'oggetto di interesse
     * @return const T&, indirizzo dell'oggetto di indice `index`
     * @throw out_of_range se `index` >= `__size`
     */
    const T& operator[](unsigned int) const;

    /**
     * @brief operatore di dereferenziazione
     * @return const T&, indirizzo dell'oggetto dereferenziato
     */
    const T& operator*() const;

    /**
     * @brief operatore freccia
     * @return const T*, indirizzo del puntatore all'oggetto desiderato
     */
    const T* operator->() const;
  };

  //* ---------- ITERATOR ----------
  /**
   * @brief classe iterator che identifica l'iteratore costante della classe u_vector
   * @tparam T è un tipo generico, salvato in u_vector
   */
  class iterator {
    friend class u_vector<T>;

   private:
    T* pointer;

    /**
     * @brief costruttore di iterator
     * @param p: const T*, puntatore con cui inizializzare `pointer`
     * @param pte: bool, valore indicante se è past the end, di default = false
     */
    iterator(T*);

   public:
    /**
     * @brief operator++ prefisso
     * @return iterator&, indirizzo dell'oggetto di invocazione + 1
     */
    iterator& operator++();

    /**
     * @brief operator++ postfisso
     * @return iterator, oggetto di invocazione + 1
     */
    iterator operator++(int);

    /**
     * @brief operator-- prefisso
     * @return iterator&, indirizzo dell'oggetto di invocazione - 1
     */
    iterator& operator--();

    /**
     * @brief operator-- postfisso
     * @return iterator, oggetto di invocazione - 1
     */
    iterator operator--(int);

    /**
     * @brief operatore di confronto di uguaglianza
     * @param it: const iterator&, iteratore con la quale eseguire il confronto
     * @return bool, `true` se i due valori sono uguali, `false` altrimenti
     */
    bool operator==(const iterator&) const;

    /**
     * @brief operatore di confronto di disuguaglianza
     * @param it: const iterator&, iteratore con la quale eseguire il confronto
     * @return bool, `true` se i due valori sono disuguali, `false` altrimenti
     */
    bool operator!=(const iterator&) const;

    /**
     * @brief operatore minore
     * @param it: const iterator&, iteratore con la quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è minore di it
     */
    bool operator<(const iterator&) const;

    /**
     * @brief operatore minore-uguale
     * @param it: const iterator&, iteratore con la quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è minore oppure uguale di it
     */
    bool operator<=(const iterator&) const;

    /**
     * @brief operatore maggiore
     * @param it: const iterator&, iteratore con la quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è maggiore di it
     */
    bool operator>(const iterator&) const;

    /**
     * @brief operatore maggiore-uguale
     * @param it: const iterator&, iteratore con la quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è maggiore oppure uguale di it
     */
    bool operator>=(const iterator&) const;

    /**
     * @brief operatore somma
     * @param value: int, numero di posizioni da avanzare
     * @return iterator, oggetto di invocazione + `value`
     * @throw out_of_range, se current_index + value >= __size
     */
    iterator operator+(int) const;

    /**
     * @brief operatore somma-uguale
     * @param value: int, numero di posizioni da avanzare
     * @return iterator&, indirizzo dell'oggetto di invocazione + `value`
     * @throw out_of_range, se current_index + value >= __size
     */
    iterator& operator+=(int);

    /**
     * @brief operatore differenza
     * @param value: int, numero di posizioni da arretrare
     * @return iterator, oggetto di invocazione - `value`
     * @throw out_of_range, se current_index + value < 0
     */
    iterator operator-(int) const;

    /**
     * @brief operatore differenza-uguale
     * @param value: int, numero di posizioni da arretrare
     * @return iterator&, indirizzo dell'oggetto di invocazione - `value`
     * @throw out_of_range, se current_index + value < 0
     */
    iterator& operator-=(int);

    /**
     * @brief operatore di subscripting
     * @param index: unsigned int, indice dell'oggetto di interesse
     * @return T&, indirizzo dell'oggetto di indice `index`
     * @throw out_of_range se `index` >= `__size`
     */
    T& operator[](unsigned int) const;

    /**
     * @brief operatore di dereferenziazione
     * @return T&, indirizzo dell'oggetto dereferenziato
     */
    T& operator*() const;

    /**
     * @brief operatore freccia
     * @return T*, indirizzo del puntatore all'oggetto desiderato
     */
    T* operator->() const;
  };

  u_vector(unsigned int = 1, unsigned int = 0);
  u_vector(unsigned int, const T&);

  /**
   * @brief costruttore di copia profonda
   * @param uv: const u_vector&, indirizzo costante del u_vector da copiare
   */
  u_vector(const u_vector&);

  /**
   * @brief distruttore di copia profonda
   */
  ~u_vector();

  /**
   * @brief metodo per l'inserimento in coda
   * @param object: const T&, indirizzo dell'oggetto da inserire in coda
   */
  void push_back(const T&);

  /**
   * @brief metodo per l'eliminazione dell'ultimo elemento di u_vector
   */
  void pop_back();

  /**
   * @brief metodo che ritorna il primo elemento di u_vector
   * @return T&, indirizzo del primo elemento di u_vector
   */
  T& front();

  /**
   * @brief metodo che ritorna l'ultimo elemento di u_vector
   * @return T&, indirizzo dell'ultimo elemento di u_vector
   */
  T& back();

  /**
   * @brief metodo che ritorna il primo elemento di u_vector
   * @return const T&, indirizzo del primo elemento di u_vector
   */
  const T& front() const;

  /**
   * @brief metodo che ritorna l'ultimo elemento di u_vector
   * @return const T&, indirizzo dell'ultimo elemento di u_vector
   */
  const T& back() const;

  /**
   * @brief metodo getter per la size del vettore
   * @return unsigned int size del vettore
   */
  unsigned int size() const;

  /**
   * @brief metodo getter per la capacity del vettore
   * @return unsigned int capacity del vettore
   */
  unsigned int capacity() const;

  /**
   * @brief medoto per fare il check del contenuto di u_vector
   * @return bool, `true` se u_vector è vuoto, `false` altrimenti
   */
  bool empty() const;

  /**
   * @brief metodo per la cancellazione di u_vector
   */
  void clear();

  /**
   * @brief definizione dell'operatore di assegnazione
   * @param v: const u_vector&, indirizzo dell'oggetto da assegnare
   */
  u_vector& operator=(const u_vector&);

  iterator begin() const;
  iterator end() const;

  const_iterator const_begin() const;
  const_iterator const_end() const;
};
#endif  // __U_VECTOR_H__

//* ---------- ITERATOR ----------

template <class T>
u_vector<T>::iterator::iterator(T* p) : pointer(p) {}

template <class T>
typename u_vector<T>::iterator& u_vector<T>::iterator::operator++() {
  pointer++;
  return *this;
}

template <class T>
typename u_vector<T>::iterator u_vector<T>::iterator::operator++(int) {
  iterator aux(*this);
  pointer++;
  return aux;
}

template <class T>
typename u_vector<T>::iterator& u_vector<T>::iterator::operator--() {
  pointer--;
  return *this;
}

template <class T>
typename u_vector<T>::iterator u_vector<T>::iterator::operator--(int) {
  iterator aux(*this);
  pointer--;
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
bool u_vector<T>::iterator::operator>=(const u_vector<T>::iterator& it) const {
  return pointer <= it.pointer;
}

template <class T>
typename u_vector<T>::iterator u_vector<T>::iterator::operator+(int value) const {
  return iterator(pointer + value);
}

template <class T>
typename u_vector<T>::iterator& u_vector<T>::iterator::operator+=(int value) {
  pointer += value;
  return *this;
}

template <class T>
typename u_vector<T>::iterator u_vector<T>::iterator::operator-(int value) const {
  return iterator(pointer - value);
}

template <class T>
typename u_vector<T>::iterator& u_vector<T>::iterator::operator-=(int value) {
  pointer += value;
  return *this;
}

template <class T>
T& u_vector<T>::iterator::operator*() const {
  return *pointer;
}

template <class T>
T* u_vector<T>::iterator::operator->() const {
  return &pointer;
}

template <class T>
T& u_vector<T>::iterator::operator[](unsigned int index) const {
  return *(pointer + index);
}

//* ---------- CONST_ITERATOR ----------

template <class T>
u_vector<T>::const_iterator::const_iterator(const T* p) : pointer(p) {}

template <class T>
typename u_vector<T>::const_iterator& u_vector<T>::const_iterator::operator++() {
  pointer++;
  return *this;
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_iterator::operator++(int) {
  const_iterator aux(*this);
  pointer++;
  return aux;
}

template <class T>
typename u_vector<T>::const_iterator& u_vector<T>::const_iterator::operator--() {
  pointer--;
  return *this;
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_iterator::operator--(int) {
  const_iterator aux(*this);
  pointer--;
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
bool u_vector<T>::const_iterator::operator>=(const u_vector<T>::const_iterator& it) const {
  return pointer <= it.pointer;
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_iterator::operator+(int value) const {
  return const_iterator(pointer + value);
}

template <class T>
typename u_vector<T>::const_iterator& u_vector<T>::const_iterator::operator+=(int value) {
  pointer += value;
  return *this;
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_iterator::operator-(int value) const {
  return const_iterator(pointer - value);
}

template <class T>
typename u_vector<T>::const_iterator& u_vector<T>::const_iterator::operator-=(int value) {
  pointer -= value;
  return *this;
}

template <class T>
const T& u_vector<T>::const_iterator::operator*() const {
  return *pointer;
}

template <class T>
const T* u_vector<T>::const_iterator::operator->() const {
  return &pointer;
}

template <class T>
const T& u_vector<T>::const_iterator::operator[](unsigned int index) const {
  return *(pointer + index);
}

//* ---------- U_VECTOR ----------

template <class T>
u_vector<T>::u_vector(unsigned int _capacity, unsigned int _size) : array(new T[_capacity]), __capacity(_capacity), __size(_size) {}

template <class T>
u_vector<T>::u_vector(unsigned int _capacity, const T& element) : array(new T[_capacity]), __capacity(_capacity), __size(_capacity) {
  for (int i = 0; i < _capacity; i++) {
    array[i] = element;
  }
}

template <class T>
u_vector<T>::u_vector(const u_vector& uv) : array(deep_copy(uv.array)), __capacity(uv.__capacity), __size(uv.__size) {}

template <class T>
T* u_vector<T>::deep_copy(unsigned int n, unsigned int c) const {
  if (n <= c && n <= __size) {
    T* p = new T[c];
    std::copy(array, array + n, p);
    return p;
  } else
    return nullptr;
}

template <class T>
void u_vector<T>::destroy(T* v) {
  if (v) delete[] v;
}

template <class T>
u_vector<T>::~u_vector() {
  destroy(array);
}

template <class T>
void u_vector<T>::push_back(const T& object) {
  if (__size >= __capacity) {
    __capacity *= 2;
    T* temp = deep_copy(__size, __capacity);
    destroy(array);
    array = temp;
  }
  array[__size++] = object;
}

template <class T>
void u_vector<T>::pop_back() {
  if (__size) {
    __size--;
  }
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
unsigned int u_vector<T>::capacity() const {
  return __capacity;
}

template <class T>
T& u_vector<T>::front() {
  return *array;
}

template <class T>
T& u_vector<T>::back() {
  return *(array + (__size - 1));
}

template <class T>
const T& u_vector<T>::front() const {
  return *array;
}

template <class T>
const T& u_vector<T>::back() const {
  return *(array + (__size - 1));
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

template <class T>
typename u_vector<T>::iterator u_vector<T>::begin() const {
  return iterator(array);
}

template <class T>
typename u_vector<T>::iterator u_vector<T>::end() const {
  return iterator(array + __size);
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_begin() const {
  return const_iterator(array);
}

template <class T>
typename u_vector<T>::const_iterator u_vector<T>::const_end() const {
  return const_iterator(array + __size);
}