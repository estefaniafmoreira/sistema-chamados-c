#include <stdio.h>
#include <string.h>

#define MAX_CHAMADOS 100

typedef struct {
    int id;
    char solicitante[50];
    char descricao[200];
    int prioridade; // 1=baixa 2=media 3=alta
    int status;     // 0=aberto 1=andamento 2=resolvido
} Chamado;

int main() {
    Chamado chamados[MAX_CHAMADOS];
    int total = 0;
    int opcao;

    do {
        printf("\n=== SISTEMA DE CHAMADOS ===\n");
        printf("1 - Abrir chamado\n");
        printf("2 - Listar chamados\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: printf("Em construcao...\n"); break;
            case 2: printf("Em construcao...\n"); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
