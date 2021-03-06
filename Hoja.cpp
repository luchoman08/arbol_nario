#include "Hoja.hpp"
#include "Lectura.cpp"
using namespace std;

Hoja::Hoja(){
	this->hoja_final = false;
}
Hoja::~Hoja(){
}
Hoja* Hoja::get_padre(){
return this->padre;
}

void Hoja::marcarComoHojaFinal(){
	
		this->hoja_final = true;
	
	}

void Hoja::set_caracter(char nuevo_caracter){
	this->caracter=nuevo_caracter;
}

char Hoja::get_caracter(){
	
	return this->caracter;
}
int Hoja::adicionar_hijo(Hoja *hijo){ //si el hijo no existia lo adiciona y retorna 0, si ya estaba no adiciona nada y retorna -1
	if(!existencia_hijo_por_caracter(hijo->get_caracter())){
		this->hijos.push_back(hijo);
		return 0;
	}
	return -1;
}
	
Hoja* Hoja::get_hijo_por_posicion(int pos){
return hijos.at(pos);	
}

void Hoja::set_padre(Hoja *padre){
	this->padre = padre;
}
Hoja* Hoja::get_hijo_por_caracter(char caracter)
{
	int numero_hijos = this->hijos.size();
	for(int i = 0; i< numero_hijos; i++)
	{
		if(hijos.at(i)->caracter==caracter)
		return hijos.at(i);	
	}
	return hijos.at(0);
	
}
bool Hoja::existencia_hijo_por_caracter(char caracter)
{
	int numero_hijos = this->hijos.size();
	for(int i = 0; i< numero_hijos; i++)
	{
		if(hijos.at(i)->caracter==caracter)
		return true;		
	}
	return false;
}
vector <Hoja*> Hoja::get_hijos()
{
	return this->hijos;
}
void ingresar_palabra(string palabra, Hoja *padre)
{
	Hoja* actual = padre;
	Hoja* hijo_ingresar = new Hoja();
	int palabra_size =  palabra.size(), resultado;
		for(int i = 0; i <palabra_size;i++)
		{
			hijo_ingresar->set_caracter(palabra.at(i));	
			resultado = actual->adicionar_hijo(hijo_ingresar);
				if(resultado == 0)
				{
					actual = hijo_ingresar;
					hijo_ingresar = new Hoja();
				}
			else
			{
				actual = actual->get_hijo_por_caracter(palabra.at(i));
				hijo_ingresar = new Hoja();
			}
	}
	
	actual->marcarComoHojaFinal();
	/*actual->ingresarFinalPara(palabra);*/
					
}

void ingresar_palabra_con_registro(string palabra, Hoja *padre,Registro *registro)
{
	Hoja* actual = padre;
	Hoja* hijo_ingresar = new Hoja();
	int palabra_size =  palabra.size(), resultado;
		for(int i = 0; i <palabra_size;i++)
		{
			hijo_ingresar->set_caracter(palabra.at(i));	
			resultado = actual->adicionar_hijo(hijo_ingresar);
				if(resultado == 0)
				{
					actual = hijo_ingresar;
					hijo_ingresar = new Hoja();
				}
			else
			{
				actual = actual->get_hijo_por_caracter(palabra.at(i));
				hijo_ingresar = new Hoja();
			}
	}
	
	actual->marcarComoHojaFinal();
	actual->adicionarRegistro(registro);
	/*actual->ingresarFinalPara(palabra);*/
					
}

void imprimir_hijos_arbol(Hoja* arbol)
{
	int size = arbol->get_hijos().size();
	for(int i = 0; i < size; i++)
	{
		cout<<arbol->get_hijos().at(i)->get_caracter()<<" ";
	}
}

void inicializar_padre(Hoja *padre)
{
  padre->set_caracter('_');
  padre->set_padre(padre);
}

bool Hoja::esHojaFinal(){
		/*for (int i = 0 ; i < this->final_para.size(); i++){
				std::cout << this->final_para[i] << std::endl;
			}*/
		return this->hoja_final;
	}

bool Hoja::existe(std::string palabra, Hoja *padre){
		
		Hoja* actual = padre;
		int palabra_size = palabra.size();
		for (int i = 0 ; i < palabra_size ; i++){
				if (actual->existencia_hijo_por_caracter(palabra.at(i))){
						actual = actual->get_hijo_por_caracter(palabra.at(i));
					}else{
							return false;
						}
			}
		return actual->esHojaFinal();
	}

Registro* Hoja::get_Registro(std::string palabraOriginal){
		int registros_size = this->registros.size();
		for (int i = 0 ; i < registros_size;i++){
			
				if (this->registros[i]->get_registro() == palabraOriginal){
						return this->registros[i];
					}
			}
		return new Registro();
	};

 void Hoja::adicionarRegistro(Registro *registro){
		this->registros.push_back(registro);
	 };
	 
Hoja* Hoja::getHojaFinal(std::string palabra, Hoja *padre){
	
		Hoja* actual = padre;
		int palabra_size = palabra.size();
		for (int i = 0 ; i < palabra_size ; i++){
				if (actual->existencia_hijo_por_caracter(palabra.at(i))){
						actual = actual->get_hijo_por_caracter(palabra.at(i));
					}else{
							return new Hoja();
						}
			}
		if (actual->esHojaFinal()){
				return actual;
			}
		return new Hoja();
	
	};

void Hoja::ingresarFinalPara(std::string cadena){
	
		this->final_para.push_back(cadena);
	
	};
	
void Hoja::eliminarFinalPara(std::string cadena){
		
		int final_para_size = this->final_para.size();
		for (int i = 0; i < final_para_size ; i++){
			
				if (this->final_para[i] == cadena){
					
						this->final_para.erase(this->final_para.begin()+i);
					
					}
			
			}
	
	};

std::vector <std::string>* Hoja::finalPara(){
		std::vector <std::string> tmp;
		tmp = this->final_para;
		return &tmp;
	
	};
