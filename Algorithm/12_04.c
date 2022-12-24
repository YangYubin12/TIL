#include<stdio.h>
#include<stdlib.h> 
#define Q_SIZE 10
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0
typedef int element;
typedef struct Qtype{
   element queue[Q_SIZE]; //1차원배열큐선언
      int front, rear;
}Qtype;
int visited[MAX_VERTICES];
typedef struct GraphNode{
   int vertax;
   struct GraphNode* link;
}GraphNode;
typedef struct GraphType{
   int n; //정점의 개수 
   GraphNode* adj_list[MAX_VERTICES];
}GraphType;

//공백 순차 큐를 생성하는 연산
Qtype* createQueue(){
   Qtype* q;
   q =(Qtype*)malloc(sizeof(Qtype));
   q->front =0; //front초기값 셋 
   q->rear =0; //rear 초기값 셋 
   return q;
}
void queue_init(Qtype* q){
   q->front = q->rear = 0;
}
//순차큐가 공백인지 검사연산 
int is_empty(Qtype* q){
   return (q->front == q->rear);
}
//순차큐가 full인지 검사 연산
int is_full(Qtype* q){
   return ((q->rear + 1) % Q_SIZE  == q->front );
} 
//순차큐의 rear에 원소를 삽입하는 연산 
void enqueue(Qtype* q,element item){
   //full이 아니면 [rear+1]위치에 저장
   if (is_full(q) == 1 ) {
      printf("큐가 포화상태입니다.");
   } 
   else {
      q->rear =(q->rear+1) % Q_SIZE; //rear위치를 삽입할 위치로 조정 
      q->queue[q->rear]=item; //아이템 삽입 
   } 
}
//순차큐의 front에서 삭제하는 연산 
element dequeue(Qtype* q){
   if (is_empty(q)) return 0;
   else {
      q->front = (q->front + 1 ) % Q_SIZE; //front의 위치를 삭제할 위치로 조정 
      return q->queue[q->front]; // front위치 값 반환 
   }
}

//그래프 초기화
void graph_init(GraphType* g){
   int v; //v는 정점 
   g->n=0; //그래프의 정점수 초기화 
   for (v = 0;v < MAX_VERTICES;v++){
      g->adj_list[v] =NULL;   
   }
} 
//정점 삽입 연산
void insert_vertax(GraphType* g, int v){
   if(g->n> MAX_VERTICES){
      printf("그래프: 정점의 개수 초과\n");
      return; 
   }
   g->n++; //정점개수 증가
} 
//간선 삽입 연산
void insert_edge(GraphType* g, int u, int v) { //u ->v1->...
   GraphNode* node;
   if (u>=g->n || v>=g->n){
		 printf("그래프: 정점번호 오류");
	 return; 
   }
   node = (GraphNode*)malloc(sizeof(GraphNode));
   node->vertax = v;
   node->link = NULL;
   if (g->adj_list[u] ==NULL){
		 g->adj_list[u]=node; //새로운 노드 주소로 갱신 
   }
   else{
      GraphNode* p=(GraphNode*)malloc(sizeof(GraphNode)) ;
      for(p = g->adj_list[u];p->link != NULL; p=p->link);
      p->link = node;//새로운 노드 주소
   }
}
void print_adj_list(GraphType* g){
   int i,j;
   for (i=0;i<g->n;i++){
      GraphNode* p =g->adj_list[i]; 
      printf("정점 %d의 인접리스트",i);
      for (;p!=NULL;p=p->link){
         printf("->%d",p->vertax);
      }
      printf("\n");
   }
}
void bfsMatrix(GraphType* g, int v){
   GraphNode* w;
   Qtype q;
   queue_init(&q);
   visited[v]= TRUE; //visited배열에 정점 V 방문표시  
   printf("%C 방문 -> " ,v + 'A'); //방문한 정점 문자로 출력
   enqueue(&q, v); //큐에 처음 정점 삽입
   while (!is_empty(&q)){
      v = dequeue(&q); //정점을 큐에서 꺼내어 v에 저장(방문)
      for (w =g->adj_list[v];w!=NULL;w=w->link) {
         if (visited[w->vertax]==0){ //v,w가 연결 && w 미방문이면 
            visited[w->vertax] = TRUE; //방문표시 
            printf("%C 방문->",w-> vertax+'A');
            enqueue(&q, w->vertax); //인접한 정점을 큐에 삽입
         }
      }
   }
}
int main(){
   GraphType* g;
   g=(GraphType*) malloc(sizeof(GraphType));
   graph_init(g);
   for (int i = 0;i<6;i++){
      insert_vertax(g,i);
   }
   insert_edge(g,0,2); //A,C
   insert_edge(g,2,1); //C, B
   insert_edge(g,2,3);
   insert_edge(g,0,4);
   insert_edge(g,4,5);
   insert_edge(g,1,5);
   printf("너비 우선탬색 \n");
   bfsMatrix(g,0);
   printf("\n");
   free(g);   
   return 0;
}
