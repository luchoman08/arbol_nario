#include "Tabla.hpp"

Tabla::Tabla(std::vector <std::string> nombres_columnas){
	
		this->nombres_columnas = nombres_columnas;
		this->indice_pk = new Hoja();
		this->indice_pk->set_caracter('_');
		this->indice_pk->set_padre(this->indice_pk);
	
	};
Tabla::~Tabla(){
	
	};
	
void Tabla::ingresar_valor_a_hoja(std::string valor,Registro *registro){
	
	
	Hoja* hijo_ingresar = new Hoja();
	int valor_size =  valor.size(), resultado;
		for(int i = 0; i < valor_size;i++)
		{
			hijo_ingresar->set_caracter(valor.at(i));	
			resultado = this->indice_pk->adicionar_hijo(hijo_ingresar);
				if(resultado == 0)
				{
					this->indice_pk = hijo_ingresar;
					hijo_ingresar = new Hoja();
				}
			else
			{
				this->indice_pk = this->indice_pk->get_hijo_por_caracter(valor.at(i));
				hijo_ingresar = new Hoja();
			}
	}
	
	this->indice_pk->marcarComoHojaFinal();
	this->indice_pk->adicionarRegistro(registro);
	};

int Tabla::ingresarRegistro(std::vector<std::string> valores){
		/*
		 * Codigos de error:
		 * 
		 * 1001 = No hay dato por columna
		 * 
		 * 
		 * */
		 
		 int valores_size = valores.size();
		 int columnas_size = this->nombres_columnas.size();
		 if (!(valores_size == columnas_size)){
				return 1001;
			 }
			 
		 if (valores_size == columnas_size){
				std::vector <Registro*> registros;
				for (int i = 0 ; i < valores_size; i++){
					
						Registro* tmp = new Registro();
						tmp->set_registro(valores[i]);
						registros.push_back(tmp);
						Tabla::ingresar_valor_a_hoja(valores[i],tmp);
					
					}
				for (int i = 0 ; i < valores_size; i++){
						
						if ((i == 0)and(valores_size > 1)){
								registros[i]->set_registro_derecho(registros[i+1]);
								registros[i]->set_registro_izquierdo(registros[i]);
							}
						if ((i == (valores_size-1))and(valores_size > 1)){
								registros[i]->set_registro_izquierdo(registros[i-1]);
								registros[i]->set_registro_derecho(registros[i]);
							}
						if ((i < (valores_size-1))and(valores_size > 1)and(i > 0)){
								registros[i]->set_registro_derecho(registros[i+1]);
								registros[i]->set_registro_izquierdo(registros[i-1]);
							}
					}
				this->registros.push_back(registros[0]);
				return 0;
			 
			 }
		return -1;
		 
	};
std::vector <Registro*> Tabla::get_registro(std::string nombre_columna, std::string valor){
		int nombre_columna_size = nombre_columna.size();
		int valor_size = valor.size();
		if ((nombre_columna_size == 0)and(valor_size == 0)){
			
				return this->registros;
			}
		
	};
