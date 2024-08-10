/*
 * Dados.hpp
 *
 *  Created on: 6 de ago. de 2024
 *      Author: user
 */

#ifndef DADOS_HPP_
#define DADOS_HPP_

#include <iostream>

using namespace std;

class Dados{
private:
	int x;
public:
	int getDado(){
		return x;
	}

	void setDado(int dado){
		this->x  = dado;
	}
};

#endif /* DADOS_HPP_ */
