#include "Interface.hpp"

namespace postinho{
void Interface::painelPrincipal(){
  std::cout << "-----------------------------------------\n";
  std::cout << "------------------Postinho---------------\n";
  std::cout << " 1 - Estoque\n";
  std::cout << " 2 - Consultas\n";
  std::cout << " 3 - Profissionais\n";
  std::cout << " 4 - Usuários\n";
  std::cout << " 5 - Fechar sistema\n";
  std::cout << "\nDigite a opção desejada: ";
}

void Interface::estoque(){
  std::cout << "-----------------------------------------\n";
  std::cout << "------------------Estoque----------------\n";
  std::cout << " 1 - Cadastrar produto\n";
  std::cout << " 2 - Remover cadastro do produto\n";
  std::cout << " 3 - Adicionar produto no estoque\n";
  std::cout << " 4 - Remover produto do estoque\n";
  std::cout << " 5 - Mostrar produtos no estoque\n";
  std::cout << " 6 - Cancelar e voltar a tela inicial\n";
  std::cout << "\nDigite a opção desejada: ";

  unsigned short op;
  std::cin >> op;

  switch(op){
    case 1:
      Estoque::cadastrarProduto();
      break;
    case 2:
      Estoque::removerCadastro();
      break;
    case 3:
      Estoque::adicionarProduto();
      break;
    case 4:
      Estoque::removerProduto();
      break;
    case 5:
      Estoque::imprimirProdutos();
      break;
    case 6:
      return;
      break;
    default:
      throw OpInvalidoException{"op diferente do intervalo [1, 6] no estoque"};
  }
}

void Interface::consulta(){
  std::cout << "-----------------------------------------\n";
  std::cout << "------------------Consulta---------------\n";
  std::cout << " 1 - Mostrar todas as consultas\n";
  std::cout << " 2 - Mostrar todas as consultas do dia\n";
  std::cout << " 3 - Marcar consulta\n";
  std::cout << " 4 - Cancelar consulta existente\n";
  std::cout << " 5 - Remarcar consulta existente\n";
  std::cout << " 6 - Abrir consulta\n";
  std::cout << " 7 - Cancelar e voltar a tela inicial\n";
  std::cout << "\nDigite a opção desejada: ";

  unsigned short op;
  std::cin >> op;

  switch(op){
    case 1:
      Consulta::imprimirConsultas();
      break;
    case 2:
      Consulta::imprimirConsultasDia();
      break;
    case 3:
      Consulta::marcarConsulta();
      break;
    case 4:
      Consulta::cancelarConsulta();
      break;
    case 5:
      Consulta::remarcarConsulta();
      break;
    case 6:
      Consulta::abrirConsulta();
      break;
    case 7:
      return; 
      break;
    default:
      throw OpInvalidoException{"op diferente do intervalo [1, 7] na consulta"};
  }
  return;
}

void Interface::profissional(){ 
  std::cout << "-----------------------------------------\n";
  std::cout << "--------------Profissional---------------\n";
  std::cout << " 1 - Cadastrar médico\n";
  std::cout << " 2 - Lista de profissionais\n";
  std::cout << " 3 - Lista de médicos\n";
  std::cout << " 4 - Remover médico\n";
  std::cout << " 5 - Alterar dados de profissional existente\n";
  std::cout << " 6 - Marcar consulta com profissional existente\n";
  std::cout << " 7 - Cancelar e voltar para tela inicial\n";
  std::cout << "\nDigite a opção desejada: ";

  Medico* medico;
  Gerente* gerente;
  Profissional* profissional;
  unsigned short op;
  std::cin >> op;

  switch(op){
    case 1:
      Medico::cadastrarMedico();
      break;
    case 2:
      Profissional::imprimirProfissionais();
      break;
    case 3:
      Medico::imprimirMedicos();
      break;
    case 4:
      Medico::removerMedico();
      break;
    case 5:
      profissional = Profissional::acharProfissional();
      gerente = Gerente::validarSenha();
      if (gerente != nullptr && profissional != nullptr)
        gerente->alterarDadosProfissional(profissional);
      break;
    case 6:
      medico = Medico::acharMedico(); 
      if(medico != nullptr)
        Consulta::marcarConsulta(nullptr, medico);
      break;
    case 7:
      return;
      break;
    default:
      throw OpInvalidoException{"op diferente do intervalo [1, 7] no profissional"};
  }
}

void Interface::usuario(){
  std::cout << "-----------------------------------------\n";
  std::cout << "-----------------Usuario-----------------\n";
  std::cout << " 1 - Cadastrar Usuário\n";
  std::cout << " 2 - Lista de Usuários\n";
  std::cout << " 3 - Remover Usuário\n";
  std::cout << " 4 - Alterar dados usuário existente\n";
  std::cout << " 5 - Marcar consulta para usuário existente\n";
  std::cout << " 6 - Cancelar e voltar para tela inicial\n";
  std::cout << "\nDigite a opção desejada: ";

  Gerente* gerente;
  Usuario* usuario;
  unsigned short op;
  std::cin >> op;

  switch(op) {
    case 1:
      Usuario::cadastrarUsuario();
      break;
    case 2:
      Usuario::imprimirUsuarios();
      break;
    case 3:
      Usuario::removerUsuario();
      break;
    case 4:
      usuario = Usuario::acharUsuario(); 
      gerente = Gerente::validarSenha();
      if (gerente != nullptr && usuario != nullptr)
        gerente->alterarDadosUsuario(usuario);
      break;
    case 5:
      usuario = Usuario::acharUsuario();
      Consulta::marcarConsulta(usuario, nullptr);
      break;
    case 6:
      return;
      break;
    default:
      throw OpInvalidoException{"op diferente do intervalo [1, 6] no usuario"};
  }
}
}
