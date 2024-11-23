//Diego Méndez Morales
//A01713173
//Proyecto Programación Orientado a Objetos
//Simulador de batalla Pokémon, el usuario tiene la oportunidad de escoger
//su entrenador favorito para después pelear contra la máquina

//Bibliotecas
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//Headers ocupados
#include "personaje_final.h"
#include "tipo_final.h"
#include "ataque_final.h"
#include "pokemon_final.h"
#include "entrenador_final.h"

// Función para ejecutar el turno del jugador
void ejecutar_turno_jugador(Pokemon &jugador, Pokemon &bot) {
    std::cout << "Elige un ataque" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i << ".- " << jugador.get_ataque(i).get_nombre() 
        << std::endl;
    }

    int num;
    std::cin >> num;
    while (num < 0 || num > 2) {
        std::cout << "Selecciona un numero entre 0 y 2: ";
        std::cin >> num;
    }

    Ataque ataq = jugador.get_ataque(num);
    Tipo tipo_ataque = ataq.get_tipo();
    Tipo tipo_objetivo = bot.get_tipo();

    int compatible = tipo_ataque.multiplica(tipo_objetivo.get_nombre());

    std::cout << jugador.get_nombre() << " ha usado " << ataq.get_nombre()
    << std::endl;
    
    if (compatible == 1.5){
        std::cout << "Es super eficaz!!"<< std::endl;
    }
    else if (compatible  == 0.5){
        std::cout << "Es poco eficaz" << std::endl;
    }
    else{
        std::cout << "Ataque fuerte" << std::endl;
    }
    
    int dano_total = ataq.get_poder() * compatible;
    bot.recibe_dano(dano_total);

    std::cout << "Vida de " << bot.get_nombre() << " es ahora de " 
    << bot.get_vida() << std::endl;
}

// Función para ejecutar el turno del bot
void ejecutar_turno_bot(Pokemon& bot, Pokemon& jugador) {
    int num_ataque_bot = std::rand() % 3;
    Ataque ataque = bot.get_ataque(num_ataque_bot);
    Tipo tipo_ataque = ataque.get_tipo();
    Tipo tipo_objetivo = jugador.get_tipo();

    int compatible = tipo_ataque.multiplica(tipo_objetivo.get_nombre());

    std::cout << bot.get_nombre() << " ha usado " << ataque.get_nombre()
    << std::endl;
    
    if (compatible == 1.5){
        std::cout << "Es super eficaz!!"<< std::endl;
    }
    else if (compatible  == 0.5){
        std::cout << "Es poco eficaz" << std::endl;
    }
    else{
        std::cout << "Ataque neutro" << std::endl;
    }
   
    int dano_total = ataque.get_poder() * compatible;
    jugador.recibe_dano(dano_total);

    std::cout << "Nueva vida de " << jugador.get_nombre() << " es de " 
    << jugador.get_vida() << std::endl;
}

// Función para imprimir separadores
void imprimir_separador() {
    std::cout << "--------------------------" << std::endl;
}

