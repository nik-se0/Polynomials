#include "GCD2.h"

void GCD2()
{
    int g, h, i, k = -1, l = -1, o1 = 0, p, g1, h1, f = 0, m = 1, x = 0, j;
    int a[100] = { 0 };
    int b[100] = { 0 };
    int r[100] = { 0 };
    int q[100] = { 0 };
    int R[100][100] = { 0 };

    printf("������� ������� �����������\n����: ");
    scanf_s("%d%d", &g, &h);
    g = g + 1;
    h = h + 1;
    g1 = g;
    h1 = h;

    printf("������� ������������ ������� ����������\n����: ");
    scan(a, g, 0);
    printf("������� ������������ ������� ����������\n����: ");
    scan(b, g, g - h);
    printf("___________________________________________________________________________________________");

    while (m != 0) {
        printf("\n�������: ");
        print(a, g);
        printf("\n��������: ");
        print(b, g);
        printf("\n");

        m = 0;
        mod(a, b, r, q, g, h);

        for (i = 0; i < g; i++)
        {
            R[i][x] = r[i];

        }
        x = x + 1;
        //
        //q==



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
    for (i = 0; i < g; i++)
    {

        r[i] = R[i][x];

    }
    printf("\n���: ");
    print(r, g);
    printf("\n");

}
