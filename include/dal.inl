#include "dal.h"
#include "dsal.h"

template < typename Key, typename Data, typename KeyComparator >
inline DAL< Key, Data, KeyComparator >::DAL( int _MaxSz ){
	mi_Length = 0;
	mi_Capacity = _MaxSz;
	mpt_Data = new NodeAL[SIZE];
}

template < typename Key, typename Data, typename KeyComparator >
inline bool DAL< Key, Data, KeyComparator >::insert( const Key & _newKey, const Data & _newInfo ){

	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);

	KeyComparator cmp;

	// Verifica se não existe uma chave com o valor de _newKey. 
	while(begin != end){
        if(!cmp( begin->id, _newKey ) && !cmp(_newKey, begin->id))
			return false;
		begin++;
	}

	// Se não haver espaço então não é possível mais adicionar pois é tamanho fixo (Seção 3 - Linha 3).
	if(mi_Length >= mi_Capacity){
		return false;
	}

	auto pos(mpt_Data + mi_Length);

	// Insere as informações em um novo node;
	NodeAL new_NodeAL;
    pos->id = _newKey;
    pos->info = _newInfo;

	// Aumenta o tamanho ocupado.
	++mi_Length;

	return true;
}

template < typename Key, typename Data, typename KeyComparator >
inline bool DAL< Key, Data, KeyComparator >::search( const Key & _x, Data & _s ) const{

	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);

	KeyComparator cmp;

	// Percorre o dicionário procurando uma chave que seja igual a informada.
	while( begin != end ){
		if(  cmp(begin->id , _x) == 0 ){
			// Atribui a _s a informação que está na chave informada.
			_s = begin->info;
			return true;
		}
		++begin;
	}

	// Caso não encontrado retorna falso.
	return false;

}

template < typename Key, typename Data, typename KeyComparator >
inline Key DAL< Key, Data, KeyComparator >::min() const{

	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);

	// Verifica se há algum dado.
	if(mi_Length == 0)
		throw std::out_of_range("[Error]: Dictionary has no elements.");;

	int menor_chave = (begin+1)->id;

	KeyComparator cmp;

	// Percorre o vetor procurando a menor chave.
	while( begin != end ){
        if(cmp(begin->id, menor_chave)){
			menor_chave = begin->id;
		}
		++begin;
	}

	return menor_chave;
}

template < typename Key, typename Data, typename KeyComparator >
inline  Key DAL< Key, Data, KeyComparator >::max() const{

	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);


	// Verifica se há algum dado.
	if(mi_Length == 0)
		throw std::out_of_range("[Error]: Dictionary has no elements.");

	KeyComparator cmp;

	int maior_chave = begin->id;

	// Percorre o vetor procurando a menor chave.
	while( begin != end ){
        if(cmp(maior_chave, begin->id)){
			maior_chave = begin->id;
		}
		++begin;
	}

	return maior_chave;
}

template < typename Key, typename Data, typename KeyComparator >
inline bool DAL< Key, Data, KeyComparator >::remove( const Key & _x, Data & _s ){
    auto begin(mpt_Data);
    auto end(mpt_Data+mi_Length);

    KeyComparator cmp;

    // Percorre o vetor procurando a chave.
    while(begin != end){
        if(cmp(begin->id, _x) == false && cmp(_x, begin->id) == false){
            _s = begin->info;
            // Realoca os dados
            auto next(begin++);
            while(begin != end){
                std::swap(*begin, *next);
                begin++;
                next++;
            }
            // Diminua uma quantidade.
            --mi_Length;
            return true;
        }
        ++begin;
    }
    return false;
}

template < typename Key, typename Data, typename KeyComparator >
inline bool DAL< Key, Data, KeyComparator >::successor( const Key & _x, Key & _y ) const{

	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);

    KeyComparator cmp;
    auto min = _x;

    while(begin != end)
    {
        if(cmp(_x, begin->id) && cmp(begin->id, min))
            min = begin->id;
        ++begin;
    }
    _y = min;
    return _x != min;

}

template < typename Key, typename Data, typename KeyComparator >
inline bool DAL< Key, Data, KeyComparator >::predecessor( const Key & _x, Key & _y ) const{

	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);

	KeyComparator cmp;
    auto max = _x;

    while(begin != end)
    {
       if(cmp(_x, begin->id) && cmp(max, begin->id))
            max = begin->id;
        ++begin;
    }
    _y = max;
    return _x != max;

}

template < typename Key, typename Data, typename KeyComparator >
int DAL<Key,Data,KeyComparator>::_search( const Key & _x ) const{

	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);

	KeyComparator cmp;


	while( begin != end ){
		if( cmp(_x, begin->id ) == 0)
			return end - begin;
		begin++;	
	}

	return -1;
}

template < typename Key, typename Data, typename KeyComparator >
size_t DAL<Key,Data,KeyComparator>::capacity()
{
    return mi_Capacity;
}

template < typename Key, typename Data, typename KeyComparator >
bool DAL<Key,Data,KeyComparator>::empty()
{
    return mi_Length == 0;
}


