/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int **res = (int**)malloc(n * sizeof(int *));
    if(NULL == res) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < n; ++i) {
        res[i] = (int*)malloc(n * sizeof(int));
        if(NULL == res[i]) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }
    int k = n%2 ? n/2+1 : n/2;  // the number of loops
    int left_up = 0, right_down = n - 1;
    int num = 0;
    for(; k > 0; --k, ++left_up, --right_down) {
        for(int i = left_up, j = left_up; j <= right_down; ++j)  // left --> right
            res[i][j] = ++num;
        for(int i = left_up + 1, j = right_down; i <= right_down; ++i)  // up --> down
            res[i][j] = ++num;
        for(int i = right_down, j = right_down - 1; j >= left_up; --j)  // right --> left
            res[i][j] = ++num;
        for(int i = right_down - 1, j = left_up; i >= left_up + 1; --i)  // down --> up
            res[i][j] = ++num;
    }
    return res;
}
