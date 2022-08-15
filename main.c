#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node Node;
struct node{
    int info;
    Node *next;
};

typedef struct lista Lista;
struct lista{
    Node *head;
};

Node *newNode(bool *deuCerto){
    Node *n;
    n = malloc(sizeof (Node));
    if (n==NULL){
        *deuCerto = false;
    }else {
        *deuCerto = true;
    }

    return n;
}

void deleteNode (Node *n){
    if(n!=NULL) free(n);
}

Lista *criar(bool *deuCerto){
    Lista *L;
    L = malloc(sizeof(Lista));
    if(L == NULL){
        *deuCerto = false;
    }else {
        *deuCerto = true;
        L->head = NULL;
    }
    return L;
}

bool vazia(Lista *L){
    if(L->head == NULL){
        return true;
    }
    else return false;
}

void inserir(Lista *L, int x, Node *p, bool *deuCerto){
    Node *ax;
    bool ok;

    p->info = x;

    if(vazia(L) == true){
        p->next = NULL;
        L->head = p;
    }else{
        ax = L->head;
        while(ax->next != NULL){
            ax = ax->next;
        }
        ax->next = p;
        p->next = NULL;
    }
}

void controle(int i, Lista *l){
    bool ok;
    Node *n = newNode(&ok);
    if(ok == false){
        exit(1);
    }
    inserir(&l, i, n, &ok);
    if(ok == false){
        exit(1);
    }
}

int main() {
    int X, N, i;
    bool ok;
    Lista *lista;
    Node *node;

    lista = criar(&ok);
    if(ok == false){
        exit(1);
    }

    //scanf("%d %d", &X, &N);
    while (scanf("%d ", &i) != -1){
        controle(i, lista);
    }


}
