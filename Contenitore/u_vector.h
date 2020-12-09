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
  unsigned int size;

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
   * @brief metodo getter per la size del vettore
   * @return unsigned int size del vettore
   */
  unsigned int get_size() const;

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
     */
    const_iterator& operator++();

    /**
     * @brief operator++ postfisso
     */
    const_iterator operator++(int);

    /**
     * @brief operator-- prefisso
     */
    const_iterator& operator--();

    /**
     * @brief operator-- postfisso
     */
    const_iterator operator--(int);

    /**
     * @brief operatore di confronto di uguaglianza
     */
    bool operator==(const const_iterator&) const;

    /**
     * @brief operatore di confronto di disuguaglianza
     */
    bool operator!=(const const_iterator&) const;

    /**
     * @brief operatore di dereferenziazione
     */
    const T& operator*() const;

    /**
     * @brief operatore freccia
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

    /**
     * @brief costruttore di iterator
     * @param p: const T*, puntatore con cui inizializzare `pointer`
     * @param pte: bool, valore indicante se è past the end, di default = false
     */
    iterator(const T*, bool = false);

   public:
    /**
    * @brief costruttore di iterator
    */
    iterator();

    /**
     * @brief operator++ prefisso
     */
    iterator& operator++();

    /**
     * @brief operator++ postfisso
     */
    iterator operator++(int);

    /**
     * @brief operator-- prefisso
     */
    iterator& operator--();

    /**
     * @brief operator-- postfisso
     */
    iterator operator--(int);

    /**
     * @brief operatore di confronto di uguaglianza
     */
    bool operator==(const iterator&) const;

    /**
     * @brief operatore di confronto di disuguaglianza
     */
    bool operator!=(const iterator&) const;

    /**
     * @brief operatore di dereferenziazione
     */
    T& operator*() const;

    /**
     * @brief operatore freccia
     */
    T* operator->() const;
  };

  iterator begin() const;
  iterator end() const;
};
#endif  // __U_VECTOR_H__