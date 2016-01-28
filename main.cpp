// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class hoja{
 private:
 char caracter;
 vector<hoja*> hijos;
 hoja* padre;
 bool hoja_final;
 
 public:
 hoja();

 hoja* get_padre();
 hoja* get_hijo_por_posicion(int posicion);
 hoja* get_hijo_por_caracter(char posicion);
 vector <hoja*> get_hijos();
 void set_caracter(char nuevo_caracter);
    
};
hoja* hoja::get_padre()
{
return this->padre;
}
void hoja::set_caracter(char nuevo_caracter)
{
	
}

int main()
{
  hoja padre,hijo;
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello word, " << name << "!\n";
}
