#include "Gerente.hpp"

namespace postinho{
Gerente::Gerente(const std::string& nome, const unsigned short idade, const unsigned long cpf,
            const unsigned short cargaHoraria, const unsigned short valorHora, const std::string& senha)
            :Profissional{nome, idade, cpf, cargaHoraria, valorHora}, senha{senha}{}
            
Gerente::~Gerente(){} 

void Gerente::limpaGerente(){
  Gerente* ptr{Gerente::gerente};
  Profissional::getProfissionais().remove(ptr);
  Gerente::gerente = nullptr;
  delete ptr;
}

Gerente* Gerente::gerente;

bool Gerente::cadastrarGerente(){
  std::string nome;
  std::string senha;
  unsigned short idade;
  unsigned long cpf;
  unsigned short valorHora;
  unsigned int cargaHoraria;

  std::cout << "Nome gerente: ";
  getline(std::cin, nome);
  while(nome.empty()){
    std::cout << "Nome não pode ser vazio!\n" << "Nome: ";
    getline(std::cin, nome);
  }
  std::cout << "Idade gerente: ";
  std::cin >> idade;
  std::cout << "CPF gerente (apenas números): ";
  std::cin >> cpf;
  std::cout << "Valor inteiro recebido por hora: "; 
  std::cin >> valorHora;
  std::cout << "Carga horária mensal: ";
  std::cin >> cargaHoraria;
  std::cout << "Digite uma senha: ";
  std::cin >> senha;
  Gerente* gerente{new Gerente(nome, idade, cpf, valorHora, cargaHoraria, senha)}; 
  Profissional::getProfissionais().push_back(gerente);
  Gerente::gerente = gerente;
  std::cout << "Gerente cadastrado com sucesso!\n";
  std::cout << "Numero de verificação do profissional: " << gerente->getId() << '\n';

  return true;
}

Gerente* Gerente::validarSenha(){
  std::string senha;

  std::cout << "Digite sua senha: ";
  std::cin >> senha;
  if (senha == Gerente::gerente->senha){
    return Gerente::gerente;
  }
  std::cout << "Senha inválida!\n";

  return nullptr;
}

void Gerente::alterarDadosUsuario(Usuario* usuario){
  unsigned short op{0};
  while(op != 4){
    std::cout << "-----------------------------------------\n";
    std::cout << "--------------Alterar Dados---------------\n";
    std::cout << " 1 - Alterar nome\n";
    std::cout << " 2 - Alterar idade\n";
    std::cout << " 3 - Alterar cpf\n";
    std::cout << " 4 - Cancelar e Fechar\n";
    std::cout << "\nDigite a opção desejada: ";

    std::cin >> op;

    switch(op){
      case 1:
        Gerente::alterarNomeUsuario(usuario);
        break;
      case 2:
        Gerente::alterarIdadeUsuario(usuario);
        break;
      case 3:
        Gerente::alterarCpfUsuario(usuario);
        break;
      case 4:
        return;
        break;
      default:
        throw OpInvalidoException{"op diferente do intervalo [1, 4] em alterar dados do Usuário"};
    }
  }
}

void Gerente::alterarNomeUsuario(Usuario* usuario){
  std::string novoNome;

  std::cout << "\nDigite o novo nome: ";
  std::cin.ignore();
  getline(std::cin, novoNome);
  usuario->setNome(novoNome);
}
      
void Gerente::alterarIdadeUsuario(Usuario* usuario){
  unsigned short novaIdade;

  std::cout << "\nDigite nova idade: ";
  std::cin >> novaIdade; 
  usuario->setIdade(novaIdade);
}

void Gerente::alterarCpfUsuario(Usuario* usuario){
  unsigned long novoCpf;

  std::cout << "\nDigite novo CPF: ";
  std::cin >> novoCpf; 
  usuario->setCpf(novoCpf);
}

void Gerente::alterarDadosProfissional(Profissional* profissional){
  unsigned short op{0};
  while(op != 8){
    std::cout << "-----------------------------------------\n";
    std::cout << "--------------Alterar Dados---------------\n";
    std::cout << " 1 - Alterar nome\n";
    std::cout << " 2 - Alterar idade\n";
    std::cout << " 3 - Alterar cpf\n";
    std::cout << " 4 - Alterar carga horária mensal\n";
    std::cout << " 5 - Alterar valor ganho por hora\n";
    std::cout << " 6 - Alterar especialização\n";
    std::cout << " 7 - Adicionar especialização\n";
    std::cout << " 8 - Cancelar e Fechar\n";
    std::cout << "\nDigite a opção desejada: ";

    std::cin >> op;

    switch(op){
      case 1:
        Gerente::alterarNomeProfissional(profissional);
        break;
      case 2:
        Gerente::alterarIdadeProfissional(profissional);
        break;
      case 3:
        Gerente::alterarCpfProfissional(profissional);
        break;
      case 4:
        Gerente::alterarCargaHoraria(profissional);
        break;
      case 5:
        Gerente::alterarValorHora(profissional);
        break;
      case 6:
        Gerente::alterarEspecializacao(profissional);
        break;
      case 7:
        Gerente::adicionarEspecializacao(profissional);
      case 8:
        return;
        break;
      default:
        throw OpInvalidoException{"op diferente do intervalo [1, 8] em alterar dodos do profissional"};
    }
  }
}

void Gerente::alterarNomeProfissional(Profissional* profissional){
  std::string novoNome;

  std::cout << "\nDigite o novo nome: ";
  std::cin.ignore();
  getline(std::cin, novoNome);
  profissional->setNome(novoNome);
}

void Gerente::alterarIdadeProfissional(Profissional* profissional){
  unsigned short novaIdade;

  std::cout << "\nDigite nova idade: ";
  std::cin >> novaIdade;
  profissional->setIdade(novaIdade);
}

void Gerente::alterarCpfProfissional(Profissional* profissional){
  unsigned long novoCpf;

  std::cout << "\nDigite novo CPF: ";
  std::cin >> novoCpf; 
  profissional->setCpf(novoCpf);
}

void Gerente::alterarCargaHoraria(Profissional* profissional){
  unsigned short novaCargaHoraria;

  std::cout << "\nDigite nova carga horária: ";
  std::cin >> novaCargaHoraria; 
  profissional->setCargaHoraria(novaCargaHoraria);
}

void Gerente::alterarValorHora(Profissional* profissional){
  unsigned short novoValorHora;
  
  std::cout << "\nDigite novo valor por hora: ";
  std::cin >> novoValorHora; 
  profissional->setValorHora(novoValorHora);
}

Medico* acharMedico(Profissional* profissional){
  std::list<Medico*>::iterator it{Medico::getMedicos().begin()};
  for( ; it != Medico::getMedicos().end(); ++it){
    if((*it)->getId() == profissional->getId())
      return (*it);
  }
  std::cout << "\nProfissional não cadastrado como Médico\n";
  return nullptr;
}

void Gerente::adicionarEspecializacao(Profissional* profissional){
  std::string especializacao;
  Medico* m = acharMedico(profissional);
  if (m != nullptr){
    std::cout << "\nEspecialização a ser adicionada: ";
    std::cin >> especializacao;
    m->addEspecializacao(especializacao);
  }
}

void Gerente::alterarEspecializacao(Profissional* profissional){
  std::string especializacao;
  Medico* m = acharMedico(profissional);
  if (m != nullptr){
    std::cout << "\nDigite Especialização: ";
    std::cin >> especializacao;
    m->setEspecializacao(especializacao);
  }
}
}
