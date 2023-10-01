//A palindromic number (also known as a numeral palindrome or a numeric palindrome) is a number (such as 16461) that remains the same when its digits are reversed. 
//In other words, it has reflectional symmetry across a vertical axis.

//example:-
// The first 30 palindromic numbers (in decimal) are:

//0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, …


// logic to check whether any number is palindrome or not

bool palindrome(int n)
{
    // converting number into string 
    string str = to_string(n);
    string p = str;
    int size = str.size();
  // running loop till half of the string sizeand swapping the string
    for (int i = 0; i < size / 2; i++){
        swap(str[i], str[size - i - 1]);}

  // checking the strings are equal or not
  // if it is equal, the number is palindrome number 
        if(p == str)return 1;
        else return 0;
        
}
