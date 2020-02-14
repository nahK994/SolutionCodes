#include<bits/stdc++.h>
using namespace std;

char ch[1000];
void rec(long i, long n)
{
    if(i == n)
    {
        ch[i] = 0;
        printf("%s\n", ch);
        return;
    }

    ch[i] = '0';
    rec(i+1, n);

    ch[i] = '1';
    rec(i+1, n);
}

int main()
{
    long a;
    scanf("%ld", &a);
    rec(0, a);
}