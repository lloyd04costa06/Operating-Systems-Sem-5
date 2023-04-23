#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_PROCESSES 20
#define HIT H++
#define FAULT F++



int FRAMES,N,P[MAX_PROCESSES];


vector<int> FRAME_box;
int H=0,F=0;

vector <int>AlreadyHandled;


void RESET_ALLO()
{
    for(int i=0; i<FRAMES;i++)
    {FRAME_box[i]=-1;}
}

void PRINT_FRAME()
{
    for(int i=0; i<FRAMES;i++)
    {cout.width(3);cout<<FRAME_box[i]<<" ";}
    cout<<endl;
}

void LRU(int P)
{
    int t,min=100000;
    cout<<"CCC";
    if(FRAME_box.size()<=FRAMES)
    {
        FRAME_box.push_back(P);
    }
    else{
       for(int i=0;i<FRAMES;i++)
       {
         for(int j=0;j<AlreadyHandled.size();j++)
         {
            if(FRAME_box[i]==AlreadyHandled[j])
            {
                t=j;
            }
         }
         if(t<min)
         {
            min=t;
         }
       }

       for(int i=0;i<FRAMES;i++)
       {
         if(FRAME_box[i]==AlreadyHandled[min]);
         {
            FRAME_box[i]=P;
            break;
         }
       }
    }


}

void FIFO()
{
    RESET_ALLO();
    int INC=0,c=0;
    for(int i=0;i<N;i++)
    {
        int FLAG=0;
   
        for(int j=0;j<FRAMES;j++)
        {
            if(P[i]==FRAME_box[j])
             {
                 HIT; 
                 FLAG=1;
                 AlreadyHandled[c++]=P[i];
             }
        }
        if(FLAG!=1)
        {
            LRU(P[i]);   
        }
        PRINT_FRAME();     
    }
     cout<<"\nNUMBER OF FAULTS: "<<F;
    cout<<"\nNUMBER OF HITS: "<<H;

}

int main()
{
    cout<<"ENTER NUMBER OF FRAMES: ";
    cin>>FRAMES;

    cout<<"ENTER NUMBER OF PROCESSES:";
    cin>>N;

    cout<<"ENTER PROCESSES: ";
    for(int i=0;i<N;i++)
    {cin>>P[i];}


    FIFO();

    
}