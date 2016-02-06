#include "Registro.hpp"

Registro::Registro(){};
Registro::~Registro(){};
 
Registro* Registro::get_registro_izquierdo(){return this->registro_izquierdo;};
std::string Registro::get_registro(){return this->registro_actual;};
Registro* Registro::get_registro_derecho(){return this->registro_derecho;};
 
void Registro::set_registro_izquierdo(Registro *registro){this->registro_izquierdo = registro;};
void Registro::set_registro(std::string registro){this->registro_actual = registro;};
void Registro::set_registro_derecho(Registro *registro){this->registro_derecho = registro;};
