// Copyright 2020 Semenova Veronika
#include <stdio.h>
#include "locale.h"
#include <stdlib.h>
#include "GCD.h"
#include "GCD2.h"
#include "Division.h"
#include "Division2.h"
#include "BezoutCoefficients.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    int entry = -1; char c;
    do {
        system("cls");
        printf("\t���������� ��� ������ � ������������\n\n\t1.������� �����������\n\t2.������� ����������� ��������\n\t3.���������� ����� ��������\n\t4.���������� ����� �������� ��������\n\t5.����������� ����\n\t0.�����\n\t����: ");
        scanf_s("%d",&entry);
        switch(entry)
        {
        case 1:
            system("cls");
            printf("\t.������� �����������\n\n");
            Division();
            break;
        case 2:
            system("cls");
            printf("\t������� ����������� ��������\n\n");
            Division2();
            break;
        case 3:
            system("cls");
            printf("\t���������� ����� ��������\n\n");
            GCD();
            break;
        case 4:
            system("cls");
            printf("\t���������� ����� �������� ��������\n\n");
            GCD2();
            break;
         case 5:
             system("cls");
             printf("\t���������� ����� ��������\n\n");
             GCD();
             break;
        }
        printf("\n\n\t��� ����������� ������� ����� ������");
        scanf_s("%�", &c);
    } while (entry != '0');
    
}




