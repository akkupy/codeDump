#include<iostream>
#include<string>
#include<queue>

using namespace std;


int Weight(char x)
{
    switch(x){
        case '+':{return 1;}
        case '-':{return 1;}
        case '*':{return 2;}
        case '/':{return 2;}
        case '^':{return 3;}
        default:{return -1;}
    }
}

bool Is_Operator(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')'){return true;}
    else {return false;}
}

bool Is_Operand(char x)
{
    if(x>=48 && x<=57){ return true; }           // FOR '1','2',.....,'9'
    else if(x>=97 && x<=122){ return true; }     // FOR  a,b,c,d.....,z
    else if(x>=65 && x<=90){ return true; }      // FOR  A,B,C.....,Z
    else return false;
}

bool Has_Higher_Preceedence(char x1,char x2)
{
    if(Weight(x1)>Weight(x2)){return true;}
    else{return false;}
}

queue<char> q1,q2;

void Push(char x)
{
    if(q1.empty())
    {
        q1.push(x);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }else if(q2.empty())
    {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
    }
}

void Pop(queue<char> &q)
{
    try{
        if(q.empty())
        {
            throw q;
        }
        q.pop();
    }
    catch(...)
    {
        cout<<"QUEUE IS EMPTY !!!\n";
    }
}

string Infix_to_Postfix(string Infix)
{
    string Postfix;
    for(int i=0;i<Infix.size();++i)
    {
        if(Is_Operator(Infix[i]))
        {
            if(q1.empty())
            {   
                if(q2.empty()){
                    Push(Infix[i]); 
                }
                else if(Has_Higher_Preceedence(Infix[i],q2.front()))
                {
                    Push(Infix[i]);    
                }else{
                    while(!Has_Higher_Preceedence(Infix[i],q2.front()))
                    {
                        Postfix=Postfix+q2.front();
                        //q2.pop();
                        Pop(q2);
                    }
                    Push(Infix[i]); 
                }
                
            }else if(q2.empty())
            {
                if(q1.empty())
                {
                    Push(Infix[i]); 
                }
                else if(Has_Higher_Preceedence(Infix[i],q1.front()))
                {
                    Push(Infix[i]);    
                }else{
                    while(!Has_Higher_Preceedence(Infix[i],q1.front()))
                    {
                        Postfix=Postfix+q1.front();
                        //q1.pop();
                        Pop(q1);
                    }
                    Push(Infix[i]); 
                }
            }
        }else{
            Postfix=Postfix+Infix[i];
        }
        //cout<<"Postfix Expression is: "<<Postfix<<endl;
    }
    while(!q1.empty())
    {
        Postfix=Postfix+q1.front();
       // q1.pop();
       Pop(q1);
    }
    while(!q2.empty())
    {
        Postfix=Postfix+q2.front();
        //q2.pop();
        Pop(q2);
    }
    return Postfix;
}

bool Check_If_Infix_Expression_Is_Correct(string s)
{
    int f1=0,f2=1,flag=1;
    for(int i=0;i<s.size();++i)
    {   
        if(f2 && !f1 && Is_Operand(s[i])){
            f1=1;  f2=0;       
        }else if(f1 && !f2 && Is_Operator(s[i]))
        {
            f1=0;   f2=1;
        }else{  
            flag=0;
            break;}
    }
    if(flag && Is_Operand(s[s.size()-1])){return true;}
    else{return false;}
}


int main()
{
    int t=1,choice,k=1;
    string Infix,Postfix;
    
    while(t)
    {
        cout<<"1. Get Infix Expression                                  - ENTER 1\n";
        cout<<"2. Print Infix Expression                                - ENTER 2\n";
        cout<<"3. Print Postfix Expression                              - ENTER 3\n";
        cout<<"4. Exit                                                  - ENTER 4\n";
        cin>>choice;
        switch(choice)
        {
            case 1:{
                while(k)
                {
                    try{
                        cout<<"Enter the Infix Expression: ";
                        cin>>Infix;
                        if(!Check_If_Infix_Expression_Is_Correct(Infix)){
                            throw Infix;
                        }
                        k=0;
                    }
                    catch(string x){
                        cout<<x<<" IS NOT AN INFIX EXPRESSION\n\n";
                    }
                }
                k=1;
                break;
            }
            case 2:{
                cout<<"Infix Expression is: "<<Infix<<endl;
                break;
            }case 3:{
                Postfix=Infix_to_Postfix(Infix);
                cout<<"Postfix Expression is: "<<Postfix<<endl;
                break;
            }
            case 4:{    t=0;
                break;
            }
            default:
            {
                cout<<"ENTER A VALID CHOICE !!!\n";
            }
        }
    
        
    }
    
    return 0;
}