#include<stdio.h>

int main()
{
    int pages[12] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int frames[3];
    int i,j,k=0,flag,fault=0;

    for(i=0;i<3;i++)
        frames[i] = -1;

    printf("Page\tStatus\t\tFrames\n");

    for(i=0;i<12;i++)
    {
        flag = 0;

        for(j=0;j<3;j++)
        {
            if(frames[j] == pages[i])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
        {
            printf("%d\tPage Hit\t", pages[i]);
        }
        else
        {
            printf("%d\tPage Fault(F%d)\t", pages[i], k+1);
            frames[k] = pages[i];
            k = (k + 1) % 3;
            fault++;
        }

        for(j=0;j<3;j++)
            printf("%d ", frames[j]);

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", fault);

    return 0;
}
