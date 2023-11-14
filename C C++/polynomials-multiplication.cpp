#include <iostream>

using namespace std;

struct Term {
    int coefficient;
    int exponent;
};

void multiplyPolynomials(Term poly1[], int m, Term poly2[], int n, Term result[]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int new_coefficient = poly1[i].coefficient * poly2[j].coefficient;
            int new_exponent = poly1[i].exponent + poly2[j].exponent;
            result[new_exponent].coefficient += new_coefficient;
            result[new_exponent].exponent = new_exponent;
        }
    }
}

int main() {
    int m, n;
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> m;

    Term poly1[m];
    cout << "Enter the terms of the first polynomial (coefficient exponent):\n";
    for (int i = 0; i < m; i++) {
        cin >> poly1[i].coefficient >> poly1[i].exponent;
    }

    cout << "Enter the number of terms in the second polynomial: ";
    cin >> n;

    Term poly2[n];
    cout << "Enter the terms of the second polynomial (coefficient exponent):\n";
    for (int i = 0; i < n; i++) {
        cin >> poly2[i].coefficient >> poly2[i].exponent;
    }

    int maxDegree = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            maxDegree = max(maxDegree, poly1[i].exponent + poly2[j].exponent);
        }
    }

    Term result[maxDegree + 1];
    for (int i = 0; i <= maxDegree; i++) {
        result[i].coefficient = 0;
        result[i].exponent = i;
    }

    multiplyPolynomials(poly1, m, poly2, n, result);

    cout << "Resultant Polynomial (coefficient exponent):\n";
    for (int i = 0; i <= maxDegree; i++) {
        if (result[i].coefficient != 0) {
            cout << result[i].coefficient << " " << result[i].exponent << endl;
        }
    }

    return 0;
}

