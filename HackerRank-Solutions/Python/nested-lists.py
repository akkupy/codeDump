n=int(input())
arr=[[input(),float(input())] for _ in range(0,n)]
arr.sort(key=lambda x: (x[1],x[0]))
names = [i[0] for i in arr]
marks = [i[1] for i in arr]
min_val=min(marks)
while marks[0]==min_val:
    marks.remove(marks[0])
    names.remove(names[0])    
for x in range(0,len(marks)):
    if marks[x]==min(marks):
        print(names[x])
