// Contributed by - Ankit Das <ankit.99d@gmail.com>
#include <bits/stdc++.h>
using namespace std;
// d -> number of characters in the input alphabet
#define d 256

void searchPattern(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++)
    {
        h = (h * d) % q;
    }

    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    for (i = 0; i <= N - M; i++)
    {

        if (p == t)
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }
            if (j == M)
                cout << "Found at index " << i << endl;
        }

        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
}

int main()
{
    char txt[] = "ABCCDEEABCCAA";
    char pat[] = "AA";

    int q = INT_MAX;

    searchPattern(pat, txt, q);
    return 0;
}