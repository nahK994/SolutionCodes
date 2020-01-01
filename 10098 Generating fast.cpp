#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

char ch[1000];

int main()
{
    long test , length , a ;
    scanf("%ld\n",&test) ;
    while (test--)
    {
        gets(ch);
        length=strlen(ch) ;
        sort(ch,ch+length) ;
        do
          {
              puts(ch) ;
              a=next_permutation(ch,ch+length) ;
          }
        while(a) ;
        //next_permutation(ch,ch+length) ;
       // puts(ch) ;
        putchar('\n');
    }
    return 0;
}
