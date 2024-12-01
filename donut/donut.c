#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*equation : (x-h)^2 + (y-k)^2 = r^2*/

void main(){
    /*generate circles*/
    srand(time(NULL));
    int radius = 0;
    int inner_radius = 0;
    printf("Type value for radius: ");
    scanf("%d",&radius);

    printf("Type inner radius: ");
    scanf("%d",&inner_radius);

    for(int i=0;i<50;i++){
        printf("%d",i);
    }
    printf("\n");
    for(int i=0;i<70;i++){
        printf("%d\t",i);
        for(int j=0;j<70;j++){
            int random = rand()%94;
            random+=33;
            int x = i - 35;
            int y = j - 35;
            if(x*x + y*y <= radius*radius && x*x + y*y >= inner_radius*inner_radius)
                printf("%c ",random);
            else
                printf("  ");
        }
        printf("\n");
    }
}