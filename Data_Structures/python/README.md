# Add Python Programs here

# Python program to demonstrate sorting in numpy 
import numpy as np 

a = np.array([[1, 4, 2], 
				[3, 4, 6], 
			[0, -1, 5]]) 

# sorted array 
print ("Array elements in sorted order:\n", 
					np.sort(a, axis = None)) 

# sort array row-wise 
print ("Row-wise sorted array:\n", 
				np.sort(a, axis = 1)) 

# specify sort algorithm 
print ("Column wise sort by applying merge-sort:\n", 
			np.sort(a, axis = 0, kind = 'mergesort')) 

# Example to show sorting of structured array 
# set alias names for dtypes 
dtypes = [('name', 'S10'), ('grad_year', int), ('cgpa', float)] 

# Values to be put in array 
values = [('Hrithik', 2009, 8.5), ('Ajay', 2008, 8.7), 
		('Pankaj', 2008, 7.9), ('Aakash', 2009, 9.0)] 
			
# Creating array 
arr = np.array(values, dtype = dtypes) 
print ("\nArray sorted by names:\n", 
			np.sort(arr, order = 'name')) 
			
print ("Array sorted by grauation year and then cgpa:\n", 
				np.sort(arr, order = ['grad_year', 'cgpa'])) 
