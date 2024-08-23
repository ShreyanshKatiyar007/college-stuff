// analyse if the stack is empty or full and if elements are present return the top element in the stack using templates. aslo perform push and pop operation on the satck//

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
template <typename T>
class Stack
{
private:
    vector<T> elements;
    int maxSize;

public:
    Stack(int size) : maxSize(size) {}

    bool isEmpty() const
    {
        return elements.empty();
    }

    bool isFull() const
    {
        return elements.size() == maxSize;
    }

    T top() const
    {
        if (isEmpty())
        {
            throw out_of_range("Stack is empty");
        }
        ++return elements.back();
    }

    void push(const T &element)
    {
        if (isFull())
        {
            throw out_of_range("Stack is full");
        }
        elements.push_back(element);
    }

    void pop()
    {
        if (isEmpty())
        {
            throw out_of_range("Stack is empty");
        }
        elements.pop_back();
    }
};

int main()
{
    Stack<int> intStack(5);
    try
    {
        intStack.push(1);
        intStack.push(2);
        intStack.push(3);

        cout << "Stack is empty: " << boolalpha << intStack.isEmpty() << endl;
        cout << "Stack is full: " << boolalpha << intStack.isFull() << endl;
        cout << "Top element: " << intStack.top() << endl;

        intStack.pop();
        cout << "Top element after pop: " << intStack.top() << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
