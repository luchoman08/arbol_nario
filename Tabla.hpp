#ifndef Tabla_cpp
#define Tabla_cpp
#include <vector>
#include <string>
#include <iostream>
#include "Hoja.cpp"

class Tabla{
	
		private:
		
			//Soporte solo para 4FN
			Hoja* indice_pk;
			std::string nombre_tabla;
			std::vector <std::string> nombres_columnas;
			std::vector <Registro*> registros;
			int indice_pk_columna;
			void ingresar_valor_a_hoja(std::string valor,Registro *registro);
		
		public:
			
			Tabla(std::vector <std::string> nombres_columnas);
			~Tabla();
			int ingresarRegistro(std::vector<std::string> valores);
			std::vector <Registro*> get_registro(std::string nombre_columna, std::string valor);
			//Update y delete pendientes
};

#endif
