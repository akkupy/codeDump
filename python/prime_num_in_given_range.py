num1 = int(input("Enter num 1: "))
num2 = int(input("Enter num 2: "))
prime_number = []


for i in range(num1, num2 + 1):
    flag = 0
    if i < 2:
        continue
    if i == 2:
        prime_number.append(num1)
        continue

    for x in range(2, i):
        if i % x == 0:
            flag = 1
            break

    if flag == 0:
        prime_number.append(i)

print(f"Prime Numbers Are : {prime_number}")

