/*
Name: Trieu Nguyen / Tran Ho
*/

#include "IntDList.hpp"
#include "IntDList_node.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Constructor
IntDLList::IntDLList() 
{
    ListHead = nullptr;
}

// Destructor
IntDLList::~IntDLList() {
    while (ListHead)  
    {
        IntDLLNode *temp = ListHead;
        ListHead = ListHead->next;
        delete temp;
    }
}

// Insert a new node in ascending order
void IntDLList::insertInOrder(int value) 
{
    IntDLLNode* newNode = new IntDLLNode(value); // Create new node

    // If the list is empty or the value < than the head's value
    if (ListHead == nullptr || ListHead->info > value) 
    {
        // Insert the new node at the beginning of the list
        newNode->next = ListHead;
        if (ListHead)
        {
            ListHead->prev = newNode;
        }
        ListHead = newNode;
    }
    else 
    {
        // Traverse the list to find node with bigger value
        IntDLLNode* cur = ListHead;
        while (cur->next != nullptr && cur->next->info < value) 
        {
            cur = cur->next;
        }
        // Insert the new node after the current node
        newNode->next = cur->next;
        if (cur->next)
        {
            cur->next->prev = newNode;
        }
        cur->next = newNode;
        newNode->prev = cur;
    }
}



void IntDLList::addToHead(int value)

{
    IntDLLNode* newNode = new IntDLLNode(value);
    if (ListHead == nullptr) ListHead = newNode; // if the list has no node, the newNode become the Head
    else 
    {
        newNode->next = ListHead; // set pointer of newNode to point to Head
        ListHead->prev = newNode; // set pointer of Head to point back to newNode
        ListHead = newNode;       // set the Head to be the newNode
    }
}

void IntDLList::addToTail(int value)
{
    IntDLLNode* newNode = new IntDLLNode(value);

    if (!ListHead)
    {
        ListHead = newNode; // If list is empty, make new node the head
    }
    else 
    {
        // Traverse list to find last node
        IntDLLNode* cur = ListHead;
        while (cur->next)
        {
            cur = cur->next;
        }

        // Add new node to end of list
        cur->next = newNode;
        newNode->prev = cur;
    }
}


int IntDLList::deleteFromHead()
{
    int value = 0;
    if (ListHead)
    {
        IntDLLNode* temp = ListHead; // store head node in temporary variable
        value = temp->info;          // get value of head node for return
        ListHead = ListHead->next;   // move head pointer to next node

        if (ListHead)
        {
            ListHead->prev = nullptr; // set previous pointer of new head to null
        }
        delete temp; // delete previous node
    }

    return value;
}

int IntDLList::deleteFromTail()
{
    int value = 0;
    
    if (ListHead) // if list is not empty
    {
        if (!ListHead->next) // if list has only 1 node
        {
            value = ListHead->info; // get value of node to be deleted for return
            delete ListHead; 
            ListHead = nullptr; 
        }
        else 
        {
            IntDLLNode* cur = ListHead;
            while (cur->next->next) // traverse list to second last node
            {
                cur = cur->next;
            }
            value = cur->next->info; // get value of node to be deleted for return
            delete cur->next;
            cur->next = nullptr; // set next pointer of second last node to null
        }
    }
    return value;
}


void IntDLList::deleteNode(int value) {
    IntDLLNode* cur = ListHead;

    while (cur != nullptr && cur->info != value) {
        cur = cur->next;
        
    }

    // if value is not in list
    if (cur == nullptr) {
        return;
    }

    // if node to be deleted is the head
    if (cur->prev == nullptr) {
        cout << "test";
        ListHead = cur->next;
    } else {
        cur->prev->next = cur->next;
    }

    // if node to be deleted is not the tail
    if (cur->next != nullptr) {
        cur->next->prev = cur->prev;
    }

    delete cur;
}





bool IntDLList::isInList(int value) const {
    IntDLLNode* cur = ListHead;
    // traverse list
    while (cur) {
        if (cur->info == value) {
            return true; // return true if current node contain the value
        }
        cur = cur->next; // move to next node
    }
    return false; // return false if node is not in list
}


  
string IntDLList::addToString() const {
    stringstream ss;
    ss << setw(0); // set width to 0 (no padding)

    // traverse the list and add each node's value to the stringstream
    for (IntDLLNode* p = ListHead; p != nullptr; p = p->next) {
        ss << p->info << ""; // add value followed by an empty string 
    }

    return ss.str(); // convert the stringstream to a string and return
}




void IntDLList::display()
{
    for (IntDLLNode *p = ListHead; p != nullptr; p = p->next) 
    {
        cout << p->info << " <-> ";
    }
    cout << "nullptr" << endl;
}
