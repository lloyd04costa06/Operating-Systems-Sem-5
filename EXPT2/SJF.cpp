#include<iostream>
#include<algorithm>
#define MAX 10
using namespace std;
int N;

typedef struct PROCESSES{
    int index;
    int BT;
    int CT;
    int TAT;
    int WT;
};

void processInput(PROCESSES Table[])
{
    cout<<"ENTER NUMBER OF ELEMENTS: ";
    cin>>N;
    cout<<"ENTER THE PROCESS DETAILS"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"P"<<i+1<<": \n";
        Table[i].index=i+1;
        cout<<"ENTER BURST TIME: ";
        cin>>Table[i].BT;
        cout<<endl;
    }

}











bool CRITERIA1(PROCESSES A,PROCESSES B)
{
    return(A.BT<B.BT);
}

void SJF(PROCESSES Table[])
{
    int sum=0;
    cout<<"\n\nGHANTT CHART: \n";
    sort(Table,Table+N,CRITERIA1);
    for(int i=0;i<N;i++)
    {
        cout<<"|"<<sum<<"|";
        cout<<"---"<<"P"<<Table[i].index<<"---";
        sum+=Table[i].BT;
        Table[i].CT=sum;
    }
    cout<<"|"<<sum<<"|"<<endl;
}

bool CRITERIA2(PROCESSES A,PROCESSES B)
{
    return(A.index<B.index);
}
void ProcessInfo(PROCESSES Table[])
{
    int TotalTAT=0,TotalWT=0;
    sort(Table,Table+N,CRITERIA2);

    cout<<"\nPROCESS     "<<"BT     "<<"TAT     "<<"WT     "<<endl;
    for(int i=0;i<N;i++)
    {
        cout.setf(ios::left,ios::adjustfield);
        cout.width(12);
        cout<<Table[i].index;

        cout.width(7);
        cout<<Table[i].BT;

        cout.width(8);
        Table[i].TAT=Table[i].CT; //TAT=CT-ArrivalTime
        cout<<Table[i].TAT;
        TotalTAT+=Table[i].TAT;

        cout.width(7);
        Table[i].WT=Table[i].TAT-Table[i].BT;
        cout<<Table[i].WT;
        TotalWT+=Table[i].WT;

        cout<<endl;
    }

    cout<<"\nATAT ="<<TotalTAT/N;
    cout<<"\nAWT ="<<TotalWT/N<<endl;
}




int main()
{
    PROCESSES Table[MAX];
    processInput(Table);
    SJF(Table);
    ProcessInfo(Table);
   
}