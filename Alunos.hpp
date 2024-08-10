/*
 * Dados.hpp
 *
 *  Created on: 6 de ago. de 2024
 *      Author: user
 */

#ifndef ALUNOS_HPP_
#define ALUNOS_HPP_

#include <iostream>
#include <string>

using namespace std;

class Alunos{
private:
	int numAluno;
	string nome;
public:
	int getNumAluno(){
		return numAluno;
	}

	void setNumAluno(int matricula){
		this->numAluno  = matricula;
	}

	string getNome(){
		return nome;
	}

	void setNome(string nome){
		this->nome = nome;
	}
};

#endif /* ALUNOS_HPP_ */
