#include<stdio.h>
#include<string.h>

char ch[5010][1050] ;

int main()
{
    long i , j , a , carry , b , n1 , n2 ;
    ch[0][0]='0' ;
    ch[1][0]='1' ;
    for(i=2 ; i<=5000 ; i++)
    {
        n1=strlen(ch[i-1]) ;
        n2=strlen(ch[i-2]) ;
        a=carry=0 ;
        if(n1>n2)
        {
            for(j=0 ; j<n1 ; j++)
            {
                if(j<n2)
                    b=carry+ch[i-1][j]+ch[i-2][j]-96 ;
                else b=carry+ch[i-1][j]-48 ;

                if(b>9)
                {
                    ch[i][a++]=(b%10)+48 ;
                    carry=b/10 ;
                }
                else
                {
                    ch[i][a++]=b+48 ;
                    carry=0 ;
                }
            }
            if(carry!=0) ch[i][j]=carry+48 ;
        }
        else if(n2>n1)
        {
            for(j=0 ; j<n2 ; j++)
            {
                if(j<n1)
                    b=carry+ch[i-2][j]+ch[i-1][j]-96 ;
                else b=carry+ch[i-2][j]-48 ;

                if(b>9)
                {
                    ch[i][a++]=(b%10)+48 ;
                    carry=b/10 ;
                }
                else
                {
                    ch[i][a++]=b+48 ;
                    carry=0 ;
                }
            }
            if(carry!=0) ch[i][j]=carry+48 ;
        }
        else
        {
            for(j=0 ; j<n1 ; j++)
            {
                b=carry+ch[i-1][j]+ch[i-2][j]-96 ;
                if(b>9)
                {
                    ch[i][a++]=(b%10)+48 ;
                    carry=b/10 ;
                }
                else
                {
                    ch[i][a++]=b+48 ;
                    carry=0 ;
                }
            }
            if(carry!=0) ch[i][j]=carry+48 ;
        }
    }
    while(scanf("%ld",&a)!=EOF)
    {
        printf("The Fibonacci number for %ld is ",a) ;
        for(i=strlen(ch[a])-1 ; i>=0 ; i--) printf("%c",ch[a][i]) ;
        printf("\n") ;
    }
    return 0 ;
}
