#include<stdio.h>
#include<string.h>

int main ()

{
    char ar[100000]={0} ;
    while(gets(ar))
    {
        long i , j=strlen(ar) , count=0 , a=0 ;
        for(i=0 ; i<j-1 ; i+=2)
        {
            if(ar[i]=='I' && ar[i+1]=='V')
            {
                count=count+4 ;
                a+=2 ;
            }
            else if(ar[i+1]=='I' && ar[i]=='V')
            {
               count=count+6 ;
               a+=2 ;
               continue ;
            }
            if(ar[i]=='I' && ar[i+1]=='X')
            {
                count=count+9 ;
                a+=2 ;
            }
            else if(ar[i]=='X' && ar[i+1]=='I')
            {
                count=count+11 ;
                a+=2 ;
                continue ;
            }
            if(ar[i]=='X' && ar[i+1]=='L')
            {
                count=count+40 ;
                a+=2 ;
            }
            else if(ar[i]=='L' && ar[i+1]=='X')
            {
                count=count+60 ;
                a+=2 ;
                continue ;
            }
            if(ar[i]=='X' && ar[i+1]=='C')
            {
                count=count+90 ;
                a+=2 ;
            }
            else if(ar[i]=='C' && ar[i+1]=='X')
            {
                count=count+110 ;
                a+=2 ;
                continue ;
            }
            if(ar[i]=='C' && ar[i+1]=='D')
            {
                count=count+400 ;
                a+=2 ;
            }
            else if(ar[i]=='D' && ar[i+1]=='C')
            {
                count=count+600 ;
                a+=2 ;
                continue ;
            }
            if(ar[i]=='C' && ar[i+1]=='M')
            {
                count=count+900 ;
                a+=2 ;
            }
            else if(ar[i]=='M' && ar[i+1]=='C')
            {
                count=count+1100 ;
                a+=2 ;
                continue ;
            }
        }
        if(j%2==0)
        {
            if(ar[j-1]=='I')
            {
                count+=1 ;
                a++ ;
            }
            else if(ar[j-1]=='V')
            {
                count+=5 ;
                a++ ;
            }
            else if(ar[j-1]=='X')
            {
                count+=10 ;
                a++ ;
            }
            else if(ar[j-1]=='L')
            {
                count+=50 ;
                a++ ;
            }
            else if(ar[j-1]=='C')
            {
                count+=100 ;
                a++ ;
            }
            else if(ar[j-1]=='D')
            {
                count+=500 ;
                a++ ;
            }
            else if(ar[j-1]=='M')
            {
                count+=1000 ;
                a++ ;
            }
        }
        if(a==j) printf("%ld\n",count) ;
        else printf("This is not a valid number\n") ;
    }
    return 0 ;
}
