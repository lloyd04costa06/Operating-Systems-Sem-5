#include<iostream>
#define MAX_PROCESSES 20
#define MAX_RESOURCES 5
using namespace std;

int AVAILABLE[MAX_PROCESSES][MAX_RESOURCES];
int REMAINING_NEED[MAX_PROCESSES][MAX_RESOURCES];
int ALLOCATION[MAX_PROCESSES][MAX_RESOURCES];
int MAX_NEED[MAX_PROCESSES][MAX_RESOURCES];
int TOTAL_RESOURCES[MAX_RESOURCES];
int INITIAL_TOTAL[MAX_RESOURCES],REQUEST[MAX_RESOURCES],R_index;
bool FLAG[MAX_PROCESSES];
int N,RESOURCES;
int NotInSafeSequence=false;
int sep=0,InfiniteLoop;
  int SAFE_SEQ[MAX_PROCESSES];

void BANKERS_INPUT()
{ 
  int i,j;
  cout<<"ENTER NUMBER OF PROCESSES: ";
  cin>>N;
  cout<<"ENTER NUMBER OF RESOURCES: ";
  cin>>RESOURCES;
  cout<<"ENTER TOTAL RESOURCE VALUES RESPECTIVELY: ";
  for(i=0;i<RESOURCES;i++)
  {
    cin>>TOTAL_RESOURCES[i];
  }

  cout<<"ENTER ALLOCATION MATRIX:\n";
  for(i=0;i<N;i++)
  {
       cout<<"P"<<i+1<<": ";
    for(j=0;j<RESOURCES;j++)
    {
     
        cin>>ALLOCATION[i][j];
    }
  }

  cout<<"ENTER MAX NEED MATRIX:\n";
  for(i=0;i<N;i++)
  {
    cout<<"P"<<i+1<<": ";
    for(j=0;j<RESOURCES;j++)
    {
        cin>>MAX_NEED[i][j];
    }
  }

  for(i=0;i<N;i++)
  {
    FLAG[i]=false;
  }

}

void Calc_INITIALLY_AVAILABLE()
{
    int sum;

    for(int i=0;i<RESOURCES;i++)
    {
        sum=0;
        for(int j=0;j<N;j++)
        {
            sum+=ALLOCATION[j][i];
        }
        INITIAL_TOTAL[i]=sum; 
    }

    for(int i=0;i<RESOURCES;i++)
    { AVAILABLE[0][i]=TOTAL_RESOURCES[i]-INITIAL_TOTAL[i];}
   
}

 void Calc_REMAINING_NEED()
 {
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<RESOURCES;j++)
        {
            REMAINING_NEED[i][j]=MAX_NEED[i][j]-ALLOCATION[i][j];
        }
    }
 }

int CHECK_if_all_true()
{
    InfiniteLoop++;
    for(int i=0;i<N;i++)
    {
        if(FLAG[i]==false)
        return 0;
    }
    return 1;
}
void BANKERS_ALGO()
{
    int fullfilled;InfiniteLoop=0;int s=0;
  
 
    Calc_REMAINING_NEED();
    Calc_INITIALLY_AVAILABLE();
  

    for(int i=0;i<N;i++)
    {
        FLAG[i]=false;
    }
    sep=0;
    while(1){
        for(int i=0;i<N;i++)
        {
            fullfilled=0;
            if(FLAG[i]==false)
            {
                for(int j=0;j<RESOURCES;j++)
                {
                    if(REMAINING_NEED[i][j]<=AVAILABLE[sep][j])
                    {fullfilled++;}
                }
              
                if(fullfilled==RESOURCES)
                {
                    FLAG[i]=true;
                    SAFE_SEQ[s++]=i;
                    // cout<<"P"<<i<<"  ";
                    for(int j=0;j<RESOURCES;j++)
                    {
                         AVAILABLE[sep+1][j]=AVAILABLE[sep][j]+ALLOCATION[i][j];
                    }
                    sep++;
                }
            }
        } 
        if(InfiniteLoop>N+40)
        {
            NotInSafeSequence=true;
            break;
        }
        if(CHECK_if_all_true())
        break;
    }

}

void PRINT_SAFEsequence()
{
     cout<<"\nSAFE SEQUENECE:  ";
    for(int i=0;i<N;i++)
    {
        cout<<"P"<<SAFE_SEQ[i]<<" ";
    }
}

void REQUEST_HANDLER()
{
    for(int i=0;i<RESOURCES;i++)
    {
    
        if(REQUEST[i]>REMAINING_NEED[R_index][i])
        {
            cout<<"PROCESS NEED CROSSES MAXIMUM CLAIM FOR RESOURCES\n";
            exit(1);
        }

        if(REQUEST[i]>AVAILABLE[0][i])
        {
            cout<<"PROCESS MUST WAIT, RESOURCES NOT AVAILABLE\n";
            exit(1);
        }
    }

    for(int i=0;i<RESOURCES;i++)
    {
        AVAILABLE[0][i]-=REQUEST[i];
        ALLOCATION[R_index][i]+=REQUEST[i];
        REMAINING_NEED[R_index][i]-=REQUEST[i];
    }
}

void RESTORE_SAFE()
{
    for(int i=0;i<RESOURCES;i++)
    {
        AVAILABLE[0][i]+=REQUEST[i];
        ALLOCATION[R_index][i]-=REQUEST[i];
        REMAINING_NEED[R_index][i]+=REQUEST[i];
    }
}

void PRINT_matrices()
{
    cout<<"\n\nPROCESS NUMBER      "<<"ALLOCATION      "<<"AVAILABLE      "<<"NEED      "<<endl;
    int i;
    for(i=0;i<N;i++)
    {
        cout.setf(ios::left,ios::adjustfield);
        cout.width(19);
        cout<<i;
        
        for(int j=0;j<RESOURCES;j++)
        {
            cout<<ALLOCATION[i][j]<<" ";
        }
       cout<<"          ";
        
        for(int j=0;j<RESOURCES;j++)
        {
            cout<<AVAILABLE[i][j]<<" ";
        }

        cout<<"          ";
        for(int j=0;j<RESOURCES;j++)
        {
            cout<<REMAINING_NEED[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<"                                   ";
        for(int j=0;j<RESOURCES;j++)
        {
            cout<<AVAILABLE[i][j]<<" ";
        }   


    cout<<endl;
}

int main()
{
       BANKERS_INPUT();
       BANKERS_ALGO();
      

       if(NotInSafeSequence==true)
       {
            cout<<"NOT IN SAFE SEQUENCE";
            exit(1);
       }
       else
       {
         cout<<"\nIN SAFE SEQUENCE\n";
          PRINT_matrices();
          PRINT_SAFEsequence();
       }
      



       cout<<"\nENTER REQUEST PROCESS NO: ";
       cin>>R_index;
       cout<<"ENTER REQUEST: ";
       for(int i=0;i<RESOURCES;i++)
       {
         cin>>REQUEST[i];
       }

       REQUEST_HANDLER();
       BANKERS_ALGO();
      

       if(NotInSafeSequence==true)
       {
        cout<<"\n\nREQUEST CANNOT BE GRANTED, HENCE RESTORED";
        RESTORE_SAFE();
        BANKERS_ALGO();
        PRINT_matrices();
        PRINT_SAFEsequence();
       }
       
       else
       {
         cout<<"REQUEST GRANTED";
          PRINT_matrices();
          PRINT_SAFEsequence();
       }
      


}