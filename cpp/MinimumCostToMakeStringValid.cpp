
// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0

#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  // Write your code here
    
    if((str.length() % 2) != 0) return -1;
    
  stack<char> ch;
  int cost=0;
  
  for(int i=0; i<str.length(); i++) {
      if(str[i] == '{') {
          ch.push('{');
      }else {
          if(ch.empty()) {
              cost++;
              ch.push('{');
          }else {
              ch.pop();
          }
      }
  }
  cost += ch.size()/2;
  return cost;
    
//     if(s.length()%2!=0)
//         return -1;
//     stack<char> st;
//     for(int i=0;i<s.length();i++){
//         if(st.empty()){
//             st.push(s[i]);
//             continue;
//         }
//         char t= st.top();
//         if(t=='{' && s[i]=='}')
//             st.pop();
//         else
//             st.push(s[i]);
//     }
//     int count=0;
//     if(st.empty())
//         return 0;
//     else{
//         char ch=st.top();
//         st.pop();
//         while(!st.empty()){
//             if(st.size()%2!=0){
//                 if(ch=='}' && st.top()=='}')
//                     count++;
//                 else if(ch=='{' && st.top()=='{')
//                     count++;
//                 else
//                     count+=2;
//             }
//             else{
//                 ch=st.top();
//             }
//             st.pop();
//         }
//     }
//     return count;
// //     int a=0, b=0;
// //     while(!st.empty()){
// //         if(st.top()=='{')
// //             a++;
// //         else
// //             b++;
// //         st.pop();
// //     }
// //     return ((a+1)/2)+((b+1)/2);
}





