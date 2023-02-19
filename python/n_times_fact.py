def count_zero(n):
    strN = str(n)
    c = 0
    l = len(strN)
    for i in range(l,0,-1):
        if strN[i] == 0: c += 1 
        break
           
    return c


def fact(n):
    if n == 1 : return 1
    return n * fact(n-1)

for i in range(2,40):
    pass
    
    # print(f"{i} : {fact(1000)}")
print(count_zero(100))
    