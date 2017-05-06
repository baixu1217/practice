//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int ounum = 0;
//	int qinum = 0;
//	int x,y;
//	int m = 0;
//	int tmp;
//	
//	while(scanf("%d%d",&x,&y) != EOF)
//	{
//		ounum = 0;
//		qinum = 0;
//		if(x>y)
//		{
//			tmp =x;
//			x = y;
//			y = tmp;
//		}
//		
//		for( m = x;m <= y;m++)
//		{
//			if(m % 2 == 0)
//			{
//				ounum+= pow(m,2);
//				
//			}
//			else
//			{
//				qinum+= pow(m,3);
//			}
//		}
//		printf("%d %d\n",ounum,qinum);
//	}
//	
//
//	return 0;
//} 


//#include<stdio.h>
//
//int main()
//{
//	char str[50];
//	int len=0;
//	char* head;
//	char* tail;
//	char* s = str;
//	scanf("%s",str);
//	while(*s != '\0')
//	{
//		len++;
//		s++;
//	}
//	
//	head = str;
//	tail = str+len-1;
//	if(str == NULL)
//		printf("N\n");
//	while(head < tail)
//	{
//		if(*head != *tail)
//		{
//			printf("N\n");
//			break;
//		}
//		head++;
//		tail--;
//	}
//	if(head >= tail)
//		printf("Y\n");
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//    char he[100];
//    char a;
//    int i=0,flag=1;
//	int n = 0;
//    while((a=getchar())!='\n')
//    {
//        he[i]=a;
//        i++;
//    }
//    n=i;
//    for(i=0;i<n/2;i++)
//    {
//        
//        if(he[i]!=he[n-1-i])
//        {
//			flag = 0;
//            printf("N");break;
//        }
//    }
//    if(flag==1)
//    {
//        printf("Y");
//    }
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int m;
//	int arr[100];
//	int num = 0;
//	int arr1[100];
//	int k = 0;
//	int t = 0;
//	int i = 0, j = 0;
//	scanf("%d",&m);
//	for( i = 0; i < m; i++)
//		scanf("%d",&arr[i]);
//
//	scanf("%d",&num);
//	for( j = 0; j < m; j++)
//	{
//		
//		arr1[j+num] = arr[j];
//		if(j == m-num)
//		{
//			while(j < m)
//				arr1[k++] = arr[j++];
//			if(j == m)
//				break;
//		}
//		
//		 
//			
//		
//	}
//	for( t = 0; t < m; t++)
//		printf("%d ",arr1[t]);
//	return 0;
//}


#include<stdio.h>
int main()
{
	struct Stu
	{
		int num;
		char name[20];
		int arr[3];
	}Stu[10];
	int i = 0;
	int number = 0;
	int j = 0;
	int avg[3] = {0};
	int aaa[10] = {0};
	int k =0;
	int m = 0;
	int max = 0;
	int flag = 0;
	scanf("%d",&number);
	for(i = 0; i < number; i++)
	{
		scanf("%d%s%d%d%d",&Stu[i].num,Stu[i].name,&Stu[i].arr[0],&Stu[i].arr[1],&Stu[i].arr[2]);
	}
	for(k = 0; k < 3; k++)
	{
		for(j = 0; j < number; j++)
		{
			avg[k]+=Stu[j].arr[k];
		}
		avg[k] /= number;
		
	}
	for(k = 0; k < 3; k++)
	{
		printf("%d ",avg[k]);
	}
	printf("\n");
	for(m = 0; m < number; m++)
	{
		for(i = 0; i < 3; i++)
		{
			aaa[m]+=Stu[m].arr[i];
		}
	}
	max = aaa[flag];
	for(m = 1; m < number; m++)
	{
		if(aaa[m] > max)
		{
			max = aaa[m];
			flag = m;
		}
	}
	printf("%d %s %d %d %d\n",Stu[flag].num,Stu[flag].name,Stu[flag].arr[0],Stu[flag].arr[1],Stu[flag].arr[2]);
	return 0;
}
