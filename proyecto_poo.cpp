#include <iostream>
#include <string>
#include "personaje.h"
#include "tipo.h"
#include "ataque.h"
#include "pokemon.h"
#include "entrenador.h"

int main() {
    
    Tipo tipoFuego("Fuego");
    Tipo tipoAgua("Agua");
    Tipo tipoPlanta("Planta");
    
    tipoFuego.agregar_ventaja("Planta");
    tipoAgua.agregar_ventaja("Fuego");
    tipoPlanta.agregar_ventaja("Agua");

    Ataque ataque1("Llamarada", 90, 85, tipoFuego);
    Ataque ataque2("Rayo burbuja", 70, 95, tipoAgua);
    Ataque ataque3("Hoja Afilada", 55, 100, tipoPlanta);

    Pokemon charmander("Charmander", "Ciudad Cañón", 5, 50, tipoFuego);
    charmander.agregar_ataq(ataque1);
    charmander.agregar_ataq(ataque2);

    Pokemon squirtle("Squirtle", "Ciudad Aguacero", 5, 55, tipoAgua);
    squirtle.agregar_ataq(ataque2);
    squirtle.agregar_ataq(ataque3);

    Entrenador ash("Ash Ketchum", "Pueblo Paleta", 10);
    ash.agregar_poke(charmander);
    ash.agregar_poke(squirtle);

    std::cout << "Entrenador: " << ash.get_nombre() << std::endl;
    ash.mostrar_equipo(); 

    std::cout << "\nAtaques de " << charmander.get_nombre() << ":\n";
    charmander.mostrar_ataques();

    std::cout << "\nVentajas de " << tipoFuego.get_nombre() << ":\n";
    tipoFuego.mostrar_ventajas();

    return 0;
}

