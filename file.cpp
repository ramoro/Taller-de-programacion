#include <fstream>
#include "file.h"
#include <iostream>
#include <vector>
 

bool File::create(char *nombre_archivo) {
 	archivo.open(nombre_archivo, std::fstream::in);
 	if (!archivo.is_open()) {
		std::cerr << nombre_archivo << ": no se pudo conectar con el dispositivo" 
		<< std::endl;
		return false;
	}
 	nombre = nombre_archivo;
 	return true;
 }

void File::leer(char *buffer, int cantidad) {
	archivo.read(buffer, 4);
}

bool File::esta_al_final() {
	return archivo.eof();
}

void File::leer_linea(char *buffer, int limite_bytes, int caracter_limite) {
	archivo.getline(buffer, limite_bytes, caracter_limite);
}

char* File::get_nombre() {
	return nombre; 
}

File::~File() {
	archivo.close();
}
