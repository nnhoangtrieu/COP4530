#include "IntDList.hpp"
#include <iostream>


IntDLList::IntDLList()
{
    ListHead = nullptr;
}

IntDLList::~IntDLList()
{
    while (ListHead)
    {
        IntDLLNode* temp = ListHead;
        ListHead = ListHead->next;
        delete temp;
    }
}

int main()
{
    IntDLList list;
}