/*#include "Hoja.cpp"*/
#include "Tabla.cpp"
#include <iostream>
#include <string>
#include <sstream>


int main(int argv, char** args){
	
	/*std::vector <std::string> columnas;
	columnas.push_back("Columna1");
	columnas.push_back("Columna2");
	columnas.push_back("Columna3");
	Tabla* tabla = new Tabla(columnas);
	
	std::vector <std::string> valores;
	valores.push_back("Jeison");
	valores.push_back("Cardona");
	valores.push_back("Gómez");
	tabla->ingresarRegistro(valores);
	
	std::vector <std::string> valores2;
	valores2.push_back("Roberto");
	valores2.push_back("Mendoza");
	valores2.push_back("Jimenez");
	tabla->ingresarRegistro(valores2);
	
	std::cout << tabla->get_registro("","")[0]->get_registro() << std::endl;
	std::cout << tabla->get_registro("","")[0]->get_registro_derecho()->get_registro() << std::endl;
	std::cout << tabla->get_registro("","")[0]->get_registro_derecho()->get_registro_derecho()->get_registro() << std::endl;*/
	
/*
  Registro x; //Centro
	x.set_registro("casa");
	Registro y; //Izquierda
	y.set_registro("comer");
	y.set_registro_derecho(&x);
	x.set_registro_izquierdo(&y);
	Registro z;//Drecha
	z.set_registro("garden");
	z.set_registro_izquierdo(&x);
	x.set_registro_derecho(&z);
	
  Hoja padre;
  ingresar_palabra_con_registro("casa",&padre,&x);
  ingresar_palabra_con_registro("carro",&padre,&x);
  std::cout << padre.existe("casa", &padre) << std::endl;
  std::cout << padre.getHojaFinal("casa", &padre)->get_Registro("casa")->get_registro() << std::endl;//Centro
  std::cout << padre.getHojaFinal("casa", &padre)->get_Registro("casa")->get_registro_derecho()->get_registro() << std::endl;//Derecha
  std::cout << padre.getHojaFinal("casa", &padre)->get_Registro("casa")->get_registro_izquierdo()->get_registro() << std::endl;//Izquierda*/
  
  Hoja padre;
  vector <string> palabras;
  Lectura lectura;
  lectura.Leer("in.txt");
  palabras=lectura.getPalabras();
  
  int palabras_size = palabras.size();
  
  inicializar_padre(&padre);
  
  imprimir_hijos_arbol(&padre);
  
  for (int i = 0 ; i < palabras_size; i++){
	  
		ingresar_palabra(palabras[i],&padre);
	  
	  }
	  
  
  
  //cout<<padre.get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->existencia_hijo_por_caracter('s')<<endl;
  //cout<<padre.get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->get_hijos().at(0)->esHojaFinal()<<endl;
  //cout<<padre.get_hijos().at(2)->get_hijos().at(0)->get_hijos().at(17)->get_hijos().at(0)->esHojaFinal()<<endl;
  //cout << padre.existe("zapato", &padre) << endl;
  //cout<<padre.get_hijo_por_posicion(0)->get_caracter()<<padre.get_hijo_por_posicion(1)->get_caracter()<<endl;
  /*int contador = 0;
  for (int i = 0; i < palabras_size; i++){
	  
			if ( padre.existe(palabras[i], &padre)){
					contador ++;
				}
	  }
	 cout << contador << " " << palabras_size << endl;*/
  
  
	/*Registro x;
	x.set_registro("casa");
	Registro y;
	y.set_registro("comer");
	y.set_registro_derecho(&x);
	x.set_registro_izquierdo(&y);
	Registro z;
	z.set_registro("garden");
	z.set_registro_izquierdo(&x);
	x.set_registro_derecho(&z);
	
	cout << x.get_registro_izquierdo()->get_registro() << " - " << x.get_registro() << " - " << x.get_registro_derecho()->get_registro();*/
	
  
	bool existe = false;
    clock_t start = clock();
    existe = padre.existe("asdasdasd", &padre);
    clock_t stop = clock();
    cout << existe << endl;
    double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);
  return 0;
}
