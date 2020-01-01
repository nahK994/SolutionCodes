#include<stdio.h>
#include<string.h>

int main()
{
    long a , b , c , d , e , f , g , h , i , j , sum ;
    char ch[25] , c1 ;
    scanf("%ld",&j) ;
    c1=getchar() ;
    for(i=1 ; i<=j ; i++)
    {
        gets(ch) ;
        a=2*(ch[0]-48) ;
        b=2*(ch[2]-48) ;
        c=2*(ch[5]-48) ;
        d=2*(ch[7]-48) ;
        e=2*(ch[10]-48) ;
        f=2*(ch[12]-48) ;
        g=2*(ch[15]-48) ;
        h=2*(ch[17]-48) ;
        if(a>9)
        {
            a=(a%10)+(a/10) ;
          //  sum+=a ;
        }
        if(b>9)
        {
            b=(b%10)+(b/10) ;
            //sum+=b ;
        }
        if(c>9)
        {
            c=(c%10)+(c/10) ;
           // sum+=c ;
        }
        if(d>9)
        {
            d=(d%10)+(d/10) ;
            //sum+=d ;
        }
        if(e>9)
        {
            e=(e%10)+(e/10) ;
           // sum+=e ;
        }
        if(f>9)
        {
            f=(f%10)+(f/10) ;
           // sum+=f ;
        }
        if(g>9)
        {
            g=(g%10)+(g/10) ;
            //sum+=g ;
        }
        if(h>9)
        {
            h=(h%10)+(h/10) ;
            //sum+=h ;
        }
        sum=a+b+c+d+e+f+g+h ;
        a=2*(ch[1]-48) ;
        b=2*(ch[3]-48) ;
        c=2*(ch[6]-48) ;
        d=2*(ch[8]-48) ;
        e=2*(ch[11]-48) ;
        f=2*(ch[13]-48) ;
        g=2*(ch[16]-48) ;
        h=2*(ch[18]-48) ;
        sum=sum+(a+b+c+d+e+f+g+h)/2.0 ;
        if(sum%10==0) printf("Valid\n") ;
        else printf("Invalid\n") ;
    }
    return 0 ;
}
