

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

int** initializeMatrix(int n) {
    int** temp = new int*[n];
    for (int i = 0; i < n; i++)
        temp[i] = new int[n];
    return temp;
}

void setToZero(int** M, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            M[i][j] = 0;
}

void input(int** M, int r, int c) {
    cout << "Enter matrix: " << endl;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> M[i][j];
    cout << endl;
}
int** initializeMatrix(int r, int c) {
    int** temp = new int*[r];
    for (int i = 0; i < r; i++)
        temp[i] = new int[c];
    return temp;
}
int** multiply(int** M1, int** M2, int r1, int c1, int c2) {
    int** temp = initializeMatrix(r1, c2);
    setToZero(temp, r1, c2);
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                temp[i][j] += M1[i][k] * M2[k][j];
    return temp;
}


int** add(int** M1, int** M2, int n) {
    int** temp = initializeMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] + M2[i][j];
    return temp;
}

int** subtract(int** M1, int** M2, int n) {
    int** temp = initializeMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] - M2[i][j];
    return temp;
}
int** divideAndConquer(int** A, int** B, int n) {
    if (n == 1) {
        int** C = initializeMatrix(1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int** C = initializeMatrix(n);
    int k = n / 2;

    int** A11 = initializeMatrix(k);
    int** A12 = initializeMatrix(k);
    int** A21 = initializeMatrix(k);
    int** A22 = initializeMatrix(k);
    int** B11 = initializeMatrix(k);
    int** B12 = initializeMatrix(k);
    int** B21 = initializeMatrix(k);
    int** B22 = initializeMatrix(k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k + j];
            A21[i][j] = A[k + i][j];
            A22[i][j] = A[k + i][k + j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k + j];
            B21[i][j] = B[k + i][j];
            B22[i][j] = B[k + i][k + j];
        }

    int** C11 = add(divideAndConquer(A11, B11, k), divideAndConquer(A12, B21, k), k);
    int** C12 = add(divideAndConquer(A11, B12, k), divideAndConquer(A12, B22, k), k);
    int** C21 = add(divideAndConquer(A21, B11, k), divideAndConquer(A22, B21, k), k);
    int** C22 = add(divideAndConquer(A21, B12, k), divideAndConquer(A22, B22, k), k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[k + i][j] = C21[i][j];
            C[k + i][k + j] = C22[i][j];
        }

    for (int i = 0; i < k; i++) {
        delete[] A11[i];
        delete[] A12[i];
        delete[] A21[i];
        delete[] A22[i];
        delete[] B11[i];
        delete[] B12[i];
        delete[] B21[i];
        delete[] B22[i];
        delete[] C11[i];
        delete[] C12[i];
        delete[] C21[i];
        delete[] C22[i];
    }

    delete[] A11;
    delete[] A12;
    delete[] A21;
    delete[] A22;
    delete[] B11;
    delete[] B12;
    delete[] B21;
    delete[] B22;

    delete[] C11;
    delete[] C12;
    delete[] C21;
    delete[] C22;

    return C;
}

int** strassenMultiply(int** A, int** B, int n) {
    if (n == 1) {
        int** C = initializeMatrix(1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int** C = initializeMatrix(n);
    int k = n / 2;

    int** A11 = initializeMatrix(k);
    int** A12 = initializeMatrix(k);
    int** A21 = initializeMatrix(k);
    int** A22 = initializeMatrix(k);
    int** B11 = initializeMatrix(k);
    int** B12 = initializeMatrix(k);
    int** B21 = initializeMatrix(k);
    int** B22 = initializeMatrix(k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k + j];
            A21[i][j] = A[k + i][j];
            A22[i][j] = A[k + i][k + j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k + j];
            B21[i][j] = B[k + i][j];
            B22[i][j] = B[k + i][k + j];
        }

    int** P1 = strassenMultiply(A11, subtract(B12, B22, k), k);
    int** P2 = strassenMultiply(add(A11, A12, k), B22, k);
    int** P3 = strassenMultiply(add(A21, A22, k), B11, k);
    int** P4 = strassenMultiply(A22, subtract(B21, B11, k), k);
    int** P5 = strassenMultiply(add(A11, A22, k), add(B11, B22, k), k);
    int** P6 = strassenMultiply(subtract(A12, A22, k), add(B21, B22, k), k);
    int** P7 = strassenMultiply(subtract(A11, A21, k), add(B11, B12, k), k);

    int** C11 = subtract(add(add(P5, P4, k), P6, k), P2, k);
    int** C12 = add(P1, P2, k);
    int** C21 = add(P3, P4, k);
    int** C22 = subtract(subtract(add(P5, P1, k), P3, k), P7, k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[k + i][j] = C21[i][j];
            C[k + i][k + j] = C22[i][j];
        }

    for (int i = 0; i < k; i++) {
        delete[] A11[i];
        delete[] A12[i];
        delete[] A21[i];
        delete[] A22[i];
        delete[] B11[i];
        delete[] B12[i];
        delete[] B21[i];
        delete[] B22[i];
        delete[] P1[i];
        delete[] P2[i];
        delete[] P3[i];
        delete[] P4[i];
        delete[] P5[i];
        delete[] P6[i];
        delete[] P7[i];
        delete[] C11[i];
        delete[] C12[i];
        delete[] C21[i];
        delete[] C22[i];
    }

    delete[] A11;
    delete[] A12;
    delete[] A21;
    delete[] A22;
    delete[] B11;
    delete[] B12;
    delete[] B21;
    delete[] B22;
    delete[] P1;
    delete[] P2;
    delete[] P3;
    delete[] P4;
    delete[] P5;
    delete[] P6;
    delete[] P7;
    delete[] C11;
    delete[] C12;
    delete[] C21;
    delete[] C22;

    return C;
}


void printMatrix(int** M, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int highestPowerof2(int n) {
    int p = (int)ceil(log2(n));
    // cout << p << endl;
    return (int)pow(2, p);
}

int main() {
    clock_t start, end;
    int r1, c1 = 0, r2 = 1, c2;
    int **A, **B, **C;

    while (c1 != r2) {
        cout << "Column of Matrix A needs to be equal to row of matrix B" << endl;
        cout << "Enter the row of matrix A: ";
        cin >> r1;
        cout << "Enter the column of matrix A: ";
        cin >> c1;
        cout << "Enter the row of matrix B: ";
        cin >> r2;
        cout << "Enter the column of matrix B: ";
        cin >> c2;
    }

    // Converting dimension to 2^n because Strassen's Matrix Multiplication Algorithm works only on square
    // matrices whose dimension is a power of 2.
    int n = highestPowerof2(max(r1, max(c1, c2)));
    A = initializeMatrix(n);
    B = initializeMatrix(n);
    setToZero(A, n, n);
    setToZero(B, n, n);

    input(A, r1, c1);

    // printMatrix(A, r1, c1);

    input(B, r2, c2);


    start = clock();
    C = multiply(A, B, n, n, n);
    end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    printMatrix(C, n, n);
    cout << "Normal Multipliction of TC O(n^3): " << time_taken << " sec" << endl;


    int** D = initializeMatrix(n);
    setToZero(D, n , n);
    start = clock();
    D = strassenMultiply(A, B, n);
    end = clock();
    time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "divideAndConquer O(n^3): " << time_taken << " sec" << endl;

    int** E = initializeMatrix(n);
    setToZero(E, n , n);
    start = clock();
    E = strassenMultiply(A, B, n);
    end = clock();
    time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "strassenMultiply of TC O(n^2.8): " << time_taken << " sec" << endl;


    for (int i = 0; i < r1; i++)
        delete[] A[i];
    delete[] A;

    for (int i = 0; i < r2; i++)
        delete[] B[i];
    delete[] B;

    for (int i = 0; i < r1; i++)
        delete[] C[i];
    delete[] C;

    for (int i = 0; i < r1; i++)
        delete[] D[i];
    delete[] D;

    for (int i = 0; i < r1; i++)
        delete[] E[i];
    delete[] E;

    return 0;
}