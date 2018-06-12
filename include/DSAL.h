#ifndef DSAL_H
#define DSAL_H

#include <cstring>
#include <algorithm>

#include "DAL.h"

namespace dic{

/// Classe para tratar um dicionário com vetor ordenado.
    template < typename Key, typename Data, typename KeyComparator >
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
        static const int SIZE = 50;
        /// Comprimento atual da lista.
        int mi_Length;
        /// Capacidade máxima de armazenamento.
        int mi_Capacity;
        /// Área de armazenamento: vetor alocado dinamicamente.
       NodeAL * mpt_Data;
    };
}
#include "DSAL.inl"

#endif
