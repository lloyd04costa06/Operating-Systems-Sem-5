#include<iostream>
#include<stdlib.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        if(i==0){
        for(int j=4;j<=n;j++)
        {
            if(j%4==0||j%4==1||j%4==2||j%4==3)
            {
                cout<<"*";
            }
            else{
                cout<<"x ";
            }
        }}cout<<"\n";

        
    }
}
