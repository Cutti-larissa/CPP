#include "Consulta.hpp"

namespace postinho{
  
std::list<Consulta *> Consulta::consultas;

Consulta::Consulta(const std::string& data, Usuario* const usuario, Medico* const medico)
          :data{data}, usuario{usuario}, medico{medico}, status{false}, motivo{"Ainda será realizada"}{}

Consulta::~Consulta(){}

void Consulta::limpaConsultas(){
  std::list<Consulta*>::iterator it{Consulta::consultas.begin()};
  while(it != Consulta::consultas.end()){
    Consulta* ptr{*it};
    ptr->usuario = nullptr;
    ptr->medico = nullptr;
    it = Consulta::consultas.erase(it);
    delete ptr;
  }
}

void Consulta::setData(const std::string& data){
  this->data = data;
}

std::string Consulta::getData() const{
  return this->data;
}

void Consulta::setUsuario(Usuario* usuario){
  this->usuario = usuario;
}

Usuario* Consulta::getUsuario() const{
  return this->usuario;
}

void Consulta::setMedico(Medico* medico){
  this->medico = medico;
}

Medico* Consulta::getMedico() const{
  return this->medico;
}

void Consulta::setStatus(bool status){
  if(status == false){
    std::cout << "-----------------------------------------\n";
    std::cout << "-----------------Motivo------------------\n";
    std::cout << " 1 - Paciente não compareceu\n";
    std::cout << " 2 - Profissional não compareceu\n";
    std::cout << " 3 - Outro\n";
    std::cout << " 4 - Cancelar\n";
    std::cout << "\nDigete a opção desejada: ";
    
    unsigned short op;
    std::cin >> op;
    std::string outro;

    switch(op){
      case 1:
        this->setMotivo("Paciente não compareceu");
        break;
      case 2:
        this->setMotivo("Profissional não compareceu");
        break;
      case 3:
        std::cout << "Digite o motivo: ";
        std::cin.ignore();
        getline(std::cin, outro);
        this->setMotivo(outro);
        break;
      case 4:
        return;
      default:
        throw std::invalid_argument{"op diferente do intervalo [1, 4] no motivo de consulta não concluida"};
        break;
    }
  }
  this->status = status;
}

bool Consulta::getStatus() const{
  return this->status;
}

void Consulta::setMotivo(const std::string& motivo){
  this->motivo = motivo;
}

std::string Consulta::getMotivo() const{
  return this->motivo;
}

void Consulta::marcarConsulta(Usuario* usuario, Medico* medico){
  std::string data;
  unsigned short int op{0};
  
  //melhoria = verificar formato da data
  std::cout << "Data da consulta na forma DD/MM/AAAA: ";
  std::cin >> data;

  if (usuario == nullptr){
    usuario = Usuario::acharUsuario();
    if(usuario  == nullptr){
      std::cout << "Usuário não encontrado, favor realizar o cadastro antes de continuar!\n";
      std::cout << "Deseja realizar o cadastro?\n"
                << "1 - Sim\n" << "2 - Não\n";
      std::cin >> op;
      if(op == 1){
        usuario = Usuario::cadastrarUsuario();
      }else{
        std::cout << "Operação cancelada!\n";
        return;
      }
    }
  }
  if (medico == nullptr){
    medico = Medico::acharMedico();
    if(medico  == nullptr){
      std::cout << "Médico não encontrado, favor realizar o cadastro antes de continuar!\n";
      std::cout << "Deseja realizar o cadastro?\n"
                << "1 - Sim\n" << "2 - Não\n";
      std::cin >> op;
      if(op == 1){
        medico = Medico::cadastrarMedico();
      }else{
        std::cout << "Operação cancelada!\n";
        return;
      }
    }
  }
  
  Consulta* consulta{new Consulta{data, usuario, medico}};
  Consulta::consultas.push_back(consulta);
  std::cout << "\nConsulta marcada com sucesso!\n";
}

Consulta* Consulta::acharConsulta(){ 
  std::string nomeMedico, data;
  unsigned long cpfUsuario;

  if(Consulta::consultas.empty()){
    std::cout << "Não há consultas cadastradas no momento!\n";
    return nullptr;
  }

  std::cout << "Opções: \n";
  Consulta::imprimirConsultas();
  
  std::list<Consulta*>::iterator it{Consulta::consultas.begin()};
  std::cout << "Procurando consulta\n";
  std::cout << "Cpf paciente: ";
  std::cin >> cpfUsuario;
  std::cout << "Nome Profissional: ";
  std::cin.ignore();
  getline(std::cin, nomeMedico);
  for( ; it != Consulta::consultas.end(); ++it){
    if((*it)->getUsuario()->getCpf() == cpfUsuario){
      if((*it)->getMedico()->getNome() == nomeMedico){
        std::cout << "Data: ";
        std::cin >> data;
        if((*it)->getData() == data)
          return (*it);
      }
    } 
  }
  std::cout << "Falha ao achar consulta!\n";
  return nullptr;
}

void Consulta::cancelarConsulta(){
  Consulta* consulta;

  consulta = acharConsulta();
  if (consulta != nullptr){
    Consulta* ptr{consulta};
    Consulta::consultas.remove(consulta);
    delete ptr;
    std::cout << "Consulta cancelada com sucesso!\n";
  }else
    std::cout << "Falha ao tentar cancelar consulta\n";
}

void Consulta::remarcarConsulta(){
  Consulta* consulta;
  std::string dataNova;

  consulta = acharConsulta();
  if (consulta != nullptr){
    std::cout << "Nova data: ";
    std::cin >> dataNova;
    consulta->setData(dataNova);
    std::cout << "Consulta remarcada com sucesso!\n";
  }else
    std::cout << "Falha ao remarcar consulta!\n";
}

void Consulta::abrirConsulta(){
   unsigned short op{0};
  Consulta *c;
  c = Consulta::acharConsulta();
  if(c != nullptr){
    while(op != 5){
      std::cout << "-----------------------------------------\n";
      std::cout << " 1 - Marcar consulta como concluida\n";
      std::cout << " 2 - Marcar consulta como não concluida\n";
      std::cout << " 3 - Abrir ficha paciente\n";
      std::cout << " 4 - Alterar dados da ficha do paciente\n";
      std::cout << " 5 - Fechar consulta\n";
      std::cout << "\nDigete a opção desejada: ";

      std::cin >> op;

    
      switch(op){
        case 1:
          c->setStatus(true);
          break;
        case 2:
          c->setStatus(false);
          break;
        case 3:
          c->getUsuario()->getFicha()->imprimirFicha();
          break;
        case 4:
          c->getMedico()->alterarFichaPaciente(c->getUsuario());
          break;
        case 5:
          return;
          break;
        default:
          throw std::invalid_argument{"op diferente do intervalo [1, 5] em abrir consulta"};
      }
    }
  }else{
    std::cout << "Falha ao abrir consulta!\n";
  }
}

void Consulta::imprimirConsultas(){
  std::cout << "----------------------------------------------------------------------\n";
  std::list<Consulta*>::iterator it{Consulta::consultas.begin()};
  for ( ; it != Consulta::consultas.end(); ++it){
    std::cout << "\nProfissional: " << (*it)->getMedico()->getNome() << '\n' 
              << "Paciente: " << (*it)->getUsuario()->getNome() << '\n' 
              << "Data: " << (*it)->getData() << '\n'
              << "Realizada? ";
    if ((*it)->getStatus() == true)
      std::cout << "Sim\n";
    else
      std::cout << "Não" << '\t' << "Motivo: " << (*it)->getMotivo() << '\n';
  }
  std::cout << "----------------------------------------------------------------------\n";
}

void Consulta::imprimirConsultasDia(){
  std::cout << "----------------------------------------------------------------------\n";
  std::string dataAtual;
  std::cout << "Digite a data de hoje na forma DD/MM/AAAA: ";
  std::cin >> dataAtual;
  std::list<Consulta*>::iterator it{Consulta::consultas.begin()};
  for ( ; it != Consulta::consultas.end(); ++it){
    if ((*it)->getData() == dataAtual){
      std::cout << "\nProfissional: " << (*it)->getMedico()->getNome() << '\n' 
                << "Paciente: " << (*it)->getUsuario()->getNome() << '\n' 
                << "Data: " << (*it)->getData() << '\n'
                << "Realizada? ";
      if ((*it)->getStatus() == true)
        std::cout << "Sim\n";
      else
        std::cout << "Não, " << (*it)->getMotivo() << '\n';
    }
  }
  std::cout << "----------------------------------------------------------------------\n";
}
}
