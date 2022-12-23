#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0
//그래프 노드(정점)구조체 정의
typedef struct GraphNode{
	int vertex;
	struct GraphNode* link;
}GraphNode;
//각 정점의 인접 정점 리스트 시작주소를 포인터 배열 구조체로 정의
typedef struct GraphType{
	int n; //정점의 개수 
	GraphNode* adj_list[MAX_VERTICES];
	//GraphNode *p0, *p1, *p2, ......,; 포인터 배열
}GraphType; 
int visited[MAX_VERTICES];
//그래프 초기화
void init(GraphType* g){
	int v; //v는 정점 
	g->n=0; //그래프의 정점수 초기화 
	for (v = 0;v < MAX_VERTICES;v++){
		g->adj_list[v]=NULL;	
	}
} 
void insert_vertex(GraphType* g, int v){//정점 개수 1증가 
	if((g->n)+1 >MAX_VERTICES){
	   printf("그래프: 정점의 개수 초과");
		return; 
	}
	g->n++; //정점개수 증가
} 
//간선 삽입 연산
void insert_edge(GraphType* g, int u, int v) { //u ->v1->...
	GraphNode  *node, *p;
	if (u>=g->n || v>=g->n){
			printf("그래프: 정점번호 오류");
		return; 
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex= v;
	if (g->adj_list[u] ==NULL ){
		node->link=g->adj_list[u]; //링크를 정점의 포인터배열 시작주소로 저장 
		g->adj_list[u]=node; //새로운 노드 주소로 갱신 
	}
	else{
		for(p=g->adj_list[u];p->link!=NULL;p=p->link);		
		p->link = node; //p는 리스트의 마지막 노드
		node->link = NULL;
	}
}
void print_adj_list(GraphType* g){
	int i,j;
	GraphNode* p ;
	for (i=0;i<g->n;i++){ 
		printf("정점 %d의 인접리스트",i);
		for (p=g->adj_list[i];p!=NULL;p=p->link){
			printf("->%d", p->vertex);
		}
		printf("\n");
	}
}
void dfs_list(GraphType* g, int v){ //v=0
	GraphNode* w; //자식주소 저장
	visited[v] = TRUE; //방문배열에 정점 방문 저장
	printf("정점 %d-> ", v);//정점출력
	for(w=g->adj_list[v];w!=NULL;w=w->link){
		if (visited[w->vertex]== 0){ //미방문
			dfs_list(g,w->vertex); //정점 탐색호출		
		}
	}
}
int main(){
	GraphType* g;
	int n;
	g=(GraphType*) malloc(sizeof(GraphType));
	init(g);
	for (int i = 0;i<5;i++){
		insert_vertex(g, i); //정점입력 함수 호출
	}
	insert_edge(g,0,1);	insert_edge(g,0,2);
	insert_edge(g,0,4);	insert_edge(g,1,0);
	insert_edge(g,1,2); insert_edge(g,2,0);
	insert_edge(g,2,1); insert_edge(g,2,3);	
	insert_edge(g,2,4); insert_edge(g,3,2);
	insert_edge(g,3,4);	insert_edge(g,4,0);	
	insert_edge(g,4,2);	insert_edge(g,4,3);	
	//print_adj_list(g);
		
	printf("깊이 우선탐색 시작 정점 입력 \n");
	scanf("%d",&n);
	dfs_list(g, n);
	free(g);	
	return 0;
}
