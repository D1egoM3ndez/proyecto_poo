#include<iostream>
#include<string>
#include"pokemon.h"
#include"entrenador.h"
#include"ataque.h"

int main(){

    Pokemon pok1("Pikachu", 12, 35, "Electrico");
    std::cout << "Pokemon:" << std::endl;
    std::cout << "Nombre:" << pok1.get_nombre() << std::endl;
    std::cout << "Nivel:" << pok1.get_nivel() << std::endl;
    std::cout << "Vida:" << pok1.get_vida() << std::endl;
    std::cout << "Tipo:" << pok1.get_tipo() << std::endl;
    
    pok1.entrenar();
    std::cout << "\n" << pok1.get_nombre() << " subio de nivel" << std::endl;
    std::cout << "Nuevo nivel:" << pok1.get_nivel() << std::endl;

    Entrenador ent1("Rojo", "Celeste", "Fuego");
    std::cout << "\nEntrenador:" << std::endl;
    std::cout << "Nombre:" << ent1.get_nombre() << std::endl;
    std::cout << "Ciudad:" << ent1.get_ciudad() << std::endl;
    std::cout << "Especialista en tipo:" << ent1.get_tipo() << std::endl;

    ent1.set_ciudad("Ciudad Carmin");
    std::cout << "\n" << ent1.get_nombre() << " se fue a "<< ent1.get_ciudad() 
    << std::endl;

    Ataque atq1("Placaje", 50, 0, "Normal");
    std::cout << "\nAtaque:" << std::endl;
    std::cout << "Nombre:" << atq1.get_nombre() << std::endl;
    std::cout << "Poder:" << atq1.get_poder() << std::endl;
    std::cout << "Presicion:" << atq1.get_precision() << std::endl;
    std::cout << "Tipo:" << atq1.get_tipo() << std::endl;

    if (atq1.usar() == true){
        std::cout << "El ataque ha acertado" << std::endl;
    }
    else{
        std::cout << "El ataque ha fallado" << std::endl;
    }

    return 0;
}