#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<iostream>

using namespace  std ;

//char ques2[100050][50] , ques1[100050][50] ;
char ques1[50] , ques2[50] ;
map<string,string>mp ;

int main()
{
    long i , j , a , length=0 ;
    char ch[100] ;
    while(gets(ch))
    {
        if(strlen(ch)==0) break ;
        sscanf(ch,"%s %s",ques1,ques2) ;
        mp[ques2]=ques1 ;
    }
    while(gets(ch))
    {
        /*for(i=0 ; i<length ; i++)
        if(strcmp(ques2[i],ch)==0)
        {
            printf("%s\n",ques1[i]) ;
            break ;
        }
        if(i==length) printf("eh\n") ;*/
        if(mp[ch]!="") cout<<mp[ch]<<endl ;
        else cout<<"eh"<<endl ;
    }
    return 0 ;
}
