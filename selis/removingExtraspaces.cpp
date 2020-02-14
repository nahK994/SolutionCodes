#include<bits/stdc++.h>
using namespace std;

int main()
{
    char ch[100] = "My name    is                   Khan. ", ans[100];
    int r=0;

    printf("%s\n", ch);
    for(int i=0 ; i<strlen(ch) ; i++)
    {
        //printf("%c\n", ch[i]);
        if(ch[i] == 32)
        {
            if(i>0 && i!=strlen(ch)-1 && ch[i-1] != 32)
                ans[r++] = ch[i];
        }
        else
        {
            //printf("HaHa\n");
            ans[r++] = ch[i];
        }
    }

    ans[r] = 0;
    printf("%s\n", ans);
}