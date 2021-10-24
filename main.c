#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    char escolha;
    FilaEncadeada *a;
    int num, repet, i;



    scanf("%d", &repet);

    for(i=0; i<repet; i++){
        a = criar_nova_fila_encadeada();
        while(1){
            scanf("%c", &escolha);

            if(escolha == 'I'){
                scanf("%d", &num);
                if(contagem_elementos_fila(a)<100){
                    enfileirar_novo_item(a, num);
                }
            }
            else if(escolha == 'R'){
                desenfileirar_item(a);
            }
            else if(escolha == 'K'){
                if(contagem_elementos_fila(a)<=100){
                    printf("Total elementos: %d\n", contagem_elementos_fila(a));
                }
            }
            else if(escolha == 'V'){
                if(verifica_fila_vazia(a)!=1){
                    printf("Fila nao vazia!\n");
                }
                else{
                    printf("Fila vazia!\n");
                }
            }
            else if(escolha == 'C'){
                if(contagem_elementos_fila(a)==100){
                    printf("Fila cheia!\n");
                }
                if(contagem_elementos_fila(a)<100){
                    printf("Fila nao cheia!\n");
                }
            }
            else if(escolha == 'P'){
                if(contagem_elementos_fila(a)<=100){
                    imprimir_conteudo_fila(a);
                }
            }
            else if(escolha == 'X'){
                break;
            }
        }
        printf("\n\n");
        liberar_fila(a);
    }



    return 0;
}
