class Solution {
    public int addDigits(int num) {
        int d,sum=0;
       while(true)
       {
          d=num%10;
          sum=0;
          while(num!=0)
          {
              sum=sum+num%10;
              num=num/10;
          }
          num=sum;
          if(num<=9)
          {
              return num;
          }
       }

    }
}