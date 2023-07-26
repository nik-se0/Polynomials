// Copyright 2020 Semenova Veronika
// Коэффиценты Безу 
#include <stdio.h>
#include  "math.h"
#include "stdlib.h"
#include "BezoutCoefficients.h"
#include <iostream>
using namespace std;

void plus(int f[], int q[], int p[], int g)
{
    int i, j, e, r;
    e = vx(f, 2 * g + 1);
    r = vx(q, 2 * g + 1);
    for (i = std::min(e, r); i <= 2 * g; i++)
    {
        //printf("\n\n");
        for (j = min(e, r); j <= 2 * g; j++)
        {
            //printf("\n %d \n", abs(2 * g - i - j));
            //printf("FGHJK  %d + ", p[abs(2 * g - i - j)]);
            p[abs(2 * g - i - j)] = p[abs(2 * g - i - j)] + f[i] * q[j];
            //printf("%d * %d =  %d\n", f[i], q[j], p[abs(2 * g - i - j)]);
        } // printf("\n\n");
    }
}

void BezoutCoefficients()
{
    int g, h, i, k = -1, l = -1, o1 = 0, p, g1, h1, f = 0, m = 1, x = 0, j, s=0;
    int a[100] = { 0 };
    int b[100] = { 0 };
    int r[100] = { 0 };
    int q[100] = { 0 };
    int R[100][100] = { 0 };
    int Q[100][100] = { 0 };
    int F[100][100] = { 0 };
    int G[100][100] = { 0 };
    int f1[100] = { 0 };
    int f2[100] = { 0 };
    int q1[100] = { 0 };

    setlocale(LC_ALL, "Rus");
    printf("Введите степени многочленов\nВвод: ");
    scanf_s("%d%d", &g, &h);
    g = g + 1;
    h = h + 1;
    g1 = g;
    h1 = h;
    F[2 * g][0] = 1;
    G[2 * g][1] = 1;

    printf("Введите коэффициенты первого многочлена\nВвод: ");
    scan(a, g, 0);
    printf("Введите коэффициенты второго многочлена\nВвод: ");
    scan(b, g, g - h);
    printf("___________________________________________________________________________________________");

    while (m != 0) {


        printf("\nДелимое: ");
        print(a, g);
        printf("\nДелитель: ");
        print(b, g);
        printf("\n");

        m = 0;
        s = 0;
        mod(a, b, r, q, g, h, &s);

        for (i = 0; i < g; i++)
        {
            R[i][x] = r[i];
            if (i < s) { Q[2*g-i][x] = q[s-i-1]; }

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

        printf("\n___________________________________________________________________________________________");


    }
    x = x - 2;

    for (i = 2; i < x + 2+1; i++)
    {
        nool(f1, 2 * g + 1);
        nool(f2, 2 * g + 1);
        nool(q1, 2 * g + 1);

        for (j = 2 * g; j >= 0; j--)
        {
            F[j][i] = F[j][i - 2];
            f1[j] = F[j][i - 1];
            q1[j] = Q[j][i-2];
        }

        //printf("\n\nq1= ");
        //print(q1, 2 * g+1);

        plus(f1, q1, f2, g);

        //printf("\n\n2F(ij)= ");
        for (j = 2 * g; j >= 0; j--)
        {
            F[j][i] = F[j][i - 2] - f2[j]; //printf("%d ", F[j][i]);
        }
       //printf("\nDFGHJKL\n");
    }

    for (i = 2; i < x + 2+1 ; i++)
    {
        nool(f1, 2 * g + 1);
        nool(f2, 2 * g + 1);
        nool(q1, 2 * g + 1);

       // printf("\n\nG(1ij)= ");
        for (j = 2 * g; j >= 0; j--)
        {
            G[j][i] = G[j][i - 2]; //printf("%d ", G[j][i]);
            f1[j] = G[j][i - 1];
            q1[j] = Q[j][i - 2];
        }
        plus(f1, q1, f2, g);
        //printf("\n\nf1= ");
        //print(f1, 2 * g+1);
       // printf("\n\nq1= ");
       // print(q1, 2 * g+1);
       // printf("\n\n2G(ij)= ");

        for (j = 2 * g; j >= 0; j--)
        {
            G[j][i] = G[j][i - 2] - f2[j]; //printf("%d ", G[j][i]);
        }
        //printf("\nDFGHJKL\n");
    }




    for (i = 0; i <= 2 * g; i++)
    {

        f1[i] = F[i][x+2];

    }

    for (i = 0; i <= 2 * g; i++)
    {

        f2[i] = G[i][x+2];

    }

    printf("\nКоэффициенты Безу:\nf(x) = ");
    print(f1, 2 * g + 1);
    printf("\ng(x) = ");
    print(f2, 2 * g + 1);
    printf("\n___________________________________________________________________________________________");

    for (i = 0; i < g; i++)
    {

        r[i] = R[i][x];

    }
    printf("\nНОД: ");
    print(r, g);
    printf("\n");

    scanf_s("%d", &f);
}
