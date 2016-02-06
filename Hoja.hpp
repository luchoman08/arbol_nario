#ifndef Hoja_hpp
#define Hoja_hpp
#include <string>
#include <vector>
#include "Registro.cpp"

class Hoja{
	
 private:
 char caracter;
 std::vector<Hoja*> hijos;
 Hoja* padre;
 bool hoja_final;
 std::vector<Registro*>registros;
 
 public:
 
 Hoja();
 ~Hoja();

 Hoja* get_padre();
 Hoja* get_hijo_por_posicion(int posicion);
 Hoja* get_hijo_por_caracter(char caracter);
 std::vector <Hoja*> get_hijos();
 void set_caracter(char nuevo_caracter);
 char get_caracter();
 int adicionar_hijo(Hoja *hijo);
 void set_padre(Hoja *padre);
 bool existencia_hijo_por_caracter(char caracter);
 void marcarComoHojaFinal();
 bool esHojaFinal();
 bool existe(std::string palabra, Hoja *padre);
 Hoja* getHojaFinal(std::string palabra, Hoja *padre);
 Registro* get_Registro(std::string palabraOriginal);
 void adicionarRegistro(Registro *registro);

};

#endif
