#Sorting a list in Ascending Order using Bubble Sort

#Bubble Sort function
def bubble_sort(alist):
    for i in range(len(alist) - 1, 0, -1):
        temp = True
        for j in range(0, i):
            if alist[j + 1] < alist[j]:
                alist[j], alist[j + 1] = alist[j + 1], alist[j]
                temp = False
        if temp:
            return
 
#Taking a list of space seperated numbers from user 
alist = input('Enter the list of numbers: ').split()
alist = [int(x) for x in alist]
bubble_sort(alist)
print('Sorted list: ', end='')
print(alist)
