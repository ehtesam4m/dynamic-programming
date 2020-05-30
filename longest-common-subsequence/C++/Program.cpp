#include <iostream>

using namespace std;

int main()
{
    int n, m;
    int * firstSequence;
    int * secondSequence;
    cin >> n >> m;
    firstSequence = new int[n];
    secondSequence = new int[m];

    for (int i = 0; i < n; i++)
        cin >> firstSequence[i];
    for (int j = 0; j < m; j++)
        cin >> secondSequence[j];

    int ** resultTable = new int*[n+1];
    for(int i=0;i< n+1; i++)
        resultTable[i] = new int[m+1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {

            if (i == 0 || j == 0)
                resultTable[i][j] = 0;
            else if (firstSequence[i - 1] == secondSequence[j - 1])
                resultTable[i][j] = resultTable[i - 1][j - 1] + 1;
            else
                resultTable[i][j] = resultTable[i - 1][j] > resultTable[i][j - 1] ? resultTable[i - 1][j] : resultTable[i][ j - 1];
        }
    }
    int index = resultTable[n][m];
    int * largestSequence = new int[index];
    int k = n;
    int l = m;

    while (k >= 1 && l >= 1)
    {
        if (firstSequence[k - 1] == secondSequence[l - 1])
        {
            largestSequence[index - 1] = firstSequence[k - 1];
            k--;
            l--;
            index--;
        }
        else if (resultTable[k - 1][l] > resultTable[k][l - 1])
            k--;
        else
            l--;
    }
    for (int q = 0; q < resultTable[n][m]; q++)
        cout<<largestSequence[q]<<' ';

    delete[] firstSequence;
    delete[] secondSequence;
     for(int i=0;i< n+1; i++)
        delete[] resultTable[i];
    delete resultTable;
    delete largestSequence;
    return 0;
}