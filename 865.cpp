#include <stdio.h>
#include <string.h>
int main()
{
    long t , i ;
    char A[100] , B[100] , ascii[200] ;
    scanf("%ld", &t) ;
    getchar() ;
    getchar() ;
    while(t--)
    {
        gets(A);
        gets(B);
        int lenA = strlen(A), lenB = strlen(B);
        for(i = 0; i < 128; i++)
            ascii[i] = i;
        for(i = 0; i < lenA || i < lenB; i++)
        {
            if(i >= lenA)	A[i] = ' ';
            if(i >= lenB)	B[i] = ' ';
            ascii[A[i]] = B[i];
        }
        printf("%s\n",B) ;
        printf("%s\n",A) ;
        while(gets(A))
        {
            if(A[0] == '\0')
                break;
            for(i = 0; A[i]; i++)
            {
                printf("%c", ascii[A[i]]) ;
            }
            printf("\n") ;
        }
        if(t)
            printf("\n") ;
    }
    return 0;
}
