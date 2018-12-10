/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/

#include <string.h>
typedef struct {
    char* arr;
    int size;
    int head;
} CharStack;

/** initialize your data structure here. */
CharStack* CharStackCreate(int maxSize) {
    CharStack *ms = (CharStack*)malloc(sizeof(CharStack));
    ms->size = maxSize;
    ms->head = -1;
    ms->arr = (char*)malloc((sizeof(char) * maxSize) + 1);
    
    return ms;
}

void Push(CharStack* obj, char x) {
    if(obj->head == -1){
        
        obj->head = 0;
        obj->arr[obj->head] = x;
        
    }else if(obj->head < obj->size-1){
        obj->head++;
        obj->arr[obj->head] = x;
    }
}

char Pop(CharStack* obj) {
    if(obj->head != -1){
        char s = obj->arr[obj->head];    
        obj->head--;
        
        return s;
    }else{
        return 0;
    }
}

void StackFree(CharStack* obj) {
    if(obj){
        if(obj->arr)
            free(obj->arr);       
        free(obj);
    }
}

bool isEmpty(CharStack* obj){
    
    if(obj->head == -1)
        return true;
    else
        return false;
}

bool isValid(char* s) {
    char *temp = s;
    int length = strlen(s);
    
    if(length == 0)
        return true;
    
    CharStack *cs = CharStackCreate(length + 1);
    
    for(int i = 0; i < length; i++){
        
        if(temp[i] == '(' || temp[i] == '[' || temp[i] == '{'){
            Push(cs, temp[i]);         
        }
        
        if(temp[i] == ')' || temp[i] == ']' || temp[i] == '}'){
            
            if(isEmpty(cs)) return false;
            
            char check = Pop(cs);
            
            if((check == '{' && temp[i] == '}') || (check == '[' && temp[i] == ']') || (check == '(' && temp[i] == ')')){
                continue;
            }
            else{
                return false;
            }
        }
        
    }
    
    if(isEmpty(cs)){
        StackFree(cs);
        return true;
    }
    else{
        StackFree(cs);
        return false;
    }
        
    
}
