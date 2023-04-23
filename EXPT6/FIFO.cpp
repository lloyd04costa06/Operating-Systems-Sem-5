#include<iostream>
using namespace std;
#define MAX_PROCESSES 20
#define HIT H++
#define FAULT F++



int FRAMES,N,P[MAX_PROCESSES];
int FRAME_box[MAX_PROCESSES];
int H=0,F=0;


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

void FIFO()
{
    RESET_ALLO();
    int INC=0;
    for(int i=0;i<N;i++)
    {
        int FLAG=0;
   
        for(int j=0;j<FRAMES;j++)
        {
            if(P[i]==FRAME_box[j])
             {
                 HIT; 
                 FLAG=1;
             }
        }
        if(FLAG!=1)
        {
            FRAME_box[INC]=P[i];
            INC=(INC+1)%FRAMES;
            FAULT;  
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