#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, long>mp;
    mp["asdf"] = 1;
    mp["qwer"] = 2;

    map<string, long>:: iterator it;
    for(it=mp.begin() ; it != mp.end() ; it++)
        cout<<it->first << " "<< it->second<<endl;
    
    string a = mp.begin()->first;
    cout<<a<<"   len = "<<a.size()<<endl;
    a = "";
    cout<<a<<"   len = "<<a.size()<<endl;

    printf("Input a string: ");
    getline(cin, a);
    cout<<a<<endl;

    return 0;
}
