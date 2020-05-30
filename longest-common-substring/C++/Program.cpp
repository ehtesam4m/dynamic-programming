#include <iostream>
#include <string>
using namespace std;

//Longest Common Substring
//time complexity O(n*m)
//space complexity O(n*m). Can be reduced to 2m
int main()
{
    string x = "OldSite:GeeksforGeeks.org";
    string y = "NewSite:GeeksQuiz.com";

    int n = x.size();
    int m = y.size();
    int maxlength = 0;
    int index1 = 0;

    int** resultTable = new int* [n + 1];
    for (int i = 0; i < n+1; i++)
        resultTable[i] = new int[m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                resultTable[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
            {
                resultTable[i][j] = resultTable[i - 1][j - 1] + 1;
                if (resultTable[i][j] > maxlength)
                {
                    maxlength = resultTable[i][j];
                    index1 = i;
                }
            }
            else
                resultTable[i][j] = 0;
        }
    }
    int temp = maxlength;
    string resultString = "";
    while (temp > 0)
    {
        resultString = x[index1 - 1] + resultString;
        temp--;
        index1--;
    }
    cout << resultString;

    for(int i=0;i< n+1; i++)
        delete[] resultTable[i];
    delete resultTable;
    return 0;
}