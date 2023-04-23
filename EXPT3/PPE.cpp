#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 10
using namespace std;


int N,TOTbt=0,space=0;

typedef struct PROCESSES{
    int index;
    int BT;
    int AT;
    int PRIO;
    int TAT;
    int WT;
    int CT;
    int CountBT;
};

typedef struct ARRANGE{vector<PROCESSES> P;};
ARRANGE ALIST[50];


void processInput(PROCESSES Table[])
{
    int temp;
    cout<<"ENTER NUMBER OF ELEMENTS: ";
    cin>>N;
    cout<<"ENTER THE PROCESS DETAILS"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"P"<<i+1<<": \n";
        Table[i].index=i+1;
        cout<<"ENTER BURST TIME: ";
        cin>>Table[i].BT; TOTbt+=Table[i].BT;

         cout<<"ENTER ARRIVAL TIME: ";
        cin>>Table[i].AT;

        cout<<"ENTER PRIORITY: ";
        cin>>Table[i].PRIO;
        cout<<endl;

        Table[i].CountBT=0;
    }
}

bool CRITERIA2(PROCESSES A,PROCESSES B) {return(A.index<B.index);}

void ProcessInfo(PROCESSES Table[])
{
    int TotalTAT=0,TotalWT=0;
    sort(Table,Table+N,CRITERIA2);

    cout<<"\n\nPROCESS     "<<"BT     "<<"AT     "<<"CT     "<<"PRIORITY   "<<"TAT     "<<"WT     "<<endl;
    for(int i=0;i<N;i++)
    {
        cout.setf(ios::left,ios::adjustfield);
        cout.width(12);
        cout<<Table[i].index;

        cout.width(7);
        cout<<Table[i].BT;

        cout.width(7);
        cout<<Table[i].AT;

        cout.width(7);
        cout<<Table[i].CT;

        cout.width(11);
        cout<<Table[i].PRIO;

        cout.width(8);
        cout<<Table[i].TAT;
        TotalTAT+=Table[i].TAT;

        cout.width(7);
        cout<<Table[i].WT;
        TotalWT+=Table[i].WT;

        cout<<endl;
    }

    
    cout<<"\nATAT ="<<(float)TotalTAT/N;
    cout<<"\nAWT ="<<(float)TotalWT/N<<endl;
}

bool CRITERIA1(PROCESSES A,PROCESSES B) { return(A.PRIO<B.PRIO); }


void processArrange(PROCESSES Table[])
{
    for(int i=0;i<N;i++)
    {
        ALIST[Table[i].AT].P.push_back(Table[i]);
    }

}


void PROCESS_execute(int i,vector<PROCESSES>& WaitQ)
{
        if(WaitQ.empty()!=true)
        {
            cout<<"| P"<<WaitQ[0].index<<" ";
            WaitQ[0].CountBT++;
        }
        else{
            cout<<"     ";
            space++;
        }
}

void PRIORITY_SCHEDULING(PROCESSES Table[])
{
    vector<PROCESSES>WaitQ;
    vector<PROCESSES>::iterator QT;
    int i;
    cout<<endl<<"GHANTT CHART\n";

     for(i=0;i<TOTbt+space;i++)
     {
            if(ALIST[i].P.empty()==false)
            {
                for(QT=ALIST[i].P.begin();QT!=ALIST[i].P.end();++QT)
                {
                    WaitQ.push_back(*QT);
                }
                sort(WaitQ.begin(),WaitQ.end(),CRITERIA1); 
            }

       
            PROCESS_execute(i,WaitQ);
            
                 
            if(WaitQ.empty()!=true)
            if(WaitQ[0].CountBT==WaitQ[0].BT)
            {
                Table[WaitQ[0].index-1].CT=i+1; 
                Table[WaitQ[0].index-1].TAT=(Table[WaitQ[0].index-1].CT) - (Table[WaitQ[0].index-1].AT);
                Table[WaitQ[0].index-1].WT=(Table[WaitQ[0].index-1].TAT) - (Table[WaitQ[0].index-1].BT);
                WaitQ.erase(WaitQ.begin()); //If process BT done then delete from waiting queue

            }
     }
     
     cout<<"|"<<endl;
     for(int j=0;j<=TOTbt+space;j++)
     { 
        cout.setf(ios::left,ios::adjustfield);
        cout.width(5);
        cout<<j; 
    }


}

int main()
{
    PROCESSES Table[MAX];
    processInput(Table);
    processArrange(Table);
    cout<<endl<<endl;
    PRIORITY_SCHEDULING(Table);
    ProcessInfo(Table);

}

