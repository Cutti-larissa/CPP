#include "OpInvalidoException.hpp"

namespace postinho{
OpInvalidoException::OpInvalidoException(const std::string& motivo)
    :std::invalid_argument{"Opção inválida: "}, motivo{motivo}{}
}