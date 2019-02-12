#naive solution in which we look at all possible triplets and compare the sum wtih
#given sum
def find_triplet(array, size, sum):
    for i in range(0, size-2):
        for j in range(0, size-1):
            for k in range(0, size):
                if(array[i] + array[j] + array[k] == sum):
                    print("triplets", array[i], array[j], array[k])
                    return True
    return False
array = [1, 4, 45, 6, 10, 8]
sum = 22
#check with 12 the elements repeat whic is not needed.
size = len(array)
find_triplet(array, size, sum)
