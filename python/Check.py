def check(list1, val):
    for x in list1:
        if val >= x:
            return "Yes"
    return "No"


list1 = [10, 20, 30, 40, 50, 60]
val = 5
print(check(list1, val))
val = 20
print(check(list1, val))
