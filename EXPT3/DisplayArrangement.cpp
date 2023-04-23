#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define MAX 10
using namespace std;


int N,TOTbt=0;

typedef struct PROCESSES{
    int index;
    int BT;
    int AT;
    int PRIO;
    int CountBT;
};

typedef struct ARRANGE{
    vector<PROCESSES> P;
};
ARRANGE ALIST[50];

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
        cin>>Table[i].BT; TOTbt+=Table[i].BT;

         cout<<"ENTER ARRIVAL TIME: ";
        cin>>Table[i].AT;

        cout<<"ENTER PRIORITY: ";
        cin>>Table[i].PRIO;
        cout<<endl;

        Table[i].CountBT=0;
    }

}

bool CRITERIA(PROCESSES A,PROCESSES B)
{
    return(A.PRIO<B.PRIO);
}


void processArrange(PROCESSES Table[])
{
    for(int i=0;i<N;i++)
    {
        ALIST[Table[i].AT].P.push_back(Table[i]);
    }

    // vector<PROCESSES>::iterator IT;
    // for(int i=0;i<TOTbt;i++)
    // {
    //     cout<<i<<"-->";
 
    //     {
    //         for(IT=ALIST[i].P.begin();IT!=ALIST[i].P.end();++IT)
    //         {
    //             cout<<"P"<<(*IT).index<<", ";
    //         }
  
    //      }
    //         cout<<endl;
    // }

}


void PROCESS_execute(int i,vector<PROCESSES>& WaitQ)
{
        cout<<"| P"<<WaitQ[0].index<<" ";
        WaitQ[0].CountBT++;
}

void PRIORITY_SCHEDULING(PROCESSES Table[])
{
    vector<PROCESSES>WaitQ;
    vector<PROCESSES>::iterator QT;
    int i;
    cout<<endl<<"GHANT CHART"

     for(i=0;i<TOTbt;i++)
     {
        if(ALIST[i].P.empty()==false)
        {
            for(QT=ALIST[i].P.begin();QT!=ALIST[i].P.end();++QT)
            {
                WaitQ.push_back(*QT);
            }
            sort(WaitQ.begin(),WaitQ.end(),CRITERIA); 
      }

        PROCESS_execute(i,WaitQ);
   
      


        if(WaitQ[0].CountBT==WaitQ[0].BT)
        {
            WaitQ.erase(WaitQ.begin());
        }

     }
  
     cout<<"|"<<endl;
     for(int j=0;j<TOTbt;j++)
     {
        cout<<j<<"    ";
     }


}

int main()
{
    PROCESSES Table[MAX];
    processInput(Table);
    processArrange(Table);
    cout<<endl<<endl;
    PRIORITY_SCHEDULING(Table);
  
}

