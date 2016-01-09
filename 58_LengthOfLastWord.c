int lengthOfLastWord(char* s) {
    int len = strlen(s), len_res = 0;
    if(0 == len) return 0;
    while(s[len-1] == ' ') --len;
    for(--len; len >= 0 && s[len] != ' '; --len)
        ++len_res;
    return len_res;
}
