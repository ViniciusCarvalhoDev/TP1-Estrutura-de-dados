#ifndef FILA_H
#define FILA_H
#include "Celula.hpp"

template <typename T>
class Fila
{
public:
	Fila();
	~Fila();
	void Enfileirar(T item);
	void Desenenfileirar();
	void Limpar();
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
		tamanho++;
	}
	else
	{
		tras->prox = temporaria;
		tras = temporaria;
		tamanho++;
	}

}
template <typename T>
void Fila<T>::Desenenfileirar() {
	if (IsVazia())
	{
		throw "Fila está vazia!";
	}
	else if (frente == tras)
	{
		delete frente;
		frente = tras = nullptr;
		tamanho--;
	}
	else
	{
		Celula<T>* temporaria = frente;
		frente = frente->prox;
		delete temporaria;
		tamanho--;
	}
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


#endif