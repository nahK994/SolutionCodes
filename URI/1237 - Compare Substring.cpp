#include<bits/stdc++.h>
using namespace std;

int main()
{
    long arr[100][100], ans;
    char ch1[100], ch2[100];
    while(gets(ch1) && gets(ch2))
    {
        //printf("%s ---> len %ld\n", ch1, strlen(ch1));
        //printf("%s ---> len %ld\n", ch2, strlen(ch2));
        for(int i=0 ; i<strlen(ch1) ; i++)
            for(int j=0 ; j<strlen(ch2) ; j++)
                arr[i][j] = 0;

        ans = 0;
        for(int i=0 ; i<strlen(ch1) ; i++)
            for(int j=0 ; j<strlen(ch2) ; j++)
                if(ch1[i] == ch2[j])
                {
                    if(i>0 && j>0)
                        arr[i][j] = arr[i-1][j-1]+1;
                    else if(i==0 || j==0)
                        arr[i][j] = 1;

                    if(ans < arr[i][j])
                        ans = arr[i][j];
                }
        
        printf("%ld\n", ans);
    }
}