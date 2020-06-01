using namespace std;
int partition(int input[], int si, int ei){
    int pivot = input[si];
    int count_smaller_than_pivot = 0;
    for(int i = si+1; i <= ei; i++ ){
        if(input[i] <= pivot){
            count_smaller_than_pivot++;
        }
    }
    int position = si + count_smaller_than_pivot;
    swap(input[si], input[position]);
    int  l = si, r = ei;
    while(l<r){
        if(input[l] <= pivot){
            l++;
        }
        else if(input[r] > pivot){
            r--;
        }
        else{
            swap(input[l], input[r]);
        }
    }
    return position;
}

void quickSortHelper(int input[], int si, int ei){
    if(si >= ei) return;
    int x = partition(input, si, ei);
    quickSortHelper(input, si, x-1);
    quickSortHelper(input, x+1, ei);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    quickSortHelper(input, 0, size -1);

}
