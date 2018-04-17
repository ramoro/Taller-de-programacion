#ifndef PAQUETE_H
#define PAQUETE_H

#include <vector>
#include <string>
#include "caja_tornillos.h"

/*Clase que simula un paquete o molde de tornillos.*/
class Paquete {
	private:
	std::vector<CajaTornillos> cajas;
	std::string nombre_tipo;
	size_t limite_tornillos;
	size_t espacio_restante;

	public:
	/*Crea el objeto Paquete asignandole el nombre del tipo de tornillos
	con los que trabajara y el limite de espacio en cuanto a la cantidad de
	tornillos.*/
	void create(std::string str_tipo, size_t limite);
	/*Agrega una caja de tornillos al paquete.*/
	void agregar_caja(CajaTornillos &caja);
	/*Imprime los tornillos restantes que no han podido llegar a completar
	el paquete.*/
	void imprimir_remanentes();

	private:
	void imprimir_y_vaciar();
	size_t calcular_mediana_y_vaciar();
	bool alcanzo_limite();
};

#endif // PAQUETE_H
