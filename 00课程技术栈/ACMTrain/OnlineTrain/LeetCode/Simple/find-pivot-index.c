int pivotIndex(int* nums, int numsSize) {
    int *sums;
    sums = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0 ; i < numsSize ; i++ ){
        sums[i] = (i == 0 ? nums[i] : sums[i-1] + nums[i]);
    }

    int ans = -1;
    for(int i = 0 ; i < numsSize ; i++ ){
        if(sums[i]-nums[i] == sums[numsSize-1]-sums[i]){
            ans = i;
            break;          
        }
    }

    return ans;
}

