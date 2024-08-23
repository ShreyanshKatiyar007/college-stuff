/*Alexa has two stacks of non-negative integers, stack and stack where
index denotes the top of the stack. Alexa challenges Nick to play the following game:
 In each move, Nick can remove one integer from the top of either stack or stack.
 Nick keeps a running sum of the integers he removes from the two stacks.
 Nick is disqualified from the game if, at any point, his running sum becomes greater
than some integer given at the beginning of the game.
 Nick's final score is the total number of integers he has removed from the two
stacks.

Given, and for games, find the maximum possible score Nick can achieve.*/

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int twoStacks(int maxSum, int a[], int n, int b[], int m)
{
    int ans = 0, sum = 0;
    int indexA = 0, indexB = 0;
    while (indexA < n && sum + a[indexA] <= maxSum)
    {
        sum += a[indexA];
        indexA++;
    }
    ans = indexA;
    while (indexB < m && indexA >= 0)
    {
        sum += b[indexB];
        indexB++;
        while (sum > maxSum && indexA > 0)
        {
            indexA--;
            sum -= a[indexA];
        }
        if (sum <= maxSum)
        {
            ans = max(ans, indexA + indexB);
        }
    }
    return ans;
}
int main()
{
    int t, i;
    cin >> t;
    while (t--)
    {
        int n, m, maxSum;
        cin >> n >> m >> maxSum;
        int a[MAX], b[MAX];
        for (i = 0; i < n; ++i)
            cin >> a[i];
        for (i = 0; i < m; ++i)
            cin >> b[i];
        cout << twoStacks(maxSum, a, n, b, m) << endl;
    }
    return 0;
}
