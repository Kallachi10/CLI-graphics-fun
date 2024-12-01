#include<stdio.h>
#include<string.h>
#include<math.h>
void main(){
    int x_size, y_size;

    printf("Type the max size of x-axis: ");
    scanf("%d",&x_size);

    printf("Type the max size of y-axis: ");
    scanf("%d",&y_size);

    int scale = 1/*set scale here*/;
    char graph[x_size*scale][y_size*scale];

    char equation[10];
    
    printf("Type equation to plot (y = f(x) format) note: only 2D continuous functions.\ny = (enter your equation(f(x))): ");
    scanf("%s",equation);
    int coeff[10] = {0},power[10] = {0};
    int k=0;
    char* token = strtok(equation,"+-");
    int constant = 0;
    while(token!=NULL){
        coeff[k] = token[0]-'0';
        if(strlen(token)==4)
            power[k] = token[3]-'0';
        else 
            constant += token[0] - '0';

        token = strtok(NULL,"+-");
        k++;
    }
    
    for(int i=0;i<x_size*scale;i++){
        for(int j=0;j<y_size*scale;j++){
            if(j==coeff[0]* pow(i,power[0]) + constant){
                graph[j][i] = '*';
            }
            else{
                graph[j][i] = '.';
            }
        }
    }

    //display
    int count_y = y_size;
    printf("\n");
    for(int i=x_size*scale-1;i>=0;i--){
        printf("\t%d -\t",count_y-1);
        count_y--;
        for(int j=0;j<y_size*scale;j++){
                printf("%c   ",graph[i][j]);
        }
        printf("\n");
    }
    printf("\n\t\t");
    for(int i=0;i<x_size;i++){
        if(i/10!=0)
            printf("%d  ",i);
        else
            printf("%d   ",i);
    }
    printf("\n");
}