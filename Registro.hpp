#ifndef Registro_hpp_
#define Registro_hpp_
#include <string>

class Registro{
		
 private:
 
 Registro* registro_izquierdo;
 std::string registro_actual;
 Registro* registro_derecho;
		
 public:
 Registro();
 ~Registro();
 
 Registro* get_registro_izquierdo();
 std::string get_registro();
 Registro* get_registro_derecho();
 
 void set_registro_izquierdo(Registro *registro);
 void set_registro(std::string registro);
 void set_registro_derecho(Registro *registro);
	
};	

#endif
