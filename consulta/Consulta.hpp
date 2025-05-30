#ifndef CONSULTA_HPP
#define CONSULTA_HPP

#include <iostream>
#include <string>
#include <list>
#include "Medico.hpp"
#include "Usuario.hpp" 

namespace postinho{
class Consulta{
  public:
    Consulta(const std::string& data, Usuario* const usuario, Medico* const medico);
    virtual ~Consulta();
    
    void setData(const std::string& data);
    std::string getData() const;

    void setUsuario(Usuario* usuario);
    Usuario* getUsuario() const;

    void setMedico(Medico* medico);
    Medico* getMedico() const;

    void setStatus(const bool status);
    bool getStatus() const;

    void setMotivo(const std::string& motivo);
    std::string getMotivo() const;

    static void marcarConsulta(Usuario* usuario = nullptr, Medico* medico = nullptr);
    static Consulta* acharConsulta();
    static void cancelarConsulta();
    static void remarcarConsulta();
    static void abrirConsulta();
    static void imprimirConsultas();
    static void imprimirConsultasDia();

    static void limpaConsultas();

  private:
    static std::list<Consulta*> consultas;
    std::string data;
    Usuario* usuario;
    Medico* medico;
    bool status;
    std::string motivo;
};
}
#endif
