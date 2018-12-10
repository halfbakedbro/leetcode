/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    
    int *arr = (int*)malloc(sizeof(int) * matrixRowSize * matrixColSize);
    
    int sr = 0;
    int sc = 0;
    int er = matrixRowSize-1;
    int ec = matrixColSize-1;
    int i;
    int j = 0;
    
    int m = matrixRowSize * matrixColSize;
    
    do{
        
        {
            
            for(i = sc ; i <= ec ; i++){
                arr[j] = matrix[sr][i];
                j++;
                m--;
            }
            sr++;            
        }
        
        {
            
            for(i = sr; i <= er; i++){
                arr[j] = matrix[i][ec];
                m--;
                j++;
            }
            ec--;
        }
        
        if(sr < er+1){
           
            
            for(i = ec; i >= sc; i--){
                arr[j] = matrix[er][i];
                m--;
                j++;
            }
            er--;
        }
        
        if(sc < ec+1){
            
            for(i = er; i>=sr ; i--){
                arr[j] = matrix[i][sc];
                m--;
                j++;
            }
            sc++;
        }
            
    }while(m != 0);
        
    return arr;
}
