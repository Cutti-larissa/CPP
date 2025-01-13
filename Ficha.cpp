#include "Ficha.hpp"

namespace postinho{
Ficha::Ficha() :necessidadesEspeciais{" "}, fumante{false}, doencaCronica{" "}, 
      tipoSanguineo{" "}, peso{0}, altura{0} {}

Ficha::~Ficha(){}

void Ficha::setNecessidadesEspeciais(const std::string& necessidades){
  this->necessidadesEspeciais = necessidades;
}

void Ficha::addNecessidadesEspeciais(const std::string& necessidades){
  this->necessidadesEspeciais += " ";
  this->necessidadesEspeciais += necessidades;
}

std::string Ficha::getNecessidadesEspeciais() const{
  return this->necessidadesEspeciais;
}

void Ficha::setFumante(const bool fumante){
  this->fumante = fumante;
}

bool Ficha::getFumante() const{
  return this->fumante;
}

void Ficha::setDoencaCronica(const std::string& doencaCronica){ 
  this->doencaCronica = doencaCronica;
}

std::string Ficha::getDoencaCronica() const{
  return this->doencaCronica;
}

void Ficha::addDoencaCronica(const std::string& doencaCronica){
  this->doencaCronica += " ";
  this->doencaCronica += doencaCronica;
}

void Ficha::setTipoSanguineo (const std::string& tipoSanguineo){ 
  this->tipoSanguineo = tipoSanguineo;
}

std::string Ficha::getTipoSanguineo() const{
  return this->tipoSanguineo;
}

void Ficha::setPeso(const unsigned short peso){
  this->peso = peso;
}

unsigned short Ficha::getPeso() const{
  return this->peso;
}

void Ficha::setAltura(const unsigned int altura){
  this->altura = altura;
}

unsigned int Ficha::getAltura() const{
  return this->altura;
}

void Ficha::imprimirFicha() const{
  std::cout << "-----------------------------------------\n";
  std::cout << "------------Ficha do paciente------------\n";
  std::cout << "Necessidades Especiais: " << this->getNecessidadesEspeciais() << '\n' 
            << "Fumante? ";
            if (this->getFumante())
              std::cout << "Sim\n";
            else
              std::cout << "Não\n";
  std::cout << "Doença Crônica: " << this->getDoencaCronica() << '\n'
            << "Tipo Sanguíneo: " << this->getTipoSanguineo() << '\n'
            << "Peso: " << this->getPeso() << '\n'
            << "Altura: " << this->getAltura() << '\n';
}
}
