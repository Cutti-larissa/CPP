#ifndef GERENTE_HPP
#define GERENTE_HPP

#include <iostream>
#include <array>
#include <string>
#include "OpInvalidoException.hpp"
#include "Profissional.hpp"
#include "Medico.hpp"
#include "Usuario.hpp"

namespace postinho{
class Gerente : public Profissional{
  public:
    Gerente(const std::string& nome, const unsigned short idade, const unsigned long cpf,
            const unsigned short cargaHoraria, const unsigned short valorHora, const std::string& senha);
    virtual ~Gerente();
    static void limpaGerente();

    static bool cadastrarGerente();
    static Gerente* validarSenha();

    void alterarDadosUsuario(Usuario* usuario);
    void alterarDadosProfissional(Profissional* profissional);
 
  
  private:
    void alterarNomeUsuario(Usuario* usuario);
    void alterarIdadeUsuario(Usuario* usuario);
    void alterarCpfUsuario(Usuario* usuario);
    void alterarNomeProfissional(Profissional* profissional);
    void alterarIdadeProfissional(Profissional* profissional);
    void alterarCpfProfissional(Profissional* profissional);
    void alterarCargaHoraria(Profissional* profissional);
    void alterarValorHora(Profissional* profissional);
    void adicionarEspecializacao(Profissional* profissional);
    void alterarEspecializacao(Profissional* profissional);

    static Gerente* gerente;
    std::string senha;
};
}
#endif