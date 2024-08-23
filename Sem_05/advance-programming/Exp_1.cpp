/*You have three stacks of cylinders where each cylinder has the same
diameter, but they may vary in height. You can change the height of a stack by removing and
discarding its topmost cylinder any number of times.
Find the maximum possible height of the stacks such that all of the stacks are exactly the same
height. This means you must remove zero or more cylinders from the top of zero or more of the
three stacks until they are all the same height, then return the height.*/

#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, i;
    cin >> a >> b >> c;
    int h1[a], h2[b], h3[c];
    for (i = 0; i < a; i++)
        cin >> h1[i];
    for (i = 0; i < b; i++)
        cin >> h2[i];
    for (i = 0; i < c; i++)
        cin >> h3[i];

    int sum1 = accumulate(h1, h1 + a, 0);
    int sum2 = accumulate(h2, h2 + b, 0);
    int sum3 = accumulate(h3, h3 + c, 0);
    int t1 = 0, t2 = 0, t3 = 0;

    while (true)
    {
        if (sum1 == sum2 && sum2 == sum3)
        {
            cout << sum1 << endl;
            break;
        }
        if (sum1 >= sum2 && sum1 >= sum3)
        {
            if (t1 < a)
                sum1 -= h1[t1++];
        }
        else if (sum2 >= sum1 && sum2 >= sum3)
        {
            if (t2 < b)
                sum2 -= h2[t2++];
        }
        else if (sum3 >= sum1 && sum3 >= sum2)
        {
            if (t3 < c)
                sum3 -= h3[t3++];
        }
    }
    return 0;
}
