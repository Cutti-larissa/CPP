#include "Estoque.hpp"

namespace postinho{
Estoque::Estoque(){}

Estoque::~Estoque(){} 

void Estoque::limpaEstoque(){
  std::list<Produto*>::iterator it{Estoque::produtos.begin()};
  while(it != Estoque::produtos.end()){
    Produto* ptr{*it};
    it = Estoque::produtos.erase(it);
    delete ptr;
  }
}

std::list<Produto*> Estoque::produtos; 

void Estoque::cadastrarProduto(){
  std::cout << "----------------------------------------------------------------------\n";
  std::cout << "-------------------Cadastrando produto---------------------------------\n";
  std::string nomeProduto;
  std::cout << "Nome do produto: ";
  std::cin.ignore();
  getline(std::cin, nomeProduto);
  Produto* p{new Produto{nomeProduto}}; 
  Estoque::produtos.push_back(p);
  std::cout << "\nProduto cadastrado com sucesso!\n";
}

void Estoque::imprimirProdutos(){
  std::cout << "----------------------------------------------------------------------\n";
  std::list<Produto*>::iterator it{Estoque::produtos.begin()};
  for ( ; it != Estoque::produtos.end(); ++it)
    std::cout << "Produto: " << (*it)->getNome() << '\t' << "Quantidade no estoque: " << (*it)->getQuantEstoque() << '\n';
  std::cout << "----------------------------------------------------------------------\n";
}

void Estoque::removerCadastro(){
  std::cout << "----------------------------------------------------------------------\n";
  std::cout << "-------------------Removendo cadastro---------------------------------\n";
  std::string nomeProduto;
  std::cout << "Opções: \n";
  Estoque::imprimirProdutos();
  std::cout << "Nome do produto: ";
  std::cin.ignore();
  getline(std::cin, nomeProduto);
  std::list<Produto*>::iterator it{Estoque::produtos.begin()};
  for( ; it != Estoque::produtos.end(); ++it){
    if ((*it)->getNome() == nomeProduto)
      break;
  }
  if (it != Estoque::produtos.end()){
    Produto* ptr{*it};
    Estoque::produtos.erase(it);
    delete ptr;
    std::cout << "\nProduto removido com sucesso!\n";
  }else{
    std::cout << "\nProduto não encontrado!\n";
  }
}

void Estoque::removerProduto(){ 
  std::string produtoNome;
  unsigned short int op;
  unsigned int produtoQuant;

  std::cout << "Opções: \n";
  Estoque::imprimirProdutos();

  std::cout << "Nome do produto a ser removido: ";
  std::cin.ignore();
  getline(std::cin, produtoNome);

  std::list<Produto*>::iterator it{Estoque::produtos.begin()};
  for( ; it != Estoque::produtos.end(); ++it){
    if((*it)->getNome() == produtoNome){
      std::cout << "Quantidade a ser removida: ";
      std::cin >> produtoQuant;
      if((*it)->getQuantEstoque() < produtoQuant){
        std::cout << "Quantidade a ser removida é maior do que a quantidade no estoque ou é inválida"
                  << '\n' << "Deseja zerar o estoque desse produto?\n"
                  << "1 - Sim\n" << "2 - Não\n"
                  << "Digite a opção desejada\n";
        std::cin >> op;
        if(op == 1){
          produtoQuant = (*it)->getQuantEstoque();
        }else if(op == 2){
          return;
        }else{
          std::cout << "Opção inválida, operação cancelada!\n";
          return;
        }
      }
      (*it)->setQuantEstoque(-produtoQuant);
      std::cout << "Produto removido com sucesso!\n";
      return;
    }
  }
  std::cout << "Produto não encontrado!\n";
}

void Estoque::adicionarProduto(){
  std::string produtoNome;
  unsigned int produtoQuant;
  
  std::cout << "Opções: \n";
  Estoque::imprimirProdutos();
  std::cout << "Nome do produto a ser adicionado: ";
  std::cin.ignore();
  getline(std::cin, produtoNome);
  std::cout << "Quantidade a ser adicionada: ";
  std::cin >> produtoQuant;
  std::list<Produto*>::iterator it{Estoque::produtos.begin()};
  for( ; it != Estoque::produtos.end(); ++it)
    if((*it)->getNome() == produtoNome){
      (*it)->setQuantEstoque(produtoQuant);
      std::cout << "Produto adicionado com sucesso!\n";
      return;
    }
  std::cout << "Produto não encontrado!\n";
}
}
