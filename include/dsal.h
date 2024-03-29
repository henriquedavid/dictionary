#ifndef DSAL_H
#define DSAL_H

#include <cstring>
#include <algorithm>

#include "dal.h"



/// Classe para tratar um dicionário com vetor ordenado.
template < typename Key, typename Data, typename KeyComparator = std::less<Key>>
class DSAL : public DAL<Key, Data, KeyComparator>
{

    using NodeAL = typename DAL<Key, Data, KeyComparator>::NodeAL;

public:
    DSAL(int _MaxSz = SIZE);
    virtual ~DSAL() { /* Empty */ };

    // Métodos para sobreescrever.
    /// Remove da lista.
    bool remove( const Key & _x, Data & );
    /// Inserir na lista.
    bool insert( const Key & _novaId, const Data & _novaInfo );
    /// Recupera a menor chave do dicionário .
    Key min() const;
    /// Recupera a maior chave do dicionário .
    Key max() const;
    /// Recupera em _y a chave sucessora a _x , se existir ( true ).
    bool sucessor( const Key & _x, Key & _y ) const;
    /// Recupera em _y a chave antecessora a _x , se existir ( true ).
    bool predecessor( const Key & _x, Key & _y ) const;
    bool search(const Key &_x, Data &_s) const;

    friend std::ostream & operator<<(std::ostream & _os, const DSAL & _oList)
    {
        _os << "[ \n";
        for( int i(0) ; i < _oList.mi_Length ; ++i ){
            _os << "{id: " <<  _oList.mpt_Data[i].id << ", info: " << _oList.mpt_Data[i].info << "} \n";
        }
        _os << "]";
        return _os;
    }

private:
    /// Método para busca auxiliar.
    int _search( const Key & _x ) const;
    /// Tamanho default da lista.
    using DAL<Key, Data, KeyComparator>::SIZE;
    /// Comprimento atual da lista.
    using DAL<Key, Data, KeyComparator>::mi_Length;
    /// Capacidade máxima de armazenamento.
    using DAL<Key, Data, KeyComparator>::mi_Capacity;
    /// Área de armazenamento: vetor alocado dinamicamente.
    using DAL<Key, Data, KeyComparator>::mpt_Data;
};

#include "dsal.inl"

#endif
