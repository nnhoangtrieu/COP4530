// Singly and Doubly Linked List 

#include <iostream>


template <typename T>
class Node
{
    public: 
        T data;
        Node* next;

        Node<T>(T value) : data(value) {};
};

template <typename T>
class LinkedList
{
    private: 
        Node<T>* head;

    public: 
        LinkedList() : head(nullptr) {};

        void display()
        {
            for (Node<T>* p = head; p != nullptr; p=p->next) 
            {
                std::cout << p->data << " -> ";
            }
            std::cout << "null" << std::endl;
        }

        void insertFront(T value)
        {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = head;
            head = newNode;
        }

        void insertBack(T value) 
        {
            Node<T>* newNode = new Node<T>(value);
            if (head == nullptr)
            {
                head = newNode;
            }
            else 
            {
                Node<T>* cur = head;
                while (cur->next != nullptr)
                {
                    cur = cur->next;
                }
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

        void removeBack()
        {
            if (head == nullptr) return;
            if (head->next == nullptr) return;

            Node<T>* cur = head;
            while (cur->next->next)
            {
                cur = cur->next;
            }
            delete cur->next;
            cur->next = nullptr;
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
};







int main()
{


    LinkedList<int> list;
    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.insertBack(15);

    list.removeFront();
    list.removeBack();
    list.display();
    std::cout << list.search(10);
    return 0;
}