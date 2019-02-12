#1)remove first element from the sum
#2)the solution then remains to find two numbers having the sum equal to the
#   remaining of the sum after we remove of the first element from the original sum.
def find_triplet(array, size, sum):
    for i in range(0, size-1):
        #removing array[i] from the sum
        curr_sum = sum - array[i]
        #initialize a set to keep track of the elements visited
        s =set()
        for j in range(i+1, size):
            if(curr_sum - array[j] in s):
                print ("triplets:" ,array[i], array[j], curr_sum - array[j])
                return True
            else:
                s.add(array[j])
    return False
array = [1, 4, 45, 6, 10, 8]
sum = 22
size = len(array)
find_triplet(array, size, sum)
