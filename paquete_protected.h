#ifndef PAQUETE_PROTECTED_H
#define PAQUETE_PROTECTED_H

#include <vector>
#include <string>
#include "caja_tornillos.h"
#include <mutex>
#include "paquete.h"

class PaqueteProtected {
	private:
	std::mutex mutex;
	Paquete paquete_protegido;

	public:
	void create(std::string nombre_tipo, size_t limite);
	void agregar_caja(CajaTornillos &caja);
	void imprimir_remanentes();
};

#endif // PAQUETE_PROTECTED_H