#include<stdio.h>
#include<string.h>

int main ()

{
    char ch[100000] ;
    while(gets(ch))
    {
        long i , j , a ;
        j=strlen(ch) ;
        if(ch[0]=='A' || ch[0]=='a' || ch[0]=='e' || ch[0]=='E' || ch[0]=='I' || ch[0]=='i' || ch[0]=='O' || ch[0]=='o' || ch[0]=='U' || ch[0]=='u')
        {
            for(i=0 ; i<j-1 ; i++)
            {
                if(ch[i]==' ') break ;
                printf("%c",ch[i]) ;
            }
            if(i!=j-1) printf("ay ") ;
            else printf("ay") ;
        }
        else
        {
            for(i=1 ; i<j-1 ; i++)
            {
                if(ch[i]==' ') break ;
                printf("%c",ch[i]) ;
            }
            printf("%c",ch[0]) ;
            if(i!=j-1) printf("ay ") ;
            else printf("ay") ;
        }
        i++ ;
            while(i<j-1)
            {
                if(ch[i]=='A' || ch[i]=='a' || ch[i]=='e' || ch[i]=='E' || ch[i]=='I' || ch[i]=='i' || ch[i]=='O' || ch[i]=='o' || ch[i]=='U' || ch[i]=='u')
                  {
                    for( ; i<j-1 ; i++)
                       {
                          if(ch[i]==' ') break ;
                          printf("%c",ch[i]) ;
                       }
                          if(i!=j-1) printf("ay ") ;
                          else printf("ay") ;
                  }
               else
                  {
                      a=i ;
                    for(i=i+1 ; i<j-1 ; i++)
                       {
                         if(ch[i]==' ') break ;
                         printf("%c",ch[i]) ;
                       }
                         printf("%c",ch[a]) ;
                         if(i!=j-1) printf("ay ") ;
                         else printf("ay") ;
                  }
                  i++ ;
             }
             printf("%c\n",ch[i-1]) ;
    }
}
