#include <stdio.h>
#include  "math.h"
#include "Division.h"


void Division()
{
    int g, h, i, k = -1, l = -1, o1 = 0, p, g1, h1, f = 0, m = 1;

    int a[100] = { 0 };
    int b[100] = { 0 };
    int c[100] = { 0 };
    int d[100] = { 0 };
    int e[100] = { 0 };

    printf("Введите степени многочленов\nВвод: ");
    scanf_s("%d%d", &g, &h);
    g = g + 1;
    h = h + 1;
    g1 = g;
    h1 = h;

    printf("Введите коэффициенты первого многочлена\nВвод: ");
    scan(a, g, 0);
    printf("Введите коэффициенты второго многочлена\nВвод: ");
    scan(b, g, g - h);

    printf("___________________________________________________________________________________________");
    printf("\nДелимое: ");
    print(a, g);
    printf("\nДелитель: ");
    print(b, g);
    printf("\n\n");

    o1 = 0;
    while (g1 >= h1 + o1) {
        nool(c, g);
        nool(e, g);
        l = dl(a, b, o1 + 1);
        if (b[o1 + l] != 0) {
            k = a[o1] / b[o1 + l];
            for (i = l + o1; i <= g; i++)
            {
                c[i - l] = a[i - l] - k * b[i];
                e[i - l] = k * b[i];
            }
            d[f] = k; f = f + 1;

        }
        o1 = o1 + 1;

        swapM(a, c, g);




    }
    printf("___________________________________________________________________________________________");
    printf("\nОстаток: ");
    print(a, g);

    printf("\nЧастное от деления: ");
    print(d, f);
    printf("\n");

    scanf_s("%d", &f);
}
