// Circular Linked List 

struct Node 
{
    int data;
    Node* next;

    Node(int value) : data(value) {};
};




void removeAfterCursor(Node*& head, int cursorValue)
{
    if (head == nullptr || head->next == nullptr) return;

    Node* cur = head;

    while (cur->next != head)
    {
        if (cur->data == cursorValue)
        {
            Node* nodeToRemove = cur->next;

            if (nodeToRemove == head) 
            {
                head = head->next; 
            }
            cur->next = nodeToRemove->next;
            delete nodeToRemove;
            return;
        }
        cur = cur->next;
    }
}


void search(Node*& head, int cursorValue)
{
    if (head == nullptr) return false;

    Node* cur = head;
    while (cur->next == head)
    {
        if (cur->data == cursorValue) return true;
        cur = cur->next;
    }

    if (cur->data == cursorValue) return true;
    return false;
}