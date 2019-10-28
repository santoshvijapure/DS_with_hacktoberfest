# -*- coding: utf-8 -*-

arr = [2,0,9,8,7,6,5,2,3,4,3,2,1]

def rec_inssort(n):
    if(n==0):
        return
    inssort(n-1)
    num = arr[n]
    j = n-1
    while(j >= 0 and arr[j] > num):
        arr[j+1] = arr[j]
        j -= 1
    arr[j+1] = num
    
print("Before sorting :", arr)
rec_inssort(len(arr) - 1)
print("After sorting", arr)
        
    
