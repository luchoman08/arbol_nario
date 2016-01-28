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
 hoja* get_padre();
 hoja* get_hijo_por_posicion(int posicion);
 hoja* get_hijo_por_caracter(char posicion);
 
 vector <hoja*> get_hijos();
    
};

int main()
{
	
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello word, " << name << "!\n";
}
