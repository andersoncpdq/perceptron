#include "perceptron.h"

int main() {

	perceptron p;

	/*
	 *	1 - OR
	 *	2 - AND
	 *	3 - NOR
	 *	4 - NAND
	 */
	int porta = 1;

	p.inicializar_conjunto_treinamento();
	p.inicializar_saidas_desejadas(porta);
	p.inicializar_pesos();

	cout << "# ANTES do treinamento:" << endl << endl;
	p.print_pesos();

	p.fase_treinamento();

	cout << "# APOS o treinamento:" << endl << endl;
	p.print_pesos();

	p.print_saidas_desejadas();

	cout << endl << "# Testes:" << endl << endl;
	p.fase_operacao(0, 0);
	p.fase_operacao(1, 0);
	p.fase_operacao(0, 1);
	p.fase_operacao(1, 1);

	return 0;
}
