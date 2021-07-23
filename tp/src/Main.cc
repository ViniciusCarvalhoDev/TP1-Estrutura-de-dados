#include <iostream>
#include <string>
#include "Fila.hpp"

int main()
{   
    Fila<std::string> minhaFila;

    std::string oi0 = "a";
    std::string oi1 = "b";
    std::string oi2 = "c";
    std::string oi3 = "d";
    std::string oi4 = "e";
    std::string oi5 = "s";

    minhaFila.Enfileirar(oi0);
    minhaFila.Enfileirar(oi1);
    minhaFila.Enfileirar(oi2);
    minhaFila.Enfileirar(oi3);
    minhaFila.Enfileirar(oi4);

    std::cout << "Whas up motherfuckers!\n" << std::endl;
    minhaFila.Imprimir();
    minhaFila.Tamanho();

    std::cout << minhaFila.Recupera(3) << std::endl;
    minhaFila.Imprimir();
    minhaFila.FurarFila(oi5);
    minhaFila.Imprimir();
    minhaFila.Remover(1);
    minhaFila.Imprimir();
    minhaFila.~Fila();
    return 0;

}
