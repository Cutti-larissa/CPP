#include <iostream>
#include "OpInvalidoException.hpp"
#include "Interface.hpp"
#include "Consulta.hpp"
#include "Estoque.hpp"
#include "Gerente.hpp"
#include "Medico.hpp"
#include "Pessoa.hpp"
#include "Produto.hpp"
#include "Profissional.hpp"
#include "Usuario.hpp"

void limpaSistema(){
  postinho::Consulta::limpaConsultas();
  postinho::Estoque::limpaEstoque();
  postinho::Gerente::limpaGerente();
  postinho::Medico::limpaMedicos();
  postinho::Profissional::limpaProfissionais();
  postinho::Usuario::limpaUsuarios();
}

int main(){
  bool cadastrado{false};
  unsigned short op{0};

  while (!cadastrado){
    try{
      std::cout << "Cadastre o gerente no sistema: \n";
      cadastrado = postinho::Gerente::cadastrarGerente();
    }catch(std::invalid_argument& iv){
      std::cout << "Argumento inválido: " << iv.what() << '\n';
    }
  }

  while(op != 5){
    postinho::Interface::painelPrincipal();
    try{
      std::cin >> op;

      switch(op){
        case 1:
          postinho::Interface::estoque();
          break;
        case 2:
          postinho::Interface::consulta();
          break;
        case 3:
          postinho::Interface::profissional();
          break;
        case 4:
          postinho::Interface::usuario();
          break;
        case 5:
          break;
        default:
          throw postinho::OpInvalidoException{"op diferente de [1, 5] no painel principal"};
      }
    } catch(std::runtime_error& re){
      std::cout << "Argumento inválido: " << re.what() << '\n';
      break;
    }catch(postinho::OpInvalidoException& opi){
      std::cout << opi.what() << opi.motivo << '\n';
    }catch(std::bad_alloc& bd){
      std::cout << "Erro ao tentar alocar memória:" << bd.what() << '\n';
    } catch(std::exception& ex){
      std::cout << "Erro genérico: " << ex.what() << '\n';
    }
  }

  limpaSistema();

  return 0;
}