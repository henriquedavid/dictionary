#include "DAL.h"

using namespace dic;

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
		if( cmp( begin->id, _newKey ) == 0 )
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
	new_NodeAL.id = _newKey;
	new_NodeAL.info = _newInfo;

	// Atribui o novo node a lista.
	*pos = new_NodeAL;
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
		if( cmp(begin->id, menor_chave) == -1 ){
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
		if( cmp(begin->id, maior_chave) == 1 ){
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
		if(cmp(begin->id, _x) == 0 ){
			// Se encontrou a chave então verifique se o dado é o mesmo.
			if(begin->info == _s){
				// Se for o mesmo dado então sobreescreva com as informações seguintes.
				auto next(begin++);
				while(begin != end){
					begin = next;
					begin++;
					next++;
				}
				// Diminua uma quantidade.
				--mi_Length;
				return true;
			}
		}
		++begin;
	}


	return false;
}

template < typename Key, typename Data, typename KeyComparator >
inline bool DAL< Key, Data, KeyComparator >::sucessor( const Key & _x, Key & _y ) const{

	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);

	KeyComparator cmp;

	// Verifica se há algum dado.
	if(mi_Length <= 1)
		return false;
	
	 if(cmp(_x, (mpt_Data+mi_Length-1)->id) == 0)
		return false;
	

	int sucessor;

	// Encontra um valor menor que o passado.
	auto b_ (begin);
	if(!cmp(begin->id, _x) == 0){
		while(b_ != end){
			if(cmp(b_->id, _x) == 1)
				sucessor = b_->id;
			b_++;
		}
	}

	// Percorre o vetor procurando o sucessor da chave _x, sendo a que possui a menor distancia com o valor de _x.
	while( begin != end ){
		if( cmp(( _x - begin->id ), (_x - sucessor)) == 1 && cmp((_x - begin->id), 0) == -1 ){
			sucessor = begin->id;
		}
		++begin;
	}

	_y = sucessor;

	return true;

}

template < typename Key, typename Data, typename KeyComparator >
inline bool DAL< Key, Data, KeyComparator >::predecessor( const Key & _x, Key & _y ) const{

	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);

	KeyComparator cmp;


	// Verifica se há algum dado.
	if(mi_Length <= 1)
		return false;

	if(_x == mpt_Data->id)
		return false;

	int predecessor;

	if(begin->id != _x)
		predecessor = begin->id;

	// Percorre o vetor procurando o predecessor da chave _x, sendo a que possui a menor distancia com o valor de _x.
	while( begin != end ){
		if( cmp(( _x - begin->id ), (_x -predecessor)) == -1 && cmp((_x - begin->id),0 ) == 1){
			predecessor = begin->id;
		}
		++begin;
	}

	_y = predecessor;

	return true;

}

template < typename Key, typename Data, typename KeyComparator >
int DAL< Key, Data, KeyComparator >::_search( const Key & _x ) const{

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