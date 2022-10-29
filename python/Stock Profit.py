import array as arr
global curpro
def profit(a,i,n,curpro):
    small=a[i]
    
    maxpro=0
    for i in range(i,n):
        if i+1==n:
            curpro=curpro+maxpro
           
            break
        elif small<a[i+1]:
            
            if(a[i+1]-small>maxpro):
                maxpro=a[i+1]-small
                
        elif small>a[i+1]:
         
            small=a[i+1]
            flag=i+1
            
       
            curpro=curpro+maxpro

            curpro=profit(a,flag,n,curpro)
            break
        else:
            if i==0:
                flag=i+1
                profit(a,flag,n,curpro)
    return curpro

n=int(input("Enter no of stock prices:"))
l=[]
for i in range(n):
    a=int(input(":"))
    l.append(a)
curpro=0
a=arr.array('i',l)
pro=profit(a,0,n,curpro)
print("Maximum profit earned:",pro)
