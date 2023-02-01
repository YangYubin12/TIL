#include<stdio.h> 
int main() 
{ 
    int map[11][11],x=2,y=2,i,j; 
    for(i=1;i<=10;i++) 
        for(j=1;j<=10;j++) 
            scanf("%d",&map[i][j]); 
    while(map[x][y]!=2) 
    { 
        map[x][y]=9; 
        if(map[x][y+1]!=1) y+=1; 
        else if(map[x+1][y]!=1) x+=1; 
        else break; 
    } 
    map[x][y]=9; 
    for(i=1;i<=10;i++) 
    { 
        for(j=1;j<=10;j++) 
            printf("%d ",map[i][j]); 
        printf("\n"); 
    } 
    return 0; 
}
