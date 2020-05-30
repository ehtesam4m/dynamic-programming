using System;

namespace CSharp
{
  class Program
    {
        static void Main(string[] args)
        {
            int n, m;
            int[] firstSequence, secondSequence;

            int[] inputStringLengths = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            n = inputStringLengths[0];
            m = inputStringLengths[1];
            firstSequence = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            secondSequence = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

            int[,] resultTable = new int[n + 1, m + 1];

            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= m; j++)
                {

                    if (i == 0 || j == 0)
                        resultTable[i, j] = 0;
                    else if (firstSequence[i - 1] == secondSequence[j - 1])
                        resultTable[i, j] = resultTable[i - 1, j - 1] + 1;
                    else
                        resultTable[i, j] = resultTable[i - 1, j] > resultTable[i, j - 1] ? resultTable[i - 1, j] : resultTable[i, j - 1];
                }
            }
            int index = resultTable[n, m];
            int[] largestSequence = new int[index];
            int k = n;
            int l = m;
            
            while (k >= 1 && l >= 1)
            {
                if (firstSequence[k-1] == secondSequence[l-1])
                {
                    largestSequence[index - 1] = firstSequence[k - 1];
                    k--;
                    l--;
                    index--;
                }
                else if (resultTable[k-1, l] > resultTable[k, l - 1])
                    k--;
                else
                    l--;
            }
          for(int q = 0; q < largestSequence.Length; q++) 
            Console.Write($"{largestSequence[q]} "); 
        }
    }
}
