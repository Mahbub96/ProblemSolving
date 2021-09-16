def findPath(i,j,m,n):
    if i == m or j == n :
        return 0
    if (i == (n - 1) and j == (m - 1)) : 
        return 1
    return findPath(i, j + 1, n, m) + findPath(i + 1, j, n, m) 

print(findPath(0,0,5,5))