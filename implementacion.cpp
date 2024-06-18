#include"clases.h"


Persona::Persona(): DNI(0), edad(0) {};
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

Usuario::Usuario(std::string nombre, int DNI, int edad)
{
    setNombre(nombre);
    setDNI(DNI);
    setEdad(edad);
};

Autor::Autor(std::string nombre)
{
    setNombre(nombre);
}
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

Noticia::Noticia(std::string titulo, std::string detalle, int dia, int mes, int ano, Autor autor)
{
    setTitulo(titulo);
    setDetalle(detalle);
    setDia(dia);
    setMes(mes);
    setAno(ano);
    setAutor(autor);
}
void Noticia::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}
void Noticia::setDetalle(std::string detalle)
{
    this->detalle = detalle;
}
void Noticia::setDia(int dia)
{
    this->dia = dia;
}
void Noticia::setMes(int mes)
{
    this->mes = mes;
}
void Noticia::setAno(int ano)
{
    this->ano = ano;
}
void Noticia::setAutor(Autor autor)
{
    this->autor = autor;
}
std::string Noticia::getTitulo()
{
    return titulo;
}
std::string Noticia::getDetalle()
{
    return detalle;
}
int Noticia::getDia()
{
    return dia;
}
int Noticia::getMes()
{
    return mes;
}
int Noticia::getAno()
{
    return ano;
}
Autor Noticia::getAutor()
{
    return autor;
}
Comentario::Comentario(int numero, std::string texto, Usuario usuario)
{
    setNumero(numero);
    setTexto(texto);
    setUsuario(usuario);
}
void Comentario::setNumero(int numero)
{
    this->numero = numero;
}
void Comentario::setTexto(std::string texto)
{
    this->texto = texto;
}
void Comentario::setUsuario(Usuario usuario)
{
    this->usuario = usuario;
}
int Comentario::getNumero()
{
    return numero;
}
std::string Comentario::getTexto()
{
    return texto;
}
Usuario Comentario::getUsuario()
{
    return usuario;
}
int noticiasPorAno(int ano)
{
    for (auto &noticia : noticias)
    {
        if (noticia.getAno() == ano)
        {
            std::cout << noticia.getTitulo() << " (" << noticia.getDia() << "/" << noticia.getMes() << "/" << noticia.getAno() << ")\n";
        }
    }
    return 0;
}

int noticiasPorMes(int mes,int ano)
{
    for (auto &noticia : noticias)
    {
        if (noticia.getAno() ==ano && noticia.getMes() == mes)
        {
            std::cout << noticia.getTitulo() << " (" << noticia.getDia() << "/" << noticia.getMes() << "/" << noticia.getAno() << ")\n";
        }
    }
    return 0;
}

void mostrarNoticia(std::string titulo)
{
    for (auto &noticia : noticias)
    {
        if (noticia.getTitulo() == titulo)
        {
            std::cout << "Titulo: " << noticia.getTitulo() << "\n";
            std::cout << "Detalle: " << noticia.getDetalle() << "\n";
            std::cout << "Fecha: " << noticia.getDia() << "/" << noticia.getMes() << "/" << noticia.getAno() << "\n";
            std::cout << "Autor: " << (noticia.getAutor()).getNombre() << " (" << (noticia.getAutor()).getMedio() << ")\n";
            std::cout << "Comentarios:\n";
            for (auto &comentario : noticia.comentarios)
            {
                std::cout << comentario.getNumero() << ". " << comentario.getTexto() << " - " << (comentario.getUsuario()).getNombre() << "\n";
            }
            return;
        }
    }
}

void articulosPorAutor(int DNI)
{
    for (auto &noticia : noticias)
    {
        if (noticia.getAutor().getDNI() == DNI)
        {
            std::cout << noticia.getTitulo() << " (" << noticia.getDia() << "/" << noticia.getMes() << "/" << noticia.getAno() << ")\n";
        }
    }
}

void publicarNoticia()
{
    std::string titulo, detalle;
    int dia, mes, ano, DNI;
    std::cout << "Ingrese titulo de la noticia: ";
    std::cin.ignore();
    getline(std::cin, titulo);
    std::cout << "Ingrese detalle de la noticia: ";
    getline(std::cin, detalle);
    std::cout << "Ingrese dia: ";
    std::cin >> dia;
    std::cout << "Ingrese mes: ";
    std::cin >> mes;
    std::cout << "Ingrese ano: ";
    std::cin >> ano;
    std::cout << "Ingrese DNI del autor: ";
    std::cin >> DNI;

    for (auto &autor : autores)
    {
        if (autor.getDNI() == DNI)
        {
            noticias.push_back(Noticia(titulo, detalle, dia, mes, ano, autor));
            std::cout << "Noticia cargada exitosamente.\n";
            return;
        }
    }
    std::cout << "Autor no encontrado.\n";
}

void comentarNoticia()
{
    std::string titulo, texto;
    int numero, DNI;
    std::cout << "Ingrese titulo de la noticia: ";
    std::cin.ignore();
    getline(std::cin, titulo);
    std::cout << "Ingrese numero del comentario: ";
    std::cin >> numero;
    std::cout << "Ingrese texto del comentario: ";
    std::cin.ignore();
    getline(std::cin, texto);
    std::cout << "Ingrese DNI del usuario: ";
    std::cin >> DNI;

    for (auto &usuario : usuarios)
    {
        if (usuario.getDNI() == DNI)
        {
            for (auto &noticia : noticias)
            {
                if (noticia.getTitulo() == titulo)
                {
                    noticia.comentarios.push_back(Comentario(numero, texto, usuario));
                    std::cout << "Comentario registrado exitosamente.\n";
                    return;
                }
            }
        }
    }
    std::cout << "Usuario o noticia no encontrados.\n";
}

