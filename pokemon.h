#include <string>

class Pokemon{
    private:
        
        std::string nombre;
        int nivel;
        int vida;
        std::string tipo;

    public:
        
        Pokemon();
        Pokemon(std::string nom, int lv, int hp, std::string type):
        nombre(nom) , nivel(lv), vida(hp), tipo(type){};

        std::string get_nombre();
        int get_nivel();
        int get_vida();
        std::string get_tipo();

        void set_nombre(std::string);
        void set_nivel(int);
        void set_vida(int);
        void set_tipo(std::string);

        void entrenar();
};

void Pokemon::entrenar(){
    nivel++;
}

Pokemon::Pokemon(){
    nombre = "";
    nivel = 0;
    vida = 0;
    tipo = "";
}

std::string Pokemon::get_nombre(){
    return nombre;
}

int Pokemon::get_nivel(){
    return nivel;
}

int Pokemon::get_vida(){
    return vida;
}

std::string Pokemon::get_tipo(){
    return tipo;
}

void Pokemon::set_nombre(std::string nom){
    nombre = nom;
}

void Pokemon::set_nivel(int lv){
    nivel = lv;
}

void Pokemon::set_vida(int hp){
    vida = hp;
}

void Pokemon::set_tipo(std::string type){
    tipo = type;
}