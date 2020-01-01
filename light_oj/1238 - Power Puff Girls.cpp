#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std ;

long dis_a[50][50] , dis_b[50][50] , dis_c[50][50] , A , B , C , row, col ;
char ch[50][50] ;
struct node
{
    long a , b ;
} aa ;
queue<struct node> Q ;

void a_bfs(long i , long j)
{
    dis_a[i][j]=1 ;
    //ch[i][j]='1' ;
    aa.a=i ;
    aa.b=j ;
    Q.push(aa) ;
    while(!Q.empty())
    {
        //printf("A") ;
        aa=Q.front() ;
        Q.pop() ;
        i=aa.a ;
        j=aa.b ;

        if(i>0)
            if(!dis_a[i-1][j] && ch[i-1][j]!='m' && ch[i-1][j]!='#')
            {
                //printf("B") ;
                dis_a[i-1][j]=dis_a[i][j]+1 ;
                if(ch[i-1][j]=='h')
                {
                    A=dis_a[i-1][j] ;
                    while(!Q.empty())
                        Q.pop() ;
                }
                else
                {
                    //ch[i-1][j]='1' ;
                    aa.a=i-1 ;
                    aa.b=j ;
                    Q.push(aa) ;
                }
            }

        if(i+1<row)
            if(!dis_a[i+1][j] && ch[i+1][j]!='m' && ch[i+1][j]!='#')
            {
                //printf("C") ;
                dis_a[i+1][j]=dis_a[i][j]+1 ;
                if(ch[i+1][j]=='h')
                {
                    A=dis_a[i+1][j] ;
                    while(!Q.empty())
                        Q.pop() ;
                }
                else
                {
                   // ch[i+1][j]='1' ;
                    aa.a=i+1 ;
                    aa.b=j ;
                    Q.push(aa) ;
                }
            }

        if(j>0)
            if(!dis_a[i][j-1] && ch[i][j-1]!='m' && ch[i][j-1]!='#')
            {
                //printf("D") ;
                dis_a[i][j-1]=dis_a[i][j]+1 ;
                if(ch[i][j-1]=='h')
                {
                    A=dis_a[i][j-1] ;
                    while(!Q.empty())
                        Q.pop() ;
                }
                else
                {
                    //ch[i][j-1]='1' ;
                    aa.a=i ;
                    aa.b=j-1 ;
                    Q.push(aa) ;
                }
            }

        if(j+1<col)
            if(!dis_a[i][j+1] && ch[i][j+1]!='m' && ch[i][j+1]!='#')
            {
                // printf("E") ;
                dis_a[i][j+1]=dis_a[i][j]+1 ;
                if(ch[i][j+1]=='h')
                {
                    A=dis_a[i][j+1] ;
                    while(!Q.empty())
                        Q.pop() ;
                }
                else
                {
                    //ch[i][j+1]='1' ;
                    aa.a=i ;
                    aa.b=j+1 ;
                    Q.push(aa) ;
                }
            }
    }
}

void b_bfs(long i , long j)
{
    dis_b[i][j]=1 ;
    //ch[i][j]='2' ;
    aa.a=i ;
    aa.b=j ;
    Q.push(aa) ;
    while(!Q.empty())
    {
        //  printf("A ") ;
        aa=Q.front() ;
        Q.pop() ;
        i=aa.a ;
        j=aa.b ;

        if(i>0)
            if(!dis_b[i-1][j] && ch[i-1][j]!='m' && ch[i-1][j]!='#')
            {
                //printf("B ") ;
                dis_b[i-1][j]=dis_b[i][j]+1 ;
                if(ch[i-1][j]=='h')
                {
                    B=dis_b[i-1][j] ;
                    while(!Q.empty())
                        Q.pop() ;
                }
                else
                {
                    //ch[i-1][j]='2' ;
                    aa.a=i-1 ;
                    aa.b=j ;
                    Q.push(aa) ;
                }
            }

        if(i+1<row)
            if(!dis_b[i+1][j] && ch[i+1][j]!='m' && ch[i+1][j]!='#')
            {
                //      printf("C ") ;
                dis_b[i+1][j]=dis_b[i][j]+1 ;
                if(ch[i+1][j]=='h')
                {
                    B=dis_b[i+1][j] ;
                    while(!Q.empty())
                        Q.pop() ;
                }
                else
                {
                 //   ch[i+1][j]='2' ;
                    aa.a=i+1 ;
                    aa.b=j ;
                    Q.push(aa) ;
                }
            }

        if(j>0)
            if(!dis_b[i][j-1] && ch[i][j-1]!='m' && ch[i][j-1]!='#')
            {
                //    printf("D ") ;
                dis_b[i][j-1]=dis_b[i][j]+1 ;
                if(ch[i][j-1]=='h')
                {
                    B=dis_b[i][j-1] ;
                    while(!Q.empty())
                        Q.pop() ;
                }
                else
                {
                    //ch[i][j-1]='2' ;
                    aa.a=i ;
                    aa.b=j-1 ;
                    Q.push(aa) ;
                }
            }

        if(j+1<col)
            if(!dis_b[i][j+1] && ch[i][j+1]!='m' && ch[i][j+1]!='#')
            {
                //        printf("E ") ;
                dis_b[i][j+1]=dis_b[i][j]+1 ;
                if(ch[i][j+1]=='h')
                {
                    B=dis_b[i][j+1] ;
                    while(!Q.empty())
                        Q.pop() ;
                }
                else
                {
                   // ch[i][j+1]='2' ;
                    aa.a=i ;
                    aa.b=j+1 ;
                    Q.push(aa) ;
                }
            }
    }
    //printf("\n") ;
}

