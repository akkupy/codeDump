#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int oc(char open,char close)
{
    if(open=='{' && close=='}') return true;
    else if(open=='[' && close==']') return true;
    else if(open=='(' && close==')') return true;
    else return false;
}
int Check(char *str)
{
    stack< char> s;
    for(int i=0;i<strlen(str);++i)
    {
        if(str[i]=='{' || str[i]=='(' || str[i]=='[')
        {
            s.push(str[i]);
        }
        else{
            if( oc(s.top(), str[i]))
            {
                s.pop();

            }else{
               // cout<<"Not balanced";
                break;
            }
        }

    }
    return s.empty() ? true:false;

}

int main()
{
    char sym[7]={'[',']','{','}', '(', '{'};
   
    if(Check(sym))  cout<<"Balanced";
    else cout<<"Not Balanced";
    

    return 0;
}