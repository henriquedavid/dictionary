#ifndef DAL_
#define DAL_

#include <cstring>
#include <stdexcept>


/// Classe para tratar um dicionário com vetor ordenado.
template < typename Key, typename Data, typename KeyComparator = std::less<Key>>
class DAL
{
protected:

    /// Estrutura do nó, representando o par chave-informação.
    struct NodeAL
    {
        /// A chave é um inteiro simples.
        Key id;
        /// A informação é uma cadeia de caracteres.
        Data info;

    };

    /// Tamanho default da lista.
    static const int SIZE = 50;
    /// Comprimento atual da lista.
    int mi_Length;
    /// Capacidade máxima de armazenamento.
    int mi_Capacity;
    /// Área de armazenamento: vetor alocado dinamicamente.
    NodeAL * mpt_Data;

    /// Método de busca auxiliar.
    int _search( const Key & _x ) const;

public:

    DAL( int _MaxSz = SIZE );
    virtual ~DAL() { delete [] mpt_Data; };
    /// Remove da lista.
    bool remove( const Key & _x, Data & _s );
    /// Busca pública.
    bool search( const Key & _x, Data & _s ) const;
    /// Insere na lista.
    bool insert( const Key & _newKey, const Data & _newInfo );
    /// Recupera a menor chave do dicionário.
    Key min() const;
    /// Recupera a maior chave do dicionário.
    Key max() const;
    /// Recupera em _y a chave sucessora a _x, se existir (true).
    bool successor( const Key & _x, Key & _y ) const;
    /// Recupera em _y a chave antecessora a _x, se existir (true).
    bool predecessor( const Key & _x, Key & _y ) const;
    /// Recupera a capacidade do dicionário
    size_t capacity();
    /// Retorna true se a lista estiver vazia e false caso o contrário.
    bool empty();

    /// Envia para saída uma representação em ASCII para a lista.
    inline friend std::ostream & operator<<(std::ostream & _os, const DAL & _oList){
        _os << "[ \n";
        for( int i(0) ; i < _oList.mi_Length ; ++i ){
            _os << "{id: " <<  _oList.mpt_Data[i].id << ", info: " << _oList.mpt_Data[i].info << "} \n";
        }
        _os << "]";
        return _os;
    }

};

#include "dal.inl"


#endif
