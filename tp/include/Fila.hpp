#ifndef FILA_H
#define FILA_H
#include <iostream>
#include "Celula.hpp"

template <typename T>
class Fila
{
public:
	Fila();
	~Fila();
	void Enfileirar(T item);
	void Desenenfileirar();
	void FurarFila(T item);
	void Limpar();
	void Imprimir();
	void Tamanho();
	void Remover(int pos);
	T Recupera(int i); //recupera item na posição i
private:
	int tamanho;
	Celula<T> *frente;
	Celula<T> *tras;
	bool IsVazia();
};

template <typename T>
Fila<T>::Fila() {
	frente =  nullptr;
	tras = nullptr;
	tamanho = 0;
}

template <typename T>
Fila<T>::~Fila() {
	Limpar();
}

template <typename T>
void Fila<T>::Enfileirar(T item) {

	Celula<T>* temporaria = new Celula<T>(item);

	if (IsVazia())
	{
		frente = temporaria;
		tras = frente;
	}
	else
	{
		tras->prox = temporaria;
		tras = temporaria;
	}

	tamanho++;
}
template <typename T>
void Fila<T>::Desenenfileirar() {
	if (IsVazia())
	{
		throw "Fila vazia!";
	}
	else if (frente == tras)
	{
		delete frente;
		frente = nullptr;
		tras = nullptr;
	}
	else
	{
		Celula<T>* temporaria = frente;
		frente = frente->prox;
		delete temporaria;
	}
	tamanho--;
}
template <typename T>
bool Fila<T>::IsVazia() {

	if (frente == nullptr && tras == nullptr)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
template <typename T>
void Fila<T>::Limpar() {
	while (!IsVazia() != 0)
		Desenenfileirar();
}

template <typename T>
void Fila<T>::Imprimir(){
	if(IsVazia())
	{
		std::cout << "Fila vazia" << std::endl;
	}else
	{
		Celula<T> * itemAtual = frente;

		while(itemAtual != NULL)
		{
			std::cout << itemAtual->dado << ' ';
			itemAtual = itemAtual->prox; 
		}
		std::cout << std::endl;
	}
}

template<typename T>
void Fila<T>::Tamanho(){
	std::cout << tamanho << ' ' << std::endl;
}

template<typename T>
T Fila<T>::Recupera(int i){
	int aux = 0;
	Celula<T> * itemAtual = frente;

		while(aux != i)
		{
			itemAtual = itemAtual->prox; 
			aux++;
		}
		return itemAtual->dado;
}

template<typename T>
void Fila<T>::FurarFila(T item){

	Celula<T>* temporaria = new Celula<T>(item);

	if (IsVazia())
	{
		frente = temporaria;
		tras = frente;
	}
	else
	{
		temporaria->prox = frente;
		frente = temporaria;
	}

	tamanho++;
}

template<typename T>
void Fila<T>::Remover(int pos){

	int aux = 0;
	Celula<T>* temporaria = frente;

	if (IsVazia())
	{
		throw "Fila vazia!";
	}
	if(pos == 0)
	{
		frente = temporaria->prox;
		free(temporaria);
	}
	else
	{
		while(aux != pos -1)
		{
			temporaria = temporaria->prox; 
			aux++;
		}

		if(temporaria == NULL || temporaria == nullptr || temporaria->prox == NULL || temporaria->prox == nullptr)
		{
			throw "Essa posição não pode ser alcançada";
		}

		Celula<T>* proxima = temporaria->prox->prox;
		free(temporaria->prox);
		temporaria->prox = proxima;
	}

	tamanho--;
}
#endif