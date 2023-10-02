class Solution {
public:
    string addStrings(string num1, string num2) {
    string num3;
    int c = 0;
    int len1 = num1.length();
    int len2 = num2.length();
    int maxlen = max(len1, len2);

    num1 = string(maxlen - len1, '0') + num1;
    num2 = string(maxlen - len2, '0') + num2;

     int temp=maxlen-1;
    while(temp>= 0) 
    {
        int digit1 = num1[temp] - '0';
        int digit2 = num2[temp] - '0';

        int sum = digit1 + digit2 + c;
        c = sum / 10;
        sum = sum%10;

        num3 = to_string(sum) + num3;
        temp--;
    }

    
    if (c > 0) {
        num3 = to_string(c) + num3;
    }

    return num3;
    }
};