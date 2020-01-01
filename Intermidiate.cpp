#include<stdio.h>
#include<math.h>

int main ()

{
	int i , j ;

	scanf("%d",&j) ;

	for( i=1 ; i<=j ; i++ )

	{
         double r , m , s ;

         scanf("%lf%lf%lf",&s,&r,&m) ;

         if(m<=r)

         {
             printf("can't determine") ;
             break ;
         }

         double minimum_time=s/m ;

         double z=sqrt(m*m-r*r) ;

         double time_for_minimum_distanse=s/z ;

         printf("Case no %d : %0.3lf\n", i , time_for_minimum_distanse-minimum_time) ;
	}

       return 0 ;

}
