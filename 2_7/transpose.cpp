int **transpose(const int *const *m, unsigned rows, unsigned cols) {
    int **mT = new int*[cols];
    unsigned i = 0, j = 0;

    for (i = 0; i < cols; i++) {
        mT[i] = new int[rows];
    }

    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            mT[i][j] = m[j][i];
        }
    }

    return mT;
}