/* 1260. DFS와 BFS Silver 1
 https://www.acmicpc.net/problem/1260
 */

#include<iostream>
#include<memory.h>
using namespace std;

void DFS(int);
void BFS(int);

typedef struct node{
    int data = 0;
    node* next = NULL;
};

node *voltex[1000];
bool isFinished[1000];
bool isDiscovered[1000];
node *queue[1000];
int q_start = 0, q_end = 0;

int main(){
    int voltex_num, edge_num, first_voltex;
    cin >> voltex_num >> edge_num >> first_voltex;
    
    //데이터 입력
    for (int i = 0; i < edge_num; i++){
        int vol1, vol2;
        cin >> vol1 >> vol2;
        
        node *n1, *n2;
        if (voltex[vol1 - 1] == NULL){
            n1 = new node();
            n1->data = vol2;
            voltex[vol1 - 1] = n1;
        }
        else{
            node *p, *q;
            for (p = q = voltex[vol1 - 1]; (p != NULL) && (p->data <= vol2); q = p, p = p->next);
            if (q->data != vol2){
                n1 = new node();
                n1->data = vol2;
                if (p == voltex[vol1 - 1]){
                    voltex[vol1 - 1] = n1;
                }
                else{
                    q->next = n1;
                }
                n1->next = p;
            }
        }
        
        if (voltex[vol2 - 1] == NULL){
            n2 = new node();
            n2->data = vol1;
            voltex[vol2 - 1] = n2;
        }
        else{
            node *p, *q;
            for (p = q = voltex[vol2 - 1]; (p != NULL) && (p->data <= vol1); q = p, p = p->next);
            if (q->data != vol1){
                n2 = new node();
                n2->data = vol1;
                if (p == voltex[vol2 - 1]){
                    voltex[vol2 - 1] = n2;
                }
                else{
                    q->next = n2;
                }
                n2->next = p;
            }
        }
    }
    
    DFS(first_voltex);
    cout << endl;
    
    memset(isFinished, false, 1000);
    memset(isDiscovered, false, 1000);
    BFS(first_voltex);
}

void DFS(int v){
    if (!isFinished[v - 1]){
        isFinished[v - 1] = true;
        node *n = voltex[v - 1];
        cout << v << " ";
        while (n != NULL){
            DFS(n->data);
            n = n->next;
        }
    }
}

void BFS(int v){
    if (!isFinished[v - 1]){
        isFinished[v - 1] = true;
        node *n = voltex[v - 1];
        cout << v << " ";
        while (n != NULL){
            if (!isDiscovered[n->data - 1]){
                queue[q_end] = n;
                isDiscovered[n->data - 1] = true;
                q_end++;
            }
            n = n->next;
        }
    }
    if (q_start != q_end){
        q_start++;
        BFS(queue[q_start - 1]->data);
    }
}
