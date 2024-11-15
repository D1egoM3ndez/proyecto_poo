#ifndef ATAQUE_POKEMON_H
#define ATAQUE_POKEMON_H

#include <string>
#include "tipo.h"

class Ataque{
    private:
        
        std::string nombre;
        int poder;
        int precision;
        Tipo tipo;

    public:

        Ataque(){
            nombre = "";
            poder = 0;
            precision = 0;
        };
        Ataque(std::string nom, int pw, int pre, Tipo type){
            nombre = nom;
            poder = pw;
            precision = pre;
            tipo = type;
        }

        
        std::string get_nombre(){
            return nombre;
        }
        int get_poder(){
            return poder;
        }
        int get_precision(){
            return precision;
        }

       
        void set_nombre(std::string nom){
            nombre = nom;
        }
        void set_poder(int pw){
            poder = pw;
        }
        void set_precision(int pre){
            precision = pre;
        }

        
        bool usar_ataq(){
            if (precision > 0){
                return true;
            }
            else{
                return false;
            }
        }
};
#endif