void registrarAutor()
{
    std::string nombre, medio;
    int edad, DNI;
    std::cout << "Ingrese DNI del autor: ";
    std::cin >> DNI;
    std::cout << "Ingrese nombre del autor: ";
    std::cin.ignore();
    getline(std::cin, nombre);
    std::cout << "Ingrese medio del autor: ";
    getline(std::cin, medio);

    autores.push_back(Autor(nombre, DNI, edad, medio));
    std::cout << "Autor registrado exitosamente.\n";
}

void registrarUsuario()
{
    std::string nombre;
    int edad, DNI;
    std::cout << "Ingrese DNI del usuario: ";
    std::cin >> DNI;
    std::cout << "Ingrese nombre del usuario: ";
    std::cin.ignore();
    getline(std::cin, nombre);
    std::cout << "Ingrese edad del usuario: ";
    std::cin >> edad;

    usuarios.push_back(Usuario(nombre, DNI, edad));
    std::cout << "Usuario registrado exitosamente.\n";
}










void cargarUsuarios()
{
    std::ifstream usuariostxt;
    usuariostxt.open("usuarios.txt");
    int DNI;
    std::string nombre, a, b, c, dni, ed;
    int edad;
    usuariostxt >> a;
    usuariostxt >> b;
    usuariostxt >> c;
    for (auto &usuario : usuarios)
    {
        usuariostxt >> dni;
        usuariostxt >> nombre;
        usuariostxt >> ed;
        DNI = stoi(dni);
        edad = stoi(ed);
        usuarios.push_back(Usuario(nombre, DNI, edad));
    }
}
void cargarAutores()
{
    std::ifstream autorestxt;
    autorestxt.open("autores.txt");
    int DNI;
    std::string nombre, a, b,
        c, d, dni, ed, medio;
    int edad;
    autorestxt >> a;
    autorestxt >> b;
    autorestxt >> c;
    autorestxt >> d;
    for (auto &autor : autores)
    {
        autorestxt >> dni;
        std::cin.ignore();
        autorestxt >> nombre;
        autorestxt >> ed;
        autorestxt >> medio;
        DNI = stoi(dni);
        edad = stoi(ed);
        autores.push_back(Autor(nombre, DNI, edad, medio));
    }
}
void cargarNoticia()
{
    std::ifstream noticiastxt;
    noticiastxt.open("autores.txt");
    std::string a, b, c, d, e, f, titulo, detalle, di, me, an, nombre;
    int dia, mes, ano;

    noticiastxt >> a;
    noticiastxt >> b;
    noticiastxt >> c;
    noticiastxt >> d;
    noticiastxt >> e;
    noticiastxt >> f;
    for (auto &autor : autores)
    {
        std::cin.ignore();
        noticiastxt >> titulo;
        noticiastxt >> detalle;
        noticiastxt >> di;
        noticiastxt >> me;
        noticiastxt >> an;
        noticiastxt >> nombre;
        dia = stoi(di);
        mes = stoi(me);
        ano = stoi(an);

        noticias.push_back(Noticia(titulo, detalle, dia, mes, ano, Autor(nombre)));
    }
}

void cargar()
{
    cargarUsuarios();
    cargarAutores();
    cargarNoticia();
}


void guardarUsuarios()
{
    std::ofstream usuariostxt;
    usuariostxt.open("usuarios.txt");
    usuariostxt << "DNI" << "     " << "Nombre" << "     " << "Edad\n";
    for (auto &usuario : usuarios)
    {
        usuariostxt << usuario.getDNI() << "  " << usuario.getNombre() << "   " << usuario.getEdad() << '\n';
    }
    usuariostxt.close();
}
void guardarAutores()
{
    std::ofstream autorestxt;
    autorestxt.open("autores.txt");
    autorestxt << "DNI" << "     " << "Nombre"<< "     " << "medio\n";
    for (auto &autor : autores)
    {
        autorestxt << autor.getDNI() << "  " << autor.getNombre() << "  " << autor.getMedio() << '\n';
    }
    autorestxt.close();
}
void guardarNoticias()
{
    std::ofstream noticiastxt;
    noticiastxt.open("noticias.txt");
    noticiastxt << "titulo" << "     " << "detalle" << "     " << "dia" << "     " << "mes" << "     " << "ano" << "     " << "nombre del autor\n";
    for (auto &noticia : noticias)
    {
        noticiastxt << noticia.getTitulo() << "  " << noticia.getDetalle() << "  " << noticia.getDia() << "  " << noticia.getMes() << "  " << noticia.getAno() << "  " << noticia.getAutor().getNombre() << '\n';
        noticiastxt << "comentarios de la noticia: \n";
        std::cout << "numero" << "     " << "texto" << "     " << "nombre del usuario\n";
        for (auto &comentario : noticia.comentarios)
        {
            noticiastxt << comentario.getNumero() << "  " << comentario.getTexto() << "  " << comentario.getUsuario().getNombre() << '\n';
        }
    }
}

void guardar()
{
    guardarUsuarios();
    guardarAutores();
    guardarNoticias();
}
