#include "DSAL.h"


template < typename Key, typename Data, typename KeyComparator >
inline dic::DSAL< Key, Data, KeyComparator >::DSAL( int _MaxSz ){
    mi_Length = 0;
    mi_Capacity = _MaxSz;
    mpt_Data = new NodeAL[SIZE];
}

template < typename Key, typename Data, typename KeyComparator >
inline bool dic::DSAL< Key, Data, KeyComparator >::remove( const Key & _x, Data &_s)
{

    int index = _search(_x);
    if(index == -1)
        return false;
    _s = mpt_Data[index].info;
    for(int c = index; c < mi_Length -1; ++c)
    {
        mpt_Data[c] = mpt_Data[c+1];
    }
    mi_Length--;
    return true;
}

template < typename Key, typename Data, typename KeyComparator >
inline bool dic::DSAL< Key, Data, KeyComparator >::insert( const Key & _novaId, const Data & _novaInfo )
{
    KeyComparator cmp;

    // verifica capacidade
    if(mi_Length == mi_Capacity)
        return false;
    // procura a nova posição de _novaId realoca os elementos
    auto slow(mpt_Data);
    auto end(mpt_Data + mi_Length);
    while(slow < end)
    {
        if(cmp(slow->id, _novaId) == 1)
            break;
        ++slow;
    }
    auto fast(end);

    while(fast > slow)
    {
        std::swap(*fast, *(fast-1));
        fast--;
    }

    slow->id = _novaId;
    slow->info = _novaInfo;
    mi_Length++;

    return true;
}

template < typename Key, typename Data, typename KeyComparator >
inline Key dic::DSAL< Key, Data, KeyComparator >::min() const
{
    if(mi_Length == 0)
        throw std::out_of_range("[Error]: Dictionary has no elements.");
    return mpt_Data[0].id;
}

template < typename Key, typename Data, typename KeyComparator >
inline Key dic::DSAL< Key, Data, KeyComparator >::max() const
{
    if(mi_Length == 0)
        throw std::out_of_range("[Error]: Dictionary has no elements.");
    return mpt_Data[mi_Length-1].id;
}

template < typename Key, typename Data, typename KeyComparator >
inline bool dic::DSAL< Key, Data, KeyComparator >::sucessor( const Key & _x, Key & _y ) const
{
    int index = _search(_x);
    if(index >= mi_Length)
        return false;
    _y = mpt_Data[index+1].id;
    return true;
}

template < typename Key, typename Data, typename KeyComparator >
inline bool dic::DSAL< Key, Data, KeyComparator >::predecessor( const Key & _x, Key & _y ) const
{
    int index = _search(_x);
    if(index < 1)
        return false;
    _y = mpt_Data[index-1].id;
    return true;
}

template < typename Key, typename Data, typename KeyComparator >
inline bool dic::DSAL< Key, Data, KeyComparator >::search(const Key &_x, Data &_s) const
{
    // realiza a busca binária pela chave x;
    int index = _search(_x);
    if(index == -1)
        return false;
    _s = mpt_Data[index].info;
    return true;

}

template < typename Key, typename Data, typename KeyComparator >
inline int dic::DSAL< Key, Data, KeyComparator >::_search(const Key &_x) const
{

    KeyComparator cmp;

    // acha o meio do vetor
    int begin_index= 0;
    int end_index = mi_Length;
    int middle_index;
    while(begin_index <= end_index)
    {
        middle_index = begin_index + (end_index - begin_index)/2;
        auto key = mpt_Data[middle_index].id;
        if(cmp(key, _x) == 0)
            return middle_index;
        else if(cmp(key, _x) == 1)
        {
            end_index = middle_index;
        }
        else
        {
            begin_index = middle_index+1;
        }
    }
    return -1;
}
