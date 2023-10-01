def FibonacciSeriesByTerms():
    nums = int(input("Enter number of terms: "))
    a,b,c = 0,1,0
    for i in range(nums):
        c = b
        b = a+b
        a = c
        print(a)

def FibonacciSeriesByMaxValue():
    nums = int(input("Enter the max value: "))
    a,b = 0, 1
    while(b<=nums):
        c = b
        b += a
        a = c
        print(a)

print("\n","-"*20,"Fibonacci Series","-"*20)
print("\n1.By no. of terms\n2.By max value")
a = int(input("\nEnter your choice[1 or 2]: "))

if(a == 1):
    FibonacciSeriesByTerms()
else:
    FibonacciSeriesByMaxValue() if(a == 2) else print("\nInvalid Input")
