bool isHappy(int n)
{
    int temp_n, temp_sum;
    
    if(n <= 0)
        return false;
    while(1) {
        int temp_mod;
        temp_n = n;
        temp_sum = 0;
        while(temp_n > 0) {
            temp_mod = temp_n % 10;
            temp_sum += temp_mod * temp_mod;
            temp_n /= 10;
        }
        if(temp_sum == 1)   // 出坑
            return true;
        else if(temp_sum == 4)    // 入坑
            return false;
        else
            n = temp_sum;    // 下一次循环
    }
}
