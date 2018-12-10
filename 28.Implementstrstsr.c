/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/


int computeZarr(char *str, int n, int len){
    int L, R, k;
    int Z[n];
    
    L = R = 0;
    for (int i = 1; i < n; ++i) 
    { 
        if (i > R) 
        { 
            L = R = i; 
            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else
        { 
            k = i-L; 
            
            if (Z[k] < R-i+1) 
                Z[i] = Z[k]; 
 
            else
            { 
                
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
        } 
    } 
    
    for(int i = 1 ; i < n ; i++){
        if(Z[i] == len){
            return (i - len - 1);
        }
    }
    
    return -1;
}

int strStr(char* haystack, char* needle) {
    
    if(needle == NULL)
        return 0;
    
    if(*needle == '\0')
        return 0;
    
    int lh = strlen(haystack);
    int ln = strlen(needle);
    int lr = lh+ln;
    char res[lr];
    
    strcpy(res, needle);
    strcat(res, "#");
    strcat(res, haystack);
    
    int i = computeZarr(res, lr+1, ln);
    
    return i;
}
