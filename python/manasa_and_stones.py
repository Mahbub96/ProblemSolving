# solveing another problem from hackerrank
def calculateSolution(n,i, a, b):
    finalResult = 0
    
    # find large number and put that number into b
    if a > b : a,b = b,a

    # add a for n-i times 
    while(n-i-1 != 0) :
        finalResult += a
        n-=1
    
    # add b for i times
    while(i!=0) :
        finalResult += b
        i -= 1
    return finalResult

testcase = int(input())
for i in range(testcase) :
    n,a,b = int(input()),int(input()),int(input())
    for i in range(n) :
        print(calculateSolution(n,i,a,b),end=" ")
        if a==b :
            break
    print()
