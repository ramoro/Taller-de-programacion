#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>

/*Clase que simula un archivo.*/
class File {
	private:
	char *nombre;
	std::fstream archivo;

	public:
	/*Recibe el nombre de un archivo, lo abre y crea el objeto. Devuelve true
	si se pudo abrir el archivo, false en caso contrario.*/
	bool create(char *nombre);
	/*Lee del archivo tantos bytes como indica cantidad y almacena lo leido
	en buffer.*/
	void leer(char *buffer, int cantidad);
	/*Devuelve true si se ha llegado al final del File. False en caso
	contrario.*/
	bool esta_al_final();
	/*Lee una linea del archivo, teniendo en cuenta un maximo de bytes 
	dado por limite_bytes y un caracter que frena la lectura recibido
	por caracter_limite. Lo leido se almacena en buffer.*/
	void leer_linea(char *buffer, int limite_bytes, int caracter_limite);
	/*Devuelve el nombre del archivo.*/
	char* get_nombre();
	/*Destructor del File. Cierra el archivo.*/
	~File();
};

#endif // FILE_H
