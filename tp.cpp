#include "lector_operaciones.h"
#include "lector_configuracion.h"
#include <iostream>
#include <thread>

int main(int argc, char *argv[]) {
	LectorConfiguracion lectorconfig;
	lectorconfig.create(argv[1]);
	FabricaPaquetes *fabrica = new FabricaPaquetes();
	lectorconfig.informar_caracteristicas_paquetes(fabrica);

	std::vector<File*> lista_archivos;
	std::vector<std::string> nombres_dispositivos;

	for (int i = 2; i < argc; ++i) {
		File *file = new File();
 		if(!file->create(argv[i])) {
 			delete (file);
 			continue;
 		}
 		char nombre_dispositivo[30];
		file->leer_linea(nombre_dispositivo, 30 , '\0');
		std::string nombre_disp(nombre_dispositivo); 
		std::cout << file->get_nombre() << 
		": se establece conexion con el dispositivo " << nombre_dispositivo 
		<< std::endl;
 		lista_archivos.push_back(file);
 		nombres_dispositivos.push_back(nombre_disp);
 	}

 	int indice_dispositivo = 0;
 	std::vector<std::thread*> threads;
	std::vector<LectorOperaciones> lectores;

	lectores.reserve(argc);

 	for (std::vector<File*>::iterator it = lista_archivos.begin();
	it != lista_archivos.end(); it++) {
		lectores.push_back(LectorOperaciones(*it, nombres_dispositivos[indice_dispositivo], fabrica));
		indice_dispositivo++;
	}

	for (unsigned int i = 0; i < (lectores.size()); ++i){
		std::thread *t = new std::thread(std::ref(lectores[i]));
		threads.push_back(t);
	}

	for (unsigned int i = 0; i < (lectores.size()); ++i){
		threads[i]->join();
		delete threads[i];
	}
		
	for (std::vector<File*>::iterator it = lista_archivos.begin();
	it != lista_archivos.end(); it++) {
		delete *it;
	}

	fabrica->imprimir_remanentes();

	delete fabrica;
	
	return 0;
}
