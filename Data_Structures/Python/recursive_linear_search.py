def recursive_linear_search(x, l, h, num):
    if(l > h):
        print(str(num)+" not found")
    if(x[l] == num):
        print(str(num)+" found in position "+str(l+1))
        return
    if(x[h] == num):
        print(str(num)+" found in position "+str(h+1))
        return
    recursive_linear_search(x, l+1, h-1, num)
    
    
x = [1, 9, 3, 6, 8, 3]
n = len(x)
num = 6 #number to be searched in array arr
recursive_linear_search(x, 0, n-1, num)
