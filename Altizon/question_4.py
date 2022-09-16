def getSum(arr):
    n = len(arr)
    sum = 0;
    for i in range(n):
        sum += arr[i]
    return sum

def getAvg(arr):
    n = len(arr)
    sum = getSum(arr)
    avg = sum/n
    return avg

def getLargest(arr):
    n = len(arr)
    large = arr[0]
    for i in range(1,n):
        if arr[i] > large:
            large = arr[i]
    return large

def getSmallest(arr):
    n = len(arr)
    small = arr[0]
    for i in range(1,n):
        if arr[i] < small:
            small = arr[i]
    return small



def program(arr):
    sum = getSum(arr)
    avg = getAvg(arr)
    largest = getLargest(arr)
    smallest = getSmallest(arr)
    
    print(sum, avg, largest, smallest)



arr = [1,2,3,4,5,5]

program(arr)
