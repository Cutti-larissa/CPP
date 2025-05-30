#include "Usuario.hpp"

namespace postinho{
std::list<Usuario*> Usuario::usuarios;

Usuario::Usuario(const std::string& nome, const unsigned short idade, const unsigned long cpf)
        :Pessoa(nome, idade, cpf), ficha{new Ficha()}{}

Usuario::~Usuario(){}

void Usuario::limpaUsuarios(){
  std::list<Usuario*>::iterator it{Usuario::usuarios.begin()};
  while(it != Usuario::usuarios.end()){
    Usuario* ptr{*it};
    it = Usuario::usuarios.erase(it);
    delete ptr->ficha;
    delete ptr;
  }
}

void Usuario::setFicha(Ficha* ficha){
  this->ficha = ficha;
}

Ficha* Usuario::getFicha() const{
  return this->ficha;
}

std::list<Usuario*>& Usuario::getUsuarios(){
  return Usuario::usuarios;
}

Usuario* Usuario::acharUsuario(){ 
  if(Usuario::usuarios.empty()){
    std::cout << "Nenhum usuário cadastrado\n";
    return nullptr;
  } 
  unsigned long cpf;
  std::list<Usuario*>::iterator it{Usuario::usuarios.begin()}; 
  std::cout << "Procurando usuario\n";
  std::cout << "Cpf do usuario: ";
  std::cin >> cpf;
  for( ; it != Usuario::usuarios.end(); ++it)
    if((*it)->getCpf() == cpf)
      return (*it);
  return nullptr;
}

Usuario* Usuario::cadastrarUsuario(){
  std::string nomeUsuario;
  unsigned short idadeUsuario;
  unsigned long cpfUsuario;

  std::cout << "Nome do Usuario: ";
  std::cin.ignore();
  getline(std::cin, nomeUsuario);
  std::cout << "Idade do Usuario: ";
  std::cin >> idadeUsuario;
  std::cout << "CPF do Usuario: ";
  std::cin >> cpfUsuario;
  Usuario* usuario{new Usuario(nomeUsuario, idadeUsuario, cpfUsuario)};
  Usuario::usuarios.push_back(usuario);
  std::cout << "\nUsuario cadastrado com sucesso!\n"; 
    
  return usuario;
}

void Usuario::imprimirUsuarios(){
  std::cout << "----------------------------------------------------------------------\n";
  std::list<Usuario*>::iterator it{Usuario::usuarios.begin()};
  for ( ; it != Usuario::usuarios.end(); ++it)
    std::cout << "\nUsuario: " << (*it)->getNome() << '\n' 
              << "Idade: " << (*it)->getIdade() << '\n'
              << "Cpf: " << (*it)->getCpf() << '\n';
  std::cout << "----------------------------------------------------------------------\n";
}

void Usuario::removerUsuario(){
  unsigned long cpfUsuario;
  std::cout << "Cpf do usuario: ";
  std::cin >> cpfUsuario;
  std::list<Usuario*>::iterator it{Usuario::usuarios.begin()};
  for( ; it != Usuario::usuarios.end(); ++it)
    if ((*it)->getCpf() == cpfUsuario)
      break;
  if (it != Usuario::usuarios.end()){
    std::cout << "Removendo o cadastro do usuário: " << (*it)->getNome() << '\t' 
              << "Idade: " << (*it)->getIdade() << '\n';
    Usuario* ptr{*it};
    Usuario::usuarios.erase(it);
    delete ptr;
    std::cout << "\nCadastro do usuario removido com sucesso!\n";
  }else{
    std::cout << "\nCadastro não encontrado!\n";
  }
}
}
