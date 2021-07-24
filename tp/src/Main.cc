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

    while (std::fgets(buf, sizeof buf, arquivo) != nullptr){

        if(aux == 0){
            temporaria = buf;
            quantidadeDeServidores = std::stoi(temporaria.substr(0,1));
        }
        aux++;
    }

    fclose (arquivo);

    Fila<std::string> servidores[quantidadeDeServidores];

    arquivo = fopen(argv[1],"rt");

    aux = 0;
    while (std::fgets(buf, sizeof buf, arquivo) != nullptr) {

        if(aux != 0){

             temporaria = buf;
             input = temporaria.substr(0,4);
            
            if(input == "INFO"){
                numeroDoServidor = std::stoi(temporaria.substr(4,4));
                std::string conteudo = temporaria.substr(8,temporaria.length()-10);
                servidores[numeroDoServidor].Enfileirar(conteudo);
                
            }if(input == "WARN"){
                numeroDoServidor = std::stoi(temporaria.substr(4,4));
                int posicao = std::stoi(temporaria.substr(6,6));
              
                std::string temp = servidores[numeroDoServidor].Recupera(posicao);

                servidores[numeroDoServidor].Remover(posicao);
                servidores[numeroDoServidor].FurarFila(temp);

            }if(input == "TRAN"){

                numeroDoServidor = std::stoi(temporaria.substr(4,4));
                int numeroDoServidor2 = std::stoi(temporaria.substr(6,6));
                
                for(int i = 0; i < servidores[numeroDoServidor].Tamanho(); i++){
                    servidores[numeroDoServidor2].Enfileirar(servidores[numeroDoServidor].Recupera(i));
                }

                servidores[numeroDoServidor2].Limpar();

            } if(input == "ERRO"){
                numeroDoServidor = std::stoi(temporaria.substr(4,4));

                std::cout << "ERRO " << numeroDoServidor << std::endl;

                servidores[numeroDoServidor].Imprimir();
                servidores[numeroDoServidor].Limpar();
               

            } if(input == "SEND"){
                for (int i = 0; i < quantidadeDeServidores; i++)
                {
                    historico.Enfileirar(servidores[i].Recupera(0));
                    servidores[i].Desenenfileirar();
                }

            }if(input == "FLUS"){

                historico.Imprimir();

                for (int i = 0; i < quantidadeDeServidores; i++)
                {
                    servidores[i].Imprimir();
                }
                
            }
        }

        aux++;
    }

    fclose (arquivo);
    return 0;

}
