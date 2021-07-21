#ifndef CELULA_H
#define CELULA_H
#include <cstdlib>

template <typename T>
class Celula {

	public:
		Celula();
		Celula(T);
		T recuperaDado();
		T dado;
		Celula<T> *prox;

};

template <typename T>
Celula<T>::Celula()
{
	dado = NULL;
	prox = nullptr;
}

template <typename T>
Celula<T>::Celula(T dadoDeEntrada)
{
	dado = dadoDeEntrada;
	prox = nullptr;
}

template <typename T>
T Celula<T>::recuperaDado() {
	return dado;
}

#endif // CELULA_H

