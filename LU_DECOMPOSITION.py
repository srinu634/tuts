# O(n^3) Algorithm to find the determinant of a matrix
# Exceptions not yet handled
# Please note that not every matrix can have LU Decomposition



mat = [  [0]*300  ]*300 #2D Array
L = [  [0]*300  ]*300
U = [  [0]*300  ]*300

def Decompose(n):   #O(n^3)
    global mat,L,U
    for i in range(0,n):
        L[i][i] = 1 
        
    for j in range(0,n):
        for i in range(0,j+1):
            sum = 0
            for k in range(0,i):
                sum = sum + L[i][k]*U[k][j]
            U[i][j] = mat[i][j] - sum
        
        for i in range(j+1,n):
            sum = 0
            for k in range(0,j):
                sum = sum + L[i][k]*U[k][j]
            L[i][j] = (mat[i][j] - sum)/U[j][j]
    
    
def printMatrix(n):
    global mat
    for i in range(0,n):
         for j in range(0,n):
             print mat[i][j]

