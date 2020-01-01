#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std ;

int main()
{
    long test , i , j , a , n ;
    char  ch , ch1[2000] , ch2[2000] ;
    cin>>test ;
    while(test--)
    {
        cin>>n ;
        cin>>ch1 ;
        a=0 ;
        for(i=1 ; i<n ; i++)
        {
            strcpy(ch2,ch1) ;
            cin>>ch1 ;
            j=strlen(ch2) ;
            if(ch2[j-1]!=ch1[0]) a=1 ;
        }
        if(a==0) cout<<"Ordering is possible.\n" ;
        else cout<<"The door cannot be opened.\n" ;
    }
    return 0 ;
}
