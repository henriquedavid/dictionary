#include "DAL.h"

using namespace dic;

inline DAL::DAL( int _MaxSz = SIZE ){
	mi_Length = 0;
	mi_Capacity = _MaxSz;
	mpt_Data = new NodeAL[SIZE];
}

inline bool DAL::insert( const Key & _newKey, const Data & _newInfo ){


	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);

	// Verifica se não existe uma chave com o valor de _newKey. 
	while(begin != end){
		if( begin->id == _newKey )
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

inline bool DAL::search( const Key & _x, Data & _s ) const{

	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);

	// Percorre o dicionário procurando uma chave que seja igual a informada.
	while( begin != end ){
		if( begin->id == _x ){
			// Atribui a _s a informação que está na chave informada.
			_s = begin->info;
			return true;
		}
		++begin;
	}

	// Caso não encontrado retorna falso.
	return false;

}

/*inline bool DAL::remove( const Key & _x, Data & _s ) const;
*/
inline DAL::Key DAL::min() const{

	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);

	// Verifica se há algum dado.
	if(mi_Length == 0)
		return -1;

	int menor_chave = (begin+1)->id;

	// Percorre o vetor procurando a menor chave.
	while( begin != end ){
		if( begin->id < menor_chave ){
			menor_chave = begin->id;
		}
		++begin;
	}

	return menor_chave;
}

inline DAL::Key DAL::max() const{
	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length);

	// Verifica se há algum dado.
	if(mi_Length == 0)
		return -1;

	int maior_chave = begin->id;

	// Percorre o vetor procurando a menor chave.
	while( begin != end ){
		if( begin->id > maior_chave ){
			maior_chave = begin->id;
		}
		++begin;
	}

	return maior_chave;
}

/*
inline bool DAL::sucessor( const Key & _x, Key & _y ) const;

inline bool DAL::predecessor( const Key & _x, Key & _y ) const;	*/