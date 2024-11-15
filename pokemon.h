#ifndef POKEMON_PERSONAJE_H
#define POKEMON_PERSONAJE_H

#include <iostream>
#include <string>
#include "personaje.h"
#include "ataque.h"
#include "tipo.h"

class Pokemon: public Personaje{
    private:
        
        int vida;
        Tipo tipo;
        Ataque ataques[4];
        int max_ataq;
    
    public:
        
        Pokemon() : Personaje(){
            vida = 0;
            max_ataq = 0;
        };
        Pokemon(std::string nom, std::string city, int lv, int hp, Tipo type):
        Personaje(nom, city, lv){
            vida = hp;
            tipo = type;
            max_ataq = 0;
        };

        
        int get_vida(){
            return vida;
        }

        
        void set_vida(int hp){
            if (hp < 0){
                std::cout << "Entrada no válida" << std::endl;
            }
            else {
            vida = hp;
            }
        }


        void agregar_ataq(Ataque atq){
            if (max_ataq < 4){  
                ataques[max_ataq] = atq;
                max_ataq++;
            }
        }

        void quitar_ataque(int posicion){
             if (posicion < 0 || posicion >= max_ataq) {
                std::cout << "Posición no válida." << std::endl;
                return;
                }
            for (int i = posicion; i < max_ataq - 1; i++) {
                ataques[i] = ataques[i + 1];
            }
            --max_ataq;
        }

        void mostrar_ataques(){
            for (int i=0; i<max_ataq; i++){
                std::cout << ataques[i].get_nombre() << std::endl;
            }
        }
};
#endif