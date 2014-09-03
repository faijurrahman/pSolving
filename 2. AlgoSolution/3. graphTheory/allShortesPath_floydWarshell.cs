using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArrayVisualizerTest
{
    class Program
    {
        static int SIZE = 4;
        static int INF = 99999;

        static int[,] floydWarshell(int[,] G)
        {
            int n = SIZE;
            for (int k = 0; k < n; k++)
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        if (G[i, k] + G[k, j] < G[i, j])
                            G[i, j] = G[i, k] + G[k, j];

            return G;
        }

        static void printMatrix(int[,] pIn)
        {
            int n = SIZE;
            for (int i = 0; i < n; i++)
            {
                string text = null;
                for (int j = 0; j < n; j++)
                {
                    if (pIn[i, j] == INF)
                        text += string.Format("{0,6}", "INF");
                    else
                        text += string.Format("{0,6}", pIn[i, j]);
                }
                Console.WriteLine(text);
            }
            Console.WriteLine("");
        }

        static void Main(string[] args)
        {
            /* 
            10
            (0)------->(3)
            |         /|\
            5 |          |
            |          | 1
            \|/         |
            (1)------->(2)
            3           
            */

            int[,] input = new int[4, 4]{ {0,   5,  INF, 10},
	                                     {INF, 0,   3, INF},
	                                     {INF, INF, 0,   1},
	                                     {INF, INF, INF, 0}
	                                   };

            Console.WriteLine("Input Matrix:");
            printMatrix(input);

            int[,] output = floydWarshell(input);
            Console.WriteLine("Output Matrix:");
            printMatrix(output);
        }
    }
}

