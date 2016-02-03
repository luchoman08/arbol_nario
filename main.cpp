#include "Hoja.cpp"
#include <iostream>

int main(int argv, char** args){
  Hoja padre;
  vector <string> palabras;
  Lectura lectura;
  lectura.Leer("in.txt");
  palabras=lectura.getPalabras();
  
  int palabras_size = palabras.size();
  
  inicializar_padre(&padre);
  
  imprimir_hijos_arbol(&padre);
  //ingresar_palabra("arbol",&padre);
  //ingresar_palabra("arbos",&padre);
  //ingresar_palabra("ar",&padre);
  
  
  for (int i = 0 ; i < palabras_size; i++){
	  
		ingresar_palabra(palabras[i],&padre);
	  
	  }
  
  
  //cout<<padre.get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->existencia_hijo_por_caracter('s')<<endl;
  //cout<<padre.get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->esHojaFinal()<<endl;
  //cout<<padre.get_hijos().at(2)->get_hijos().at(0)->get_hijos().at(17)->get_hijos().at(0)->esHojaFinal()<<endl;
  //cout << padre.existe("zapato", &padre) << endl;
  //cout<<padre.get_hijo_por_posicion(0)->get_caracter()<<padre.get_hijo_por_posicion(1)->get_caracter()<<endl;
 /* int contador = 0;
  for (int i = 0; i < palabras_size; i++){
	  
			if ( padre.existe(palabras[i], &padre)){
					contador ++;
				}
	  }
	 cout << contador << " " << palabras_size << endl;*/
  ingresar_palabra("こんにちは0",&padre);
   clock_t start = clock();
    cout << padre.existe("こんにちは", &padre);
    clock_t stop = clock();
    double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);
  return 0;
}
