#ifndef FICHA_HPP
#define FICHA_HPP

#include <iostream>
#include <string>

namespace postinho{
class Ficha{
  public:
    Ficha(); 
    virtual ~Ficha();

    void setNecessidadesEspeciais(const std::string& necessidades);
    std::string getNecessidadesEspeciais() const;
    void addNecessidadesEspeciais(const std::string& necessidades);

    void setFumante(const bool fumante);
    bool getFumante() const;

    void setDoencaCronica(const std::string& doencaCronica);
    std::string getDoencaCronica() const;
    void addDoencaCronica(const std::string& doencaCronica);

    void setTipoSanguineo (const std::string& tipoSanguineo);
    std::string getTipoSanguineo() const;

    void setPeso(const unsigned short peso);
    unsigned short getPeso() const;

    void setAltura(const unsigned int altura);
    unsigned int getAltura() const;

    void imprimirFicha() const;

  private:
    std::string necessidadesEspeciais;
    bool fumante;
    std::string doencaCronica;
    std::string tipoSanguineo;
    unsigned short peso;
    unsigned int altura;
};
}
#endif