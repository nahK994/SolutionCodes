#include<bits/stdc++.h>
using namespace std;

int main()
{

    map<string, long>mp;
    mp["aa"] = 1;
    mp["aa"] = 2;

    map<string, long>:: iterator it;
    for(it=mp.begin() ; it!=mp.end() ; it++)
        cout<<it->first << " "<< it->second<<endl;

    string a = mp.begin()->first;
    cout<<a<<"   len = "<<a.size()<<endl;
    a[a.size()-1] = 'Z';
    cout<<a<<"   len = "<<a.size()<<endl;

    printf("Input a string: ");
    getline(cin, a);
    cout<<a<<endl;



    string aa = "asdf", ss = "Zsd";
    if(aa > ss)
        printf("HaHa\n");
    else if(aa < ss)
        printf("HiHi\n");
    else if(aa == ss)
        printf("HoHo\n");
    return 0;
}
