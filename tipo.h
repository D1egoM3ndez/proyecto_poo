#ifndef TIPO1_H
#define TIPO1_H

#include <string>
#include <iostream>

class Tipo{
    private:
        
        std::string nombre;
        std::string ventajas[5];
        std::string debilidades[5];
        int max_ven;
        int max_deb;

    public:

        Tipo(){
            nombre = "";
            max_ven = 0;
            max_deb = 0;
        };
        Tipo(std::string nom){
            nombre = nom;
            max_ven = 0;
            max_deb = 0;
        }

        std::string get_nombre(){
            return nombre;
        }

        void set_nombre(std::string nom){
            nombre = nom;
        }

        void agregar_ventaja(std::string type){
            if (max_ven < 5){
                ventajas[max_ven] = type;
                max_ven++;
            }
        }

        void agregar_debilidad(std::string type){
            if (max_deb < 5){
                debilidades[max_deb] = type;
                max_deb++;
            }
        }

        void mostrar_ventajas(){
            for (int i=0; i<max_ven; i++){
                std::cout << ventajas[i]<< std::endl;
            }
        }

        void mostrar_debilidades(){
            for (int i=0; i<max_deb; i++){
                std::cout << debilidades[i]<< std::endl;
            }
        }
};
#endif