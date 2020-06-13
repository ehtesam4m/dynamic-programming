//Time complexity O(N*M)
//Space complexity O(N*M)
#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    int **resultArray = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        resultArray[i] = new int[W + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int w = 0; w < W + 1; w++)
        {
            if (i == 0 || w == 0)
                resultArray[i][w] = 0;
            else if (wt[i - 1] <= w)
                resultArray[i][w] = max(resultArray[i - 1][w], val[i - 1] + resultArray[i - 1][w - wt[i - 1]]);
            else
                resultArray[i][w] = resultArray[i - 1][w];
        }
    }
    int result = resultArray[n][W];
    for (int i = 0; i < n + 1; i++)
        delete[] resultArray[i];
    delete resultArray;
    return result;
}
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
}
