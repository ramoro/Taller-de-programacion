#include <mutex>
#include "paquetes_protected.h"

bool PaquetesProtected::alcanzo_limite(size_t espacio_restante) {
  bool espacio;
  mutex.lock();
  espacio = (espacio_restante == 0);
  mutex.unlock(); 
  return espacio;
}

void PaquetesProtected::incluir_caja(std::vector<CajaTornillos> paquete, CajaTornillos &caja, size_t espacio_restante) {
  mutex.lock();
  paquete.push_back(caja);
  mutex.unlock();

}

/*void PaquetesProtected::igualar(size_t *valor1, size_t* valor2) {
  mutex.lock();
  *valor1 = *valor2;
  mutex.unlock();
}*/

bool PaquetesProtected::preguntar_si_mayor(size_t valor1, size_t valor2) {
  bool es_mayor;
  mutex.lock();
  es_mayor = (valor1 > valor2);
  mutex.unlock();
  return es_mayor;
}

/*void PaquetesProtected::borrar_caja(std::vector<CajaTornillos> paquete, int offset) {
  mutex.lock();
  paquete.erase(paquete.begin() + offset);
  mutex.unlock();
}*/