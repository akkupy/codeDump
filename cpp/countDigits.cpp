//count the digit present in the number
int countDigits(int n){

  int cnt=0;
	int digit = n;

  //separate the digits from a number and count it
	while(digit >0){
	int rem = digit%10;
	if( rem !=0 && n%rem == 0){
		cnt++;
	}
	digit /=10;
	}
  
  // return the count
	return cnt;
}
