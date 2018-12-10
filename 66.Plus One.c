/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isEveryNine(int *arr, int n){
    bool yes = true;
    for(int i = 0; i < n; i++){
        if(arr[i] == 9)
            continue;
        else{
            yes = false;
            break;
        }
    }
    
    return yes;
}

int countNine(int *arr, int n){
    int count = 0;
    
    for(int i = n-1; i>= 0 ; i--){
        if(arr[i] == 9)
            count++;
        else
            break;
    }
    
    return count;
}
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    int* arr;
    *returnSize = digitsSize;
    
    
    if(isEveryNine(digits, digitsSize)){
        arr = (int*)malloc(sizeof(int) * digitsSize + 1);
        arr[0] = 1;
        for(int i = 1 ; i <= (digitsSize + 1) ; i++)
            arr[i] = 0;
        
        *returnSize += 1;
        
        return arr;
    }
    
    arr = (int*)malloc(sizeof(int) * digitsSize);
    int count = countNine(digits, digitsSize);
    
    
    if(count == 0){
        arr[digitsSize - 1] = digits[digitsSize - 1] + 1;
        for(int i = 0 ; i <= digitsSize - 2; i++)
            arr[i] = digits[i];
    }else{
        printf("count:%d\n", count);
        int n = digitsSize - 1 - count;
        arr[n] = digits[n] + 1;
        printf("arr[n]:%d , n = %d\n", arr[n], n);
        for(int i = n + 1 ; i < digitsSize ; i++)
            arr[i] = 0;
        for(int j = 0 ; j < n; j++)
            arr[j] = digits[j];
    }
    
    return arr;
}
