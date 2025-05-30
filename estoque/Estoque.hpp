#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <list>
#include <iostream>
#include <string>
#include "OpInvalidoException.hpp"
#include "Produto.hpp"

namespace postinho{
class Estoque{ 
  public:
    Estoque();
    virtual ~Estoque();
    static void limpaEstoque();
    
    static void cadastrarProduto(); 
    static void imprimirProdutos();
    static void removerCadastro(); 

    static void removerProduto(); 
    static void adicionarProduto(); 

  private:
  static std::list<Produto*> produtos;

};
}
#endif
