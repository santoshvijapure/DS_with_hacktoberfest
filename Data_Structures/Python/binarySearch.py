def binarySearch(list, item):
    if len(list) == 0:
        return False
    else:
        middle = len(list) // 2
        if list[middle] == item:
            return True
        elif list[middle] > item:
            return binarySearch(list[:middle], item)
        else:
            return binarySearch(list[middle+1:], item)


testlist = [0, 1, 2, 8, 13, 17, 19, 32, 42, ]
print(binarySearch(testlist, 3))
print(binarySearch(testlist, 13))