void c_bfs(long i , long j)
{
    dis_c[i][j]=1 ;
    //ch[i][j]='3' ;
    aa.a=i ;
    aa.b=j ;
    Q.push(aa) ;
    while(!Q.empty())
    {
        aa=Q.front() ;
        Q.pop() ;
        i=aa.a ;
        j=aa.b ;

        if(i>0)
            if(!dis_c[i-1][j] && ch[i-1][j]!='m' && ch[i-1][j]!='#')
            {
                dis_c[i-1][j]=dis_c[i][j]+1 ;
                if(ch[i-1][j]=='h')
                {
                    C=dis_c[i-1][j] ;
                    while(!Q.empty())
                        Q.pop() ;
                }
                else
                {
                    //ch[i-1][j]='3' ;
                    aa.a=i-1 ;
                    aa.b=j ;
                    Q.push(aa) ;
                }
            }

        if(i+1<row)
            if(!dis_c[i+1][j] && ch[i+1][j]!='m' && ch[i+1][j]!='#')
            {
                dis_c[i+1][j]=dis_c[i][j]+1 ;
                if(ch[i+1][j]=='h')
                {
                    C=dis_c[i+1][j] ;
                    while(!Q.empty())
                        Q.pop() ;
                }
                else
                {
                    //ch[i+1][j]='3' ;
                    aa.a=i+1 ;
                    aa.b=j ;
                    Q.push(aa) ;
                }
            }

        if(j>0)
            if(!dis_c[i][j-1] && ch[i][j-1]!='m' && ch[i][j-1]!='#')
            {
                dis_c[i][j-1]=dis_c[i][j]+1 ;
                if(ch[i][j-1]=='h')
                {
                    C=dis_c[i][j-1] ;
                    while(!Q.empty())
                        Q.pop() ;
                }
                else
                {
                   // ch[i][j-1]='3' ;
                    aa.a=i ;
                    aa.b=j-1 ;
                    Q.push(aa) ;
                }
            }

        if(j+1<col)
            if(!dis_c[i][j+1] && ch[i][j+1]!='m' && ch[i][j+1]!='#')
            {
                dis_c[i][j+1]=dis_c[i][j]+1 ;
                if(ch[i][j+1]=='h')
                {
                    C=dis_c[i][j+1] ;
                    while(!Q.empty())
                        Q.pop() ;
                }
                else
                {
                    //ch[i][j+1]='3' ;
                    aa.a=i ;
                    aa.b=j+1 ;
                    Q.push(aa) ;
                }
            }
    }
}

int main()
{
    long loop , test , a , b , c , i , j , a1 , a2 , a3 , a4 , a5 , a6 ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld",&row,&col) ;
        for(i=0 ; i<row ; i++)
            scanf("%s",ch[i]) ;

        for(i=0 ; i<row ; i++)
        {
            memset(dis_a[i],0,sizeof(dis_a[i])) ;
            memset(dis_b[i],0,sizeof(dis_b[i])) ;
            memset(dis_c[i],0,sizeof(dis_c[i])) ;
        }

        a=0 ;
        for(i=0 ; i<row && a!=3 ; i++)
            for(j=0 ; j<col && a!=3 ; j++)
                if(ch[i][j]=='a')
                {
                    a1=i ;
                    a2=j ;
                    a++ ;
                }
                else if(ch[i][j]=='b')
                {
                    a3=i ;
                    a4=j ;
                    a++ ;
                }
                else if(ch[i][j]=='c')
                {
                    a5=i ;
                    a6=j ;
                    a++ ;
                }

        a_bfs(a1,a2) ;
        b_bfs(a3,a4) ;
        c_bfs(a5,a6) ;

        //printf("%ld  %ld  %ld\n",A,B,C) ;

        if(A<B)
            A=B ;
        if(A<C)
            A=C ;
        printf("Case %ld: %ld\n",loop,A-1) ;

    }
    return 0 ;
}
