#include "clases.h"

Persona::Persona(){};
void Persona::setNombre(std::string nombre)
{
    this->nombre = nombre;
}
void Persona::setDNI(int DNI)
{
    this->DNI = DNI;
};
void Persona::setEdad(int edad)
{
    this->edad = edad;
};
std::string Persona::getNombre()
{
    return nombre;
};
int Persona::getDNI()
{
    return DNI;
};
int Persona::getEdad()
{
    return edad;
};
Autor::Autor(std::string nombre, int DNI, int edad, std::string medio)
{
    setNombre(nombre);
    setDNI(DNI);
    setEdad(edad);
    setMedio(medio);
}
void Autor::setMedio(std::string medio)
{
    this->medio = medio;
}
std::string Autor::getMedio()
{
    return medio;
}

Noticia::Noticia(std::string titulo, std::string detalle, int dia, int mes, int ano, Autor autor){
    setTitulo(titulo);
    setDetalle(detalle);
    setDia(dia);
    setMes(mes);
    setAno(ano);
    setAutor(autor);
}
void Noticia::setTitulo(std::string titulo){
    this->titulo=titulo;
}
void Noticia::setDetalle(std::string detalle){
    this->detalle=detalle;
}
void Noticia::setDia(int dia){
    this->dia=dia;
}
void Noticia::setMes(int mes){
    this->mes=mes;
}
void Noticia::setAno(int ano){
    this->ano=ano;
}
void Noticia::setAutor(Autor autor){
    this->autor=autor;
}
std::string Noticia::getTitulo(){
    return titulo;
}
std::string Noticia::getDetalle(){
    return detalle;
}
int Noticia::getDia(){
    return dia;
}
int Noticia::getMes(){
    return mes;
}
int Noticia::getAno(){
    return ano;
}
Autor Noticia::getAutor(){
    return autor;
}
Comentario::Comentario(int numero, std::string texto, Usuario usuario){
    setNumero(numero);
    setTexto(texto);
    setNombre(nombre);
    setUsuario(usuario);
}
void Comentario::setNumero(int numero){
    this->numero=numero;
}
void Comentario::setTexto(std::string texto){
    this->texto=texto;
}
void Comentario::setNombre(std::string nombre){
    this->nombre=nombre;
}
void Comentario::setUsuario(Usuario usuario){
    this->autor=autor;
}
int Comentario::getNumero(){
    return numero;
}
std::string Comentario::getTexto(){
    return texto;
}
std::string Comentario::getNombre(){
    return nombre;
}
Usuario Comentario::getUsuario(){
    return usuario;
}
    
