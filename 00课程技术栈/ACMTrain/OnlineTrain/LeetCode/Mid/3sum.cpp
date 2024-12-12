/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 /*solution 1: violence*/
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    returnColumnSizes = (int**)malloc(sizeof(int*) * *returnSize);

    int index = 0;

    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            for(int k = j + 1; k < numsSize; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    returnColumnSizes[index] = (int*)malloc(sizeof(int) * 3);
                    returnColumnSizes[index][0] = nums[i];
                    returnColumnSizes[index][1] = nums[j];
                    returnColumnSizes[index][2] = nums[k];
                    index++;
                }
            }
        }
    }

    return returnColumnSizes;
}
/*result fail and return AddressSanitizer*/


