def maxDiff(array, n):
    max_diff = array[1]-array[0]
    for i in range(0, n):
        for j in range(i+1, n):
            diff = array[j] - array[i]
            if(diff > max_diff):
                max_diff= diff
    print(max_diff)

array = [1, 2, 7, 6, 5]
n = len(array)
maxDiff(array, n)
