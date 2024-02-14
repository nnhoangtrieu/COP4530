#include <iostream>


template <typename T>
class Node 
{
    public: 
        T data;
        Node* next;
        Node* prev;

        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};


template <typename T>
class DoublyLinkedList
{
    private: 
        Node<T>* head;
        Node<T>* tail;
    
    public: 
        DoublyLinkedList() : head(nullptr), tail(nullptr) {};

        ~DoublyLinkedList()
        {
            while (head != nullptr)
            {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
            std::cout << "Deleted Doubly Linked List" << std::endl;
        }


        void display()
        {
            for (Node<T>* p = head; p != nullptr; p = p->next)
            {
                std::cout << p->data << " -> ";
            }
            std::cout << "nullptr" << std::endl;
        }
        void insertFront(T value)
        {
            Node<T>* newNode = new Node<T>(value);
            if (head == nullptr) head = newNode;
            else 
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        void insertEnd(T value) 
        {
            Node<T>*newNode = new Node<T>(value);

            if (head == nullptr) head = newNode;
            
            Node<T>* cur = head;
            while (cur->next != nullptr)
            {
                cur = cur->next;
            }

            cur->next = newNode;
            newNode->prev = cur;
        }

        void removeFront()
        {
            if (head != nullptr)
            {
                Node<T>* temp = head;
                head = head->next;

                if (head != nullptr) 
                {
                    head->prev = nullptr;
                }
                delete temp;
            }
        }

        void removeEnd()
        {
            if (head == nullptr) return;
            if (head->next == nullptr) 
            {
                delete head;
                head = nullptr;
            }

            Node<T>* cur = head;

            while (cur->next->next != nullptr)
            {
                cur = cur->next;
            }
            delete cur->next;
            cur->next = nullptr;

        }

        bool search(T value)
        {
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
    DoublyLinkedList<int> list;
    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.insertEnd(50);
    list.removeFront();
    list.removeEnd();
    list.display();

    std::cout << list.search(15) << std::endl;
    return 0;
}