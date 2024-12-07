#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Função para verificar a previsão do tempo
void verificar_previsao_tempo() {
    char cidade[50];
    int dia, mes;
    FILE *arquivo;

    // Lista de previsões fictícias
    const char *previsoes[4][2] = {
        {"Porto Alegre", "Chuva moderada"},
        {"Caxias do Sul", "Nublado"},
        {"Pelotas", "Ensolarado"},
        {"Santa Maria", "Tempo instável"}
    };

    printf("Informe a cidade (Porto Alegre, Caxias do Sul, Pelotas, Santa Maria): ");
    scanf(" %[^\n]", cidade);
    printf("Informe a data (dia e mês separados por espaço): ");
    scanf("%d %d", &dia, &mes);

    // Busca pela previsão
    int encontrada = 0;
    for (int i = 0; i < 4; i++) {
        if (strcmp(cidade, previsoes[i][0]) == 0) {
            printf("Previsão para %s no dia %02d/%02d: %s\n", cidade, dia, mes, previsoes[i][1]);

            // Salva no arquivo
            arquivo = fopen("previsao.txt", "a");
            if (arquivo != NULL) {
                fprintf(arquivo, "Cidade: %s, Data: %02d/%02d, Previsão: %s\n", cidade, dia, mes, previsoes[i][1]);
                fclose(arquivo);
            }
            encontrada = 1;
            break;
        }
    }

    if (!encontrada) {
        printf("Cidade não encontrada!\n");
    }
}

// Função para exibir informações sobre doações
void doar_para_vitimas() {
    printf("\n=== Doações para Vítimas das Chuvas ===\n");
    printf("1. Dinheiro: Doe através de contas oficiais do Governo ou ONGs confiáveis como a ACNUR.\n");
    printf("2. Alimentos: Entregue alimentos não perecíveis nos postos de arrecadação.\n");
    printf("3. Roupas e Cobertores: Doe roupas em bom estado e cobertores.\n");
    printf("4. Seja voluntário: Cadastre-se em organizações locais de assistência.\n");
    printf("\nVerifique locais confiáveis como Cruz Vermelha, Defesa Civil ou igrejas locais.\n");
}

// Função para enviar mensagens de apoio
int enviar_mensagens_de_apoio() {
	FILE *arq;
    int tipo_cidadao, anon;
    char nome[50] = "Usuario Anonimo";
    char mensagem[100];
    printf("\nVocê quer mandar uma mensagem:\n");
    printf("1. Normal\n2. Anonima\n");
    printf("Opção: ");
    scanf("%d", &anon);
    if(anon <1 || anon > 2) {
	printf("Opção inválida!\n");
	return 0;}
    if(anon == 1){
    	printf("\nDigite seu nome:");
    	scanf(" %[^\n]", nome);
    	printf("\n");
	}
	printf("\nDigite sua mensagem:");
    scanf(" %[^\n]", mensagem);
    printf("\nEscolha o tipo de cidadão para a mensagem de apoio:\n");
    printf("1. Criança\n2. Jovem\n3. Adulto\n");
    printf("Opção: ");
    scanf("%d", &tipo_cidadao);
    
    arq = fopen("mensagens_apoio.txt", "a");
    switch (tipo_cidadao) {
        case 1:
            printf("%s enviou uma mensagem para crianças: ' %s '\n", nome, mensagem);
            fprintf(arq,"%s enviou uma mensagem para crianças: ' %s '\n", nome, mensagem);
            break;
        case 2:
            printf("%s enviou uma mensagem para jovens: ' %s '\n", nome, mensagem);
            fprintf(arq,"%s enviou uma mensagem para jovens: ' %s '\n", nome, mensagem);
            break;
        case 3:
            printf("%s enviou uma mensagem para adultos: ' %s '\n", nome, mensagem);
            fprintf(arq,"%s enviou uma mensagem para adultos: ' %s '\n", nome, mensagem);
            break;
        default:
            printf("Opção inválida!\n");
    }
    fclose(arq);
    return 1;
}

// Função principal
int main() {
	setlocale(LC_ALL, "Portuguese");
    int opcao=0;
    while(opcao!=4){
        printf("\n=== Menu de Monitoramento de Chuvas no RS ===\n");
        printf("1. Verificar a Previsão do Tempo\n");
        printf("2. Doar para Vítimas das Chuvas\n");
        printf("3. Enviar Mensagens de Apoio\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                verificar_previsao_tempo();
                break;
            case 2:
                doar_para_vitimas();
                break;
            case 3:
                enviar_mensagens_de_apoio();
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
