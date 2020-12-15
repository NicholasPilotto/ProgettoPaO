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

  /**
   * @brief metodo per la ditruzione profonda di un array
   * @param array : T*, puntatore al primo elemento dell'array da distruggere
   */
  static void destroy_array(T*);

  /**
   * @brief medoto per la copia profonda di un oggetto T*
   * @param _size : unsigned int, size dell'array di invocazione
   * @param _capazity : unsigned int, capacity dell'array di invocazione
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
     * @param it: const const_iterator&, iteratore con il quale eseguire il confronto
     * @return bool, `true` se i due valori sono uguali, `false` altrimenti
     */
    bool operator==(const const_iterator&) const;

    /**
     * @brief operatore di confronto di disuguaglianza
     * @param it: const const_iterator&, iteratore con il quale eseguire il confronto
     * @return bool, `true` se i due valori sono disuguali, `false` altrimenti
     */
    bool operator!=(const const_iterator&) const;

    /**
     * @brief operatore minore
     * @param it: const const_iterator&, iteratore con il quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è minore di it
     */
    bool operator<(const const_iterator&) const;

    /**
     * @brief operatore minore-uguale
     * @param it: const const_iterator&, iteratore con il quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è minore oppure uguale di it
     */
    bool operator<=(const const_iterator&) const;

    /**
     * @brief operatore maggiore
     * @param it: const const_iterator&, iteratore con il quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è maggiore di it
     */
    bool operator>(const const_iterator&) const;

    /**
     * @brief operatore maggiore-uguale
     * @param it: const const_iterator&, iteratore con il quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è maggiore oppure uguale di it
     */
    bool operator>=(const const_iterator&) const;

    /**
     * @brief operatore somma
     * @param value: int, numero di posizioni da avanzare
     * @return const_iterator, oggetto di invocazione + `value`
     */
    const_iterator operator+(int) const;

    /**
     * @brief operatore somma-uguale
     * @param value: int, numero di posizioni da avanzare
     * @return const_iterator&, indirizzo dell'oggetto di invocazione + `value`
     */
    const_iterator& operator+=(int);

    /**
     * @brief operatore differenza
     * @param value: int, numero di posizioni da arretrare
     * @return const_iterator, oggetto di invocazione - `value`
     */
    const_iterator operator-(int) const;

    /**
     * @brief operatore differenza-uguale
     * @param value: int, numero di posizioni da arretrare
     * @return const_iterator&, indirizzo dell'oggetto di invocazione - `value`
     */
    const_iterator& operator-=(int);

    /**
     * @brief operatore di subscripting
     * @param index: unsigned int, indice dell'oggetto di interesse
     * @return const T&, indirizzo dell'oggetto di indice `index`
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
     * @param it: const iterator&, iteratore con il quale eseguire il confronto
     * @return bool, `true` se i due valori sono uguali, `false` altrimenti
     */
    bool operator==(const iterator&) const;

    /**
     * @brief operatore di confronto di disuguaglianza
     * @param it: const iterator&, iteratore con il quale eseguire il confronto
     * @return bool, `true` se i due valori sono disuguali, `false` altrimenti
     */
    bool operator!=(const iterator&) const;

    /**
     * @brief operatore minore
     * @param it: const iterator&, iteratore con il quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è minore di it
     */
    bool operator<(const iterator&) const;

    /**
     * @brief operatore minore-uguale
     * @param it: const iterator&, iteratore con il quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è minore oppure uguale di it
     */
    bool operator<=(const iterator&) const;

    /**
     * @brief operatore maggiore
     * @param it: const iterator&, iteratore con il quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è maggiore di it
     */
    bool operator>(const iterator&) const;

    /**
     * @brief operatore maggiore-uguale
     * @param it: const iterator&, iteratore con il quale eseguire il confronto
     * @return bool, `true` se l'oggetto di invocazione è maggiore oppure uguale di it
     */
    bool operator>=(const iterator&) const;

    /**
     * @brief operatore somma
     * @param value: int, numero di posizioni da avanzare
     * @return iterator, oggetto di invocazione + `value`
     */
    iterator operator+(int) const;

    /**
     * @brief operatore somma-uguale
     * @param value: int, numero di posizioni da avanzare
     * @return iterator&, indirizzo dell'oggetto di invocazione + `value`
     */
    iterator& operator+=(int);

    /**
     * @brief operatore differenza
     * @param value: int, numero di posizioni da arretrare
     * @return iterator, oggetto di invocazione - `value`
     */
    iterator operator-(int) const;

    /**
     * @brief operatore differenza-uguale
     * @param value: int, numero di posizioni da arretrare
     * @return iterator&, indirizzo dell'oggetto di invocazione - `value`
     */
    iterator& operator-=(int);

    /**
     * @brief operatore di subscripting
     * @param index: unsigned int, indice dell'oggetto di interesse
     * @return T&, indirizzo dell'oggetto di indice `index`
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

  /**
   * @brief costruttore di u_vector
   * @param _capacity : unsigned int, valore che indica la capacity di u_vector, defautl = 1
   * @param _size : unsigned int, valore che indica la size di u_vector, default = 0
   */
  u_vector(unsigned int = 1, unsigned int = 0);

  /**
   * @brief costruttore di u_vector
   * @param element : const T&, elemento T inserito `_capacity` volte
   * @param _capacity : unsigned int, indica la capacity di u_vector, default = 1
   */
  u_vector(const T&, unsigned int = 1);

  /**
   * @brief costruttore di copia profonda
   * @param uv: const u_vector&, indirizzo costante del u_vector da copiare
   */
  u_vector(const u_vector&);

  /**
   * @brief distruttore profondo di u_vector
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
   * @brief metodo at
   * @param index : unsigned int, indice dell'elemento desiderato
   * @return indirizzo dell'elemento di indice `index`
   */
  T& at(unsigned int) const;

  /**
   * @brief metodo data
   * @return il puntatore del primo elemento dell'array di u_vector
   */
  T* data() const;

  /**
   * @brief massimo numero di elementi
   * @return unsigned int, numero massimo di elementi che u_vector può contenere
   */
  static unsigned int max_size();

  /**
   * @brief metodo per il ritorno del primo elemento
   * @return iterator, iteratore rappresentante il primo elemento di u_vector
   */
  iterator begin() const;

  /**
   * @brief metodo per il ritorno dell'ultimo elemento
   * @return iterator, iteratore rappresentante l'ultimo elemento di u_vector
   */
  iterator end() const;

  /**
   * @brief metodo per il ritorno del primo elemento costante
   * @return const_iterator, iteratore rappresentante il primo elemento costante di u_vector
   */
  const_iterator const_begin() const;

  /**
   * @brief metodo per il ritorno dell'ultimo elemento costante
   * @return const_iterator, iteratore rappresentante l'ultimo elemento costante di u_vector
   */
  const_iterator const_end() const;

  /**
   * @brief metodo per l'inserimento di un elemento T in posizione position - 1
   * @param position : iterator, posizione successiva alla posizione di inserimento
   * @param element : const T&, elemento da inserire
   * @return iterator, iteratore rappresentante l'elemento inserito
   */
  iterator insert(iterator, const T&);

  /**
   * @brief metodo per l'inserimento di un elemento T in posizione position - 1
   * @param position : const_iterator, posizione successiva alla posizione di inserimento
   * @param element : const T&, elemento da inserire
   * @return iterator, iteratore rappresentante l'elemento inserito
   */
  iterator insert(const_iterator, const T&);

  /**
   * @brief metodo per l'inserimento ripetuto di un oggetto in posizione position - 1
   * @param postion iterator, posizione successica alla posizione di inserimento
   * @param count size_t, numero di ripetizioni dell'oggetto da inserire
   * @param element const T&, elemento da inserire 
   */
  void insert(iterator, size_t, const T&);

  /**
   * @brief metodo per la ricerca di un elemento all'interno di u_vector
   * @param element : const T&, elemento da ricercare all'interno di u_vector
   * @return bool, true sse element presente in u_vector, false altrimenti
   */
  bool search(const T&) const;

  /**
   * @brief operatore di assegnazione
   * @param uv : const u_vector&, u_vector da assegnare
   * @return u_vector&, indirizzo di u_vector di invocazione
   */
  u_vector& operator=(const u_vector&);

  /**
   * @brief operatore di uguaglianza
   * @param uv const u_vector&, u_vector da controllare
   * @return bool, `true` sse u_vector di invocazione ugale a `uv`, false altrimenti
   */
  bool operator==(const u_vector&) const;

  /**
   * @brief operatore di confronto minore
   * @param uv const u_vector&, u_vector da controllare
   * @return bool, `true` sse u_vector di invocazione minore di `uv`, false altrimenti
   */
  bool operator<(const u_vector&) const;

  /**
   * @brief operatore di confronto maggiore
   * @param uv const u_vector&, u_vector da controllare
   * @return bool, `true` sse u_vector di invocazione maggiore di `uv`, false altrimenti
   */
  bool operator>(const u_vector&) const;

  /**
   * @brief operatore di confronto minore-uguale
   * @param uv const u_vector&, u_vector da controllare
   * @return bool, `true` sse u_vector di invocazione minore-uguale di `uv`, false altrimenti
   */
  bool operator<=(const u_vector&) const;

  /**
   * @brief operatore di confronto maggiore-uguale
   * @param uv const u_vector&, u_vector da controllare
   * @return bool, `true` sse u_vector di invocazione maggiore-uguale di `uv`, false altrimenti
   */
  bool operator>=(const u_vector&) const;

  /**
   * @brief operatore di subscripting
   * @param index : unsigned int, indice richiesto
   * @return const T&, indirizzo dell'elemento di indice `index`
   */
  const T& operator[](unsigned int) const;
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
u_vector<T>::u_vector(const T& element, unsigned int _capacity) : array(new T[_capacity]), __capacity(_capacity), __size(_capacity) {
  for (int i = 0; i < _capacity; i++) {
    array[i] = element;
  }
}

