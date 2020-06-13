//Time complexity O(N*M)
//Space complexity O(N*M)

using System;

namespace CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] val = new int[] { 60, 100, 120 };
            int[] wt = new int[] { 10, 20, 30 };
            int W = 50;
            int n = val.Length;

            Console.WriteLine(
                knapSack(W, wt, val, n));
        }
        static int knapSack(int W, int[] wt, int[] val, int n)
        {
            int[,] resultArray = new int[n + 1, W + 1];

            for (int i = 0; i < n + 1; i++)
            {
                for (int w = 0; w < W + 1; w++)
                {
                    if (i == 0 || w == 0)
                        resultArray[i, w] = 0;
                    else if (wt[i - 1] <= w)
                        resultArray[i, w] = Math.Max(resultArray[i - 1, w], val[i - 1] + resultArray[i - 1, w - wt[i - 1]]);
                    else
                        resultArray[i, w] = resultArray[i - 1, w];
                }
            }
            return resultArray[n, W];
        }
    }
}
