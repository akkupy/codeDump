def checkArmstrong(n,o):
    sum = 0
    temp = n
    while temp > 0:
       digit = temp % 10
       sum += digit ** o
       temp = temp//10
    if n == sum:
       print(n,"is an Armstrong number")
    else:
       print(n,"is not an Armstrong number")

num = int(input("Enter your Number: "))
order = len(str(num))
checkArmstrong(num,order)
