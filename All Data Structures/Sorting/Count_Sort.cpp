#Count Sort Function
def countSort(arr):
    x = max(arr) #Finding the maximum element of the arr
    countArr = [0 for i in range(x+1)]   #Initialising countArr with 0 with length x+1
    resultArr = [0 for i in range(len(arr))]  #Initialising resultArr with 0 with length same of arr
    for i in range(0,len(arr)):
        countArr[arr[i]]+=1  #counting each number of each distinct values in the arr
    for i in range(1, len(countArr)):
        countArr[i]=countArr[i]+countArr[i-1]   #updating the countArr to cummulative sum
    for i in range(len(arr)-1,-1,-1):
        countArr[arr[i]]-=1 
        resultArr[countArr[arr[i]]]=arr[i]     #Filling up the resultArr
    return resultArr
#*****************************************************************************************************************#
#arr to be sorted
arr = [7, 1, 4, 2, 1, 3, 1, 4, 5, 2]
resultArray = countSort(arr)
print("Original Array: ", arr, "Sorted Array: ", resultArray)
#*****************************************************************************************************************#
