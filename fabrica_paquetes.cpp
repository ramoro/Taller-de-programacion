#include "fabrica_paquetes.h"
#include "paquete.h"
#include <iostream>
#include <utility>
#include <map>
#include <string>

void FabricaPaquetes::agregar_paquete(size_t id_tipo, std::string nombre_tipo,
size_t limite, PaquetesProtected *proteccion) {
	Paquete paquete;
	paquete.create(nombre_tipo, limite, proteccion);
	paquetes.insert(std::pair<size_t,Paquete>(id_tipo, paquete));
}

void FabricaPaquetes::aplicar_operacion(size_t id_tipo,
size_t cantidad_tornillos, size_t ancho_tornillos) {
	CajaTornillos caja;
	caja.create(cantidad_tornillos, ancho_tornillos);
	paquetes[id_tipo].agregar_caja(caja);
}

void FabricaPaquetes::imprimir_remanentes() {
	std::cout << "# Informe de remanentes" << std::endl;
	for (std::map<size_t, Paquete>::iterator it = paquetes.begin();
	it != paquetes.end(); it++) {
		(it->second).imprimir_remanentes();
	}
}

bool FabricaPaquetes::tiene_tipo(size_t tipo) {
	return paquetes.count(tipo) > 0;
}
