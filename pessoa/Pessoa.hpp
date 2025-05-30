#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <stdexcept>
#include <cstdint>
#include <string>

namespace postinho{
class Pessoa{
  public:
    Pessoa();
    Pessoa(const std::string& nome, const unsigned short idade, const unsigned long cpf);
    virtual ~Pessoa();
    
    void setNome(const std::string& nome);
    std::string getNome() const;

    void setIdade(const unsigned short idade);
    unsigned short getIdade() const;

    void setCpf(const unsigned long cpf);
    unsigned long getCpf() const;

  private:
    bool validarCPF(unsigned long cpf);

    std::string nome;
    uint8_t idade;
    unsigned long cpf; 
};
}
#endif
