#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int power;
    struct Term *next;
};

struct Term *createTerm(int coeff, int pow) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coefficient = coeff;
    newTerm->power = pow;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(struct Term **poly, int coeff, int pow) {
    struct Term *newTerm = createTerm(coeff, pow);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term *current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}


struct Term *multiplyPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;

    struct Term *current1 = poly1;
    while (current1 != NULL) {
        struct Term *current2 = poly2;
        while (current2 != NULL) {
            int coeff = current1->coefficient * current2->coefficient;
            int pow = current1->power + current2->power;

            struct Term *existingTerm = result;
            while (existingTerm != NULL) {
                if (existingTerm->power == pow) {
                    existingTerm->coefficient += coeff;
                    break;
                }
                existingTerm = existingTerm->next;
            }

            if (existingTerm == NULL) {
                insertTerm(&result, coeff, pow);
            }

            current2 = current2->next;
        }
        current1 = current1->next;
    }

    return result;
}


void displayPolynomial(struct Term *poly) {
    struct Term *current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->power);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;
    struct Term *result = NULL;

    int numTerms1, numTerms2;
    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &numTerms1);

    for (int i = 0; i < numTerms1; i++) {
        int coeff, pow;
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertTerm(&poly1, coeff, pow);
    }

    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &numTerms2);

    for (int i = 0; i < numTerms2; i++) {
        int coeff, pow;
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertTerm(&poly2, coeff, pow);
    }

    result = multiplyPolynomials(poly1, poly2);

    printf("Resultant polynomial after multiplication: ");
    displayPolynomial(result);

    return 0;
}
