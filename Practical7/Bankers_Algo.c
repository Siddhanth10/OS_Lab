#include <stdio.h>

int main()
{
    int n,m,i,j,k;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resource types: ");
    scanf("%d",&m);

    int alloc[n][m],max[n][m],need[n][m];
    int avail[m];
    int finish[n];
    int safe[n];

    printf("\nEnter Allocation Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("\nEnter Maximum Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("\nEnter Available Resources:\n");
    for(i=0;i<m;i++)
        scanf("%d",&avail[i]);

    printf("\n-----------------------------------\n");
    printf("CALCULATING NEED MATRIX\n");
    printf("-----------------------------------\n");

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    printf("\nNeed Matrix:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d : ",i);
        for(j=0;j<m;j++)
            printf("%d ",need[i][j]);
        printf("\n");
    }

    printf("\nInitial Available Resources: ");
    for(i=0;i<m;i++)
        printf("%d ",avail[i]);
    printf("\n");

    for(i=0;i<n;i++)
        finish[i]=0;

    int count=0;

    printf("\n=====================================\n");
    printf("STARTING BANKER'S ALGORITHM\n");
    printf("=====================================\n");

    while(count<n)
    {
        int found=0;

        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                printf("\n-----------------------------------\n");
                printf("Checking Process P%d\n",i);
                printf("-----------------------------------\n");

                printf("Need of P%d : ",i);
                for(j=0;j<m;j++)
                    printf("%d ",need[i][j]);

                printf("\nAvailable   : ");
                for(j=0;j<m;j++)
                    printf("%d ",avail[j]);

                printf("\n");

                int possible=1;

                for(j=0;j<m;j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        possible=0;
                        printf("Resource %d not sufficient\n",j);
                        break;
                    }
                }

                if(possible)
                {
                    printf("All required resources available\n");
                    printf("Process P%d CAN execute\n",i);

                    printf("Releasing resources of P%d back to system\n",i);

                    for(k=0;k<m;k++)
                    {
                        avail[k]+=alloc[i][k];
                    }

                    printf("Updated Available Resources: ");
                    for(k=0;k<m;k++)
                        printf("%d ",avail[k]);

                    printf("\n");

                    safe[count]=i;
                    count++;
                    finish[i]=1;
                    found=1;
                }
                else
                {
                    printf("Process P%d CANNOT execute now\n",i);
                }
            }
        }

        if(found==0)
        {
            printf("\nSYSTEM IS NOT IN SAFE STATE\n");
            return 0;
        }
    }

    printf("\n=====================================\n");
    printf("SYSTEM IS IN SAFE STATE\n");
    printf("SAFE SEQUENCE:\n");

    for(i=0;i<n;i++)
        printf("P%d ",safe[i]);

    printf("\n=====================================\n");

    return 0;
}

