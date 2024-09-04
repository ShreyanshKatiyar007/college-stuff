// Apply the concept of Linked list and write code to Insert and Delete an element at the beginning and at end in Circular Linked List.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteAtBeginning()
    {
        if (head == nullptr)
            return;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            Node *toDelete = head;
            temp->next = head->next;
            head = head->next;
            delete toDelete;
        }
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
            return;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != head)
            {
                temp = temp->next;
            }
            Node *toDelete = temp->next;
            temp->next = head;
            delete toDelete;
        }
    }

    void display()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    CircularLinkedList cll;

    cll.insertAtBeginning(10);
    cll.insertAtBeginning(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);

    cout << "Circular Linked List: ";
    cll.display();

    cll.deleteAtBeginning();
    cll.deleteAtEnd();

    cout << "After Deletion: ";
    cll.display();

    return 0;
}
