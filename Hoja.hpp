#ifndef Hoja_hpp
#define Hoja_hpp
#include <string>
#include <vector>

class Hoja{
 private:
 char caracter;
 std::vector<Hoja*> hijos;
 Hoja* padre;
 bool hoja_final;
 
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

};

#endif
