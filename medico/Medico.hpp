#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <iostream>
#include <list>
#include <string>
#include "OpInvalidoException.hpp"
#include "Usuario.hpp"
#include "Profissional.hpp"

namespace postinho{
class Medico : public Profissional{
  public:
    Medico(const std::string& nome, const unsigned short idade, const unsigned long cpf,
          const unsigned short cargaHoraria, const unsigned short valorHora, const std::string& especializacao); 
    virtual ~Medico();
    static void limpaMedicos();

    static Medico* acharMedico();
    static Medico* cadastrarMedico();
    static void removerMedico();
    static void imprimirMedicos();

    void setEspecializacao(const std::string& especializacao);
    std::string getEspecializacao() const;
    void addEspecializacao(const std::string& especializacao);

    void alterarFichaPaciente(Usuario* paciente);

    static std::list<Medico*>& getMedicos(); 
    
  private:
    void alterarNecessidadesEspeciais(Ficha* ficha);
    void adicionarNecessidadesEspeciais(Ficha* ficha);
    void alterarFumante(Ficha* ficha);
    void alterarDoencaCronica(Ficha* ficha);
    void adicionarDoencaCronica(Ficha* ficha);
    void alterarTipoSanguineo(Ficha* ficha);
    void alterarPeso(Ficha* ficha);
    void alterarAltura(Ficha* ficha);
    static std::list<Medico*> medicos;
    std::string especializacao; 
};
}
#endif
