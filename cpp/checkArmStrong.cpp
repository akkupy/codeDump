// ArmStrong number

//A positive integer of n digits is called an Armstrong number of order n (order is the number of digits) if
//abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + .... 

// Input:153
// Output: Yes
// 153 is an Armstrong number.
// 1*1*1 + 5*5*5 + 3*3*3 = 153

// Input: 1253
// Output: No
// 1253 is not an Armstrong Number
// 1*1*1*1 + 2*2*2*2 + 5*5*5*5 + 3*3*3*3 = 723


// logic to check whether any number is an Armstrong number or not

bool checkArmstrong(int n){
	//checking edge case here
	if(n==1){return true;}
  
  // converting into string
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
  // check if sum of the number is same as initial number or not
  // if it is same return true 
   if(sum == poww) return true;
   return false;
}
