int compareVersion(char* version1, char* version2) {
    char *ptr1 = version1, *ptr2 = version2;
    int val1 = 0, val2 = 0;
    
    while(*ptr1 != '\0' || *ptr2 != '\0') {
        // 跳过小数点
        if(*ptr1 == '.')
            ++ptr1;
        if(*ptr2 == '.')
            ++ptr2;
            
        // 分别计算两个版本对应的子版本号
        while(*ptr1 != '\0' && *ptr1 != '.') {
            val1 *= 10;
            val1 += *ptr1 - '0';
            ++ptr1;
        }
        while(*ptr2 != '\0' && *ptr2 != '.') {
            val2 *= 10;
            val2 += *ptr2 - '0';
            ++ptr2;
        }
        
        // 比较版本号大小
        if(val1 > val2) 
            return 1;
        else if(val1 < val2)
            return -1;
            
        // 归零
        val1 = val2 = 0;
    }
    return 0;
}
