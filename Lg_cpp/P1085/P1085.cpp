#include <iostream>
using namespace std;
int main()
{
    int a,b,sum=0;
    for(int i=1;i<=7;i++)
    {
        cin>>a>>b;
        if(!sum && a+b>8)
            sum=i;
    }
    cout<<sum;
    return 0;
}
