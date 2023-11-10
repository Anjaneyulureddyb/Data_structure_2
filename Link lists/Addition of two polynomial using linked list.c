#include<stdio.h>
#include<stdlib.h>
typedef struct Term 
{
    int coefficient;
    int power;
    struct Term* next;
}Term;

Term* createTerm(int coeff, int pow) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coeff;
    newTerm->power = pow;
    newTerm->next = NULL;
    return newTerm;
}

void insertEnd(Term** head, int coeff, int pow) {
    Term* newTerm = createTerm(coeff, pow);

    if (*head == NULL) {
        *head = newTerm;
        return;
    }

    Term* ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newTerm;
}

Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    Term* ptr = NULL;

    while (poly1 && poly2) {
        if (poly1->power > poly2->power) {
            insertEnd(&result, poly1->coefficient, poly1->power);
            poly1 = poly1->next;
        }
        else if (poly1->power < poly2->power) {
            insertEnd(&result, poly2->coefficient, poly2->power);
            poly2 = poly2->next;
        }
        else {
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (sumCoeff != 0) {
                insertEnd(&result, sumCoeff, poly1->power);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        insertEnd(&result, poly1->coefficient, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2) {
        insertEnd(&result, poly2->coefficient, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

void displayPolynomial(Term* poly) {
    Term* ptr = poly;

    while (ptr != NULL) {
        printf(" %dX^%d ", ptr->coefficient, ptr->power);
        if (ptr->next != NULL && ptr->next->coefficient >= 0) {
            printf("+");
        }
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int coeff, pow, n;
    Term* polynomial1 = NULL;
    Term* polynomial2 = NULL;

    while (1) {
        printf("\nEnter 1 to input polynomials and 0 to exit:");
        scanf("%d", &n);

        if (n == 1) {
            printf("Enter the first polynomial (coefficient, power, enter -1 -1 to stop):\n");
            while (1) {
                printf("\nEnter the coefficient:");
                scanf("%d", &coeff);
                printf("Enter the power:");
                scanf("%d", &pow);
                if (coeff == -1 && pow == -1) {
                    break;
                }
                insertEnd(&polynomial1, coeff, pow);
            }
            printf("\nThis is the first polynomial:\n");
            displayPolynomial(polynomial1);

            printf("\nEnter the second polynomial (coefficient, power, enter -1 -1 to stop):\n");
            while (1) {
                printf("\nEnter the coefficient:");
                scanf("%d", &coeff);
                printf("Enter the power:");
                scanf("%d", &pow);
                if (coeff == -1 && pow == -1) {
                    break;
                }
                insertEnd(&polynomial2, coeff, pow);
            }
            printf("\nThis is the second polynomial:\n");
            displayPolynomial(polynomial2);

            Term* sum = addPolynomials(polynomial1, polynomial2);

            printf("\nThis is the first polynomial: ");
            displayPolynomial(polynomial1);
            printf("This is the second polynomial: ");
            displayPolynomial(polynomial2);
            printf("Sum of the two polynomials: ");
            displayPolynomial(sum);
        }
        else {
            break;
        }
    }
    return 0;
}
