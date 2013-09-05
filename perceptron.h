/*
 * percepton.h
 *
 * Perceptron Simples com somente uma camada neural e
 * um neurônio, capaz de classificar as saídas das portas
 * lógicas OR, AND, NOR e NAND.
 *
 * Created on: 27/08/2013
 * Author: Anderson Couto
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef PERCEPTON_H_
#define PERCEPTON_H_

class perceptron {

	int n_epocas, n_entradas, n_pesos, n_amostras;
	double tx_aprendizagem;

	int **X;	// conjunto de treinamento.
	int *D;		// vetor de saidas desejadas para cada amostra.
	int *Y;		// vetor de saidas calculadas para cada amostra.
	float *W;	// vetor de pesos sinapticos.
	int *E;		// Erros entre saidas desejadas e calculadas.

public:
	perceptron();
	void inicializar_conjunto_treinamento();
	void inicializar_pesos();
	void inicializar_saidas_desejadas(int porta);
	void fase_treinamento();
	void fase_operacao(int x1, int x2);
	float calcular_potencial(int indice_amostra);
	void corrigir_pesos(int indice_amostra, int y);
	int degrau(double u);
	void print_pesos();
	void print_saidas_desejadas();
	~perceptron();
};

#endif /* PERCEPTON_H_ */
