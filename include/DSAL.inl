#include "DSAL.h"

bool dic::DSAL::remove( const Key & _x, Data &_s)
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

bool dic::DSAL::insert( const Key & _novaId, const Data & _novaInfo )
{
    // verifica capacidade
    if(mi_Length == mi_Capacity)
        return false;
    // procura a nova posição de _novaId realoca os elementos
    auto slow(mpt_Data);
    auto end(mpt_Data + mi_Length);
    while(slow < end)
    {
        if(slow->id > _novaId)
            break;
        ++slow;
    }
    auto fast(slow);
    while(fast + 1 <= end)
    {
        std::swap(*fast, *(fast+1));
        fast++;
    }
    slow->id = _novaId;
    slow->info = _novaInfo;
    mi_Length++;
    return true;
}
dic::DSAL::Key dic::DSAL::min() const
{
    if(mi_Length == 0)
        throw std::out_of_range("[Error]: Dictionary has no elements.");
    return mpt_Data[0].id;
}
dic::DSAL::Key dic::DSAL::max() const
{
    if(mi_Length == 0)
        throw std::out_of_range("[Error]: Dictionary has no elements.");
    return mpt_Data[mi_Length-1].id;
}
bool dic::DSAL::sucessor( const Key & _x, Key & _y ) const
{
    int index = _search(_x);
    if(index >= mi_Length)
        return false;
    _y = mpt_Data[index+1].id;
    return true;
}

bool dic::DSAL::predecessor( const Key & _x, Key & _y ) const
{
    int index = _search(_x);
    if(index < 1)
        return false;
    _y = mpt_Data[index-1].id;
    return true;
}

bool dic::DSAL::search(const Key &_x, Data &_s) const
{
    // realiza a busca binária pela chave x;
    int index = _search(_x);
    if(index == -1)
        return false;
    _s = mpt_Data[index].info;
    return true;

}
int dic::DSAL::_search(const Key &_x) const
{
    // acha o meio do vetor
    int begin_index= 0;
    int end_index = mi_Length;
    int middle_index;
    while(begin_index < end_index)
    {
        middle_index = begin_index + (end_index - begin_index)/2;
        auto key = mpt_Data[middle_index].id;
        if(key == _x)
            return middle_index;
        else if(key > _x)
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
