int sum(int *arr, int start, int end){
  int sum = 0;
  while(start <= end){
    sum += arr[start];
    start++;
  }
  return sum;
}

int pivotIndex(int* nums, int numsSize) {
  int sums = 0;
  if (nums == NULL)
    return 0;
    
  sums = sum(nums, 0 , numsSize-1);
  
  int leftsum = 0;
  
  for(int i = 0 ; i < numsSize; i++){
    sums -= nums[i];
    
    if(leftsum == sums)
      return i;
    else
      leftsum += nums[i];
  
return -1;
}
