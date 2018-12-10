/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int binary(int *nums, int n, int k, int dir){
    int low = 0;
    int high = n-1;
    int mid;
    
    while(low <= high){
        mid = low + (high - low)/2;
        
        if(nums[mid] == k){
            if(dir == -1){
                
                if(mid == 0 || nums[mid-1] != nums[mid]){
                    return mid;
                }else if(nums[mid-1] == nums[mid]){
                    high = mid-1;
                    continue;
                }
            }else if(dir == 1){
                if(mid == n -1 || nums[mid+1] != nums[mid]){
                    return mid;
                }else if(nums[mid+1] == nums[mid]){
                    low = mid + 1;
                    continue;
                }
            }
            
        }
        
        if(k < nums[mid]){
            high = mid -1;
        } else{
            low = mid + 1;
        }
    }
    
    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *arr = (int*)malloc(sizeof(int) * 2);
    
    *returnSize = 2;
    memset(arr, -1 , sizeof(arr));
    
    if(nums == NULL){
        return arr;
    }
    
    arr[0] = binary(nums, numsSize, target,-1);
    arr[1] = binary(nums, numsSize, target,1);
    
    return arr;
}
