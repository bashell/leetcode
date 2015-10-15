/*
** 谁先给对面剩下4k个石子，谁就能赢。(k = 0, 1, 2, 3, ...)
** 设A抓时有4k个石子，因为每次最多抓3个石子, 所以A抓完后，B总能使剩下的石子保持4(k-1)个
*/
bool canWinNim(int n) {
    if(n % 4 == 0)
        return false;
    else
        return true;
}
