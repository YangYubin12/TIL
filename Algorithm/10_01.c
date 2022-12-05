#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct TreeNode{
   element key;
   struct TreeNode* left;
   struct TreeNode* right
}TreeNode;
//순환적 탐색함수
TreeNode* search(TreeNode* node, int key){
   if(node == NULL ) return NULL;
   if(key == node->key)
      return node; 
   else if (key < node->key) 
      return search(node->left, key);
   else return search(node->right, key);
}
TreeNode* newNode(int item){
   TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
   temp->key =  item;
   temp->left = temp->right = NULL;
   return temp;
}
TreeNode* insertNode(TreeNode* node, int key){
   //탐색이 실패한 위치에 새로운 노드를 삽입 후 반환
   if ( node == NULL ) return newNode(key);
   //그렇지 않으면 순환적으로 트리를 내려간다.
   else if (key < node->key){ 
      node->left = insertNode(node->left, key);
   }
   else if (key > node->key) {
      node->right = insertNode(node->right, key);
   }
   //변경된 루트 포인터 반환
   return node;
}
TreeNode* minNode(TreeNode* node){
   TreeNode* cur = node;
   //맨 왼쪽 최소단말 탐색
   while(cur->left !=NULL){
      cur = cur->left;
   }
   return cur;
}
//이진 탐색트리와 키가 주어지면 키가 저장된 노드를 삭제하고 
//새로운 루트 노드를 반환한다.
TreeNode* deleteNode(TreeNode* root, int key){
   //printf("delete 주소=%p, key =%d\n",root,key);
   if (root == NULL) return root;
   //만약 키가 루트보다 작으면 ->왼쪽서브트리
   if ( key < root->key) {
      root->left =  deleteNode(root->left, key);
   }
   //만약 키가 루트보다 크면 -> 오른쪽 서브트리
   else if(key > root->key){
      root->right = deleteNode(root->right, key);
   } 
   //키가 루트와 같으면 노드 삭제
   else { //또는 else if(key > root->key) 이렇게 해도됨
      //삭제노드가 단말이거나 하나의 서브트리를 가지는 경우
      if (root->left == NULL){
         TreeNode* temp = root->right;
         free(root);
         return temp;
      }
      else if (root->right == NULL){
         TreeNode* temp = root->left;
         free(root);
         return temp;
      }
      //삭제노드가 두개의 서브트리를 가지고 있는 경우
      TreeNode* temp = minNode(root->right); //22의 주소값
      //중위순회시 후계노드 복사
      root->key = temp->key; //22
      //중위순회시 후계 노드 삭제
      //printf("delete [26]주소=%p, key =%d\n",root->right,temp->key);
      root->right = deleteNode(root->right,temp->key); //26주소 ,22
   }
   return root;
}
void inorder(TreeNode* root){
   if (root != NULL){
      inorder(root->left);
      printf("[%d] ",root->key); //root 노드방문 출력
      inorder(root->right); //오른쪽서브트리 순회
   }
}
int main() {
   TreeNode* root = NULL;
   TreeNode* tmp = NULL;
   int n;
   root = insertNode(root,35);
   root = insertNode(root,18);
   root = insertNode(root,68);
   root = insertNode(root,7);
   root = insertNode(root,26);
   root = insertNode(root,99);
   root = insertNode(root,3);
   root = insertNode(root,12);
   root = insertNode(root,22);
   root = insertNode(root,30);   
   printf("이진탐색트리 중위순회 결과 출력\n");
   inorder(root);
   printf("\n삭제할 숫자를 입력하세요\n");
   //deleteNode(root, 18);
   printf("이진탐색트리 중위순회 결과 출력\n");
   inorder(root);   
   return 0;
}
