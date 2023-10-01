class Solution {
public:
    int romanToInt(string s) {
       int d=0;
       for(int i=0;i<s.length();i++){
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    d=d+4;
                    i++;
                }
                else if(s[i+1]=='X'){
                    d=d+9;
                    i++;
                }
                else{
                d=d+1;
                }
            }
            else if(s[i]=='V'){
                d=d+5;
            }
            else if(s[i]=='X'){
                if(s[i+1]=='L'){
                    d=d+40;
                    i++;
                }
                else if(s[i+1]=='C'){
                    d=d+90;
                    i++;
                }
                else{
                d=d+10;
            }
            }
            else if(s[i]=='L'){
                d=d+50;
            }
            else if(s[i]=='C'){
                if(s[i+1]=='D'){
                    d=d+400;
                    i++;
                }
                else if(s[i+1]=='M'){
                    d=d+900;
                    i++;
                }
                else{
                d=d+100;
            }
            }
            else if(s[i]=='D'){
                d=d+500;
            }
            else if(s[i]=='M'){
                d=d+1000;
            }
        }
        return d;
    }
};
