#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include "Consulta.hpp"
#include "Estoque.hpp"
#include "Gerente.hpp"

namespace postinho{
class Interface{
  public:
    Interface() = default;
    virtual ~Interface() = default;
    static void painelPrincipal();
    static void estoque();
    static void consulta();
    static void profissional();
    static void usuario();
};
}
#endif
