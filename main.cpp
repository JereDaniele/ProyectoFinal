#include"implementacion.cpp"

int main() {
    cargar();

    int opcion;
    while (true) {
        try {
            std::cout << "Menu: \n";
            std::cout << "1. Registrar Autor. \n";
            std::cout << "2. Registrar Usuario. \n";
            std::cout << "3. Cargar Noticia. \n";
            std::cout << "4. Crear Comentario. \n";
            std::cout << "5. Listar Noticias del Año. \n";
            std::cout << "6. Listar Noticias del Ultimo Mes. \n";
            std::cout << "7. Mostrar Noticia con Comentarios. \n";
            std::cout << "8. Listar Noticias por Autor. \n";
            std::cout << "9. Salir. \n";
            std::cout << "Elija una Opcion: ";
            std::cin >> opcion;

            if (std::cin.fail()) {
                throw std::invalid_argument("Entrada invalida. Por favor, ingrese un numero.");
            }

            switch (opcion) {
                case 1:
                    registrarAutor();
                    break;
                case 2:
                    registrarUsuario();
                    break;
                case 3:
                    publicarNoticia();
                    break;
                case 4:
                    comentarNoticia();
                    break;
                case 5: {
                    int ano;
                    std::cout << "Ingrese el año que desea ver: ";
                    std::cin >> ano;
                    if (std::cin.fail()) {
                        throw std::invalid_argument("Entrada invalida. Por favor, ingrese un numero.");
                    }
                    noticiasPorAno(ano);
                    break;
                }
                case 6: {
                    int mes, ano;
                    std::cout << "Indique el mes actual: ";
                    std::cin >> mes;
                    if (std::cin.fail()) {
                        throw std::invalid_argument("Entrada invalida. Por favor, ingrese un numero.");
                    }
                    std::cout << "Indique el ano actual: ";
                    std::cin >> ano;
                    if (std::cin.fail()) {
                        throw std::invalid_argument("Entrada invalida. Por favor, ingrese un numero.");
                    }
                    noticiasPorMes(mes, ano);
                    break;
                }
                case 7: {
                    std::string titulo;
                    std::cout << "Coloque el titulo de la noticia: ";
                    std::cin.ignore();
                    std::getline(std::cin, titulo);
                    mostrarNoticia(titulo);
                    break;
                }
                case 8: {
                    std::string nombre;
                    std::cout << "Coloque el nombre del autor: ";
                    std::cin >> nombre;
                    if (std::cin.fail()) {
                        throw std::invalid_argument("Entrada invalida. Por favor, ingrese un numero.");
                    }
                    articulosPorAutor(nombre);
                    break;
                }
                case 9:
                    guardar();
                    return 0;
                default:
                    std::cout << "Opcion invalida. Intente de nuevo.\n";
                    break;
            }
        } catch (const std::invalid_argument &e) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    }
}
