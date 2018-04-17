#ifndef LECTOR_OPERACIONES_H
#define LECTOR_OPERACIONES_H

#include <stdlib.h>
#include <fstream>
#include <string>
#include "fabrica_paquetes.h"
#include "file.h"
#include <vector>

/*Clase que simula un lector de un archivo cuyo contenido son su nombre
y las operaciones a aplicar a los tornillos.*/
class LectorOperaciones {
	private:
	File *archivo;
	std::string nombre_dispositivo;
	FabricaPaquetes &fabrica;

	public:
	/*Constructor de la clase. Almacena en sus atributos el archivo de tipo
	File, el nombre que lleva el dispositivo y la fabrica de paquetes a
	la que le avisara sobre las operaciones.*/
	LectorOperaciones(File *arch, std::string nombre_disp, FabricaPaquetes &fabrica);
	/*Operador con el cual se lee el archivo y se avisa a la fabrica de paquetes 
	las operaciones a aplicar.*/
	void operator()();
};

#endif // LECTOR_OPERACIONES_H
