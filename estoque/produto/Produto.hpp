#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <list>
#include <string>

namespace postinho{
class Produto{
  public:
    Produto(std::string& nome);
    virtual ~Produto() = default;

    void setNome(std::string& nome);
    std::string getNome() const;

    void setQuantEstoque(int quantidade);
    unsigned int getQuantEstoque() const;
    
  private:
    std::string nome;
    unsigned int quantEstoque;
};
}
#endif
