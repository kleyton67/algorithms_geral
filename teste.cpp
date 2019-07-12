#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    int ** p ;
    p = new int*[10000];
    for(int i = 0; i< 10000; i++)
    {
        p[i] = new int[10000];
    }

    int a, b;
    cin>>a>>b;

    cout <<"X = "<< a+b << '\n';
    return 0;
}
