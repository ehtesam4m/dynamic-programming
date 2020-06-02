//Longest palindromic Subsequence
//time complexity O(n*n)
//space complexity O(n*n).
#include <iostream>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int lps(string s, int **resultTable, int n)
{
    for (int i = 0; i < n; i++)
        resultTable[i][i] = 1;

    for (int c = 2; c <= n; c++)
    {
        for (int i = 0; i < n - c + 1; i++)
        {
            int j = i + c - 1;
            if (s[i] == s[j] && c == 2)
            {

                resultTable[i][j] = 2;
            }
            else if (s[i] == s[j])
            {
                resultTable[i][j] = resultTable[i + 1][j - 1] + 2;
            }
            else
                resultTable[i][j] = max(resultTable[i + 1][j], resultTable[i][j - 1]);
        }
    }

    return resultTable[0][n - 1];
}

string lpsString(string s, int **resultTable, int n, int maxLength)
{
    char *ps = new char[maxLength];
    int i = 0;
    int j = n - 1;
    int startIndex = 0;
    int endIndex = maxLength - 1;

    while (startIndex <= endIndex)
    {
        if (s[i] == s[j])
        {
            ps[startIndex] = s[i];
            ps[endIndex] = s[j];
            i++;
            j--;
            startIndex++;
            endIndex--;
        }
        else if (resultTable[i + 1][j] > resultTable[i][j - 1])
            i = i + 1;
        else
            j = j - 1;
    }

    string result = string(ps);
    delete ps;
    return result;
}

int main()
{
    string s = "GEEKSFORGEEKS";
    int n = s.size();
    int **resultTable = new int *[n];
    for (int i = 0; i < n; i++)
        resultTable[i] = new int[n];

    int lpsLength = lps(s, resultTable, n);
    string ps = lpsString(s, resultTable, n, lpsLength);

    cout << ps;
    for(int i=0;i< n; i++)
        delete[] resultTable[i];
    delete resultTable;
    return 0;
}
