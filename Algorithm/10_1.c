#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
typedef struct
{
    char word[100];
    char meaning[200];
} element;
typedef struct TreeNode
{
    element key;
    struct TreeNode *left, *right;
} TreeNode;
int compare(element e1, element e2)
{
    return strcmp(e1.word, e2.word); // e1<e2:-1,==:0,>1
}
//이진탐색트리 출력함수
void display(TreeNode *p)
{
    if (p != NULL)
    {
        printf("(");
        display(p->left);
        printf("%s:%s", p->key.word, p->key.meaning);
        display(p->right);
        printf(")");
    }
}
//이진탐색트리 탐색함수
TreeNode *search(TreeNode *root, element key)
{
    TreeNode *p = root;
    while (p != NULL)
    {
        if (compare(key, p->key) == 0)
            return p;
        else if (compare(key, p->key) < 0)
            p = p->left;
        else if (compare(key, p->key) > 0)
            p = p->right;
    }
    return p;
}
TreeNode *new_node(element item)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode *insert_node(TreeNode *node, element key)
{
    //트리가 공백이면 새로운 노드를 반환
    if (node == NULL)
        return new_node(key);
    if (compare(key, node->key) < 0)
        node->left = insert_node(node->left, key);
    else if (compare(key, node->right) > 0)
        node->right = insert_node(node->right, key);
    return node;
    //순환적으로 트리를 내려가서 삽입
}
// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 루트노드반환
TreeNode *delete_node(TreeNode *root, element key)
{
    if (root == NULL)
        return root;
    if (compare(key, root->key) < 0)
        root->left = delete_node(root->left, key);
    if (compare(key, root->key) > 0)
        root->right = delete_node(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        TreeNode *temp = min_value_node(root->right);
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}
TreeNode *min_value_node(TreeNode *node)
{
    TreeNode *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}
int main()
{
    char command;
    element e;
    TreeNode *root = NULL;
    TreeNode *tmp;
    do
    {
        printf("\n ****i: 입력, d: 삭제,s: 탐색,p: 출력,q:종료****:");
        command = getchar();
        getchar();
        switch (command)
        {
        case 'i':
            printf("단어:");
            gets(e.word, MAX_WORD_SIZE); //단어 한줄 e.word에 입력받음
            printf("의미:");
            gets(e.meaning, MAX_MEANING_SIZE); //의미 한줄 e.meaning에 입력받음
            root = insert_node(root, e); //구조체변수 e입력하는 함수 실행
            break;
        case 'd':
            printf("단어:");
            gets(e.word);
            root = delete_node(root, e); //삭제 함수 실행
            break;
        case 's':
            printf("단어:");
            gets(e.word);
            tmp = search(root, e); //탐색함수 실행
            if (tmp != NULL)
            {
                printf("의미: %s\n", e.meaning);
            }
            break;
        case 'p':
            display(root);
            printf("\n");
            break;
        }
    } while (/*q를 입력하지 않을 동안 실행*/);
    return 0;
}
