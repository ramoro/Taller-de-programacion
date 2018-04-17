#include "paquete.h"
#include "caja_tornillos.h"
#include <iostream>
#include <vector>
#include <string>

size_t Paquete::calcular_mediana_y_vaciar() {
	std::vector<size_t> anchos;
	size_t cont_pos;
	size_t min_ancho;
	int pos_min;

	int pos_vector_anchos = 0;

	size_t cant_tor;

	while(!cajas.empty()){
		min_ancho = cajas[0].get_milimetros_tornillos();
		cont_pos = 0;
		for (std::vector<CajaTornillos>::iterator it = cajas.begin();
		it != cajas.end(); it++) {
			if ((*it).get_milimetros_tornillos() <= min_ancho) {
				min_ancho = (*it).get_milimetros_tornillos();
				pos_min = cont_pos;
			}
			cont_pos++;
		}
		cant_tor = cajas[pos_min].get_cantidad_tornillos();
		cajas.erase(cajas.begin() + pos_min);
		pos_min = 0;
		for (; cant_tor > 0; cant_tor--) {
			anchos.push_back(min_ancho);
			pos_vector_anchos++;
		}
	}

	bool par;
	if (limite_tornillos % 2 == 0){
		par = true;	
	} else {
		par = false;
	}

	if (par) {
		size_t valor1;
		size_t valor2;
		valor1 = anchos[(limite_tornillos / 2) - 1];
		valor2 = anchos[limite_tornillos / 2];
		return (valor1 + valor2) / 2;
	}

	return anchos[limite_tornillos / 2];
}


void Paquete::create(std::string tipo, size_t limite){
	nombre_tipo = tipo; 
	limite_tornillos = limite; 
	espacio_restante = limite;
}

bool Paquete::alcanzo_limite() {
	return espacio_restante == 0; 
}

/*pre: paquete llego al limite.*/
void Paquete::imprimir_y_vaciar() {
	size_t mediana = calcular_mediana_y_vaciar();
	std::cout << "Paquete listo: " << limite_tornillos << " tornillos de tipo "
	<< nombre_tipo << " (mediana: " << mediana << ')' << std::endl;
	espacio_restante = limite_tornillos;
}

void Paquete::agregar_caja(CajaTornillos &caja) {
	if (caja.get_cantidad_tornillos() > espacio_restante) { 
		while (caja.get_cantidad_tornillos() >= espacio_restante) { 
			CajaTornillos caja_aux;
			caja_aux.create(espacio_restante, caja.get_milimetros_tornillos());
			caja.reducir_cantidad(espacio_restante);	
			cajas.push_back(caja_aux);
			imprimir_y_vaciar();
		}
		cajas.push_back(caja);	
		
		espacio_restante -= caja.get_cantidad_tornillos();
	} else {
		cajas.push_back(caja);
		
		espacio_restante -= caja.get_cantidad_tornillos();
		if(alcanzo_limite()) {
			imprimir_y_vaciar();
		}
	}
}

void Paquete::imprimir_remanentes() {
	std::cout << "* " << (limite_tornillos - espacio_restante) <<
	" tornillos de tipo " << nombre_tipo << std::endl;
}
