/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.
*/

int removeElement(int* nums, int numsSize, int val) {
    
    if(numsSize == 0){
        return 0;
    }else if(numsSize == 1){
        if(nums[0] == val)
            return 0;
        else
            return 1;
    }
    
    int k = 0;
    
    for(int i = 0 ; i < numsSize ; i++){
        if(nums[i] != val){
            nums[k] = nums[i];
            ++k;
        }
    }
    
    
    return k;
}
