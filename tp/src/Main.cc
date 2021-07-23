#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "Fila.hpp"

int main(int argc, char *argv[])
{   
    std::string linha;
    std::string input;
    std::string temporaria;

    int numeroDoServidor;
    int quantidadeDeServidores;
    int aux = 0;

    Fila<std::string> historico;
    
    FILE* arquivo = fopen(argv[1],"rt");

    char buf[100];
    while (std::fgets(buf, sizeof buf, arquivo) != nullptr) {

        if(aux == 0){
            std::cout << buf << '\n';
        }else{
             temporaria = buf;
            input = temporaria.substr(0,4);

            if(input == "INFO"){
                std::cout << "info" << '\n';
            }else if(input == "WARN"){
                std::cout << "warn" << '\n';
            }else if(input == "TRAN"){
                std::cout << "tran" << '\n';
            }else if(input == "ERRO"){
                std::cout << "erro" << '\n';
            }else if(input == "SEND"){
                std::cout << "send" << '\n';
            }else{
                std::cout << "flush" << '\n';
            }
        }
        
        aux++;
    }

    return 0;

}