template <class T>
u_vector<T>::u_vector(const u_vector& uv) : array(uv.deep_copy(uv.__size, uv.__capacity)), __capacity(uv.__capacity), __size(uv.__size) {}

template <class T>
T* u_vector<T>::deep_copy(unsigned int _size, unsigned int _capacity) const {
  if (_size <= _capacity && _size <= __size) {
    T* aux = new T[_capacity];
    std::copy(array, array + _size, aux);
    return aux;
  } else
    return nullptr;
}

template <class T>
void u_vector<T>::destroy_array(T* array) {
  if (array) {
    delete[] array;
  }
}

template <class T>
u_vector<T>::~u_vector() {
  destroy_array(array);
}

template <class T>
void u_vector<T>::push_back(const T& object) {
  if (__size >= __capacity) {
    __capacity *= 2;
    T* temp = deep_copy(__size, __capacity);
    destroy_array(array);
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
T& u_vector<T>::at(unsigned int index) const {
  return *(array + index);
}

template <class T>
T* u_vector<T>::data() const {
  return __size ? array : nullptr;
}

template <class T>
unsigned int u_vector<T>::max_size() {
  return UINT_MAX;
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

template <class T>
typename u_vector<T>::iterator u_vector<T>::insert(u_vector<T>::iterator position, const T& element) {
  //? Valutare se rifarlo o tenerlo copiato
  ++__size;
  if (__size >= __capacity) {
    unsigned int offset = static_cast<unsigned int>(position.pointer - array);
    __capacity *= 2;
    T* aux = deep_copy(offset, __capacity);
    aux[offset] = element;
    std::copy(position, end(), iterator(aux + offset + 1));

    destroy_array(array);
    array = aux;
    return iterator(aux + offset);
  }

  std::copy_backward(position, end() - 1, end());
  *position = element;
  return position;
}

template <class T>
typename u_vector<T>::iterator u_vector<T>::insert(u_vector<T>::const_iterator position, const T& element) {
  //! MOLTO RISCHIOSO
  auto it = iterator(const_cast<T*>(position.pointer));
  return insert(it, element);
}

template <class T>
void u_vector<T>::insert(u_vector<T>::iterator position, size_t count, const T& element) {
  //! NON FUNZIONA COME DOVREBBE
  for (size_t i = 0; i < count; i++) {
    insert(position, element);
  }
}

template <class T>
bool u_vector<T>::search(const T& element) const {
  u_vector<T>::iterator it = begin();
  u_vector<T>::iterator last = end();

  for (; it != last; it++) {
    if (*it == element) {
      return true;
    }
  }

  return false;
}

template <class T>
u_vector<T>& u_vector<T>::operator=(const u_vector<T>& v) {
  if (this != &v) {
    destroy_array(array);
    __size = v.__size;
    __capacity = v.__capacity;
    array = v.deep_copy(__size, __capacity);
  }
  return *this;
}

template <class T>
bool u_vector<T>::operator==(const u_vector<T>& uv) const {
  if (this == &uv) {
    return true;
  }

  if (__size != uv.__size) {
    return false;
  }

  for (size_t i = 0; i < __size; i++) {
    if (array[i] != uv.array[i]) {
      return false;
    }
  }
  return true;
}

template <class T>
bool u_vector<T>::operator<(const u_vector<T>& uv) const {
  unsigned int min_size = __size < uv.__size ? __size : uv.__size;

  for (size_t i = 0; i < min_size; i++) {
    if (array[i] != uv.array[i]) {
      return array[i] < uv.array[i];
    }
  }
  return __size < uv.__size ? true : false;
}

template <class T>
bool u_vector<T>::operator>(const u_vector<T>& uv) const {
  unsigned int min_size = __size < uv.__size ? __size : uv.__size;

  for (size_t i = 0; i < min_size; i++) {
    if (array[i] != uv.array[i]) {
      return array[i] > uv.array[i];
    }
  }
  return __size > uv.__size ? true : false;
}

template <class T>
bool u_vector<T>::operator<=(const u_vector<T>& uv) const {
  return *this < uv || this->operator==(uv);
}

template <class T>
bool u_vector<T>::operator>=(const u_vector<T>& uv) const {
  return *this > uv || this->operator==(uv);
}

template <class T>
const T& u_vector<T>::operator[](unsigned int index) const {
  return *(array + index);
}