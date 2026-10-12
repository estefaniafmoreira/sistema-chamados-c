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

void abrir_chamado(Chamado chamados[], int *total) {
    Chamado c;
    c.id = *total + 1;

    getchar();
    printf("Nome do solicitante: ");
    fgets(c.solicitante, 50, stdin);
    c.solicitante[strcspn(c.solicitante, "\n")] = 0;

    printf("Descricao do problema: ");
    fgets(c.descricao, 200, stdin);
    c.descricao[strcspn(c.descricao, "\n")] = 0;

    printf("Prioridade (1=baixa 2=media 3=alta): ");
    scanf("%d", &c.prioridade);

    c.status = 0;
    chamados[*total] = c;
    (*total)++;

    printf("Chamado %d aberto com sucesso!\n", c.id);
}
 
void listar_chamados(Chamado chamados[], int total) {
    if (total == 0) {
        printf("Nenhum chamado registrado.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\n--- Chamado %d ---\n", chamados[i].id);
        printf("Solicitante: %s\n", chamados[i].solicitante);
        printf("Descricao: %s\n", chamados[i].descricao);
        const char *prioridades[] = {"", "Baixa", "Media", "Alta"};
        const char *status[] = {"Aberto", "Em andamento", "Resolvido"};

        printf("Prioridade: %s\n", prioridades[chamados[i].prioridade]);
        printf("Status: %s\n", status[chamados[i].status]);
    }
}

void atualizar_status(Chamado chamados[], int total) {
    int id, novo;

    if (total == 0) {
        printf("Nenhum chamado registrado.\n");
        return;
    }

    printf("Numero do chamado: ");
    scanf("%d", &id);

    if (id < 1 || id > total) {
        printf("Chamado nao encontrado.\n");
        return;
    }

    printf("Novo status (0=Aberto 1=Em andamento 2=Resolvido): ");
    scanf("%d", &novo);


    if (novo < 0 || novo > 2) {
        printf("Status invalido.\n");
        return;
    }

    chamados[id - 1].status = novo;

    printf("Status do chamado %d atualizado!\n", id);
}



int main() {
    Chamado chamados[MAX_CHAMADOS];
    int total = 0;
    int opcao;

    do {
        printf("\n=== SISTEMA DE CHAMADOS ===\n");
        printf("1 - Abrir chamado\n");
        printf("2 - Listar chamados\n");
        printf("3 - Atualizar status\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: abrir_chamado(chamados, &total); break;
            case 2: listar_chamados(chamados, total); break;
            case 3: atualizar_status(chamados, total); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}