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

void IntDLList::addToHead(int value)
{
    IntDLLNode* newNode = new IntDLLNode(value);

    if (ListHead == nullptr)
    {
        ListHead = newNode;
    }
    else 
    {
        newNode->next = ListHead;
        ListHead->prev = newNode;
        ListHead = newNode;
    }
}



void IntDLList::addToTail(int value)
{
    IntDLLNode* newNode = new IntDLLNode(value);

    if (!ListHead)
    {
        ListHead = newNode;
    }
    else 
    {
        IntDLLNode* cur = ListHead;

        while (cur->next)
        {
            cur = cur->next;
        }

        cur->next = newNode;
        newNode->prev = cur;
    }
}


int IntDLList::deleteFromHead()
{
    int value = 0;
    if (ListHead)
    {
        IntDLLNode* temp = ListHead;
        value = temp->info;
        ListHead = ListHead->next;

        if (ListHead)
        {
            ListHead->prev = nullptr;
        }
        delete temp;
    }

    return value;
}

int IntDLList::deleteFromTail()
{
    int value = 0;

    if (ListHead)
    {
        if (!ListHead->next)
        {
            value = ListHead->info;
            delete ListHead;
            ListHead = nullptr;
        }
        else 
        {
            IntDLLNode* cur = ListHead;
            while (cur->next->next)
            {
                cur = cur->next;
            }
            value = cur->next->info;
            delete cur->next;
            cur->next = nullptr;
        }
    }
    return value;
}

void IntDLList::display()
{
   for (IntDLLNode *p = ListHead; p != nullptr; p = p->next)
   {
    cout << p->info<< " -> ";
   }
   cout << "nullptr" << endl;
}

int main()
{
    IntDLList list;
    list.addToHead(1);
    list.addToHead(2);
    list.addToHead(3);
    list.addToHead(4);
    list.addToTail(10);
    list.deleteFromHead();
    list.deleteFromTail();
    list.display();
}