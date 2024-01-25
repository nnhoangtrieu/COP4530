#include <iostream>

using namespace std;




template <typename T>
class Node
{
    public: 
        T data; 
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
};


template <typename T> 
class LinkedList 
{
    private: 
        Node<T>* head; 
    
    public: 
        LinkedList() : head(nullptr) {} 

        void insertFront(T value) 
        {
            Node<T>* newNode = new Node<T> (value);
            newNode->next = head;
            head = newNode;
        }

        
        void insertAfter(T valueToFind, T valueToInsert) 
        {
            Node<T>* cur = head;

            while (cur != nullptr && cur ->data != valueToFind) 
            {
                cur = cur->next;
            }

            if (cur != nullptr) 
            {
                Node<T>* newNode = new Node<T> (valueToInsert);
                newNode->next = cur->next;
                cur->next = newNode;
            }
        }


        void removeFront()
        {
            if (head != nullptr) 
            {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }


        void display() 
        {
            Node<T>* temp = head;
            while (temp != nullptr) 
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
        

        ~LinkedList() 
        {
            Node<T>* temp = head;
            while (temp != nullptr) 
            {
                Node<T>* next = temp->next;
                delete temp;
                temp = next;
            }
        }
};


int main ()
{
    LinkedList<int> list; 
    list.insertFront(5);
    list.insertFront(10);
    list.insertFront(15);
    
    cout << "Before insert after 10: ";

    list.display();
    
    cout << "After insert after 10: ";

    list.insertAfter(10, 11);
    list.display(); 

}