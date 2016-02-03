#include "Hoja.cpp"
#include <iostream>

int main(int argv, char** args){
  Hoja padre;
  vector <string> palabras;
  Lectura lectura;
  lectura.Leer("in.txt");
  palabras=lectura.getPalabras();
  inicializar_padre(&padre);
  
  imprimir_hijos_arbol(&padre);
  ingresar_palabra("arbol",&padre);
  ingresar_palabra("arbos",&padre);
  ingresar_palabra("ar",&padre);
  //cout<<padre.get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->existencia_hijo_por_caracter('s')<<endl;
  //cout<<padre.get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->esHoja()<<endl;
  cout<<padre.get_hijos().at(0)->get_hijos().at(0)->esHoja()<<endl;
  //cout<<padre.get_hijo_por_posicion(0)->get_caracter()<<padre.get_hijo_por_posicion(1)->get_caracter()<<endl;
  return 0;
}
