﻿//Longest palindromic Subsequence
//time complexity O(n*n)
//space complexity O(n*n).
using System;
namespace Csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = "GEEKSFORGEEKS";
            int n = s.Length;
            int[,] resultTable = new int[n, n];
            int lpsLength = lps(s, resultTable, n);
            string ps = lpsString(s, resultTable, n, lpsLength);

            Console.WriteLine(ps);
        }
        static int lps(string s, int[,] resultTable, int n)
        {
            for (int i = 0; i < n; i++)
                resultTable[i, i] = 1;

            for (int c = 2; c <= n; c++)
            {
                for (int i = 0; i < n - c + 1; i++)
                {
                    int j = i + c - 1;
                    if (s[i] == s[j] && c == 2) {
                      
                        resultTable[i, j] = 2;
                    }
                    else if (s[i] == s[j]) {
                        resultTable[i, j] = resultTable[i + 1, j - 1] + 2;
                        
                    }
                    else
                        resultTable[i, j] = max(resultTable[i + 1, j], resultTable[i, j - 1]);
                }
            }
         
            return resultTable[0, n - 1];

        }

       static string lpsString(string s, int[,] resultTable, int n, int maxLength)
        {
            char[] ps = new char[maxLength];
            int i = 0;
            int j = n - 1;
            int startIndex = 0;
            int endIndex = maxLength -1;

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
                else if (resultTable[i + 1, j] > resultTable[i, j - 1])
                    i = i + 1;
                else
                    j = j - 1;
            }

            return new string(ps);
        }

        static int max(int a, int b)
        {
            return a > b ? a : b;
        }

    }
}
