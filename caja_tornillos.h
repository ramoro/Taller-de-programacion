#ifndef CAJA_TORNILLOS_H
#define CAJA_TORNILLOS_H

#include <stdlib.h>

/*Clase que simula una caja con tornillos.*/
class CajaTornillos {
	private:
	size_t cantidad;
	size_t ancho_tornillos;

	public:
	/*Crea el objeto CajaTornillos con cantidad_inicial como la cantidad de
	tornillos y con ancho como el ancho de los mismos.*/
	void create(size_t cantidad_inicial, size_t ancho);
	/*Devuelve el ancho de los tornillos que posee la caja.*/
	size_t get_milimetros_tornillos();
	/*Devuelve la cantidad de tornillos que posee la caja.*/
	size_t get_cantidad_tornillos();
	/*Reduce la cantidad determinada por reduccion de tornillos en
	la caja.*/
	void reducir_cantidad(size_t reduccion);
};

#endif // CAJA_TORNILLOS_H
