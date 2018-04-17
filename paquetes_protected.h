#ifndef PAQUETES_PROTECTED_H
#define PAQUETES_PROTECTED_H

#include <vector>
#include <string>
#include "caja_tornillos.h"
#include <mutex>

class PaquetesProtected {
	private:
	std::mutex mutex;

	public:
	bool alcanzo_limite(size_t espacio_restante);
	void incluir_caja(std::vector<CajaTornillos> paquete, CajaTornillos &caja, size_t espacio_restante);
	//void igualar(size_t *valor1, size_t* valor2);
	bool preguntar_si_mayor(size_t valor1, size_t valor2);
	//void borrar_caja(std::vector<CajaTornillos> paquete, int offset);
};

#endif // PAQUETES_PROTECTED_H