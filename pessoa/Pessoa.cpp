#include "Pessoa.hpp"

#include <iostream>

namespace postinho{
Pessoa::Pessoa(){}

Pessoa::Pessoa(const std::string& nome, const unsigned short idade, const unsigned long cpf)
      :nome{nome}{
  this->setIdade(idade);
  this->setCpf(cpf);
} 

Pessoa::~Pessoa(){}

void Pessoa::setNome(const std::string& nome){
  this->nome = nome;
}

std::string Pessoa::getNome() const{
  return this->nome;
}

void Pessoa::setIdade(const unsigned short idade){
  if (idade > 200)
    throw std::invalid_argument{"Idade inválida"}; 
  this->idade = (unsigned char)idade; 
}
unsigned short Pessoa::getIdade() const{
  return this->idade;
}

void Pessoa::setCpf(const unsigned long cpf){
  if(validarCPF(cpf)){
    this->cpf = cpf;
    return;
  }
  throw std::invalid_argument{"Cpf inválido"};; 
}

unsigned long Pessoa::getCpf() const{
  return this->cpf;
}

bool Pessoa::validarCPF(unsigned long cpf){
  bool digitosIguais{true};
  int somatorioValidaUltimo;
  int modulo;
  int somatorioValidaPenultimo = 0;
  int ultimo = cpf % 10;
  cpf = cpf / 10;
  int penultimo = cpf % 10;
  cpf = cpf / 10;

  if(ultimo != penultimo){
    digitosIguais = false;
  }

  somatorioValidaUltimo = penultimo * 2;
  for (int i = 2; i <= 11; i++) {
    modulo = cpf % 10;
    cpf = cpf / 10;
    if ((modulo != 0) && (modulo != ultimo)){
      digitosIguais = false;
    }
    somatorioValidaPenultimo += modulo * i;
    somatorioValidaUltimo += modulo * (i + 1);
  }
  modulo = somatorioValidaPenultimo % 11;
  if (modulo < 2) {
    if (!penultimo) return false;  // cpf invalido
  } else {
    if (penultimo != 11 - modulo) return false;  // cpf invalido
  }
  modulo = somatorioValidaUltimo % 11;
  if (modulo < 2) {
    if (!ultimo) return false;  // cpf invalido
  } else {
    if (ultimo != 11 - modulo) return false;  // cpf invalido
  }
  if (digitosIguais){
    return false; //cpf invalido
  }
  return true;  // cpf valido
}
}
