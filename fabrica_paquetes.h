#ifndef FABRICA_PAQUETES_H
#define FABRICA_PAQUETES_H

#include <map>
#include <string>
#include "paquete.h"
#include "paquetes_protected.h"

/*Clase que simula una fabrica de paquetes o moldes para
armar conjuntos de tornillos del mismo tipo.*/
class FabricaPaquetes {
	private:
	std::map<size_t, Paquete> paquetes;

	public:
	/*Agrega un paquete o molde que almacenará tornillos de tipo
	id_tipo, con nombre nombre_tipo.*/
	void agregar_paquete(size_t id_tipo, std::string nombre_tipo, 
	size_t limite, PaquetesProtected *proteccion);
	/*Recibe una operacion, es decir, un tipo, una cierta cantidad
	de tornillos y un ancho en milimetros y crea una caja para
	sumarla al paquete correspondiente e ir completandolo.*/
	void aplicar_operacion(size_t id_tipo, size_t cantidad_tornillos,
	size_t ancho_tornillos);
	/*Muestra por pantalla todos los tornillos junto con su tipo
	que no se pudieron usar para armar un paquete.*/
	void imprimir_remanentes();	
	/*Recibe un size_t tipo y se fija si alguno de los paquetes
	o moldes posee el tipo. En caso de tenerlo, se devuelve true.
	False en caso contrario.*/
	bool tiene_tipo(size_t tipo);
};

#endif // FABRICA_PAQUETES_H
