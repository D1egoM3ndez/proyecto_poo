#include<string>

class Ataque{
    private:
        
        std::string nombre;
        int poder;
        int precision;
        std::string tipo;
    
    public:

        Ataque();
        Ataque(std::string nom, int p, int pr, std::string type):
        nombre(nom), poder(p), precision(pr), tipo(type){};

        std::string get_nombre();
        int get_poder();
        int get_precision();
        std::string get_tipo();

        void set_nombre(std::string);
        void set_poder(int);
        void set_precision(int);
        void set_tipo(std::string);

        bool usar();
};

bool Ataque::usar(){
    if (precision > 0){
        precision = precision - 10;
        return true;
    }
    else{
        precision = precision;
        return false;
    }
}

Ataque::Ataque(){
    nombre = "";
    poder = 0;
    precision = 0;
    tipo = "";
}

std::string Ataque::get_nombre(){
    return nombre;
}

int Ataque::get_poder(){
    return poder;
}

int Ataque::get_precision(){
    return precision;
}

std::string Ataque::get_tipo(){
    return tipo;
}

void Ataque::set_nombre(std::string nom){
    nombre = nom;
}

void Ataque::set_poder(int p){
    poder = p;
}

void Ataque::set_precision(int pr){
    precision = pr;
}

void Ataque::set_tipo(std::string type){
    tipo = type;
}