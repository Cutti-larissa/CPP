#include "Produto.hpp"
#include <iostream>

namespace postinho{
Produto::Produto(std::string& nome): nome{nome}, quantEstoque{0}{}

void Produto::setNome(std::string& nome){
  this->nome = nome;
}

std::string Produto::getNome() const{
  return this->nome;
}

void Produto::setQuantEstoque(int quantidade){
  this->quantEstoque += quantidade; 
}

unsigned int Produto::getQuantEstoque() const{
  return this->quantEstoque;
}
}
