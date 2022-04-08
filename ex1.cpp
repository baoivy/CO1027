#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};


Node* createLinkedList(int n)
{
    // TO DO
    int count = 0;
    Node* head = nullptr;
    while (count != n)
    {
        int x; cin >> x;
        Node* temp = new Node;
        temp->value = x;
        temp->next = nullptr;
        if (head == nullptr)
        {
            head = temp;
        }
        else {
            Node* ptr = head;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
        count++;
    }
    return head;
}

void print(Node* head)
{
    while (head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
}

Node* reduceDuplicate(Node* root)
{
    Node* ptr = root;
    while (ptr->next->next != nullptr)
    {
        Node* temp = ptr;
        while (temp->next->value == ptr->value)
        {
            Node* p = temp->next;
            temp->next = temp->next->next;
            delete p;
        }
        ptr = ptr->next;
    }
    return root;
}

int main()
{
    Node* head = createLinkedList(7);
    print(head);
    cout << endl;
    head = reduceDuplicate(head);
    print(head);
    return 0;
}
