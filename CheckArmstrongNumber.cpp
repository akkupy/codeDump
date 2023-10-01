// What is Armstrong Number
//A positive integer of n digits is called an Armstrong number of order n (order is the number of digits) if

//abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + .... 

//example:-

//153 
//it is an Armstrong number.
//1*1*1 + 5*5*5 + 3*3*3 = 153

// 120
//Output: false
//120 is not an Armstrong number.
//1*1*1 + 2*2*2 + 0*0*0 = 9


bool isArmstrong(int n){
	//edge case when n==1
	if(n==1){return true;}
  // converting the no. isto string 
	string str = to_string(n);
	int size = str.size();

   int digit;
   int poww = n;
   int sum = 0;
  // separating the digits from a number
   while (n > 0) {
     digit = n%10;
	sum +=  pow(digit,size);
	n /=10;
	 
   }
  // checking the condition 
   if(sum == poww) return true;
   return false;
}
