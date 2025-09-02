class TriDiagonal {
    int *A, n;
public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3*n - 2];
    }
    void set(int i, int j, int x) {
        if (i-j == 1) A[i-2] = x;
        else if (i-j == 0) A[n-1 + i-1] = x;
        else if (i-j == -1) A[2*n-1 + i-1] = x;
    }
    int get(int i, int j) {
        if (i-j == 1) return A[i-2];
        else if (i-j == 0) return A[n-1 + i-1];
        else if (i-j == -1) return A[2*n-1 + i-1];
        else return 0;
    }
};
