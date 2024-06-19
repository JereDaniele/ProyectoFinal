#include"implementacion.cpp"
int main(){

    cargar();

    int opcion;
    do{
        std::cout<< "Menu: \n";
        std::cout<< "1. Registrar Autor. \n";
        std::cout<< "2. Registrar Usuario. \n ";
        std::cout<< "3. Cargar Noticia. \n ";
        std::cout<< "4. Crear Comentario. \n ";
        std::cout<< "5. Listar Noticias del Año. \n ";
        std::cout<< "6. Listar Noticias del Ultimo Mes. \n ";
        std::cout<< "7. Mostrar Noticia con Comentarios. \n ";
        std::cout<< "8. Listar Noticias por Autor. \n ";
        std::cout<< "9. Salir. \n ";
        std::cout<< "Elija una Opcion: ";
        std::cin>> opcion;

    switch (opcion){
        case 1: registrarAutor(); break;
        case 2: registrarUsuario(); break;
        case 3: publicarNoticia(); break;
        case 4: comentarNoticia(); break;
        case 5: {
            int ano;
            std::cout<<"Ingrese el año que desea ver: ";
            std::cin>>ano;
            noticiasPorAno(ano);
            break;
        }
        case 6: {
            int mes,ano;
            std::cout<<"indique el mes actual: ";
            std::cin>>mes; 
            std::cout<<"indique el ano actual: ";
            std::cin>>ano;          
            noticiasPorMes(mes,ano);
            break;
        }
        case 7: {
            std::string titulo;
            std::cout<<"Coloque el titulo de la noticia: ";
            std::cin.ignore();
            getline(std::cin,titulo);
            mostrarNoticia(titulo);
            break;
        }
        case 8:{
            int DNI;
            std::cout<<"Coloque el dni del autor: ";
            std::cin>>DNI;
            articulosPorAutor(DNI);
            break;
        }
        case 9:guardar();
        return 0;

         default: std::cout << "Opcion invalida. Intente de nuevo. \n";
    }
    }while (true);
}
