#ifndef LECTOR_CONFIGURACION_H
#define LECTOR_CONFIGURACION_H

#include <stdlib.h>
#include <fstream>
#include "fabrica_paquetes.h"

/*Clase que simula un lector de archivos con configuraciones de tornillos.*/
class LectorConfiguracion {
	private:
	std::fstream archivo_configuraciones;

	public:
	/*Crea el lector asignandole el archivo abierto 
	(se usa char *archivo para ello) como atributo.*/
	void create(char *archivo);

	/*Lee el archivo que tiene como atributo y le informa sobre sus datos
	a fabrica.*/
	void informar_caracteristicas_paquetes(FabricaPaquetes &fabrica);

	/*Destructor del objeto. Cierra el archivo que tiene como atributo.*/
	~LectorConfiguracion();
};

#endif // LECTOR_CONFIGURACION_H
