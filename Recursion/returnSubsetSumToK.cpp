/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    if(n == 0){
        if(k == 0){
            output[0][0] = 0;
            return 1;
        }
        else{
            return 0;
        }
    }
    int o1[500][50], o2[500][50];
    int t1 = subsetSumToK(input , n - 1, o1, k-input[n-1]);
    int t2 = subsetSumToK(input , n - 1, o2, k);

    for(int i = 0; i < t1; i++){
        output[i][0] = o1[i][0]  + 1;
    //}
   // for(int i = 0; i < t1; i++){
        int j;
       for(j=1; j <= o1[i][0]; j++){//change the range
            output[i][j] = o1[i][j];
        } 
        output[i][j]=input[n-1];
    }
    //for(int i = 0; i < t1; i++){
      //  output[i][1] = input[0];
    //}

 int p=0;//take another varaible for coyping
    for(int i =t1 ; i < (t1+t2); i++){
        for(int j = 0; j <= o2[p][0]; j++){
            output[i][j] = o2[p][j];
        }p++;

    }
    return t1 + t2;

}
