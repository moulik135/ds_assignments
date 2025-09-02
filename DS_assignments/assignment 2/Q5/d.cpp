class UpperTriangular {
    int *A, n;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i <= j) A[n*(i-1) - (i-1)*(i-2)/2 + (j-i)] = x;
    }
    int get(int i, int j) {
        if (i <= j) return A[n*(i-1) - (i-1)*(i-2)/2 + (j-i)];
        return 0;
    }
};
