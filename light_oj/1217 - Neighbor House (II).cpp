#include<stdio.h>
#include<string.h>

long n , ara[1010] , max , ans1[1010][2] , ans2[1010][2] ;

long rec1(long pos , long color)
{
    long a , b ;
    if(pos >= n) return 0 ;

    if(ans1[pos][color] != -1) return ans1[pos][color] ;

    if(color == 1)
    {
        a =  rec1(pos+2 , 0) ;
        b = rec1(pos+2 ,  1) ;
        if(b>a) ans1[pos][color] = b + ara[pos] ;
        else ans1[pos][color] = a + ara[pos] ;
    }
    else
    {
        a =  rec1(pos+1 , 0) ;
        b = rec1(pos+1 ,  1) ;
        if(b>a) ans1[pos][color] = b ;
        else ans1[pos][color] = a ;
    }
    //printf("ans1[ %ld ] [ %ld ] = %ld\n",pos,color,ans1[pos][color]) ;
    return ans1[pos][color] ;
}

long rec2(long pos , long color)
{
    long a , b ;
    if(pos >= n-1) return 0 ;

    if(ans2[pos][color] != -1) return ans2[pos][color] ;

    if(color == 1)
    {
        a =  rec2(pos+2 , 0) ;
        b = rec2(pos+2 ,  1) ;
        if(b>a) ans2[pos][color] = b + ara[pos] ;
        else ans2[pos][color] = a + ara[pos] ;
    }
    else
    {
        a =  rec2(pos+1 , 0) ;
        b = rec2(pos+1 ,  1) ;
        if(b>a) ans2[pos][color] = b ;
        else ans2[pos][color] = a ;
    }
    // printf("ans2[ %ld ] [ %ld ] = %ld\n",pos,color,ans2[pos][color]) ;
    return ans2[pos][color] ;
}

int main()
{
    long loop , test , a , b , c ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        memset(ans1,-1,sizeof(ans1)) ;
        memset(ans2,-1,sizeof(ans2)) ;
        scanf("%ld",&n) ;
        max = 0 ;
        for(a=0 ; a<n ; a++)
            scanf("%ld",&ara[a]) ;
        a= rec1(0,0) ;
        b = rec2(0,1) ;
        if(a<b) a = b ;
        printf("Case %ld: %ld\n",loop,a) ;
    }
    return 0 ;
}
