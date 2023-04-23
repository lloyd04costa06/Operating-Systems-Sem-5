#include<iostream>
#include<queue>

using namespace std;

#define MAX_SIZE 10
#define WAIT s--
#define SIGNAL s++
#define FULL EMPTY_SLOTS==X
#define SLOT_OCCUPIED EMPTY_SLOTS--

int s=0;
int EMPTY_SLOTS=MAX_SIZE;
int X=0;
queue<int> BUFFER;

void DISPLAY()
{
    queue<int> DISPLAY_BUFF=BUFFER;
    cout<<"CURRENT BUFFER CONTENT: ";

    if(DISPLAY_BUFF.empty()==true)
    {
        cout<<"QUEUE IS EMPTY"<<endl;
        return;
    }
    while(DISPLAY_BUFF.empty()==false)
    {
        cout<<DISPLAY_BUFF.front()<<"  ";
        DISPLAY_BUFF.pop();
    }
}










void PRODUCE()
{
    int r=rand()%100;

    if(FULL)
    {
       cout<<"\n\nQUEUE IS FULL";
       return;
    }

    WAIT;   cout<<"\n\nSEMAPHORE WAIT: "<<s<<endl;
    BUFFER.push(r);
    SLOT_OCCUPIED;
    SIGNAL; cout<<"SEMAPHORE SIGNAL: "<<s<<endl;





    DISPLAY();

}

void CONSUME()
{
    if(BUFFER.empty()==true)
    {
        cout<<"\n\nQUEUE IS EMPTY"<<endl;
        return;
    } 

    WAIT;   cout<<"\n\nSEMAPHORE WAIT: "<<s<<endl;
    cout<<"PROCESS CONSUMED: "<<BUFFER.front()<<endl;
    BUFFER.pop();X--;
    SIGNAL; cout<<"SEMAPHORE SIGNAL: "<<s<<endl;


    
    DISPLAY();
}








int main()
{
      int ch;
    do
    {
        cout<<"\n\n1: PRODUCE\n2: CONSUME\n3: DISPLAY\n0: EXIT\n";    
        cout<<"ENTER YOUR CHOICE ";
        cin>>ch;
        switch(ch)
        {
            case 1: PRODUCE();
                    break;

            case 2: CONSUME();
                    break;
            case 3: DISPLAY();
                    break;

            case 0: break;

            default : cout<<"INVALID CHOICE ";
                      break;
        }
    }while(ch);
    return 0;

}