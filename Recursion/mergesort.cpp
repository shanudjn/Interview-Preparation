using namespace std;

void merge(int input[], int si, int ei){
    int mid = (si + ei) / 2;
    int i = si, j = mid + 1, k = 0;
    int output[1000] = {0};
    while(i <= mid && j <= ei){
        if(input[i] <= input[j]){
            output[k] = input[i];
            i++;
        }
        else{
            output[k] = input[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        output[k] = input[i];
        i++;
        k++;
    }
    while(j <= ei){
        output[k] = input[j];
        j++;
        k++;
    }
   // int m;

    for(k = 0,i = si; i <= ei; i++, k++){
        input[i] = output[k];
    }
}


void mergeSortHelper(int input[], int si, int ei){
    if(si>=ei) return;
    int mid = (si + ei)/2;
    //cout << mid;
    mergeSortHelper(input, si, mid);
    mergeSortHelper(input, mid+1, ei);
    merge(input, si, ei);

}


void mergeSort(int input[], int size){
	// Write your code here
        mergeSortHelper(input, 0, size - 1);

}
