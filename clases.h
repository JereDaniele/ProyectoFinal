#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

class Persona
{
private:
    std::string nombre;
    int DNI, edad;

public:
    Persona();
    void setNombre(std::string);
    void setDNI(int DNI);
    void setEdad(int edad);
    std::string getNombre();
    int getDNI();
    int getEdad();
};
class Autor : public Persona
{
private:
    std::string medio;

public:
    Autor();
    Autor(std::string nombre, int DNI, int edad, std::string medio);
    void setMedio(std::string medio);
    std::string getMedio();
};
class Usuario : public Persona
{
public:
    Usuario(std::string nombre, int DNI, int edad);
};
class Noticia
{
private:
    std::string titulo, detalle;
    int dia, mes, ano;
    Autor autor;

public:
    Noticia(std::string titulo, std::string detalle, int dia, int mes, int ano, Autor autor);
    void setTitulo(std::string titulo);
    void setDetalle(std::string detalle);
    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);
    void setAutor(Autor autor);
    std::string getTitulo();
    std::string getDetalle();
    std::string getNombre();
    std::string getMedio();
    int getDia();
    int getMes();
    int getAno();
    int getDNI();
    int getEdad();
    Autor getAutor();
};
class Comentario
{
private:
    int numero;
    std::string texto;
    Usuario usuario;

public:
    Comentario(int numero, std::string texto, Usuario usuario);
    void setNumero(int numero);
    void setTexto(std::string texto);
    void setUsuario(Usuario usuario);
    int getNumero();
    int getTexto();
    Usuario getUsuario();
};

int noticiasPorAno(int ano);
int noticiasPorMes(int mes);
void mostrarNoticia(std::string titulo);
void articulosPorAutor(int DNI);
void publicarNoticia();
void registrarAutor();
void comentarNoticia();
void registrarUsuario();
