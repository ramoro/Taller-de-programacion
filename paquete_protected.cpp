#include <mutex>
#include "paquete_protected.h"


void PaqueteProtected::create(std::string nombre_tipo,
size_t limite) {
  Paquete paquete;
  paquete.create(nombre_tipo, limite);
  paquete_protegido = paquete;
}

void PaqueteProtected::agregar_caja(CajaTornillos &caja) {
  mutex.lock();
  paquete_protegido.agregar_caja(caja);
  mutex.unlock();
}

void PaqueteProtected::imprimir_remanentes() {
	paquete_protegido.imprimir_remanentes();
}