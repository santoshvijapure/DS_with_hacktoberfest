# Python program to find n-th stair   
# using step size 1 or 2 or 3. 
  
# Returns count of ways to reach n-th  
# stair using 1 or 2 or 3 steps. 
def findStep( n) : 
    if (n == 1 or n == 0) : 
        return 1
    elif (n == 2) : 
        return 2
      
    else : 
        return findStep(n - 3) + findStep(n - 2) + findStep(n - 1)  
  
  
# Driver code 
n = 4
print(findStep(n)) 
  
# This code is contributed by Nikita Tiwari. 
