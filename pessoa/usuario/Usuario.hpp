#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include <memory>
#include <list>
#include "Ficha.hpp"
#include "Pessoa.hpp"

namespace postinho{
class Usuario : virtual public Pessoa{
  public:
    Usuario(const std::string& nome, const unsigned short idade, 
            const unsigned long cpf);
    virtual ~Usuario();
    static void limpaUsuarios();

    void setFicha(Ficha* ficha);
    Ficha* getFicha() const;
    
    static std::list<Usuario*>& getUsuarios();

    static Usuario* acharUsuario();
    static Usuario* cadastrarUsuario();
    static void imprimirUsuarios();
    static void removerUsuario();
    
  private:
    static std::list<Usuario*> usuarios;
    Ficha* ficha;
};
}
#endif
