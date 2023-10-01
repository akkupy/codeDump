def bin_to_dec(x):
    l=list(x)
    l=list(map(int,l))
    bin=j=0
    for i in range(len(l)-1,-1,-1):
        bin+=l[i]*2**j
        j+=1
    return bin
x=input("Enter a Binary Number: ")
print(bin_to_dec(x))