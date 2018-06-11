#ifndef DAL_
#define DAL_

#include "string"

namespace dic{

	class DAL
	{
	protected:
		/// Alias para chave.
		using Key = int;
		/// ALias para daoo.
		using Data = std::string;

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

		/// Método que retorna o tamanho para fins de testes.
		int size(){
			return mi_Length;
		}

		DAL( int _MaxSz );
		virtual ~DAL() { delete [] mpt_Data; };
		/// Remove da lista.
		bool remove( const Key & _x, Data & _s ) const;
		/// Busca pública.
		bool search( const Key & _x, Data & _s ) const;
		/// Insere na lista.
		bool insert( const Key & _newKey, const Data & _newInfo );
		/// Recupera a menor chave do dicionário.
		Key min() const;
		/// Recupera a maior chave do dicionário.
		Key max() const;
		/// Recupera em _y a chave sucessora a _x, se existir (true).
		bool sucessor( const Key & _x, Key & _y ) const;
		/// Recupera em _y a chave antecessora a _x, se existir (true).
		bool predecessor( const Key & _x, Key & _y ) const;	

		/// Envia para saída uma representação em ASCII para a lista.
		inline friend std::ostream & operator<<(std::ostream & _os, const DAL & _oList){
			_os << "[ ";
			for( int i(0) ; i < _oList.mi_Length ; ++i ){
				_os << "{id: " <<  _oList.mpt_Data[i].id << ", info: " << _oList.mpt_Data[i].info << "} ";
				_os << "]";
				return _os;
			}
		}
		
	};

	#include "DAL.inl"

}
#endif