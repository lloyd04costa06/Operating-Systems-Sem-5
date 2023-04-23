#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#define MAX_REQUESTS 15
using namespace std;

vector<int> QUEUEmax;
vector<int>QUEUEmin;


void SCAN()
{
     int t,CURRENT_RW,N,TRACKS;
    cout<<"ENTER CURRENT R/W HEADER POSITION: ";
    cin>>CURRENT_RW;

    cout<<"ENTER NUMBER OF REQUESTS: ";
    cin>>N;

     cout<<"ENTER NUMBER OF TRACKS: ";
    cin>>TRACKS;

    cout<<"ENTER THE REQUESTS: ";
    for(int i=0;i<N;i++)
    {
        cin>>t;
        if(t>CURRENT_RW)
        QUEUEmax.push_back(t);
        else
         QUEUEmin.push_back(t);
    }

    // QUEUEmax.push_back(TRACKS-1); //Need to go to the end
    QUEUEmax.push_back(CURRENT_RW); //Move from the current pointer
    // QUEUEmin.push_back(0); //Need to go to 0

    sort(QUEUEmax.begin(),QUEUEmax.end());
    sort(QUEUEmin.begin(),QUEUEmin.end());
    
    
    vector<int>::iterator V1;
    cout<<"DISK SCHEDULE: ";
    for(V1=QUEUEmax.begin();V1!=QUEUEmax.end();++V1)
    {
        cout<<*(V1)<<" --> ";
    }
     for(V1=QUEUEmin.begin();V1!=QUEUEmin.end();++V1)
    {
        cout<<*(V1)<<" --> ";
    }
    cout<<endl;

    int seek1=QUEUEmax.front()-QUEUEmax.back();
    int seek2=QUEUEmax.back()-QUEUEmin.front();
    int seek3=QUEUEmin.front()-QUEUEmin.back();
    int final=abs(seek1)+abs(seek2)+abs(seek3);
   
    cout<<"\nTOTAL NUMBER OF SEEKS: "<<final;

}
int main()
{
   
   SCAN();
   /*
   Start from current pointer and move till the last track and face the first smallest element
   after the First Header Position
   */
  
}