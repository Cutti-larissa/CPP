#ifndef PROFISSIONAL_HPP
#define PROFISSIONAL_HPP

#include <iostream>
#include <list>
#include "Pessoa.hpp"

namespace postinho{
class Profissional : public Pessoa{
  public:
    Profissional(const std::string& nome, const unsigned short idade, const unsigned long cpf,
                const unsigned short cargaHoraria, const unsigned short valorHora);
    virtual ~Profissional();
    static void limpaProfissionais();
    
    static std::list<Profissional*>& getProfissionais();

    void setCargaHoraria(const unsigned short cargaHoraria);
    unsigned short getCargaHoraria() const;

    void setValorHora(const unsigned short valorHora);
    unsigned short getValorHora() const;

    unsigned int getSalario() const;

    unsigned int getId() const;

    static Profissional* acharProfissional();
    static void imprimirProfissionais();

  private:
    static std::list<Profissional*> profissionais;
    static unsigned int proxId;
    unsigned short cargaHoraria;
    unsigned short valorHora;
    unsigned int id; 
};
}
#endif