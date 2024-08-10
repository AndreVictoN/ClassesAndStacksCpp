/*
 * Pilha.hpp
 *
 *  Created on: 06 de ago. de 2024
 *      Author: user
 */

#ifndef PILHAALUNOS_HPP_
#define PILHAALUNOS_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Alunos.hpp"

using namespace std;

#define InicioArranjo   1
#define MaxTam 100

class PilhaAlunos {
private:
	int base, topo, limite;
	int pilha[MaxTam];
public:
	PilhaAlunos() {
		inicializarPilha();
	}

	void inicializarPilha() {
		base = 1;
		topo = base - 1;
		limite = 10;
	}

	bool inserirPilha(int valor) {
		if (topo < limite) {
			topo++;
			pilha[topo] = valor;
			return true;
		}
		return false;
	}

	bool removerPilha(int *valorRemovido) {
		if (topo >= base) {
			*valorRemovido = pilha[topo];
			topo--;
			return true;
		}
		return false;
	}

	bool consultarPilhaAluno(int *valor) {
		if (topo >= base) {
			*valor = pilha[topo];
			return true;
		}
		return false;
	}

	//Única alteração feita no código da pilha, apenas para liberar a memória.
	~PilhaAlunos(){
		free(pilha);
	}

};

int testePilhaAlunos() {

	PilhaAlunos pilha;
	bool sucesso;
	int item;
	int max = 11;
	int alunoConsultado = 0;
	vector<Alunos> alunos;
	vector<string> nomes = {"André", "Alisson", "Isaque", "Pietro", "Rômulo", "Rebecca", "João", "Alessandro", "Hevillyn", "Davi"};

	/*Insere cada chave na lista */
	for (int i = 1; i < max; i++) {
		Alunos aluno;
		item = i;
		if (pilha.inserirPilha(item)) {
			aluno.setNumAluno(item);
			alunos.push_back(aluno);
			alunos[i - 1].setNome(nomes[i - 1]);
			cout << "Empilhou Aluno: " << alunos[i - 1].getNome() << endl;
		} else {
			cout << "Não empilhou Aluno: " << item << endl;
		}
	}

	sucesso = pilha.consultarPilhaAluno(&alunoConsultado);

	if(sucesso){
		cout << "O primeiro aluno da pilha é: " << alunos[alunoConsultado - 1].getNome() << endl;
	}else{
		cout << "Não foi possível acessar a pilha" << endl;
	}

	/*Retira cada chave da lista */
	while (pilha.removerPilha(&item) == true) {
		/*retira chave apontada */
		cout << "Desempilhou Aluno: " << alunos[item - 1].getNome() << endl;

		alunos.pop_back();
	}

	return 0;
}
#endif /* PILHAALUNOS_HPP_ */
