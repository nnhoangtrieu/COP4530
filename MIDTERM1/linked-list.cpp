#include <iostream>


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
        LinkedList() : head(nullptr) {};

        ~LinkedList() 
        {
            Node<T>* temp = head;
            Node<T>* nextNode;
            while (temp != nullptr)
            {
                nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }

            std::cout << "Destroyed Linked List" << std::endl;
        }

        void display()
        {
            for (Node<T>* p = head; p != nullptr; p=p->next)
            {
                std::cout << p->data << " -> ";
            }
            std::cout << "nullptr" << std::endl;
        }


        void insertFront(T value)
        {
            Node<T>* nextNode = new Node<T>(value);
            nextNode->next = head;
            head = nextNode;
        }

        void insertEnd(T value) 
        {
            Node<T>* newNode = new Node<T>(value);
            if (head == nullptr) head = newNode;

            Node<T>* cur = head;
            while (cur->next != nullptr)
            {
                cur = cur->next;
            }
            cur->next = newNode;
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

        void removeEnd()
        {
            if (head == nullptr) return;

            if (head->next == nullptr)
            {
                head = head->next;
                return;
            }

            Node<T>*cur = head;
            while (cur->next->next != nullptr)
            {
                cur = cur->next;
            }
            
            Node<T>* nodeToRemove = cur->next;
            cur->next = nodeToRemove->next;
            delete nodeToRemove;
        }

        bool search(T value) 
        {
            if (head == nullptr) return false;

            Node<T>* cur = head;
            while (cur != nullptr)
            {
                if (cur->data == value) return true;
                cur = cur->next;
            }
            return false;

        }

        void insertAfter(T findValue, T addValue)
        {
            if (head != nullptr)
            {
                Node<T>* cur = head;
                while (cur != nullptr && cur->data != findValue) 
                {
                    cur = cur->next;
                }
                if (cur == nullptr) return;
                Node<T>* newNode = new Node<T>(addValue);
                newNode->next = cur->next;
                cur->next = newNode;
            }
        }
};











int main()
{
    LinkedList<int> list;

    list.insertFront(10);    
    list.insertFront(20);    
    list.insertFront(30);    
    list.insertEnd(40);

    list.insertAfter(10, 25);
    list.insertAfter(25, 80);
    list.display();
}