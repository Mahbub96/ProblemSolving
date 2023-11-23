n = int(input())


for i in range(1,n+1):
    m = int(input())
    arr = []
    for j in range(1,m+1):
        arr.append(input())
    
    arr.sort()
    x = arr[0]
    times = False
    found = "NO"

    for text in arr:
        if x in text:
            if times == False : 
                times = True
            else : 
                found = "YES"
                break
    
    print(f"Case {i} \: {found}")

            

