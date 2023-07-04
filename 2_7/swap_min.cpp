void swap_min(int *m[], unsigned rows, unsigned cols) {
    int min_value = m[0][0], min_row = 0;
    int *tmp = new int[cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m[i][j] < min_value) {
                min_value = m[i][j], min_row = i;
            }
        }
    }

    tmp = m[0];
    m[0] = m[min_row];
    m[min_row] = tmp;
}