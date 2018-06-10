namespace dc{

	template < typename KeyType, typename DataType >
	class Dictionary{

	private:

	public:
		DataType * search( const KeyType & );
		void insert( DataType & );
		void remove( DataType & );
		DataType max();
		DataType min();
		DataType predecessor( KeyType & );
		DataType sucessor( KeyType & );

	};
}