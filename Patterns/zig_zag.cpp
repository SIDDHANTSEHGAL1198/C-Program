#include <iostream>
using namespace std;
int main()
{
    cout<<"Enter n"<<endl;
    int n;
    cin>>n;

    int i,j,space;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(((i+j)%4==0) || (i==2 && j%4==0))
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;

    }
    return 0;
}