#ifndef OP_IVALIDO_EXCEPTION
#define OP_IVALIDO_EXCEPTION

#include <stdexcept>
#include <string>

namespace postinho{
class OpInvalidoException : public std::invalid_argument{
  public:
    std::string motivo;

    OpInvalidoException(const std::string& motivo);
    virtual ~OpInvalidoException() = default;
};
}

#endif
