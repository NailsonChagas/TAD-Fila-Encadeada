//TAD Cell
typedef struct celula Cell;

Cell* criar_nova_celula(int num);
int acessar_valor_celula(Cell *a);
int liberar_celula(Cell *a);

//TAD fila encadeada
typedef struct fila FilaEncadeada;

FilaEncadeada* criar_nova_fila_encadeada();
int verifica_fila_vazia(FilaEncadeada *a);
int enfileirar_novo_item(FilaEncadeada *a, int num);
int enfileirar_nova_celula(FilaEncadeada *a, Cell *b);
int desenfileirar_item(FilaEncadeada *a);
Cell* desenfileirar_celula(FilaEncadeada *a);
void imprimir_conteudo_fila(FilaEncadeada *a);
void imprimir_conteudo_com_endereco_fila(FilaEncadeada *a);
int liberar_fila(FilaEncadeada *a);
int contagem_elementos_fila(FilaEncadeada *a);
FilaEncadeada* concatenar_duas_filas(FilaEncadeada *a, FilaEncadeada *b);
void ordenar_crescente_fila_encadeada(FilaEncadeada *a);

