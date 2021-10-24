#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct celula{
    int item;
    Cell *next;
};

Cell* criar_nova_celula(int num){
    Cell *a;

    a = (Cell*) malloc(sizeof(Cell));

    a->item = num;
    a->next = NULL;

    return a;
}

int acessar_valor_celula(Cell *a){
    return a->item;
}

int liberar_celula(Cell *a){
    if(a!=NULL){
        free(a);
        return 1;
    }
    return 0;
}

struct fila{
    Cell *inicio;
    Cell *fim;
};

FilaEncadeada* criar_nova_fila_encadeada(){
    FilaEncadeada *a;

    a = (FilaEncadeada*) malloc(sizeof(FilaEncadeada));

    a->inicio = NULL;
    a->fim = NULL;

    return a;
}

int verifica_fila_vazia(FilaEncadeada *a){
    if(a==NULL){
        return -1;
    }
    else if(a->inicio==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int enfileirar_novo_item(FilaEncadeada *a, int num){
    Cell *nova;

    if(a!=NULL){
        nova = criar_nova_celula(num);

        if(a->inicio == NULL){
            a->inicio = a->fim = nova;
            return 1;
        }
        else{
            a->fim->next = nova;
            a->fim = nova;
            return 1;
        }
    }
    return 0;
}

int enfileirar_nova_celula(FilaEncadeada *a, Cell *b){
    if(a!=NULL && b!=NULL){
        if(a->inicio == NULL){
            a->inicio = a->fim = b;
            return 1;
        }
        else{
            a->fim->next = b;
            a->fim = b;
            return 1;
        }
    }
    return 0;
}

int desenfileirar_item(FilaEncadeada *a){
    Cell *primeiroElemento;
    int valor;

    if(verifica_fila_vazia(a)!=1 && verifica_fila_vazia(a)!=-1){
        primeiroElemento = a->inicio;
        a->inicio = primeiroElemento->next;

        valor = primeiroElemento->item;

        liberar_celula(primeiroElemento);
    }
    return valor;
}

Cell* desenfileirar_celula(FilaEncadeada *a){
    Cell *primeiroElemento;

    if(verifica_fila_vazia(a)!=1 && verifica_fila_vazia(a)!=-1){
        primeiroElemento = a->inicio;
        a->inicio = primeiroElemento->next;

        primeiroElemento->next = NULL;
    }
    return primeiroElemento;
}

void imprimir_conteudo_fila(FilaEncadeada *a){
    Cell *aux;

    if(verifica_fila_vazia(a)!=1 && verifica_fila_vazia(a)!=-1){
        aux = a->inicio;
        while(aux!=NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }
    }
}

void imprimir_conteudo_com_endereco_fila(FilaEncadeada *a){
    Cell *aux;

    if(verifica_fila_vazia(a)!=1 && verifica_fila_vazia(a)!=-1){
        aux = a->inicio;
        while(aux!=NULL){
            printf("Endereco: %x / Item: %d\n", aux, aux->item);

            aux = aux->next;
        }
    }
}

int liberar_fila(FilaEncadeada *a){
    Cell *aux;

    if(a!=NULL){
        if(verifica_fila_vazia(a)==1){
            free(a);
            return 1;
        }
        else{
            aux = a->inicio;

            while(aux!=NULL){
                a->inicio = aux->next;

                free(aux);

                aux = a->inicio;
            }
            free(a);

            return 1;
        }
    }
    return 0;
}

int contagem_elementos_fila(FilaEncadeada *a){
    int cont = 0;
    Cell *aux;

    if(a!=NULL){
        if(verifica_fila_vazia(a)==1){
            return cont;
        }
        else{
            aux = a->inicio;
            while(aux!=NULL){
                cont += 1;
                aux = aux->next;
            }
            return cont;
        }
    }
    return -1;
}

FilaEncadeada* concatenar_duas_filas(FilaEncadeada *a, FilaEncadeada *b){
    FilaEncadeada *c;
    Cell *auxA;

    if(a!=NULL && b!=NULL){
        c = criar_nova_fila_encadeada();

        if(verifica_fila_vazia(a)!=1){
            auxA = a->inicio;
            while(auxA!=NULL){
                enfileirar_novo_item(c, auxA->item);

                auxA = auxA->next;

            }
        }
        if(verifica_fila_vazia(b)!=1){
            auxA = b->inicio;
            while(auxA!=NULL){
                enfileirar_novo_item(c, auxA->item);

                auxA = auxA->next;
            }
        }
    }
    return c;
}

void ordenar_crescente_fila_encadeada(FilaEncadeada *a){
    Cell *proximo, *atual;
    int aux;

    if(verifica_fila_vazia(a)!=1 && verifica_fila_vazia(a)!=-1){
        atual = a->inicio;
        while(atual != NULL){
            proximo = atual->next;
            while(proximo!=NULL){
                if(atual->item > proximo->item){
                    aux = proximo->item;

                    proximo->item = atual->item;

                    atual->item = aux;
                }
                proximo = proximo->next;
            }
            atual = atual->next;
        }
    }
}

