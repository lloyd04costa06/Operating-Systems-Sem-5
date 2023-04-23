#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#define MAX_REQUESTS 15
using namespace std;

int CURRENT_RW,PREVIOUS_RW;
int N,seekC=0;
struct REQUEST_DIFFERNCE{
    int REQUEST;
    int DIFF;
};
vector <REQUEST_DIFFERNCE>R;
 vector <REQUEST_DIFFERNCE>:: iterator IT;

int COMP(struct REQUEST_DIFFERNCE A,struct REQUEST_DIFFERNCE B)
{
  return(A.DIFF<B.DIFF);
}

void HEADER_UPDATER()
{
    PREVIOUS_RW=CURRENT_RW;
    for(IT=R.begin();IT!=R.end();++IT)
    {
        (*IT).DIFF=abs((*IT).REQUEST-CURRENT_RW);
    }
    IT=min_element(R.begin(),R.end(),COMP);
    CURRENT_RW=(*IT).REQUEST;
    R.erase(IT);
    seekC+=(abs(CURRENT_RW-PREVIOUS_RW));
    cout<<CURRENT_RW<<" ";
}
void SSTF()
{ 
    for(int i=0;i<N;i++)
    {
          HEADER_UPDATER();
    }
}

int main()
{
    int t;
    cout<<"ENTER CURRENT R/W HEADER POSITION: ";
    cin>>CURRENT_RW;

    cout<<"ENTER NUMBER OF REQUESTS: ";
    cin>>N;

    cout<<"ENTER THE REQUESTS: ";
    for(int i=0;i<N;i++)
    {
        cin>>t;
        R.push_back(REQUEST_DIFFERNCE());
        R[i].REQUEST=t;
    }
    cout<<"\nSEQUENCE: "<<CURRENT_RW<<" ";
    SSTF();
    cout<<"\nTOTAL NUMBER OF TRACK MOVEMENTS: "<<seekC;

  
}