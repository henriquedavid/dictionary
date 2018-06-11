#include "DAL.h"

using namespace dic;

inline DAL::DAL( int _MaxSz = SIZE ){
	mi_Length = 0;
	mi_Capacity = _MaxSz;
	mpt_Data = new NodeAL[SIZE];
}

inline bool DAL::insert( const Key & _newKey, const Data & _newInfo ){

	auto begin(mpt_Data);
	auto end(mpt_Data+mi_Length+1);

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

	auto pos(mpt_Data + mi_Length + 1);

	NodeAL new_NodeAL;
	new_NodeAL.id = _newKey;
	new_NodeAL.info = _newInfo;

	*pos = new_NodeAL;
	++mi_Length;

	return true;
}