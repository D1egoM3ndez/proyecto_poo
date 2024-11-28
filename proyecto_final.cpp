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

// Función para validar entrada del usuario
int valida_entrada(int min, int max) {
    std::string entrada;
    int num = 0;
    bool es_valido = false;

    while (!es_valido) {
        std::cout << "Introduce un numero entre " 
        << min << " y " << max << ": ";
        std::cin >> entrada;
        // Verificar que todos los caracteres sean dígitos
        es_valido = true;
        for (char c : entrada) {
            if (!std::isdigit(c)) {
                es_valido = false;
                break;
            }
        }
        // Si es válido, convertir a entero y verificar rango
        if (es_valido) {
            num = std::stoi(entrada);
            es_valido = (num >= min && num <= max);
        }
        if (!es_valido) {
            std::cout << "Entrada invalida." << std::endl;
        }
    }
    return num;
}

// Función para ejecutar el turno del jugador
void ejecutar_turno_jugador(Pokemon &jugador, Pokemon &bot) {
    std::cout << "Elige un ataque" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i << ".- " << jugador.get_ataque(i).get_nombre() 
        << std::endl;
    }

    int num = valida_entrada(0 , 2);

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
void ejecutar_turno_bot(Pokemon &bot, Pokemon &jugador) {
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

    // Declaración de tipos y configuración inicial de ventajas y debilidades
    Tipo fuego("Fuego");
    Tipo agua("Agua");
    Tipo planta("Planta");
    Tipo normal("Normal");
    Tipo elec("Eléctrico");
    Tipo tierra("Tierra");
    Tipo hielo("Hielo");
    Tipo bicho("Bicho");
    Tipo volador("Volador");
    Tipo veneno("Veneno");

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
    volador.agregar_ventaja("Tierra");

    volador.agregar_debilidad("Eléctrico");
    volador.agregar_debilidad("Hielo");

    veneno.agregar_ventaja("Planta");

    veneno.agregar_debilidad("Tierra");

    //Creacion de ataques

    Ataque pla1("Hoja Afilada", 60.0, 100, planta);
    Ataque pla2("Absorber", 40.0, 100, planta);
    Ataque pla3("Follaje", 50.0, 90, planta);

    Ataque fue1("Llamarada", 90.0, 85, fuego);
    Ataque fue2("Ascuas", 40.0, 100, fuego);
    Ataque fue3("Lanzallamas", 90.0, 80, fuego);

    Ataque agua1("Rayo Burbuja", 70.0, 95, agua);
    Ataque agua2("Agua Lodosa", 80.0, 85, agua);
    Ataque agua3("Buceo", 80.0, 80, agua);

    Ataque nor1("Golpe", 60.0, 80, normal);
    Ataque nor2("Agarron", 40.0, 100, normal);
    Ataque nor3("Atadura", 50.0, 85, normal);
    Ataque nor4("Amago", 60.0, 70, normal);
    Ataque nor5("Placaje", 50.0, 90, normal);
    Ataque nor6("Hiper rayo", 70.0, 60, normal);

    Ataque elec1("Chispa", 70.0, 90, elec);
    Ataque elec2("Colmillo Rayo", 70.0, 95, elec);
    Ataque elec3("Trueno", 80.0, 75, elec);

    Ataque tie1("Excavar", 60.0, 90, tierra);
    Ataque tie2("Huesomerang", 70.0, 75, tierra);
    Ataque tie3("Terremoto", 90.0, 50, tierra);

    Ataque hie1("Bola de Nieve", 50.0, 90, hielo);
    Ataque hie2("Chuzos", 70.0, 65, hielo);
    Ataque hie3("Granizo", 60.0, 85, hielo);

    Ataque bic1("Chupavidas", 30.0, 100, bicho);
    Ataque bic2("Megacuerno", 60.0, 70, bicho);
    Ataque bic3("Picadura", 50.0, 90, bicho);

    Ataque vol1("Acrobata", 60.0, 90, volador);
    Ataque vol2("Aire Afilado", 60.0, 90, volador);
    Ataque vol3("Ataque Ala", 60.0, 80, volador);

    Ataque ven1("Toxico", 60.0, 90, veneno);
    Ataque ven2("Bomba Acida", 70.0, 75, veneno);
    Ataque ven3("Cola Veneno", 90.0, 50, veneno);

    // Creación de Pokémon
    Pokemon venusaur("Venusaur", "Ruta 2", 36, 150.0, planta);
    venusaur.agregar_ataq(pla1);
    venusaur.agregar_ataq(pla2);
    venusaur.agregar_ataq(pla3);

    Pokemon charizard("Charizard", "Ruta 5", 35, 160.0, fuego);
    charizard.agregar_ataq(fue1);
    charizard.agregar_ataq(fue2);
    charizard.agregar_ataq(fue3);

    Pokemon blastoise("Blastoise", "Ruta 4", 36, 160, agua);
    blastoise.agregar_ataq(agua1);
    blastoise.agregar_ataq(agua2);
    blastoise.agregar_ataq(agua3);

    Pokemon snorlax("Snorlax", "Ruta 22", 32, 190.0, normal);
    snorlax.agregar_ataq(nor1);
    snorlax.agregar_ataq(nor2);
    snorlax.agregar_ataq(nor3);

    Pokemon raichu("Raichu", "Ruta 3", 34, 140.0, elec);
    raichu.agregar_ataq(elec1);
    raichu.agregar_ataq(elec2);
    raichu.agregar_ataq(elec3);

    Pokemon marowak("Marowak", "Monte lunar", 33, 160.0, tierra);
    marowak.agregar_ataq(tie1);
    marowak.agregar_ataq(tie2);
    marowak.agregar_ataq(tie3);

    Pokemon lapras("Lapras", "Playa", 35, 170.0, hielo);
    lapras.agregar_ataq(hie1);
    lapras.agregar_ataq(hie2);
    lapras.agregar_ataq(hie3);

    Pokemon beedrill("Beedrill", "Ruta 1", 33, 150.0, bicho);
    beedrill.agregar_ataq(bic1);
    beedrill.agregar_ataq(bic2);
    beedrill.agregar_ataq(bic3);

    Pokemon pidgeot("Pidgeot", "Ruta 6", 37, 150.0, volador);
    pidgeot.agregar_ataq(vol1);
    pidgeot.agregar_ataq(vol2);
    pidgeot.agregar_ataq(vol3);

    Pokemon nidoking("Nidoking", "Ruta 7", 35, 180.0, veneno);
    nidoking.agregar_ataq(ven1);
    nidoking.agregar_ataq(ven2);
    nidoking.agregar_ataq(ven3);

    Pokemon persian("Persian", "Calle Victoria", 36, 150.0, normal);
    persian.agregar_ataq(nor4);
    persian.agregar_ataq(nor5);
    persian.agregar_ataq(nor6);

    // Creación de entrenadores
    Entrenador ent1("Rojo", "Pueblo Paleta", 10);
    ent1.agregar_poke(venusaur);
    ent1.agregar_poke(raichu);
    ent1.agregar_poke(lapras);

    Entrenador ent2("Azul", "Ciudad Carmin", 10);
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

    int num = valida_entrada(0, 2);

    Entrenador player = arr[num];

    std::cout << "Claro!, como olvidar tu nombre " << player.get_nombre() 
    << std::endl;

    player.info();

    imprimir_separador();

    std::cout << "Estas a punto de embarcarte en una aventura inimaginable" 
    << std::endl;
    std::cout << "Para empezar, elige a tu amigo: " << std::endl;

    std::cout << "Selecciona a tu pokemon" << std::endl;
    std::cout << "0.- " << player.get_poke(0).get_nombre() << "\n1.- "
    << player.get_poke(1).get_nombre() << "\n2.- " 
    << player.get_poke(2).get_nombre() << std::endl;

    int n = valida_entrada(0, 2);

    Pokemon poke = player.get_poke(n); 
    
    std::cout << poke.mostrar() << std::endl;

    std::cout << "Quieres ponerle un apodo a tu Pokemon?" << std::endl;
    std::cout << "Si = 1" << std::endl;
    std::cout << "No = 2" << std::endl;

    int dec;
    std::string nom;
    std::cin >> dec;

    if (dec == 1){
        std::cout << "Como quieres que se llame?: " << std::endl;
        std::cin >> nom;
        poke.set_nombre(nom);
    }
    else{
        std::cout << "Ok, sigamos" << std::endl;
    }
    
    imprimir_separador();

    std::cout << player.get_nombre() << " y " << poke.get_nombre() 
    << ", juntos haran grandes cosas." << std::endl;

    std::cout << "Bueno, a comenzar." << std::endl;

    imprimir_separador();

    std::cout << "Un entrenador te esta retando!!" << std::endl;

    Entrenador bot("Gary", "Liga Pokémon", 15);
    bot.agregar_poke(nidoking);
    bot.agregar_poke(persian);

    Pokemon poke_bot;

    int botp = std::rand() % 2;
    if (botp == 0){
        poke_bot = bot.get_poke(0);
    }
    else{
        poke_bot = bot.get_poke(1);
    }

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