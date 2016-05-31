int strStr(char* haystack, char* needle) {
    char *ptr1 = haystack, *ptr2 = needle;
    int i, j, size1 = 0, size2 = 0;
    while(*ptr1++) ++size1;
    while(*ptr2++) ++size2;
    for(i = 0; i <= size1 - size2; ++i) {
        for(j = 0; j < size2; ++j) {
            if(haystack[i+j] != needle[j])
                break;
        }
        if(j == size2) 
            return i;
    }
    return -1;
}
