/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i , j = 0;
    
    for (i = 0 ; i < numsSize; i++){
        
        for(j = i + 1; j < numsSize; j++){
            
            if(nums[j] + nums[i] == target){
                
                int *arr = malloc(2*numsSize);
                arr[0] = i;
                arr[1] = j;
                
                return arr;
            }
        }
    }
    
    return 0;
}
