/*You’re given the pointer to the head nodes of two linked lists.
Compare the data in the nodes of the linked lists to check if they are equal. If
all data attributes are equal and the lists are the same length, return 1 .
Otherwise, return 0.
*/

#include <iostream>
#include <list>
using namespace std;

int main()
{
    int numTests;
    cin >> numTests;

    while (numTests--)
    {
        int size1, size2;
        cin >> size1;
        list<int> list1(size1);
        for (int &item : list1)
            cin >> item;

        cin >> size2;
        list<int> list2(size2);
        for (int &item : list2)
            cin >> item;

        cout << (list1 == list2 ? "1" : "0") << endl;
    }
    return 0;
}
