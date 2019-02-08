def maxDiff(array ,n):
    #we assume a max difference
    max_diff=array[1] - array[0]
    #we assume a minimun element
    min_element = array[0]

    for i in range(1, n):
        #if the difference between the ith array element
        #and the minimum element is greater than the assumed max difference
        #then max difference will be the difference b/w the the ith array element
        #and the minimum element
        if(array[i] - min_element > max_diff):
            max_diff = array[i] - min_element
        #condition to keep updating the minimum element as we go through the array
        if(array[i]<min_element):
            min_element = array[i]
    return max_diff
array = [1, 2, 6, 80, 110]
n = len(array)
print (maxDiff(array, n))
