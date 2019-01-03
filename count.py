def hasPairSum(arr, len, sum):
    s = set()
    for i in range(0,len):
        temp = sum - arr[i]
        if(temp in s ):
            print(arr[i], temp)
        s.add(arr[i])
    else:
        print("DNE")
A = [-1,-4,45,6,10,8]
n = 1005
hasPairSum(A, len(A), n)
