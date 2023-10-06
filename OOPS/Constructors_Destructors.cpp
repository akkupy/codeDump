#include<iostream>
using namespace std;

class Time1{
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        Time1()
        {
            hours=0;    minutes=0;      seconds=0;
        }
        Time1(int h,int m, int s)
        {

            hours=h;    minutes=m;      seconds=s;
        }
        int gethour()
        {
            return hours;
        }
        int getminutes()
        {
            return minutes;
        }
        int getseconds()
        {
            return seconds;
        }
        ~Time1(){}

};

void Print_Standard_Time(Time1 T );

void Print_Universal_Standard_Time(Time1 T);

void Print_Indian_Standard_Time(Time1 T);


void Print_Pacific_Standard_Time(Time1 T);


Time1 Set_Time();

void Functions(Time1 T);

int main()
{
    int t=1,x;
    while(t)
    {
        cout<<"\nCreate                - ENTER 1"<<endl;
        cout<<"Create and Set Time   - ENTER 2"<<endl;
        cin>>x;
        switch(x)
        {
        case 1:{Time1 T1;                    
            Functions(T1);      t=0;
            break;}
        case 2:{Time1 T1=Set_Time();         
            Functions(T1);      t=0;
            break;}
        default:
            cout<<"ENTER A VALILD CHOICE\n\n";
        }
    }
      

    return 0;
}

void Print_Standard_Time(Time1 T )
{
    int h,m,s,flag=0;
    h=T.gethour();
    m=T.getminutes();
    s=T.getseconds();
    if(h>=12)
    {
        if(h==24){h=12;flag=0;}
        else{
            h=h-12;
            flag=1;
        }
        
    }

    if(flag)
    {
        if(h==12)
        {
            if(m>0 || s>0){h=0;}
        }
        cout<<h<<":"<<m<<":"<<s<<" PM"<<endl; 
    }else{
        cout<<h<<":"<<m<<":"<<s<<" AM"<<endl; 
    }
}

void Print_Universal_Standard_Time(Time1 T)
{
    int h,m,s,flag=0;
    h=T.gethour();
    m=T.getminutes();
    s=T.getseconds();

        cout<<h<<":"<<m<<":"<<s<<endl;
}

void Print_Indian_Standard_Time(Time1 T)
{
    int h,m,s,flag=0;
    h=T.gethour();
    m=T.getminutes();
    s=T.getseconds();

    h=h+5;
    m=m+30;
    if(h>24)
    {
        h=h-24;
    }
    if(m>=60)
    {
        h=h+1;
        m=m-60;
    }
    if(h>24)
    {
        h=h-24;
    }
    
    cout<<h<<":"<<m<<":"<<s<<endl;

}

void Print_Pacific_Standard_Time(Time1 T)
{
    int h,m,s,flag=0;
    h=T.gethour();
    m=T.getminutes();
    s=T.getseconds();
    h=h-8;
    if(h<0)
    {
        h=h+24;
    }
    
    if(h>12)
    {
        if(h==12)
        {
            if(m>0 || s>0){h=0;}
        }else{
            h=h-12;
        }
        cout<<h<<":"<<m<<":"<<s<<" PM"<<endl; 
    }else{
        cout<<h<<":"<<m<<":"<<s<<" AM"<<endl; 
    }
}

Time1 Set_Time()
{
    int t=1,m, h,s;
    cout<<"Enter the time in GMT\n";
            while(t)
            {
                cout<<"ENTER HOUR (0 - 24): ";
                cin>>h;
                if(h<0 || h>24)
                {
                    cout<<"ENTER THE VALID HOUR"<<endl;
                }else break;
            }       
            while(t)
            {
                cout<<"ENTER MINUTES (0 - 59): ";
                cin>>m;
                if(m<0 || m>=60){
                    cout<<"ENTER VALID MINUTES"<<endl;
                }else break;
            }
            while(t)
            {
                cout<<"ENTER SECONDS (0 - 59): ";
                cin>>s;
                if(s<0 || s>=60)
                {
                    cout<<"ENTER VALID SECONDS"<<endl;
                }else break;
            }
            Time1 T(h,m ,s);
            return T;
}

void Functions(Time1 T)
{
    int x,flag=1;
    while(1)
    {
        cout<<"\nPrint Standard Time          - ENTER 1\n";
        cout<<"Print Universal Standard Time- ENTER 2\n";
        cout<<"Print Indian Standard Time   - ENTER 3\n";
        cout<<"Print Pacific Standard Time  - ENTER 4\n";
        cout<<"Reset Time                   - ENTER 5\n";
        cout<<"Exit                         - ENTER 6\n";

        cin>>x;
        switch(x)
        {
            case 1:Print_Standard_Time(T);          break;
            case 2:Print_Universal_Standard_Time(T);    break;
            case 3:Print_Indian_Standard_Time( T);       break;
            case 4:Print_Pacific_Standard_Time(T);      break;
            case 5:T=Set_Time();                    break;
            case 6:flag=0; break;
            default:cout<<"ENTER VALID CHOICES !!!\n\n";
        }
        if(!flag){break;}
    }
}
