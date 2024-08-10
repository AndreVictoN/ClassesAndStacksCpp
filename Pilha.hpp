/*
 * Pilha.hpp
 *
 *  Created on: 06 de ago. de 2024
 *      Author: user
 */

#ifndef PILHA_HPP_
#define PILHA_HPP_

//AS PARTES QUE EU COMENTEI SÃO UM MÉTODO DE ADIÇÃO DE CLASSES USANDO O OPERATOR+, VECTOR E STRING

#include <iostream>
#include <cstdlib>
//#include <vector>
//#include <sstream>
//#include <string>
#include "Dados.hpp"

using namespace std;

#define InicioArranjo   1
#define MaxTam 100

class Pilha {
private:
	int base, topo, limite;
	Dados pilha[MaxTam];
public:
	Pilha() {
		inicializarPilha();
	}

	Pilha(int limite){
		this-> base = 1;
		this-> topo = base - 1;
		this-> limite = limite;
	}

	void inicializarPilha() {
		base = 1;
		topo = base - 1;
		limite = 10;
	}

	bool inserirPilha(Dados dado) {
		if (topo < limite) {
			topo++;
			pilha[topo] = dado;
			return true;
		}
		return false;
	}

	bool removerPilha(Dados *dadoRemovido) {
		if (topo >= base) {
			*dadoRemovido = pilha[topo];
			topo--;
			return true;
		}
		return false;
	}

	bool consultarPilha(Dados *dadoConsultado, int posicaoConsultada) {
		if(posicaoConsultada == -99){
			if (topo >= base) {
				*dadoConsultado = pilha[topo];
				return true;
			}
			return false;
		}else{
			if(topo >= base){
				*dadoConsultado = pilha[topo - posicaoConsultada + 1];

				return true;
			}
			return false;
		}
	}

	int getLimite(){
		return limite;
	}

	int getTopo(){
		return topo;
	}

	/*Pilha operator+(Pilha pilha){
		Pilha somaPilha;
		Dados somaDado;
		Dados consulta;
		int soma = 0;

		int dadoVelho = somaDado.getDado();

		for(int i = pilha.getLimite(); i > 0; i--){
			pilha.consultarPilha(&consulta, i);
			soma += consulta.getDado();
			somaDado.setDado(soma + dadoVelho);
		}

		somaPilha.inserirPilha(somaDado);

		return somaPilha;
	}

	string toString(){
		stringstream ss;
		Dados consulta;

		consultarPilha(&consulta, -99);

		ss << "A soma é: " << consulta.getDado() << endl;

		return ss.str();
	}*/

	~Pilha(){
		free(pilha);
	}

};

Pilha reunePilhas(Pilha* pilha1, Pilha* pilha2){
	Pilha newPilha(pilha1->getLimite() + pilha2->getLimite());
	Dados consulta;
	Dados dado;
	int contador = 0;

	for(int i = pilha1->getLimite(); i > 0; i--){
		pilha1->consultarPilha(&consulta, i - contador);
		if(newPilha.inserirPilha(consulta)){
			cout << "Empilhou newPilha: " << consulta.getDado() << endl;
		}else{
			cout << "Não empilhou newPilha: " << consulta.getDado() << endl;
		}
		pilha1->removerPilha(&dado);

		contador++;
	}

	contador = 0;

	for(int i = pilha2->getLimite(); i > 0; i--){
		pilha2->consultarPilha(&consulta, i - contador);
		if(newPilha.inserirPilha(consulta)){
			cout << "Empilhou newPilha: " << consulta.getDado() << endl;
		}else{
			cout << "Não empilhou newPilha: " << consulta.getDado() << endl;
		}
		pilha2->removerPilha(&dado);

		contador++;
	}

	return newPilha;
}

/*void somaPilhas(vector<Pilha> pilhas, string* somaString){
	Pilha soma;

	for(size_t i = 0; i < pilhas.size(); i++){
		soma = soma + pilhas[i];
	}

	*somaString = soma.toString();
}*/

int somaPilhas(Pilha* pilha1, Pilha* pilha2){
	int soma = 0;
	Dados consulta;

	for(int i = pilha1->getLimite(); i > 0; i--){
		pilha1->consultarPilha(&consulta, i);
		soma += consulta.getDado();
	}

	for(int i = pilha2->getLimite(); i > 0; i--){
		pilha2->consultarPilha(&consulta, i);
		soma += consulta.getDado();
	}

	return soma;
}

int testePilha() {

	Pilha pilha1;
	Pilha pilha2;
	int max = 11;
	Dados dado;
	Dados consulta;
	bool sucesso;

	/*vector <Pilha> pilhas;
	string somaString;*/

	/*Insere cada chave na lista */
	for (int i = 1; i < max; i++) {
		Dados dados;
		dados.setDado(i);
		if (pilha1.inserirPilha(dados)) {
			cout << "Empilhou: " << dados.getDado() << endl;
		} else {
			cout << "Não empilhou: " << dados.getDado() << endl;
		}
	}

	sucesso = pilha1.consultarPilha(&consulta, -99);

	if(sucesso){
		cout << "O último valor da pilha é: " << consulta.getDado() << endl;
	}else{
		cout << "Não foi possível consultar a pilha." << endl;
	}

	for(int i = 1; i < max; i++){
		Dados dados2;
		dados2.setDado(i + 10);
		if(pilha2.inserirPilha(dados2)){
			cout << "Empilhou piha 2: " << dados2.getDado() << endl;
		}else{
			cout << "Não empilhou pilha 2: " << dados2.getDado() << endl;
		}
	}

	sucesso = pilha2.consultarPilha(&consulta, -99);

	if(sucesso){
		cout << "O último valor da pilha 2 é: " << consulta.getDado() << endl;
	}else{
		cout << "Não foi possível consultar a pilha 2." << endl;
	}

	/*pilhas.push_back(pilha1);
	pilhas.push_back(pilha2);

	somaPilhas(pilhas, &somaString);*/

	int soma = somaPilhas(&pilha1, &pilha2);

	Pilha newPilha = reunePilhas(&pilha1, &pilha2);

	sucesso = newPilha.consultarPilha(&consulta, -99);

	if(sucesso){
		cout << "O último valor da newPilha é: " << consulta.getDado() << endl;
	}else{
		cout << "Não foi possível consultar newPilha." << endl;
	}

	//cout << somaString << endl;

	cout << "A soma é: " << soma << endl;

	/*Retira cada chave da lista */
	while (newPilha.removerPilha(&dado) == true) {
		cout << "Desempilhou: " << dado.getDado() << endl;
	}

	return 0;
}
#endif /* PILHA_HPP_ */
