#include<iostream>
using namespace std ;

int main()
{
    long row , coloum , stars , i , j ;
    char sky[200][200] ;
    while(cin>>row>>coloum && row!=0 && coloum!=0)
    {
        stars=0 ;
        for(i=0 ; i<row ; i++)
        cin>>sky[i] ;
        for(i=0 ; i<row ; i++)
        for(j=0 ; j<coloum ; j++)
        if(sky[i][j]=='*')
        {
            if(i!=0 && sky[i-1][j-1]=='*') ;
            else if(i!=0 && sky[i-1][j]=='*') ;
            else if(i!=0 && j+1<coloum && sky[i-1][j+1]=='*') ;
            else if(sky[i][j-1]=='*') ;
            else if(j+1<coloum && sky[i][j+1]=='*') ;
            else if(i+1<row && sky[i+1][j-1]=='*') ;
            else if(i+1<row && sky[i+1][j]=='*') ;
            else if(i+1<row && j+1<coloum && sky[i+1][j+1]=='*') ;
            else stars++ ;
        }
        cout<<stars<<endl ;
    }
    return 0 ;
}
