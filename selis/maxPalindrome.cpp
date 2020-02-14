#include<bits/stdc++.h>
using namespace std;

char ch[100];
long ara[100][100];

long func(char *ch, long a, long b)
{
    if(a == b) return ara[a][a] = 1;

    if(ara[a][b] != -1) return ara[a][b];
    
    long r=0;
    char chh[100];
    for(int i=a ; i<=b ; i++)
        chh[r++] = ch[i];
    chh[r]=0;

    long flag = 1, length = strlen(chh);
    for(int i=0 ; i<strlen(chh) && i<strlen(chh)-1-i ; i++)
        if(chh[i] != chh[strlen(chh)-1-i])
        {
            flag = 0;
            break;
        }
    if(!flag) length = 0;

    if(a+1<=b)
        ara[a][b] = max(length, func(ch, a+1, b));
    if(a<=b-1)
        ara[a][b] = max(ara[a][b], func(ch, a, b-1));

    return ara[a][b];
}

int main()
{
    scanf("%s", ch);
    memset(ara, -1, sizeof(ara));
    //printf("%ld\n", ara[0][0]);
    printf("%ld\n", func(ch, 0, strlen(ch)-1));
}