#include"clases.h"

Persona::Persona(){};
void Persona::setNombre(std::string nombre){
    this->nombre=nombre;
 }
void Persona::setDNI(int DNI){
    this->DNI=DNI;
};
void Persona::setEdad(int edad){
    this->edad=edad;
};
std::string Persona::getNombre(){
    return nombre;
};
int Persona::getDNI(){
    return DNI;
};
int Persona::getEdad(){
    return edad;
};
    
