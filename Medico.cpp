#include "Medico.hpp"

namespace postinho{
std::list<Medico*> Medico::medicos; 

Medico::Medico(const std::string& nome, const unsigned short idade, const unsigned long cpf,
              const unsigned short cargaHoraria, const unsigned short valorHora, const std::string& especializacao)
        :Profissional{nome, idade, cpf, cargaHoraria, valorHora}, especializacao{especializacao}{} 

Medico::~Medico(){}

void Medico::limpaMedicos(){
  std::list<Medico*>::iterator it{Medico::medicos.begin()};
  while(it != Medico::medicos.end()){
    Medico* ptr{*it};
    Profissional::getProfissionais().remove(ptr);
    it = Medico::medicos.erase(it);
    delete ptr;
  }
}

Medico* Medico::acharMedico(){
  if(Medico::medicos.empty()){
    std::cout << "Nenhum médico cadastrado\n";
    return nullptr;
  }
  unsigned int id;
  std::list<Medico*>::iterator it{Medico::medicos.begin()}; 
  std::cout << "Procurando profissional\n";
  std::cout << "Id do profissional: ";
  std::cin >> id;
  for( ; it != Medico::medicos.end(); ++it)
    if((*it)->getId() == id)
      return (*it);

  std::cout << "Medico não encontrado!\n";
  return nullptr;
}

Medico* Medico::cadastrarMedico(){
  std::string nome, especializacao;
  unsigned short idade;
  unsigned long cpf;
  unsigned short valorHora;
  unsigned int cargaHoraria;

  std::cout << "Nome médico: ";
  std::cin.ignore();
  getline(std::cin, nome);
  std::cout << "Idade médico: ";
  std::cin >> idade;
  std::cout << "CPF médico: ";
  std::cin >> cpf;
  std::cout << "Valor inteiro recebido por hora: ";
  std::cin >> valorHora;
  std::cout << "Carga Horaria mensal: ";
  std::cin >> cargaHoraria;
  std::cout << "Especialização: ";
  std::cin.ignore();
  getline(std::cin, especializacao);
  Medico* medico{new Medico(nome, idade, cpf, valorHora, cargaHoraria, especializacao)};
  Medico::medicos.push_back(medico);
  Profissional::getProfissionais().push_back(medico);
  std::cout << "Médico cadastrado com sucesso!\n";
  std::cout << "Numero de verificação do médico: " << medico->getId() << '\n';

  return medico;
}
  
void Medico::removerMedico(){
  unsigned int id;

  std::cout << "Número de identificação do profissional: ";
  std::cin >> id;
  std::list<Medico*>::iterator it{Medico::medicos.begin()};
  for( ; it != Medico::medicos.end(); ++it)
    if ((*it)->getId() == id)
      break;
  if (it != Medico::medicos.end()){
    std::cout << "Removendo o cadastro do profissional: " << (*it)->getNome() << '\t' 
              << "Idade: " << (*it)->getIdade() << '\t' 
              << "Número de identificação: " << (*it)->getId() << '\n';
    Medico* ptr{*it};
    Medico::medicos.erase(it);
    Profissional::getProfissionais().remove(ptr); 
    delete ptr;
    std::cout << "\nCadastro do profissional removido com sucesso!\n";
  }else{
    std::cout << "\nCadastro não encontrado!\n";
  }
}

void Medico::imprimirMedicos(){
  std::cout << "----------------------------------------------------------------------\n";
  std::list<Medico*>::iterator it{Medico::medicos.begin()};
  for ( ; it != Medico::medicos.end(); ++it)
    std::cout << "\nProfissional: " << (*it)->getNome() << '\n' 
              << "Idade: " << (*it)->getIdade() << '\n'
              << "Número de identificação: " << (*it)->getId() << '\n'
              << "Especialização: " << (*it)->getEspecializacao() << '\n'
              << "Salário: " << (*it)->getSalario() << '\n'; 
  std::cout << "----------------------------------------------------------------------\n";
}

void Medico::setEspecializacao(const std::string& especializacao){
  this->especializacao = especializacao;
}
  
std::string Medico::getEspecializacao() const{
  return this->especializacao;
}

void Medico::addEspecializacao(const std::string& especializacao){
  this->especializacao += especializacao;
}

void Medico::alterarFichaPaciente(Usuario* paciente){
  unsigned short op{0};
  while(op != 9){
    std::cout << "-----------------------------------------\n";
    std::cout << "--------------Alterar Ficha---------------\n";
    std::cout << " 1 - Alterar necessidades Especiais\n";
    std::cout << " 2 - Adicionar necessidades Especiais\n";
    std::cout << " 3 - Alterar status de fumante\n";
    std::cout << " 4 - Alterar doença crônica\n";
    std::cout << " 5 - Adicionar doença crônica\n";
    std::cout << " 6 - Alterar tipo Sanguíneo\n";
    std::cout << " 7 - Alterar peso\n";
    std::cout << " 8 - Alterar altura\n";
    std::cout << " 9 - Cancelar e Fechar\n";
    std::cout << "\nDigite a opção desejada: ";

    Ficha* ficha = paciente->getFicha();

    std::cin >> op;

    switch(op){
      case 1:
        Medico::alterarNecessidadesEspeciais(ficha);
        break;
      case 2:
        Medico::adicionarNecessidadesEspeciais(ficha);
        break;
      case 3:
        Medico::alterarFumante(ficha);
        break;
      case 4:
        Medico::alterarDoencaCronica(ficha);
        break;
      case 5:
        Medico::adicionarDoencaCronica(ficha);
        break;
      case 6:
        Medico::alterarTipoSanguineo(ficha);
        break;
      case 7:
        Medico::alterarPeso(ficha);
        break;
      case 8:
        Medico::alterarAltura(ficha);
        break;
      case 9:
        return;
        break;
      default:
        throw OpInvalidoException{"op diferente do inetrvalo [1, 9] em alterar ficha do paciente"}; 
    }
  }
}

void Medico::alterarNecessidadesEspeciais(Ficha* ficha){
  std::string novaNecessidade;

  std::cout << "Digite a necessidade: ";
  std::cin.ignore();
  getline(std::cin, novaNecessidade);
  ficha->setNecessidadesEspeciais(novaNecessidade);
}

void Medico::adicionarNecessidadesEspeciais(Ficha* ficha){
  std::string novaNecessidade;

  std::cout << "Digite a necessidade: ";
  std::cin.ignore();
  getline(std::cin, novaNecessidade);
  ficha->addNecessidadesEspeciais(novaNecessidade);
}

void Medico::alterarFumante(Ficha* ficha){
  bool fumante;

  std::cout << "Aperte: \n" << "1 - fumante\n" << "0 - não fumante\n";
  std::cin >> fumante;
  ficha->setFumante(fumante);
}

void Medico::alterarDoencaCronica(Ficha* ficha){
  std::string novaDoencaCronica;

  std::cout << "Digite a doença crônica: ";
  std::cin.ignore();
  getline(std::cin, novaDoencaCronica);
  ficha->setDoencaCronica(novaDoencaCronica);
}

void Medico::adicionarDoencaCronica(Ficha* ficha){
  std::string novaDoencaCronica;

  std::cout << "Digite a doença crônica: ";
  std::cin.ignore();
  getline(std::cin, novaDoencaCronica);
  ficha->addDoencaCronica(novaDoencaCronica);
}


void Medico::alterarTipoSanguineo(Ficha* ficha){
  std::string novoTipoSanguineo;

  std::cout << "Digite o tipo sanguíneo: ";
  std::cin.ignore();
  getline(std::cin, novoTipoSanguineo);
  ficha->setTipoSanguineo(novoTipoSanguineo);
}

void Medico::alterarPeso(Ficha* ficha){
  unsigned int novoPeso;

  std::cout << "Digite o peso: ";
  std::cin >> novoPeso;
  ficha->setPeso(novoPeso);
}

void Medico::alterarAltura(Ficha* ficha){
  unsigned int novaAltura;
  
  std::cout << "Digite a altura: ";
  std::cin >> novaAltura;
  ficha->setAltura(novaAltura);
}

std::list<Medico*>& Medico::getMedicos(){
  return Medico::medicos;
}
}