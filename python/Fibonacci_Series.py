def FibonacciSeriesByTerms():
    nums = int(input("Enter number of terms: "))
    a = 0
    b = 1
    i = 0
    for i in range(0,nums):
        c = b
        b = a+b
        a = c
        print(a)

def FibonacciSeriesByMaxValue():
    nums = int(input("Enter the max value: "))
    a = 0
    b = 1
    while(b<=nums):
        c = b
        b = a+b
        a = c
        print(a)

print("\n","-"*20,"Fibonacci Series","-"*20)
print("\n1.By no. of terms")
print("\n2.By max value")
a = int(input("\nEnter your choice[1 or 2]: "))
if(a == 1):FibonacciSeriesByTerms()
else:
    if(a == 2):FibonacciSeriesByMaxValue()
    else:print("\nInvalid Input")