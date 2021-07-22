#include <iostream>
#include <string>
#include "Fila.hpp"

int main()
{   
    Fila<std::string> minhaFila;

    std::string oi0 = "1";
    std::string oi1 = "2";
    std::string oi2 = "3";
    std::string oi3 = "4";
    std::string oi4 = "5";

    minhaFila.Enfileirar(oi0);
    minhaFila.Enfileirar(oi1);
    minhaFila.Enfileirar(oi2);
    minhaFila.Enfileirar(oi3);
    minhaFila.Enfileirar(oi4);

    std::cout << "Whas up motherfuckers!\n";
    minhaFila.Imprimir();

    minhaFila.Desenenfileirar();
    minhaFila.Imprimir();
    
    minhaFila.~Fila();
    return 0;

}
