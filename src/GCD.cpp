#include "GCD.h"

void swapM(int a[], int c[], int h) {
    int i = 0;
    for (i = 0; i < h; i++)
    {
        a[i] = c[i];
    }
}
void swap(int* a, int* b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

//Функции ввода/вывода многочленов
void scan(int b[], int a, int o) {
    int i;
    for (i = o; i < a; i++)
    {
        scanf_s("%d", &b[i]);
    }
}
void print(int b[], int n) {
    int i, z = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (b[i] != 0) {
            if ((z != 0) && (b[i] > 0)) { printf("+"); }
            if (b[i] == -1) { printf("-"); }
            if (abs(b[i]) == 1) { printf("x"); z = 1; }
            else { printf("%dx", b[i]); z = 1; }
        }

        if ((b[i] != 0) && (i < n - 2)) { printf("^%d", n - i - 1); }

    }
    if (b[n - 1] > 0) { printf("+"); }
    if (b[n - 1] != 0) { printf("%d", b[n - 1]); }
}

//Функции для работы с многочленами
int dl(int a[], int b[], int g)
{
    int i = 0, j = 0;
    while ((a[i] == 0) && (i < g)) { i++; }
    while ((b[j] == 0) && (i < g)) { j++; }

    return j - i;
}
int vx(int a[], int g)
{
    int i = 0, j = 0;
    while ((a[i] == 0) && (i < g)) { i++; }

    return i;
}
void mod(int a[], int b[], int c[], int d[], int g, int h)
{
    int i, k = -1, l = -1, o1 = 0, p = 0, g1 = 0, h1 = 0, f = 0;
    g1 = g;
    h1 = h;

    o1 = vx(a, g);
    while (g1 >= h1 + o1) {
        // printf("ASDFG ")
        for (i = 0; i < g1; i++)
        {
            c[i] = 0;
        }
        l = dl(a, b, o1 + 1);
        if (b[o1 + l] != 0) {
            k = a[o1] / b[o1 + l];
            for (i = l + o1; i <= g; i++)
            {
                c[i - l] = a[i - l] - k * b[i];

            }
            d[f] = k; f = f + 1;
            //printf("\nОстаток %d: ", o1);
            //print(c, g);
        }
        o1 = o1 + 1;

        swapM(a, c, g);




    }
    //printf("\nОстаток: ");
    //print(a, g);
    //printf("\nЧастное от деления: ");
    //print(d, f);

}
void nool(int a[], int g)
{
    int i;
    for (i = 0; i < g; i++)
    {
        a[i] = 0;
    }
}

//Наибольший общий делитель
void GCD()
{
    int g=0, h=0, i=0, k = -1, l = -1, o1 = 0, p=0, g1=0, h1=0, f = 0, m = 1, x = 0, j=0;
    int a[100] = { 0 };
    int b[100] = { 0 };
    int r[100] = { 0 };
    int q[100] = { 0 };
    int R[100][100] = { 0 };

    printf("\tВведите степени многочленов, сначала вводится многочлен с наибольшей степенью\n\tВвод: ");
    scanf_s("%d%d", &g, &h);
    g = g + 1;
    h = h + 1;
    g1 = g;
    h1 = h;

    printf("\n\tВведите коэффициенты первого многочлена\n\tВвод: ");
    scan(a, g, 0);
    
    printf("\n\tВведите коэффициенты второго многочлена\n\tВвод: ");
    scan(b, g, g - h);


    printf("\n\n\t\tНОД для многочленов ");
    print(a, g);   
    printf(" и ");
    print(b, h);
    printf(":\t\t");

    while (m != 0) {
        m = 0;
        mod(a, b, r, q, g, h);

        for (i = 0; i < g; i++)
        {
            R[i][x] = r[i];

        }
        x = x + 1;

        for (i = 0; i < g; i++)
        {
            m = m + abs(r[i]);
        }

        swapM(a, b, g);
        swapM(b, r, g);
        nool(r, g);
        nool(q, g);
        h = g - vx(b, g);

    }
    x = x - 2;
    for (i = 0; i < g; i++)
    {

        r[i] = R[i][x];

    }
   
    print(r, g);
    printf("\n");

}




