#include <stdio.h>

int main()
{
    int poly1[6][2], poly2[6][2], max1, max2, Biggest;

    printf("input number of terms (less than 6) in poly1 and poly 2, respectively.");
    scanf("%d %d", &max1, &max2);

    printf("Enter the coefficient and exponent of each term in first polynomial");

    for (int i = 0; i < &max1; i++)
    {
        scanf("%d %d", &poly1[i][0], &poly1[i][1]);
    }

    printf("Enter the coefficient and exponent of each term in second polynomial");

    for (int i = 0; i < &max1; i++)
    {
        scanf("%d %d", &poly2[i][0], &poly2[i][1]);
    }

    printf("The Addition of two polynomials is ");

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (poly1[i][1] == poly2[j][1])
                printf(poly1[i][0] + poly2[i][0], poly2[i][1]);
        }
    }

    return 0;
}