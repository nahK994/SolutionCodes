#include<iostream>
#include<string>
#include<stack>
using namespace std ;
int main()
{
    stack<string>back , fore ;
    string ch , ask ;
    long i , j , loop , test ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        ch="http://www.lightoj.com/" ;
        cout<<"Case "<<loop<<":\n" ;
        while(!fore.empty()) fore.pop() ;
        while(!back.empty()) back.pop() ;
        while(cin>>ask && ask!="QUIT")
        {
            if(ask=="BACK")
            {
                if(back.size()==0) cout<<"Ignored\n" ;
                else
                {
                    fore.push(ch) ;
                    ch=back.top() ;
                    back.pop() ;
                    cout<<ch<<endl ;
                }
            }
            else if(ask=="FORWARD")
            {
                if(fore.size()==0) cout<<"Ignored\n" ;
                else
                {
                    back.push(ch) ;
                    ch=fore.top() ;
                    fore.pop() ;
                    cout<<ch<<endl ;
                }
            }
            else if(ask=="VISIT")
            {
                back.push(ch) ;
                cin>>ch ;
                cout<<ch<<endl ;
                while(!fore.empty()) fore.pop() ;
            }
        }
    }
    return 0 ;
}
