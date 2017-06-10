#define _CRT_SECURE_NO_WARNINGS 1
extern "C"
#include<stdio.h>
#include<stdlib.h>
#define W 10
int Available[W];           //��ʹ����Դ
int Max[W][W];             //���������Դ��
int Allocation[W][W];      //�ѷ�����Դ
int Need[W][W];            //������Դ
int Work[W];              //��������
int Finish[W];           //�Ƿ����㹻����Դ���䣬״̬��־
int Request[W][W];        //����������Դ����
int Temp[W];             //�ݴ������Դ��
int AllReSourceNum[W];        //������Դ����
int i, j;
int ResourceNum;              //ϵͳ��Դ����
int ProcessNum;               //�ܵĽ�����
int a;                       //��ǰ����Ľ��̺�
int l, e;                     
int b = 0, c = 0, f = 0, g;  //c: ͳ�ƶ���ÿһ�����̣��ɹ��������Դ�����
int  SecurityCheck()     //��ȫ�Լ��
{
    printf("\n\n");
    printf("\t\t\t ��ȫ�Լ�� \n\n");

    printf("          ��������       ��������       �ѷ���      ��������+�ѷ���\n���� ");
	for (c = 1; c <= 4; c++)
	{
        for (j = 1; j <=ResourceNum; j++)
		{
             printf("  %d��", j);
        }
	}
    for (i = 1; i <=ProcessNum; i++)
    {
        Temp[i] = Available[i];    //Temp[i]ֻ��һ����ʱ�Ĵ���м������Ϊ��ֹ�����氲ȫ�Լ��ʱ�޸ĵ�Available[i]�������һά����
        Finish[i] = false;
    }
    for (g = 1; g <=ProcessNum; g++)
    {
        for (i = 1; i <=ProcessNum; i++)
        {
            b = 0;                 //��������ʼ��
            Finish[i] == false;
            for (j = 1; j <=ResourceNum; j++)
            {
                if (Need[i][j] <= Temp[j])
                {
                    b = b + 1;
                }
                if (Finish[i] == false && b ==ResourceNum)
                {
                    Finish[i] = true;
                    printf("\nP[%d] ", i);        //����������̰�ȫ����  
                    for (l = 1; l <=ResourceNum; l++)
                    {
                        printf("  %2d ", Temp[l]);
                    }
                    for (j = 1; j <=ResourceNum; j++)
                    {
                        printf("  %2d ",Need[i][j]);
                    }
                    for (j = 1; j <=ResourceNum; j++)
                    {
                        //Allocation[i][j]=Temp[j]-Need[i][j];
                        printf("  %2d ", Allocation[i][j]);
                    }
                    for (j = 1; j <=ResourceNum; j++)
                    {
                        printf("  %2d ", Temp[j] + Allocation[i][j]);
                    }
                    for (l = 1; l <=ResourceNum; l++)
                    {
                        Temp[l] = Temp[l] + Allocation[i][l];        
                    }
                }
            }
        }
    }
    printf("\n\n");
    for (i = 1; i <=ProcessNum; i++)
    {
        if (Finish[i] == true) f = f + 1;  //ͳ��Finish[i]����true�ĸ���
    }
    if (f ==ProcessNum)
    {
        printf("��ȫ����");
        printf("\n\nϵͳʣ����Դ����");
        for (i = 1; i <=ResourceNum; i++)
        {
        printf("   %d ", Available[i]);
        }
        f = 0;       //��������f���³�ʼ����Ϊ��һ������µĽ���������׼��
        return 1;
    }
    else
    {
        printf("����ȫ����");
        return 0;
    }
}
void Initialize()    //��ʼ��
{
    printf("������ϵͳ����Դ��������");
	scanf("%d", &ResourceNum);
    for (i = 1; i <=ResourceNum; i++)
    {
        printf("��%d����Դ������", i);
        scanf("%d", &AllReSourceNum[i]);
    }
    printf("���������������");
	scanf("%d", &ProcessNum);
    for (i = 1; i <=ProcessNum; i++)
    {
        for (j = 1; j <=ResourceNum; j++)
        {
            printf("����P[%d]�Ե�%d����Դ�������������", i, j);
            scanf("%d", &Max[i][j]);
        }
    }
    for (i = 1; i <=ProcessNum; i++)
    {
        for (j = 1; j <=ResourceNum; j++)
        {
            printf("����P[%d]�Ե�%d����Դ�ѷ�������", i, j);
            scanf("%d", &Allocation[i][j]);
           Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
    for (i = 1; i <=ResourceNum; i++)
    {
        for (j = 1; j <=ProcessNum; j++)
        {
            AllReSourceNum[i] -= Allocation[j][i];
        }
    }
    for (i = 1; i <=ResourceNum; i++)
        Available[i] = AllReSourceNum[i];
    SecurityCheck();
}
void RequestResource()  //����������Դ
{
    printf("������������Դ�Ľ��̣�");
    scanf("%d", &a);
    for (i = 1; i <=ResourceNum; i++)
    {
        printf("���������P[%d]��%d����Դ����������", a, i);
        scanf("%d", &Request[a][i]);
        if (Request[a][i] >Need[a][i])
        {
            printf("\n���������������Դ���������Լ��걨�����������\n");
            return;
        }
        if (Request[a][i] > Available[i])
        {
            printf("\nP[%d]�������Դ�����ڿ�����Դ��������ȴ�\n", a);
            return;
        }
    }
    for (i = 1; i <=ResourceNum; i++)
    {
        //��������̽�Է���
        Available[i] = Available[i] - Request[a][i];
        Allocation[a][i] = Allocation[a][i] + Request[a][i];
		Need[a][i] =Need[a][i] - Request[a][i];
    }
    int ret=SecurityCheck();
    if (ret == 1)
    {
        int key = 0;
        for (j = 1; j <=ResourceNum; j++)
        {
            if (Need[a][j] == 0)
            {
                key++;
            }
        }
        if (key ==ResourceNum)
        {
            for (j = 1; j <=ResourceNum; j++)
            {
                Available[j] += Allocation[a][j];
                Allocation[a][j] = 0;
            }
        }
    }
}
  
void ResourceState()
{
    printf("\n\n");
    printf("          �ѷ���       ���������       ����Ҫ�� \n����");
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <=ResourceNum; j++)
        {
            printf("  %d��", j);
        }
    }
    for (i = 1; i <=ProcessNum; i++)
    {
        printf("\nP[%d]", i);
        for (j = 1; j <=ResourceNum; j++)
        {
            printf("  %2d ", Allocation[i][j]);
        }
        for (j = 1; j <=ResourceNum; j++)
        {
            printf("  %2d ", Max[i][j]);
        }
        for (j = 1; j <=ResourceNum; j++)
        {
            printf("  %2d ",Need[i][j]);
        }
    }
    printf("\n\nϵͳʣ����Դ����   ");
    for (i = 1; i <=ResourceNum; i++)
    {
        printf("   %d ", Available[i]);
    }
    printf("\n");
}

void menu()
{
    printf("\n\t-------------���м��㷨---------------\n");
    printf("             1����ʼ��                \n");
    printf("             2������������Դ          \n");
    printf("             3����Դ����״̬          \n");
    printf("             4���˳�                  \n");
	printf("\t--------------------------------------\n");
    printf("\n���������ѡ��: ");
}
//BankerAlth.cpp
#include"BankerAlth.h"
int main()
{
    int select = 0;
    printf("\n\n");
    while (1)
    {
        menu();
        scanf("%d", &select);
        printf("\n\n");
        switch (select)
        {
        case 1:
            Initialize();
            break;
        case 2:
            RequestResource();
            break;
        case 3:
            ResourceState();
            break;
        case 4:
            printf("\nSee you Next time !\n\n");
            system("pause");
            return 0;
        }
    }
    system("pause");
    return 0;
}