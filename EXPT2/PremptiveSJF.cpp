#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 10
using namespace std;
int N,TOTTime=0,space=0;

typedef struct PROCESSES{
    int index;
    int BT;
    int CT;
    int TAT;
    int WT;
    int AT;
    int CurrBT;
};


struct ARRANGE{
    vector<PROCESSES>P;
}ALIST[50];

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

        cout<<"ENTER ARRIVAL TIME: ";
        cin>>Table[i].AT;
        cout<<endl;

        TOTTime+=Table[i].BT;
        Table[i].CurrBT=Table[i].BT;
    }

}


void ARRANGE(PROCESSES Table[]){
    for(int i=0;i<N;i++)
    {
        ALIST[Table[i].AT].P.push_back(Table[i]);
    }

    vector<PROCESSES>::iterator IT;
    for(int i=0;i<TOTTime;i++)
    {
        cout<<i<<"-->";
 
        {
            for(IT=ALIST[i].P.begin();IT!=ALIST[i].P.end();++IT)
            {
                cout<<"P"<<(*IT).index<<", ";
            }
  
         }
            cout<<endl;
    }

}








bool CRITERIA1(PROCESSES A,PROCESSES B)
{
    return(A.CurrBT<B.CurrBT);
}

void PROCESS_execute(vector<PROCESSES>& WaitQ,int i)
{
    if(WaitQ.empty()==false)
    {
        cout<<"| P"<<WaitQ[0].index<<" ";
        WaitQ[0].CurrBT--;
    }
    else{
        cout<<"  ";
        space++;
    }
}

void SJF(PROCESSES Table[])
{
    int sum=0;
    cout<<"\n\nGHANTT CHART: \n";
   

    vector<PROCESSES>WaitQ;
    vector<PROCESSES>::iterator IT;

    int count=0;
    for(int clock=0;clock<TOTTime+space;clock++)
    {
        if(ALIST[clock].P.empty()==false)
        {
            for(IT=ALIST[clock].P.begin();IT!=ALIST[clock].P.end();++IT)
            {
                WaitQ.push_back(*IT);
            }
            sort(WaitQ.begin(),WaitQ.end(),CRITERIA1); 
        }

        PROCESS_execute(WaitQ,clock);

        if(WaitQ.empty()==false)
        {
            if(WaitQ[0].CurrBT==0)
            {
                WaitQ.erase(WaitQ.begin());
            }
        }
    }

    cout<<endl;
    for(int i=0;i<TOTTime;i++)
    {
        cout<<i<<"    ";
    }
    
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
    ARRANGE(Table);
    SJF(Table);
    // ProcessInfo(Table);
   
}