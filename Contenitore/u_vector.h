#ifndef __U_VECTOR_H__
#define __U_VECTOR_H__

#include <iostream>

/**
 * @brief universal vector
 * @tparam T è un tipo generico, che verrà salvato nel vettore
*/
template <class T>
class u_vector {
 private:
  T* array;
  unsigned int __size;

  /**
   * @brief medoto per la copia profonda di un oggetto T*
   * @param a: const T*, puntatore costante alla prima cella dell'array da copiare
   */
  T* deep_copy(const T*);

 public:
  /**
  * @brief costruttore
  * @param size: unsigned int, grandezza iniziale del vettore, di default = 0
 */
  u_vector(unsigned int = 0);

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
  u_vector& push_back(const T&);

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
   * @brief metodo getter per la __size del vettore
   * @return unsigned int __size del vettore
   */
  unsigned int size() const;

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

  /**
   * @brief classe const_iterator che identifica l'iteratore costante della classe u_vector
   * @tparam T è un tipo generico, salvato in u_vector
   */
  class const_iterator {
    friend class u_vector<T>;

   private:
    const T* pointer;
    bool past_the_end;

    unsigned int current_position;

    /**
     * @brief costruttore di const_iterator
     * @param p: const T*, puntatore con cui inizializzare `pointer`
     * @param pte: bool, valore indicante se è past the end, di default = false
     */
    const_iterator(const T*, bool = false);

   public:
    /**
    * @brief costruttore di const_iterator
    */
    const_iterator();

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

  const_iterator const_begin() const;
  const_iterator const_end() const;

  /**
   * @brief classe iterator che identifica l'iteratore costante della classe u_vector
   * @tparam T è un tipo generico, salvato in u_vector
   */
  class iterator {
    friend class u_vector<T>;

   private:
    T* pointer;
    bool past_the_end;

    unsigned int current_position;

    /**
     * @brief costruttore di iterator
     * @param p: const T*, puntatore con cui inizializzare `pointer`
     * @param pte: bool, valore indicante se è past the end, di default = false
     */
    iterator(const T*, bool = false);

   public:
    /**
    * @brief costruttore di coiteratornst_iterator
    */
    iterator();

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

  iterator begin() const;
  iterator end() const;
};
#endif  // __U_VECTOR_H__