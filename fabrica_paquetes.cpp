#include "fabrica_paquetes.h"
#include "paquete.h"
#include <iostream>
#include <utility>
#include <map>
#include <string>

void FabricaPaquetes::agregar_paquete(size_t id_tipo, std::string nombre_tipo,
size_t limite) {
 	PaqueteProtected *proteccion = new PaqueteProtected();
	proteccion->create(nombre_tipo, limite);
	paquetes_protegidos.insert(std::pair<size_t,PaqueteProtected*>(id_tipo, proteccion));
}

void FabricaPaquetes::aplicar_operacion(size_t id_tipo,
size_t cantidad_tornillos, size_t ancho_tornillos) {
	CajaTornillos caja;
	caja.create(cantidad_tornillos, ancho_tornillos);
	paquetes_protegidos[id_tipo]->agregar_caja(caja);
}

void FabricaPaquetes::imprimir_remanentes() {
	std::cout << "# Informe de remanentes" << std::endl;
	for (std::map<size_t, PaqueteProtected*>::iterator it = paquetes_protegidos.begin();
	it != paquetes_protegidos.end(); it++) {
		(it->second)->imprimir_remanentes();
	}
}

bool FabricaPaquetes::tiene_tipo(size_t tipo) {
	return paquetes_protegidos.count(tipo) > 0;
}

FabricaPaquetes::~FabricaPaquetes() {
	for (std::map<size_t, PaqueteProtected*>::iterator it = paquetes_protegidos.begin();
	it != paquetes_protegidos.end(); it++) {
		delete (it->second);
	}
}
