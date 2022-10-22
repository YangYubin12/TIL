#include <stdio.h>
#include <math.h>
#define N 5
typedef struct point{
	int x,  y;
}POINT;

void inputPoint( POINT *p );
void outputPoint( POINT *p );
double distance( POINT *p, POINT *q);

int main() {
	int i, j, mi = 0;
	POINT p[5];
	POINT origin = { 0, 0};
	//5개 입력, 출력
	for(i=0; i<5; i++){
		inputPoint(p+i);//&p[i]
	}
	for(i=0; i<5; i++){
		outputPoint(p+i);//&p[i]
	}
	for(i=1; i<5; i++){
		if(distance(&p[mi], &origin) >= distance(&p[i], &origin)){ //min거리 >= i번째 거리
			if(p[mi].x +p[i].y > p[i].x+p[i].y){		
				mi = i;
			}	
		} 
	}
	//5개 거리계산 하면서 제일 작은거리 계산
	printf("원점에서 가장 가까운 좌표 : (%4d, %4d)", p[mi].x,p[mi].y);
	return 0;
}
void inputPoint( POINT *p){
	scanf("%d %d", &p->x,&p->y);
}
void outputPoint( POINT *p ){
	//printf("%d %d", p->x, p->y);	
}
double distance( POINT *p, POINT *q){
	return sqrt(pow(p->x - q->x, 2) + pow(p->y - q->y, 2));
}
