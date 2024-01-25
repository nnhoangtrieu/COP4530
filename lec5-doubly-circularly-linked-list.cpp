#include <iostream>


using namespace std;


template <typename T>
class Node 
{
    public: 
        T data; 
        Node *prev; 
        Node *next;

        Node(const T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList
{
    private:
        Node<T>* head;

    public: 
        DoublyLinkedList() : head(nullptr) {}


        void insertFront(const T& value) 
        {
            Node<T>* newNode = new Node(value);

            if (!head) 
            {
                head = newNode;
            }
            else 
            {
                newNode->next = head;
                head->prev = newNode; 
                head = newNode;
            }
        }

        void insertBack(const T& value) 
        {
            Node<T>* newNode = new Node(value);

            if (!head) 
            {
                head = newNode;
            }
            else 
            {
                Node<T>* cur = head;

                while (cur->next) 
                {
                    cur = cur->next;
                }

                cur->next = newNode;
                newNode->prev = cur;
            }
        }


        void removeFront()
        {
            if (head) 
            {
                Node<T>* temp = head;
                head = head->next;

                if (head)
                {
                    head->prev = nullptr;
                }
                delete temp;
            }
        }


        void removeBack()
        {
            if (head)
            {
                if (!head->next)
                {
                    delete head;
                    head = nullptr;
                }
                else 
                {
                    Node<T>* cur = head;
                    while (cur->next->next)
                    {
                        cur = cur->next;
                    }
                    delete cur->next;
                    cur->next = nullptr;
                }
            }
        }

        
        ~DoublyLinkedList() 
        {
            while (head) 
            {
                Node<T>* temp = head; 
                head = head->next;
                delete temp;
            }
        }
}




int main ()
{

}