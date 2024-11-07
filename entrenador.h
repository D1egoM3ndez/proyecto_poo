#include<string>

class Entrenador{
    private:
        
        std::string nombre;
        std::string ciudad;
        std::string tipo;

    public:

        Entrenador();
        Entrenador(std::string nom, std::string city, std::string type):
        nombre(nom), ciudad(city), tipo(type){};

        std::string get_nombre();
        std::string get_ciudad();
        std::string get_tipo();

        void set_nombre(std::string);
        void set_ciudad(std::string);
        void set_tipo(std::string);
};

Entrenador::Entrenador(){
    nombre = "";
    ciudad = "";
    tipo = "";
}

std::string Entrenador::get_nombre(){
    return nombre;
}

std::string Entrenador::get_ciudad(){
    return ciudad;
}

std::string Entrenador::get_tipo(){
    return tipo;
}

void Entrenador::set_nombre(std::string nom){
    nombre = nom;
}

void Entrenador::set_ciudad(std::string city){
    ciudad = city;
}

void Entrenador:: set_tipo(std::string type){
    tipo = type;
}