#include "Profissional.hpp"

namespace postinho{

unsigned int Profissional::proxId{0};
std::list<Profissional*> Profissional::profissionais;

Profissional::Profissional(const std::string& nome, const unsigned short idade, const unsigned long cpf,
                          const unsigned short cargaHoraria, const unsigned short valorHora)
              :Pessoa(nome, idade, cpf), cargaHoraria{cargaHoraria}, valorHora{valorHora}, id{Profissional::proxId}{
  Profissional::proxId++;
}

Profissional::~Profissional(){}

void Profissional::limpaProfissionais(){
  std::list<Profissional*>::iterator it{Profissional::profissionais.begin()};
  while(it != Profissional::profissionais.end()){
    Profissional* ptr{*it};
    it = Profissional::profissionais.erase(it);
    delete ptr;
  }
}
    
std::list<Profissional*>& Profissional::getProfissionais(){
  return Profissional::profissionais;
}

void Profissional::setCargaHoraria(const unsigned short cargaHoraria){
  this->cargaHoraria = cargaHoraria;
}

unsigned short Profissional::getCargaHoraria() const{
  return this->cargaHoraria;
}

void Profissional::setValorHora(const unsigned short valorHora){
  this->valorHora = valorHora;
}

unsigned short Profissional::getValorHora() const{
  return this->valorHora;
}
    
unsigned int Profissional::getSalario() const{
  return (cargaHoraria*valorHora); 
}

unsigned int Profissional::getId() const{
  return this->id;
}

Profissional* Profissional::acharProfissional(){
  unsigned int id;

  std::list<Profissional*>::iterator it{Profissional::profissionais.begin()};
  std::cout << "Procurando profissional\n";
  std::cout << "Id do profissional: ";
  std::cin >> id;
  for( ; it != Profissional::profissionais.end(); ++it)
    if((*it)->getId() == id)
      return (*it);
      
  return nullptr;
}

void Profissional::imprimirProfissionais(){
  std::cout << "----------------------------------------------------------------------\n";
  std::list<Profissional*>::iterator it{Profissional::profissionais.begin()};
  for ( ; it != Profissional::profissionais.end(); ++it)
    std::cout << "\nProfissional: " << (*it)->getNome() << '\n' 
              << "Idade: " << (*it)->getIdade() << '\n'
              << "Número de identificação: " << (*it)->getId() << '\n'
              << "Salário: " << (*it)->getSalario() << '\n';
  std::cout << "----------------------------------------------------------------------\n";
}
}
