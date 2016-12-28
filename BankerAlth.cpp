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