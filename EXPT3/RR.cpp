#include<iostream>
#include<algorithm>
#include <queue>
#define MAX 10
using namespace std;
int N,TotalTimeNeeded=0,QT,space=0;

typedef struct PROCESSES{
    int index;
    int BT;
    int AT;
    int Remaining;
    int CT;
    int TAT;
    int WT;
    int TimeOut;
};

typedef struct ARRANGE{vector<PROCESSES> P;};
ARRANGE ALIST[50];

void processArrange(PROCESSES Table[])
{
    for(int i=0;i<N;i++)
    {
        ALIST[Table[i].AT].P.push_back(Table[i]);
    }

    
    vector<PROCESSES>::iterator IT;
    for(int i=0;i<TotalTimeNeeded;i++)
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

void processInput(PROCESSES Table[])
{
    cout<<"ENTER NUMBER OF ELEMENTS: ";
    cin>>N;

    cout<<"ENTER QUNTUM TIME SLICE";
    cin>>QT;

    cout<<"ENTER THE PROCESS DETAILS"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"P"<<i+1<<": \n";
        Table[i].index=i+1;
        cout<<"ENTER BURST TIME: ";
        cin>>Table[i].BT;
        Table[i].Remaining=0;

        cout<<"ENTER ARRIVAL TIME: ";
        cin>>Table[i].AT;
        cout<<endl;

        TotalTimeNeeded+=Table[i].BT;
        Table[i].TimeOut=0;
    }

}

bool CRITERIA1(PROCESSES A,PROCESSES B)
{
    return(A.AT<B.AT);
}

void ProcessExcute(queue<PROCESSES>&waitQ,int i)
{
   
        PROCESSES &X=waitQ.front();
        cout<<"| P"<<X.index;
        X.Remaining++;
        X.TimeOut++;
    
    
}
void Qview( queue<PROCESSES>waitQ)
{
     queue<PROCESSES>waitQ2=waitQ;
     while(waitQ2.empty()==false)
     {
        cout<<"-p"<<waitQ2.front().index<<" ";
        waitQ2.pop();
     }
     cout<<endl;
}

void RR(PROCESSES Table[])
{
  queue<PROCESSES>waitQ;
  vector<PROCESSES>::iterator IT;
  int flag=0;
  PROCESSES s;
 
  for(int clock=0;clock<TotalTimeNeeded;clock++)
  {
        for(IT=ALIST[clock].P.begin();IT!=ALIST[clock].P.end();++IT)
        {
            waitQ.push(*IT);
            if(flag==1)
            {
                waitQ.push(s);
                flag=0;
            }
        }
      
        ProcessExcute(waitQ,clock);
      
        if( waitQ.front().Remaining==waitQ.front().BT)
        {
            waitQ.pop();
            continue;
        }

        if(waitQ.front().TimeOut==QT)
        {
            waitQ.front().TimeOut=0;
            s=waitQ.front();
            waitQ.pop();
            flag=1;
        }
  }
    

  cout<<endl;
  for(int i=0;i<TotalTimeNeeded;i++)
  {
    cout<<i<<"   ";
  }
  


}



void ProcessInfo(PROCESSES Table[])
{
    int TotalTAT=0,TotalWT=0;


    cout<<"\nPROCESS     "<<"BT     "<<"TAT     "<<"WT     "<<endl;
    for(int i=0;i<N;i++)
    {
        cout.setf(ios::left,ios::adjustfield);
        cout.width(12);
        cout<<Table[i].index;

        cout.width(7);
        cout<<Table[i].BT;

        cout.width(8);
        // Table[i].TAT=Table[i].CT; //TAT=CT-ArrivalTime
        cout<<Table[i].Remaining;
        // TotalTAT+=Table[i].TAT;

        cout.width(7);
        // Table[i].WT=Table[i].TAT-Table[i].BT;
        // cout<<Table[i].WT;
        // TotalWT+=Table[i].WT;

        cout<<endl;
    }

    cout<<"\nATAT ="<<TotalTAT/N;
    cout<<"\nAWT ="<<TotalWT/N<<endl;
}

int main()
{
    PROCESSES Table[MAX];
    processInput(Table);
    processArrange(Table);
    RR(Table);
    // ProcessInfo(Table);
   
}