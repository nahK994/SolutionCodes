#include<stdio.h>

int main ()

{
      long a ;
      while(scanf("%ld",&a)!=EOF)
            {
                  if(a<0)
                  break ;
                  if(a==1)
                  printf("0%c\n",37) ;
                  else printf("%ld%c\n",a*25,37) ;
            }
      return 0 ;
}
