#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>

class Personaje{
    protected:
        
        std::string nombre;
        std::string lugar;
        int nivel;

    public:
        
        Personaje(){
            nombre = "";
            lugar = "";
            nivel = 0;
        }

        Personaje(std::string nom, std::string city, int lv){
            nombre = nom;
            lugar = city;
            nivel = lv;
        }

        
        std::string get_nombre(){
            return nombre;
        }
        std::string get_lugar(){
            return lugar;
        }
        int get_nivel(){
            return nivel;
        }

        
        void set_nombre(std::string nom){
            nombre = nom;
        }
        void set_lugar(std::string city){
            lugar = city;
        }
        void set_nivel(int lv){
            nivel = lv;
        }

        
        void aumento_lv(){
            nivel++;
        }

        
        void mostrar(){
            std::cout << "Nombre" << nombre << std::endl;
            std::cout << "Lugar" << lugar << std::endl;
            std::cout << "Nivel" << nivel << std::endl;
        }
};
#endif