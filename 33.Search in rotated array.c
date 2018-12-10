/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

int findpiv(int *arr, int low, int high){
    if(high < low) return -1;
    if(high == low) return low;
    
    int mid = low + (high - low)/2;
    
    if(mid < high && arr[mid] > arr[mid + 1])
        return mid;
    else if(mid > low && arr[mid] < arr[mid-1])
        return mid-1;
    else if(arr[low] >= arr[mid])
        return findpiv(arr, low, mid-1);
    else
        return findpiv(arr, mid+1, high);
}

int binary(int *nums, int low, int high, int target){
    if(low <= high){
        int mid = low + (high-low)/2;
        
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return binary(nums, low, mid-1,target);
        else
            return binary(nums, mid+1, high,target);
    }    
    return -1;
}

int findpivotsearch(int *nums, int high, int target){
    int piv = findpiv(nums, 0, high);
    
    if(piv == -1)
        return binary(nums, 0 , high, target);
    
    if(nums[piv] == target)
        return piv;
    
    if(nums[0] <= target)
        return binary(nums, 0, piv-1,target);
    else
        return binary(nums, piv+1, high,target);
}


int search(int* nums, int numsSize, int target) {
    if(nums == NULL)
        return -1;
    
    return findpivotsearch(nums, numsSize-1, target);
}
