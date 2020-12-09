#ifndef __U_VECTOR_H__
#define __U_VECTOR_H__

/**
 * @brief universal vector
 * @tparam T è un tipo generico, che verrà salvato nel vettore
*/
template <class T>
class u_vector {
 private:
  /**
  * @brief puntatore alla prima cella dell'array contenente `size` volte T
  */
  T* array;

  /**
   * @brief unsigned int che identifica la dimensione dell'array
   */
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
   * @param object: const T&, indirizzo dell'oggetto  da inserire in coda
   */
  u_vector& push_back(const T&);
};
#endif  // __U_VECTOR_H__