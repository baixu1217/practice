#define _CRT_SECURE_NO_WARNINGS 1
extern "C"
 #include<stdio.h>
#include<stdlib.h>
#define W 10
int Available[W];           //可使用资源
int Max[W][W];             //最大需求资源数
int Allocation[W][W];      //已分配资源
int Need[W][W];            //需求资源
int Work[W];              //工作向量
int Finish[W];           //是否有足够的资源分配，状态标志
int Request[W][W];        //进程申请资源向量
int Temp[W];             //暂存可用资源数
int AllReSourceNum[W];        //各类资源总数
int i, j;
int ResourceNum;              //系统资源总数
int ProcessNum;               //总的进程数
int a;                       //当前申请的进程号
int l, e;                     
int b = 0, c = 0, f = 0, g;  //c: 统计对于每一个进程，成功分配的资源类别数
  
int  SecurityCheck()     //安全性检测
{
    printf("\n\n");
    printf("\t\t\t 安全性检测 \n\n");
    printf("          工作向量       尚需求量       已分配      工作向量+已分配\n进程 ");
	for (c = 1; c <= 4; c++)
	{
        for (j = 1; j <=ResourceNum; j++)
		{
             printf("  %d类", j);
        }
	}
    for (i = 1; i <=ProcessNum; i++)
    {
        Temp[i] = Available[i];    //Temp[i]只是一个暂时寄存的中间变量，为防止在下面安全性检查时修改到Available[i]而代替的一维数组
        Finish[i] = false;
    }
    for (g = 1; g <= ProcessNum; g++)
    {
        for (i = 1; i <= ProcessNum; i++) 
        {
            b = 0;                 //计数器初始化，否和条件的资源个数
            Finish[i] == false;
            for (j = 1; j <= ResourceNum; j++)
            {
                if (Need[i][j] <= Temp[j])
                {
                    b = b + 1;
                }
                if (Finish[i] == false && b == ResourceNum)
                {
                    Finish[i] = true;
                    printf("\nP[%d] ", i);        //依次输出进程安全序列  
                    for (l = 1; l <= ResourceNum; l++)
                    {
                        printf("  %2d ", Temp[l]);
                    }
                    for (j = 1; j <= ResourceNum; j++)
                    {
                        printf("  %2d ",Need[i][j]);
                    }
                    for (j = 1; j <= ResourceNum; j++)
                    {
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
        if (Finish[i] == true) 
			f = f + 1;			//统计Finish[i]＝＝true的个数
    }
    if (f ==ProcessNum)
    {
        printf("安全序列");
        printf("\n\n系统资源量：");
        for (i = 1; i <= ResourceNum; i++)
        {
			printf("   %d ", Available[i]);
        }
        f = 0;       //将计数器f重新初始化，为下一次提出新的进程申请做准备
        return 1;
    }
    else
    {
        printf("不安全序列");
		for (i = 1; i <= ResourceNum; i++)
        {
            Available[i] = Available[i] + Request[a][i];
            Allocation[a][i] = Allocation[a][i] - Request[a][i];
            Need[a][i] =Need[a][i] + Request[a][i];
        }
        return 0;
    }
}

void Initialize()    //初始化
{
    printf("请输入系统的资源种类数：");
	scanf("%d", &ResourceNum);
    for (i = 1; i <=ResourceNum; i++)
    {
        printf("第%d类资源总数：", i);
        scanf("%d", &AllReSourceNum[i]);
    }
    printf("请输入进程总数：");
	scanf("%d", &ProcessNum);
    for (i = 1; i <=ProcessNum; i++)
    {
        for (j = 1; j <=ResourceNum; j++)
        {
            printf("进程P[%d]对第%d类资源的最大需求量：", i, j);
            scanf("%d", &Max[i][j]);
        }
    }
    for (i = 1; i <=ProcessNum; i++)
    {
        for (j = 1; j <=ResourceNum; j++)
        {
            printf("进程P[%d]对第%d类资源已分配数：", i, j);
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
  
void RequestResource()  //进程申请资源
{
    printf("请输入申请资源的进程：");
    scanf("%d", &a);
    for (i = 1; i <= ResourceNum; i++)
    {
        printf("请输入进程P[%d]对%d类资源的申请量：", a, i);
        scanf("%d", &Request[a][i]);
        if (Request[a][i] > Need[a][i])
        {
            printf("\n出错！进程申请的资源数多于它自己申报的最大需求量\n");
            return;
        }
        if (Request[a][i] > Available[i])
        {
            printf("\nP[%d]请求的资源数大于可用资源数，必须等待\n", a);
            return;
        }
    }
    for (i = 1; i <=ResourceNum; i++)
    {
        //以下是试探性分配
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
    printf("          已分配       最大需求量       尚需要量 \n进程");
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <=ResourceNum; j++)
        {
            printf("  %d类", j);
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
    printf("\n\n系统剩余资源量：   ");
    for (i = 1; i <=ResourceNum; i++)
    {
        printf("   %d ", Available[i]);
    }
    printf("\n");
}

void menu()
{
    printf("\n\t-------------银行家算法---------------\n");
    printf("             1、初始化                \n");
    printf("             2、进程请求资源          \n");
    printf("             3、资源分配状态          \n");
    printf("             4、退出                  \n");
	printf("\t--------------------------------------\n");
    printf("\n请输入你的选择: ");
}