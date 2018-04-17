#include "lector_configuracion.h"

#include <iostream>
#include <string>

void LectorConfiguracion::create(char *archivo) {
	archivo_configuraciones.open(archivo, std::fstream::in);
	if (!archivo_configuraciones.is_open()) {
		std::cerr << archivo << ": no se pudo conectar con el dispositivo"
		<< std::endl;
	}
}

void LectorConfiguracion::informar_caracteristicas_paquetes(FabricaPaquetes
	&fabrica, PaquetesProtected *proteccion) {
	while (true) {
		char tipo_str[6];
		int tipo = 0;
		archivo_configuraciones.getline(tipo_str,3,'=');
		tipo = atoi(tipo_str);

		char nombre_str[20];
		archivo_configuraciones.getline(nombre_str,19,',');
		std::string nombre(nombre_str);
		
	
		char limite_str[6];
		int limite;
		archivo_configuraciones.getline(limite_str, 5, '\n');
		limite = atoi(limite_str);

		if(archivo_configuraciones.eof()) break;
		
		
		fabrica.agregar_paquete(tipo, nombre, limite, proteccion);
	}
}

LectorConfiguracion::~LectorConfiguracion() {
	archivo_configuraciones.close();
}

/*int main(int argc, char *argv[]) {
	LectorConfiguracion lector;
	lector.create(argv[1]);
	FabricaPaquetes fabrica;
	lector.informar_caracteristicas_paquetes(fabrica);
	return 0;
}*/
