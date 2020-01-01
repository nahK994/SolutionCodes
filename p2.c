#include<stdio.h>
#include<string.h>

char add(char ch1[100000] , char ch2[100000])

{
    gets(ch1) ;
    gets(ch2) ;
    /*while(gets(ch1),gets(ch2))
    {*/
      char ch3[100000] ;
      long q , x , y , t , n , c=0 , n1=strlen(ch1) , n2=strlen(ch2) , p ;
      if(n1>n2)
      {
        for(q=n1-1,p=n2-1,x=0 ; q>=0 ; q--,x++)
           {
              if(p>=0)
              {
                  y=c+ch1[q]+ch2[p]-96 ;
                  p-- ;
              }
              else y=c+ch1[q]-48 ;
              if(y>9)
              {
                 ch3[x]=(y%10)+48 ;
                 c=y/10 ;
              }
              else
              {
                 ch3[x]=y+48 ;
                 c=0 ;
              }
          }
          if(c!=0) ch3[x]=c+48 ;
      }
      else if(n2>n1)
      {
        for(q=n2-1,p=n1-1,x=0 ; q>=0 ; q--,x++)
           {
              if(p>=0)
              {
                  y=c+ch2[q]+ch1[p]-96 ;
                  p-- ;
              }
              else y=c+ch2[q]-48 ;
              if(y>9)
              {
                 ch3[x]=(y%10)+48 ;
                 c=y/10 ;
              }
              else
              {
                 ch3[x]=y+48 ;
                 c=0 ;
              }
          }
          if(c!=0) ch3[x]=c+48 ;
      }
      else
      {
        for(p=n1-1,x=0 ; p>=0 ; p--,x++)
        {
            y=c+ch1[p]+ch2[p]-96 ;
            if(y>9)
              {
                 ch3[x]=(y%10)+48 ;
                 c=y/10 ;
              }
            else
              {
                 ch3[x]=y+48 ;
                 c=0 ;
              }
        }
        if(c!=0) ch3[x]=c+48 ;
      }
    /*  n=strlen(ch3) ;
      for(t=n-1 ; t>=0 ; t--) printf("%c",ch3[t]) ;
      printf("\n") ;*/
      return ch3[100000] ;
   // }
}

char rev(char ch[100000])

{
    long i , j=strlen(ch) , a ;
    char b ;
    for(i=0, a=j-1 ; i<a ; i++,a--)
    {
        b=ch[i] ;
        ch[i]=ch[a] ;
        ch[a]=b ;
    }
    return ch[100000] ;
}

int main ()

{
    char ch1[100000] , ch2[100000] , ch3[100000] , ca[100000] , ch4[100000] ;
    while(gets(ch1),gets(ch2))
    {
         ch1[100000]=rev(ch1) ;
         ch2[100000]=rev(ch2) ;
         long i , b=strlen(ch1) , c=strlen(ch2) , d , e , f , g , h=0 , carry=0 , k=0 , l , m , p , q , r ;
         for(i=0 ; i<100000 ; i++) ca[i]=48 ;
         for(d=0 ; d<c ; d++)
         {
             for(e=0 ; e<b ; e++)
             {
                f=(ch1[e]-48)*(ch2[d]-48)+carry ;
                if(f>9)
                {
                    ch3[h]=(f%10)+48 ;
                    carry=f/10 ;
                }
                else
                {
                    ch3[h]=f+48 ;
                    carry=0 ;
                }
                h++ ;
                //printf("K") ;
             }
             ch3[100000]=rev(ch3) ;
             ca[100000]=rev(ca) ;
             ch3[100000]=add(ch3,ca) ;
             memset(ca,0,sizeof(ca)) ;
             ch4[k]=ch3[0] ;
             k++ ;
             m=strlen(ch3) ;
             for(l=0 ; l<m ; l++) ca[l]=ch3[l+1] ;
             memset(ch3,0,sizeof(ch3)) ;
         }
         p=strlen(ca) ;
         if(p!=0)
         {
             for(q=0 ; q<p ; q++)
             {
                  ch4[k]=ca[q] ;
                  k++ ;
             }
         }
        r=strlen(ch4) ;
        for( ; r>=0 ; r--) printf("%c",ch4[r]) ;
        printf("\n") ;
    }
    return 0 ;
}
