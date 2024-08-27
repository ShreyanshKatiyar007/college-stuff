/*Given the pointer to the head node of a doubly linked list, reverse the
order of the nodes in place. That is, change the next and prev pointers of the
nodes so that the direction of the list is reversed. Return a reference to the
head node of the reversed list.
*/

#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node
{
    int data;
    Node *next;
    Node *prev;

    // Constructor to initialize a new node
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to reverse the doubly linked list
Node *reverseDoublyLinkedList(Node *head)
{
    Node *current = head;
    Node *temp = nullptr;

    // Traverse the list and swap next and prev pointers for each node
    while (current != nullptr)
    {
        // Swap the next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node in the original list (previous node in the reversed list)
        current = current->prev;
    }

    // Update head to the last node (now the new head of the reversed list)
    if (temp != nullptr)
    {
        head = temp->prev;
    }

    return head;
}

// Function to print the doubly linked list
void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Main function to demonstrate the reversal
int main()
{
    // Creating a sample doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original list: ";
    printList(head);

    // Reversing the doubly linked list
    head = reverseDoublyLinkedList(head);

    cout << "Reversed list: ";
    printList(head);

    // Free the memory (optional here, but good practice)
    Node *temp = nullptr;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
