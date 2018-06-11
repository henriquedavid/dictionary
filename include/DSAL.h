#ifndef DSAL
#define DSAL

/// Classe para tratar um dicionário com vetor ordenado.
class DSAL : public dic::DAL
{

public:
	DSAL( int _MaxSz ){ /* empty */ };
	virtual ~DSAL() { /*empty*/ };

	// Métodos para sobreescrever.
	/// Remove da lista.
	bool remove( const Key & _x, Data & );
	/// Inserir na lista.
	bool insert( const Key & _novaId, const Data & _novaInfo );
	/// Recupera a menor chave do dicion´ario .
	Key min() const;
	/// Recupera a maior chave do dicion´ario .
	Key max() const;
	/// Recupera em _y a chave sucessora a _x , se existir ( true ).
	bool sucessor( const Key & _x, Key & _y ) const;
	/// Recupera em _y a chave antecessora a _x , se existir ( true ).
	bool predecessor( const Key & _x, Key & _y ) const;

private:
	/// Método para busca auxiliar.
	int _search( const Key & _x ) const;
}

#endif