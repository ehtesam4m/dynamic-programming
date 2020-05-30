using System;
//Longest Common Substring
//time complexity O(n*m) 
//space complexity O(n*m). Can be reduced to 2m
namespace Csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            string x = "OldSite:GeeksforGeeks.org";
            string y = "NewSite:GeeksQuiz.com";

            int n = x.Length;
            int m = y.Length;
            int maxlength = 0;
            int index1 = 0;

            int[,] resultTable = new int[n + 1, m + 1];

            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= m; j++)
                {
                    if (i == 0 || j == 0)
                        resultTable[i, j] = 0;
                    else if (x[i - 1] == y[j - 1])
                    {
                        resultTable[i, j] = resultTable[i - 1, j - 1] + 1;
                        if (resultTable[i, j] > maxlength)
                        {
                            maxlength = resultTable[i, j];
                            index1 = i;
                        }
                    }
                    else
                        resultTable[i, j] = 0;
                }
            }
            int temp = maxlength;
            string resultString="";
            while(temp > 0)
            {
                resultString = x[index1 -1] + resultString;
                temp--;
                index1--;
            }
            Console.WriteLine(resultString);
        }
    }
}
