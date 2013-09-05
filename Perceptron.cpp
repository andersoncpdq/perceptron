#include "perceptron.h"
#define myrand ((float)(random())/(float)(RAND_MAX) ) //macro myrand: gera numeros float entre 0 e 1.

perceptron::perceptron() {

	cout << endl << " =========== Perceptron Simples construído =========== " << endl << endl;

	n_epocas = 0;
	tx_aprendizagem = 0.5;
	n_entradas = n_pesos = 3;
	n_amostras = 4;

	X = new int*[n_entradas];
	D = new int[n_amostras];
	Y = new int[n_amostras];
	W = new float[n_pesos];
	E = new int[n_amostras];
}

void perceptron::inicializar_conjunto_treinamento() {

	for (int i = 0; i < n_entradas; i++) {
		X[i] = new int[3];
	}

	X[0][0] = -1;
	X[1][0] = 0;	// Amostra 0
	X[2][0] = 0;

	X[0][1] = -1;
	X[1][1] = 1;	// Amostra 1
	X[2][1] = 0;

	X[0][2] = -1;
	X[1][2] = 0;	// Amostra 2
	X[2][2] = 1;

	X[0][3] = -1;
	X[1][3] = 1;	// Amostra 3
	X[2][3] = 1;
}

void perceptron::inicializar_pesos() {

	srand(time(NULL));

	for (int i = 0; i < n_pesos; i++) {
		//W[i] = myrand;
		W[i] = 1-i;
	}
}

void perceptron::inicializar_saidas_desejadas(int porta) {

	int p = porta;

	switch(p) {
		case 1:	// OR
			D[0] = 0;
			D[1] = 1;
			D[2] = 1;
			D[3] = 1;
			break;
		case 2:	// AND
			D[0] = 0;
			D[1] = 0;
			D[2] = 0;
			D[3] = 1;
			break;
		case 3:	// NOR
			D[0] = 1;
			D[1] = 0;
			D[2] = 0;
			D[3] = 0;
			break;
		case 4:	// NAND
			D[0] = 1;
			D[1] = 1;
			D[2] = 1;
			D[3] = 0;
			break;
		default:
			break;
	}
}

int perceptron::degrau(double u) {

	int result = 0;

	if(u >= 0)
		result = 1;
	else
		result = 0;

	return result;
}

float perceptron::calcular_potencial(int indice_amostra) {

	float potencial = 0;

	for (int j = 0; j < n_entradas; j++) {

		potencial += (W[j] * X[j][indice_amostra]);
	}

	return potencial;
}

void perceptron::corrigir_pesos(int indice_amostra, int y) {

	int erro = (D[indice_amostra] - y);

	for (int k = 0; k < n_pesos; k++) {

		W[k] += ( tx_aprendizagem * erro * X[k][indice_amostra] );

		if(n_epocas % 200 == 0) {
			cout << "Peso :" << k << " - " << W[k] << endl;
		}
	}
}

void perceptron::fase_treinamento() {

	double u = 0;	// potencial de acao.
	int y = 0;		// saida calculada.
	int d = 0;		// saida desejada.

	do {

		for (int i = 0; i < n_amostras; i++) {

			d = D[i];

			u = calcular_potencial(i);
			y = degrau(u);

			if(y != d) {
				corrigir_pesos(i, y);
			}
		}
		n_epocas++;

	} while(n_epocas <= 1000);
}

void perceptron::fase_operacao(int x1, int x2) {

	double u = 0;
	int y = 0, bias = -1;
	int entrada[3];

	entrada[0] = bias;
	entrada[1] = x1;
	entrada[2] = x2;

	for(int i = 0; i < n_entradas; i++) {
		u += W[i] * entrada[i];
	}

	y = degrau(u);

	cout << "(" << x1 << ", " << x2 << ") ---> " << "Saida: " << y << endl;
}

void perceptron::print_pesos() {

	cout << "Pesos = [ ";
	for (int k = 0; k < n_pesos; k++) {
		cout << W[k] << " ";
	}
	cout << "]";
	cout << endl << endl;
}

void perceptron::print_saidas_desejadas() {

	cout << "Saidas Desejadas = [ ";
	for (int i = 0; i < n_amostras; i++) {
		cout << D[i] << " ";
	}
	cout << "]" << endl;
}

perceptron::~perceptron() {
	cout << endl << " =========== Perceptron Simples destruído =========== " << endl;
}
