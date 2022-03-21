#include <stdio.h>
#include <stdlib.h>

void birlestir(int *ptr1 , int *ptr2 , int boyut) {

    int *x, f = 0, s = 0, i = 0;

    x = (int *) malloc(boyut * sizeof(int));

    for (i ; i < boyut; i++) {
        if (*(ptr1 + f) <= *(ptr2 + s)) {
            *(x + i) = *(ptr1 + f);
            f++;
        } else {
            *(x + i) = *(ptr2 + s);
            s++;
        }

        if (*(ptr1 + f) == NULL) {
            *(x + i) = *(ptr2 + s);
            break;
        }

        if (*(ptr2 + s) == NULL) {
            *(x + i) = *(ptr1 + f);
            break;
        }

    }

    for (int j = 0; j < boyut - 1; j++) {
        printf("%d\n", *(x + j));
    }
}

int main() {

    int A[6] = {1,5,11,13,14,21};
    int B[7] = {2,3,12,13,15,17,25};

    int *ptr1, *ptr2;

    ptr1 = A;
    ptr2 = B;

    birlestir(ptr1 , ptr2 , 13);

    return 0;
}