int main() {
    std::srand(std::time(0)); // Inicializar generador de números aleatorios

    // Declaración de tipos y configuración inicial
    Tipo fuego("Fuego");
    Tipo agua("Agua");
    Tipo planta("Planta");
    Tipo normal("Normal");
    Tipo elec("Eléctrico");
    Tipo tierra("Tierra");
    Tipo hielo("Hielo");
    Tipo bicho("Bicho");
    Tipo volador("Volador");

    fuego.agregar_ventaja("Planta");
    fuego.agregar_ventaja("Bicho");
    fuego.agregar_ventaja("Hielo");

    fuego.agregar_debilidad("Tierra");
    fuego.agregar_debilidad("Agua");

    agua.agregar_ventaja("Fuego");
    agua.agregar_ventaja("Tierra");

    agua.agregar_debilidad("Eléctrico");
    agua.agregar_debilidad("Planta");


    planta.agregar_ventaja("Agua");
    planta.agregar_ventaja("Tierra");

    planta.agregar_debilidad("Fuego");
    planta.agregar_debilidad("Hielo");
    planta.agregar_debilidad("Bicho");

    elec.agregar_ventaja("Agua");
    
    elec.agregar_debilidad("Tierra");

    tierra.agregar_ventaja("Fuego");
    tierra.agregar_ventaja("Eléctrico");

    tierra.agregar_debilidad("Agua");
    tierra.agregar_debilidad("Planta");
    tierra.agregar_debilidad("Hielo");

    hielo.agregar_ventaja("Planta");
    hielo.agregar_ventaja("Tierra");

    hielo.agregar_debilidad("Fuego");

    bicho.agregar_ventaja("Planta");

    bicho.agregar_debilidad("Fuego");

    volador.agregar_ventaja("Planta");
    volador.agregar_ventaja("Bicho");

    volador.agregar_debilidad("Eléctrico");
    volador.agregar_debilidad("Hielo");

    // Creación de Pokémon
    Pokemon venusaur("Venusaur", "Ruta 2", 36, 150.0, planta);
    venusaur.agregar_ataq(Ataque ("Hoja Afilada", 60.0, 100, planta));
    venusaur.agregar_ataq(Ataque ("Absorber", 40.0, 100, planta));
    venusaur.agregar_ataq(Ataque ("Follaje", 50.0, 90, planta));

    Pokemon charizard("Charizard", "Ruta 5", 35, 160.0, fuego);
    charizard.agregar_ataq(Ataque ("Llamarada", 90.0, 85, fuego));
    charizard.agregar_ataq(Ataque ("Ascuas", 40.0, 100, fuego));
    charizard.agregar_ataq(Ataque ("Lanzallamas", 90.0, 80, fuego));

    Pokemon blastoise("Blastoise", "Ruta 4", 36, 160, agua);
    blastoise.agregar_ataq(Ataque ("Rayo Burbuja", 70.0, 95, agua));
    blastoise.agregar_ataq(Ataque ("Agua Lodosa", 80.0, 85, agua));
    blastoise.agregar_ataq(Ataque ("Buceo", 80.0, 80, agua));

    Pokemon snorlax("Snorlax", "Ruta 22", 32, 190.0, normal);
    snorlax.agregar_ataq(Ataque ("Golpe", 60.0, 80, normal));
    snorlax.agregar_ataq(Ataque ("Agarron", 40.0, 100, normal));
    snorlax.agregar_ataq(Ataque ("Atadura", 50.0, 85, normal));

    Pokemon raichu("Raichu", "Ruta 3", 34, 140.0, elec);
    raichu.agregar_ataq(Ataque ("Chispa", 70.0, 90, elec));
    raichu.agregar_ataq(Ataque ("Colmillo Rayo", 70.0, 95, elec));
    raichu.agregar_ataq(Ataque ("Trueno", 80.0, 75, elec));

    Pokemon marowak("Marowak", "Monte lunar", 33, 160.0, tierra);
    marowak.agregar_ataq(Ataque ("Excavar", 60.0, 90, tierra));
    marowak.agregar_ataq(Ataque ("Huesomerang", 70.0, 75, tierra));
    marowak.agregar_ataq(Ataque ("Terremoto", 90.0, 50, tierra));

    Pokemon lapras("Lapras", "Playa", 35, 170.0, hielo);
    lapras.agregar_ataq(Ataque ("Bola de Nieve", 50.0, 90, hielo));
    lapras.agregar_ataq(Ataque ("Chuzos", 70.0, 65, hielo));
    lapras.agregar_ataq(Ataque ("Granizo", 60.0, 85, hielo));

    Pokemon beedrill("Beedrill", "Ruta 1", 33, 150.0, bicho);
    beedrill.agregar_ataq(Ataque ("Chupavidas", 30.0, 100, bicho));
    beedrill.agregar_ataq(Ataque ("Megacuerno", 60.0, 70, bicho));
    beedrill.agregar_ataq(Ataque ("Picadura", 50.0, 90, bicho));

    Pokemon pidgeot("Pidgeot", "Ruta 6", 37, 150.0, volador);
    pidgeot.agregar_ataq(Ataque ("Acrobata", 60.0, 90, volador));
    pidgeot.agregar_ataq(Ataque ("Aire Afilado", 60.0, 90, volador));
    pidgeot.agregar_ataq(Ataque ("Ataque Ala", 60.0, 80, volador));

    Pokemon nidoking("Nidoking", "Ruta 7", 35, 180.0, tierra);
    nidoking.agregar_ataq(Ataque ("Bofeton Lodo", 60.0, 90, tierra));
    nidoking.agregar_ataq(Ataque ("Fuerza Equina", 70.0, 75, tierra));
    nidoking.agregar_ataq(Ataque ("Terratemblor", 90.0, 50, tierra));

    // Creación de entrenadores
    Entrenador ent1("Rojo", "Pueblo Paleta", 10);
    ent1.agregar_poke(venusaur);
    ent1.agregar_poke(raichu);
    ent1.agregar_poke(lapras);

    Entrenador ent2("Azul", "Ciudad Carmín", 10);
    ent2.agregar_poke(charizard);
    ent2.agregar_poke(snorlax);
    ent2.agregar_poke(marowak);

    Entrenador ent3("Verde", "Ciudad Celeste", 10);
    ent3.agregar_poke(blastoise);
    ent3.agregar_poke(pidgeot);
    ent3.agregar_poke(beedrill);

    Entrenador arr[3] = {ent1, ent2, ent3};

    imprimir_separador();

    //Inicio del juego

    std::cout << "Bienvenido a este maravilloso mundo" << std::endl;
    std::cout << "Donde humanos y Pokemon conviven en armonia" << std::endl;
    std::cout << "Me alegra que estes aqui..." << std::endl;
    std::cout << "Perdona, me repites tu nombre?" << std::endl;
    
    std::cout << "Selecciona tu entrenador:" << std::endl;
    std::cout << "0.- " << ent1.get_nombre() << "\n1.- " 
    << ent2.get_nombre() << "\n2.- " << ent3.get_nombre() << std::endl;

    int num;
    std::cin >> num;
    while (num < 0 || num > 2) {
        std::cout << "Por favor, selecciona un numero valido: ";
        std::cin >> num;
    }

    Entrenador player = arr[num];

    std::cout << "Claro!, como olvidar tu nombre " << player.get_nombre() 
    << std::endl;

    imprimir_separador();

    std::cout << "Estas a punto de embarcarte en una aventura inimaginable" 
    << std::endl;
    std::cout << "Para empezar, elige a tu amigo: " << std::endl;

    std::cout << "Selecciona a tu pokemon" << std::endl;
    std::cout << "0.- " << player.get_poke(0).get_nombre() << "\n1.- "
    << player.get_poke(1).get_nombre() << "\n2.- " 
    << player.get_poke(2).get_nombre() << std::endl;

    int n;
    std::cin >> n;
    while (n < 0 || n > 2) {
        std::cout << "Por favor, selecciona un numero valido: ";
        std::cin >> n;
    }

    Pokemon poke = player.get_poke(n); 
    
    std::cout << poke.mostrar() << std::endl;
    
    imprimir_separador();

    std::cout << player.get_nombre() << " y " << poke.get_nombre() 
    << " juntos haran grandes cosas." << std::endl;

    std::cout << "Bueno, a comenzar." << std::endl;

    imprimir_separador();

    std::cout << "Un entrenador te esta retando!!" << std::endl;

    Entrenador bot("Gary", "Liga Pokémon", 15);
    bot.agregar_poke(nidoking);
    Pokemon poke_bot = bot.get_poke(0);

    std::cout << "Se trata de " << bot.get_nombre() << " con su " 
    << poke_bot.get_nombre() << "!" << std::endl;

    std::cout << poke_bot.mostrar() << std::endl;

    std::cout << "Que comience la batalla!" << std::endl;

    // Turnos
    int turno = std::rand() % 2;
    while (poke.get_vida() > 0 && poke_bot.get_vida() > 0) {
        imprimir_separador();
        if (turno == 0) {
            std::cout << "Tu turno:" << std::endl;
            ejecutar_turno_jugador(poke, poke_bot);
            turno = 1;
        } else {
            std::cout << "Turno del Bot:" << std::endl;
            ejecutar_turno_bot(poke_bot, poke);
            turno = 0;
        }
    }

    // Determinar el ganador
    imprimir_separador();
    if (poke.get_vida() > 0) {
        std::cout << "Ganaste la batalla!" << std::endl;
        player.aumento_lv();
        poke.aumento_lv();
        std::cout << "Nuevo nivel de entrenador: " 
        << player.get_nivel() << std::endl;
        std::cout << "Nuevo nivel de tu Pokemon: " 
        << poke.get_nivel() << std::endl;
    } 
    else {
        std::cout << "Perdiste la batalla. Sigue entrenando!" << std::endl;
    }

    return 0;
} 