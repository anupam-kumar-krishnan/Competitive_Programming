#include <stdio.h>

void printRightHalfPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printLeftHalfPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf("  ");
        }
        for (int k = 1; k <= i; k++) {
            if (k == 1 || k == i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printFullPyramid(int n) {
    for (int i = 1, k = 0; i <= n; ++i, k = 0) {
        for (int space = 1; space <= n - i; ++space) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            if (k == 0 || k == 2 * i - 2 || i == n) {
                printf("* ");
            } else {
                printf("  ");
            }
            ++k;
        }
        printf("\n");
    }
}

void printInvertedRightHalfPyramid(int n) {
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int binomialCoefficient(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void printPascalsTriangle(int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", binomialCoefficient(i, j));
        }
        printf("\n");
    }
}void printInvertedLeftHalfPyramid(int n) {
    for (int i = n; i >= 1; --i) {
        for (int j = n; j > i; j--) {
            printf("  ");
        }
        for (int k = 1; k <= i; k++) {
            if (k == 1 || k == i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printInvertedFullPyramid(int n) {
    for (int i = n, k = 0; i >= 1; --i, k = 0) {
        for (int space = 0; space < n - i; ++space) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            if (k == 0 || k == 2 * i - 2 || i == n) {
                printf("* ");
            } else {
                printf("  ");
            }
            ++k;
        }
        printf("\n");
    }
}

void printRhombus(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j > 0; j--) {
            printf(" ");
        }
        for (int k = 1; k <= n; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printDiamond(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j > 0; j--) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            if (k == 1 || k == 2 * i - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            if (k == 1 || k == 2 * i - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printHourglass(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }

    for (int i = 2; i <= n; i++) {
        for (int j = n - i; j > 0; j--) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printHollowSquare(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printHollowFullPyramid(int n) {
    for (int i = 1, k = 0; i <= n; ++i, k = 0) {
        for (int space = 1; space <= n - i; ++space) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            if (k == 0 || k == 2 * i - 2 || i == n) {
                printf("* ");
            } else {
                printf("  ");
            }
            ++k;
        }
        printf("\n");
    }
}

void printHollowInvertedFullPyramid(int n) {
    for (int i = n, k = 0; i >= 1; --i, k = 0) {
        for (int space = 0; space < n - i; ++space) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            if (k == 0 || k == 2 * i - 2 || i == n) {
                printf("* ");
            } else {
                printf("  ");
            }
            ++k;
        }
        printf("\n");
    }
}

void printHollowDiamond(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j > 0; j--) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            if (k == 1 || k == 2 * i - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            if (k == 1 || k == 2 * i - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printHollowHourglass(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            if (k == 1 || k == 2 * i - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (int i = 2; i <= n; i++) {
        for (int j = n - i; j > 0; j--) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            if (k == 1 || k == 2 * i - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}


int main() {
    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Right Half Pyramid:\n");
    printRightHalfPyramid(rows);

    printf("\nLeft Half Pyramid:\n");
    printLeftHalfPyramid(rows);

    printf("\nFull Pyramid:\n");
    printFullPyramid(rows);

    printf("\nInverted Right Half Pyramid:\n");
    printInvertedRightHalfPyramid(rows);

    printf("\nInverted Left Half Pyramid:\n");
    printInvertedLeftHalfPyramid(rows);

    printf("\nInverted Full Pyramid:\n");
    printInvertedFullPyramid(rows);

    printf("\nRhombus:\n");
    printRhombus(rows);

    printf("\nDiamond:\n");
    printDiamond(rows);

    printf("\nHourglass:\n");
    printHourglass(rows);

    printf("\nHollow Square:\n");
    printHollowSquare(rows);

    printf("\nHollow Full Pyramid:\n");
    printHollowFullPyramid(rows);

    printf("\nHollow Inverted Full Pyramid:\n");
    printHollowInvertedFullPyramid(rows);

    printf("\nHollow Diamond:\n");
    printHollowDiamond(rows);

    printf("\nHollow Hourglass:\n");
    printHollowHourglass(rows);

    printf("Pascal's Triangle:\n");
    printPascalsTriangle(rows);
    
    return 0;
}
