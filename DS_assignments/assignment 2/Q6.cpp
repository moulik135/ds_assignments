#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

struct Sparse {
    int rows, cols, terms;
    Element *ele;
};

void display(Sparse s) {
    cout << "Row Col Val\n";
    for (int i = 0; i < s.terms; i++) {
        cout << s.ele[i].row << " "
             << s.ele[i].col << " "
             << s.ele[i].val << endl;
    }
}

Sparse transpose(Sparse s) {
    Sparse t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.terms = s.terms;
    t.ele = new Element[s.terms];

    int k = 0;
    for (int i = 0; i < s.cols; i++) {
        for (int j = 0; j < s.terms; j++) {
            if (s.ele[j].col == i) {
                t.ele[k].row = s.ele[j].col;
                t.ele[k].col = s.ele[j].row;
                t.ele[k].val = s.ele[j].val;
                k++;
            }
        }
    }
    return t;
}

Sparse add(Sparse s1, Sparse s2) {
    if (s1.rows != s2.rows || s1.cols != s2.cols) {
        cout << "Addition not possible\n";
        return {0,0,0,nullptr};
    }

    Sparse sum;
    sum.rows = s1.rows;
    sum.cols = s1.cols;
    sum.ele = new Element[s1.terms + s2.terms];

    int i = 0, j = 0, k = 0;
    while (i < s1.terms && j < s2.terms) {
        if (s1.ele[i].row < s2.ele[j].row ||
            (s1.ele[i].row == s2.ele[j].row && s1.ele[i].col < s2.ele[j].col)) {
            sum.ele[k++] = s1.ele[i++];
        }
        else if (s2.ele[j].row < s1.ele[i].row ||
                 (s2.ele[j].row == s1.ele[i].row && s2.ele[j].col < s1.ele[i].col)) {
            sum.ele[k++] = s2.ele[j++];
        }
        else {
            sum.ele[k] = s1.ele[i];
            sum.ele[k++].val = s1.ele[i++].val + s2.ele[j++].val;
        }
    }
    while (i < s1.terms) sum.ele[k++] = s1.ele[i++];
    while (j < s2.terms) sum.ele[k++] = s2.ele[j++];

    sum.terms = k;
    return sum;
}

Sparse multiply(Sparse s1, Sparse s2) {
    if (s1.cols != s2.rows) {
        cout << "Multiplication not possible\n";
        return {0,0,0,nullptr};
    }

    Sparse prod;
    prod.rows = s1.rows;
    prod.cols = s2.cols;
    prod.ele = new Element[s1.terms * s2.terms]; 
    int k = 0;

    for (int i = 0; i < s1.terms; i++) {
        for (int j = 0; j < s2.terms; j++) {
            if (s1.ele[i].col == s2.ele[j].row) {
                int r = s1.ele[i].row;
                int c = s2.ele[j].col;
                int v = s1.ele[i].val * s2.ele[j].val;

                int found = -1;
                for (int x = 0; x < k; x++) {
                    if (prod.ele[x].row == r && prod.ele[x].col == c) {
                        found = x;
                        break;
                    }
                }
                if (found != -1) prod.ele[found].val += v;
                else {
                    prod.ele[k].row = r;
                    prod.ele[k].col = c;
                    prod.ele[k].val = v;
                    k++;
                }
            }
        }
    }
    prod.terms = k;
    return prod;
}

int main() {
    Sparse s1;
    s1.rows = 3; s1.cols = 3; s1.terms = 3;
    s1.ele = new Element[s1.terms]{{0,0,5},{1,1,8},{2,2,9}};

    Sparse s2;
    s2.rows = 3; s2.cols = 3; s2.terms = 3;
    s2.ele = new Element[s2.terms]{{0,1,7},{1,1,3},{2,0,6}};

    cout << "Matrix 1 (Triplet):\n"; display(s1);
    cout << "Matrix 2 (Triplet):\n"; display(s2);

    Sparse t = transpose(s1);
    cout << "\nTranspose of Matrix 1:\n"; display(t);

    Sparse sum = add(s1, s2);
    cout << "\nSum of Matrix 1 and 2:\n"; display(sum);

    Sparse prod = multiply(s1, s2);
    cout << "\nProduct of Matrix 1 and 2:\n"; display(prod);

    return 0;
}
