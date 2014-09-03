#include<iostream>
#include<string>
using namespace std;

void search(string text, string pattern)
{
    int X = text.size();
    int Y = pattern.size();  
    int j;
    for (int i = 0; i <= X - Y; i++)
    {
        for (j = 0; j < Y; j++) if (text[i+j] != pattern[j]) break;
        if (j == Y) printf("Pattern found at index %d \n", i);
    }
}
  
/* Driver program to test above function */
int main()
{
   string txt = "AABAACAADAABAAABAA";
   string pat = "AABA";
   search(txt, pat);
   return 0;
}
