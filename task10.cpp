
/* Q.2 Given an array A[] consisting of N integers from a range [1, N], the task is to calculate the count of  array elements (non-distinct) that can be represented as the sum of two or more consecutive array  elements. 
 Input: a[] = {3, 1, 4, 1, 5, 9, 2, 6, 5} 
 Output: 5 
 Explanation: 
 The array elements satisfying the condition are:  
 4 = 3 + 1 
 5 = 1 + 4 or 4 + 1  
 9 = 3 + 1 + 4 + 1  
 6 = 1 + 5 or 1 + 4 + 1  
 5 = 1 + 4 or 4 + 1 
 Input: a[] = {1, 1, 1, 1, 1} 
*/


#include <iostreAm>
#include <bits/stdc++.h>
using namespace std;

int ElementCnt(int A[], int n)
{

    int Count[n + 1] = {0};
    memset(Count, 0, sizeof(Count));

    int Ans = 0;

    for (int i = 0; i < n; i++)
    {
        ++Count[A[i]];
    }

    for (int j = 0; j < n; ++j)
    {
        int sum = 0;

        for (int r = j; r < n; ++r)
        {
            sum += A[r];

            if (j == r)
                continue;

            if (sum <= n)
            {

                Ans += Count[sum];

                Count[sum] = 0;
            }
        }
    }

    return Ans;
}

int main()
{

    int A[] = {1,1,1,1,11,11};
    int N = sizeof(A) / sizeof(A[0]);
    cout << ElementCnt(A, N);
}
