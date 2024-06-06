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
Autor::Autor(std::string nombre, int DNI, int edad, std::string medio){
    Persona.setNombre(nombre);
    Persona.setDNI(DNI);
    Persona.setEdad(edad);
    setMedio(medio);
}
void Autor::setMedio(std::string medio){
    this->medio=medio;
}
std::string Autor::getMedio(){
    return medio;
}
    
