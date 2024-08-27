#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *top = NULL;

void push(int n);
void pop();
void imprimir();

int main(){
    int n, opcao;
    do{
        printf("\n\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n4 - Exit\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Entre com um valor a ser empilhado: ");
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                imprimir();
                break;
            case 4:
                printf("Saindo...\n");
                break;
                return 0;
        }
    } while(opcao != 4);
}

void push(int n){
    printf("\n************************\n");
    printf("*******Empilhando******* %d\n", n);
    celula *novo = (celula *) malloc(sizeof(celula));
    if (novo == NULL) {
        printf("Erro de alocação de memória\n");
        return;
    }
    novo->dado = n;
    novo->prox = top;
    top = novo;
}

void pop(){
    if (top == NULL) {
        printf("Pilha vazia\n");
        return;
    }
    celula *temp = top;
    top = top->prox;
    printf("Desempilhando %d\n", temp->dado);
    free(temp);
}

void imprimir(){
    if (top == NULL) {
        printf("Pilha vazia\n");
        return;
    }
    celula *temp = top;
    printf("Elementos da pilha:\n");
    while (temp != NULL) {
        printf("%d\n", temp->dado);
        temp = temp->prox;
    }
}