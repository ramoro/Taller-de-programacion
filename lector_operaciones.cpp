#include "lector_operaciones.h"
#include <iostream>
#include <fstream>
#include <bitset>
#include <stdio.h>
#include <arpa/inet.h>
#include "file.h"
#include <string>
#include <vector>
#include "fabrica_paquetes.h"

LectorOperaciones::LectorOperaciones(File *arch, std::string nombre_disp, FabricaPaquetes &fabrica) :
	archivo(arch), nombre_dispositivo(nombre_disp), fabrica(fabrica){}

void LectorOperaciones::operator() () {
	while (true) {
		unsigned char buffer[4];
		uint32_t *aux;

		archivo->leer((char*)buffer, 4);
		if(archivo->esta_al_final()) break;

		aux = (unsigned int*)buffer;
		if(*aux == (unsigned int)-1) {
			std::cerr << nombre_dispositivo 
			<< " atascado" << std::endl;
			continue;
		}

		uint32_t aux2 = htonl(*aux);

		std::bitset<32> operacion;

		operacion = aux2;


		
		unsigned int tipo =(operacion >> 27).to_ulong();
		

		if(!fabrica.tiene_tipo(tipo)) {
			std::cerr << "Tipo de tornillo invalido: " << tipo << std::endl;
			continue;
		} 

		
		unsigned int ancho =((operacion << 27)>>27).to_ulong();
		
		

		
		unsigned int cantidad =((operacion << 5)>>10).to_ulong();
		

		fabrica.aplicar_operacion(tipo, cantidad, ancho);
	}
}
