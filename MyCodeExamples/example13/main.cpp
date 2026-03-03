int count_diagonal_paths(int m, int n) {
    if (n == 0 || m == 0) {
        return 0;
    }

    if (m == 1 || n == 1) {
        return 1;
    }
    if (m == 2 && n == 2) {
        return 3;
    }

    return count_diagonal_paths(m - 1, n) + count_diagonal_paths(m - 1, n - 1) + count_diagonal_paths(m, n - 1);
}
