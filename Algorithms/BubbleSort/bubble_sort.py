# Contributed by - Ankit Das <ankit.99d@gmail.com>
def bubbleSort(arr):
    n = len(arr)
    is_swapped = False
    for i in range(n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j + 1]:
                is_swapped = True
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
         
        if not is_swapped:
            return
 
arr = [23, 121, -23, 24, 56, 12, 99]
 
bubbleSort(arr)
 
print("Sorted array :")
for i in range(len(arr)):
    print("% d" % arr[i], end=" ")