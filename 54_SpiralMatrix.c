/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int *res = (int *)malloc(matrixRowSize * matrixColSize * sizeof(int));
    if(NULL == res) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    int k = 0, sz = matrixRowSize * matrixColSize;
    int up = 0, down = matrixRowSize - 1, left = 0, right = matrixColSize - 1;
    while(1) {
        int i = up, j = left;
        for(j = left; j <= right; ++j)  // left --> right
            res[k++] = matrix[i][j];
        if(k >= sz) break;
        ++up, --j;
        
        for(i = up; i <= down; ++i)  // up --> down
            res[k++] = matrix[i][j];
        if(k >= sz) break;
        --right, --i;
        
        for(j = right; j >= left; --j)  // right --> left
            res[k++] = matrix[i][j];
        if(k >= sz) break;
        --down, ++j;
        
        for(i = down; i >= up; --i)  // down --> up
            res[k++] = matrix[i][j];
        if(k >= sz) break;
        ++left, ++i;
    }
    return res;
}
