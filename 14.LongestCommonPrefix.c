/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    
    int k = 0;
    char *arr = NULL;
    
    if(strcmp(strs[0], "\0") == 0){
        arr = (char*)malloc(sizeof(char) * 1);
        arr[0] = '\0';
        return arr;
    }else if(strsSize == 1){
        int len = strlen(strs[0]);
        arr = (char*)malloc(sizeof(char) * len);
        strcpy(arr, strs[0]);
        return arr;
    }
    /*
    for(int i = 0 ; i < strsSize ; i++){
        printf("str : %c\n", *(strs[i] + k));
        k++;
    }
    */
    int i = 0;
    int j = INT_MAX;
    bool match = false;
    while(--strsSize){
        k = 0;
        i = 0;
        while((*(strs[strsSize] + k) != '\0') && (*(strs[strsSize-1] + k) != '\0')){
            if(*(strs[strsSize] + k) == *(strs[strsSize-1] + k)){
                i++;
                k++;
                match = true;
            }else{
                break;
            }
        }
        
        if(i>0){
            j = j < i ? j : i;
           // match = false;
        }else{
            j = 0;
            match = false;
            break;
        }
    }
    
    if(j && match){
        arr = (char*)malloc(sizeof(char) * j);
        arr[j] = '\0';
        for(int l = 0 ; l < j; l++){
            arr[l] = *(strs[0] + l);
        }       
    }
    else{
        arr = (char*)malloc(sizeof(char));
        arr[0] = '\0';
    }
    
    return arr;
}
