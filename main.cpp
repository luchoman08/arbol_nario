#include <iostream>
#include "Hoja.hpp"
#include "Lectura.cpp"
using namespace std;

Hoja::Hoja(){
}
Hoja::~Hoja(){
}
Hoja* Hoja::get_padre(){
return this->padre;
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
	int size =  palabra.size(), resultado;
		for(int i = 0; i <size;i++)
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



int main(int argv, char** args){
  Hoja padre;
  vector <string> palabras;
  Lectura lectura;
  lectura.Leer("in.txt");
  palabras=lectura.getPalabras();
  inicializar_padre(&padre);
  
  imprimir_hijos_arbol(&padre);
  ingresar_palabra("a",&padre);
  cout<<padre.get_hijos().at(0)->existencia_hijo_por_caracter('a')<<endl;
  //cout<<padre.get_hijo_por_posicion(0)->get_caracter()<<padre.get_hijo_por_posicion(1)->get_caracter()<<endl;
  return 0;
}
