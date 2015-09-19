int mySqrt(int x)
{
    long long result = x;
    
	if(x < 2)
	    return x;
    while(result * result > x)
        result = (result + x / result) >> 1;
    
    return result;
}
