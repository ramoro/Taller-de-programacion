#include "caja_tornillos.h"
#include <iostream>

void CajaTornillos::create(size_t cantidad_inicial, size_t ancho) {
	cantidad = cantidad_inicial;
	ancho_tornillos = ancho;
}

size_t CajaTornillos::get_milimetros_tornillos() {
	return ancho_tornillos;
}

size_t CajaTornillos::get_cantidad_tornillos(){
	return cantidad;
}

void CajaTornillos::reducir_cantidad(size_t reduccion) {
	if (reduccion > cantidad) {
		std::cout << "No se pueden sacar mas tornillos de los que hay!";
		return;
	}
	cantidad -= reduccion;
	return;
}
