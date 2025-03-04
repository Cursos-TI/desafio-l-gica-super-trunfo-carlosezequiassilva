#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //VARIAVEIS

    char pais1[20], pais2[20], estado1[10], estado2[10], nome_cidade1[50],nome_cidade2[50], codigo_cidade1[20], codigo_cidade2[20];
    unsigned long int populacao1, populacao2;
    int numeros_pontos_turisticos1, numeros_pontos_turisticos2, escolha_inicio, escolha_comparacao, opcoes_comparacao1, opcoes_comparacao2;
    float area1, area2, pib1, pib2, densidade_populacional1, densidade_populacional2, pib_per_capita1, pib_per_capita2;

    int pontos_cidade1 = 1, pontos_cidade2 = 1;
    //INICIO DO JOGO

    printf("***** JOGO SUPER TRUNFO *****\n");
    printf("1. INICIAR\n");
    printf("2. REGRAS\n");
    printf("3. SAIR\n");
    printf("Entre com a opção!\n");
    scanf("%d", &escolha_inicio);

    switch (escolha_inicio)
    {
    case 1:
        //FUNÇÕES PARA CADASTRAS AS INFORMAÇÕES DAS CIDADES

        printf("CADASTRO DAS CARTAS\n");

        //===================PRIMEIRA CARTA===================

        printf("\n***** ENTRE COM OS DADOS DA PRIMEIRA CIDADE ***** \n");

        //PAIS 
        printf("Digite o primeiro país:");
        scanf("%s", &pais1);
        
        //ESTADO 
        printf("Digite o estado da primeria cidade:");
        scanf("%s", &estado1);

        //CÓDIGO DA CIDADE
        printf("Digite o código da primeira cidade:");
        scanf("%s", &codigo_cidade1);

        // Limpa o buffer para evitar problemas com fgets()
        getchar();

        //NOME DA CIDADE
        printf("Digite o nome da primeira cidade:");
        fgets(nome_cidade1, sizeof(nome_cidade1), stdin);
        nome_cidade1[strcspn(nome_cidade1, "\n")] = '\0';
        //scanf("%s", &nome_cidade);

        //POPULAÇAO DA CIDADE
        printf("Digite a população da primeira cidade:");
        scanf("%lu", &populacao1);

        //NÚMERO DE PONTOS TURÍSTICOS DA CIDADE
        printf("Número de pontos turísticos da primeira cidade:");
        scanf("%d", &numeros_pontos_turisticos1);

        //PIB DA CIDADE
        printf("Digite o PIB da primeira cidade:");
        scanf("%f", &pib1);

        //ÁREA TOTAL DA CIDADE
        printf("Digite a área total da primeira cidade:");
        scanf("%f", &area1);

        //===================SEGUNDA CARTA===================

        printf("\n***** ENTRE COM OS DADOS DA SEGUNDA CIDADE ***** \n");

        //PAIS 
        printf("Digite o segundo país:");
        scanf("%s", &pais2);

        //ESTADO
        printf("Digite o estado da segunda cidade:");
        scanf(" %s", &estado2);

        //CÓDIGO DA CIDADE
        printf("Digite o código da segunda cidade:");
        scanf("%s", &codigo_cidade2);

        // Limpa o buffer para evitar problemas com fgets()
        getchar();

        //NOME DA CIDADE
        printf("Digite o nome da segunda cidade:");
        fgets(nome_cidade2, sizeof(nome_cidade2), stdin);
        nome_cidade2[strcspn(nome_cidade2, "\n")] = '\0';
        //scanf("%s", &nome_cidade);

        //POPULAÇAO DA CIDADE
        printf("Digite a população da segunda cidade:");
        scanf("%lu", &populacao2);

        //NÚMERO DE PONTOS TURÍSTICOS DA CIDADE
        printf("Número de pontos turísticos da segunda cidade:");
        scanf("%d", &numeros_pontos_turisticos2);

        //PIB DA CIDADE
        printf("Digite o PIB da segunda cidade:");
        scanf("%f", &pib2);

        //ÁREA TOTAL DA CIDADE
        printf("Digite a área total da segunda cidade:");
        scanf("%f", &area2);
        

        //CALCULOS DAS DENSIDADES E PIB PER CAPITA

        //=====CIDADE 1=====
        densidade_populacional1 = populacao1 / area1;
        pib_per_capita1 = pib1 / populacao1;

        //=====CIDADE 2=====

        densidade_populacional2 = populacao2 / area2;
        pib_per_capita2 = pib2 / populacao2;

        // VERIFICA SE NENHUM ATRIBUTO É IGUAL A ZERO

        if (populacao1 || populacao2 || pib1 || pib2 || area1 || area2 != 0)
        {
            // ESCOLHA DOS ATRIBUTOS PARA COMPARAÇÃO
            printf("\n===================================================================================================\n");
            printf("1. Escolher dois atributos das cartas para comparação.\n");
            printf("2. Escolha aleatória.\n");
            printf("\n*** Escolha uma das opções! ***\n");
            scanf("%d", &escolha_comparacao);
            
            if (escolha_comparacao == 1)
            {
                printf("Escolha o atributo para comparação!\n ");
                printf("1. População.\n");
                printf("2. PIB.\n");
                printf("3. Área total em km².\n");
                printf("4. Densidade populacional.\n");
                printf("5. PIB per capita.\n");
                scanf("%d", &opcoes_comparacao1);

                // COMPARAÇÃO DOS ATRIBUTOS E ATRIBUIÇÃO DE PONTOS
                if ((opcoes_comparacao1 == 1 && populacao1 > populacao2) ||
                (opcoes_comparacao1 == 2 && pib1 > pib2) ||
                (opcoes_comparacao1 == 3 && area1 > area2) ||
                (opcoes_comparacao1 == 4 && densidade_populacional1 < densidade_populacional2) ||
                (opcoes_comparacao1 == 5 && pib_per_capita1 > pib_per_capita2)) 
                {
                    pontos_cidade1++;
                } else {
                    pontos_cidade2++;
                }

                printf("Escolha outro atributo para mais uma comparação!\n ");
                printf("1. População.\n");
                printf("2. PIB.\n");
                printf("3. Área total em km².\n");
                printf("4. Densidade populacional.\n");
                printf("5. PIB per capita.\n");
                scanf("%d", &opcoes_comparacao2);
                if (opcoes_comparacao1 == opcoes_comparacao2)
                {
                    printf("### Não é permitido a comparação de dois atributos iguais! ###");
                }else
                {
                    if ((opcoes_comparacao2 == 1 && populacao1 > populacao2) ||
                    (opcoes_comparacao2 == 2 && pib1 > pib2) ||
                    (opcoes_comparacao2 == 3 && area1 > area2) ||
                    (opcoes_comparacao2 == 4 && densidade_populacional1 < densidade_populacional2) ||
                    (opcoes_comparacao2 == 5 && pib_per_capita1 > pib_per_capita2)) 
                    {
                        pontos_cidade1++;
                    } else {
                        pontos_cidade2++;
                    }
                }
            } else if (escolha_comparacao == 2)  // ESCOLHA ALEATÓRIA
            {
                //GERA UM NÚMERO ALEATÓRIO
                srand(time(0));
                opcoes_comparacao1 = rand() % 5 + 1; // GERA UM NÚMERO DE 1 A 5;
                opcoes_comparacao2 = rand() % 5 + 1;

                if ((opcoes_comparacao1 == 1 && populacao1 > populacao2) ||
                (opcoes_comparacao1 == 2 && pib1 > pib2) ||
                (opcoes_comparacao1 == 3 && area1 > area2) ||
                (opcoes_comparacao1 == 4 && densidade_populacional1 < densidade_populacional2) ||
                (opcoes_comparacao1 == 5 && pib_per_capita1 > pib_per_capita2)) 
                {
                    pontos_cidade1++;
                } else {
                    pontos_cidade2++;
                }
            
                if (opcoes_comparacao1 != opcoes_comparacao2)
                {
                    if ((opcoes_comparacao2 == 1 && populacao1 > populacao2) ||
                    (opcoes_comparacao2 == 2 && pib1 > pib2) ||
                    (opcoes_comparacao2 == 3 && area1 > area2) ||
                    (opcoes_comparacao2 == 4 && densidade_populacional1 < densidade_populacional2) ||
                    (opcoes_comparacao2 == 5 && pib_per_capita1 > pib_per_capita2)) 
                    {
                        pontos_cidade1++;
                    } else {
                        pontos_cidade2++;
                    }
                    printf("\n========== Atributos escolhidos aleatoriamente: ==========\n");
                    printf("\n1º Atributo: %d\n", opcoes_comparacao1);
                    printf("2º Atributo: %d\n", opcoes_comparacao2);
                    printf("\n============================================\n");
                    printf("1. População.\n");
                    printf("2. PIB.\n");
                    printf("3. Área total em km².\n");
                    printf("4. Densidade populacional.\n");
                    printf("5. PIB per capita.\n");
                    printf("\n============================================\n");
                }else
                {
                    printf("##### TENTE DE NOVO, O COMPUTADOR ESCOLHEU DUAS OPÇÕES IGUAIS! #####");
                }
            }

            // MOSTRANDO RESULTADO

            if (pontos_cidade1 > pontos_cidade2)
            {
                printf("\n***** DADOS DA CARTA VENCEDORA ***** \n");
                printf("Pontos cartas 1: %d\n Pontos cartas 2: %d\n", pontos_cidade1 - 1, pontos_cidade2 - 1);

                printf("\n===================================================================================================\n");
                printf("\nPaís: %s\n", pais1);
                printf("\nEstado: %s\n", estado1);
                printf("\nCódigo da cidade: %s\n", codigo_cidade1);
                printf("\nNome da cidade: %s\n", nome_cidade1);
                printf("\nPopulação da cidade: %lu\n", populacao1);
                printf("\nPontos turísticos da cidade: %d\n", numeros_pontos_turisticos1);
                printf("\nPIB da cidade: %.2f\n", pib1);
                printf("\nÁrea total em km² da cidade: %.2f\n", area1);
                printf("\nDensidade populacional da cidade: %.2f\n", densidade_populacional1);
                printf("\nPIB per capita da cidade: %.2f\n", pib_per_capita1);
                printf("\n===================================================================================================\n");
            } else if (pontos_cidade1 < pontos_cidade2)
            {
                printf("\n***** DADOS DA CARTA VENCEDORA ***** \n");
                printf("Pontos cartas 1: %d\n Pontos cartas 2: %d\n", pontos_cidade1 - 1, pontos_cidade2 - 1);

                printf("\n===================================================================================================\n");
                printf("\nPaís: %s\n", pais2);
                printf("\nEstado: %s\n", estado2);
                printf("\nCódigo da cidade: %s\n", codigo_cidade2);
                printf("\nNome da cidade: %s\n", nome_cidade2);
                printf("\nPopulação da cidade: %lu\n", populacao2);
                printf("\nPontos turísticos da cidade: %d\n", numeros_pontos_turisticos2);
                printf("\nPIB da cidade: %.2f\n", pib2);
                printf("\nÁrea total em km² da cidade: %.2f\n", area2);
                printf("\nDensidade populacional da cidade: %.2f\n", densidade_populacional2);
                printf("\nPIB per capita da cidade: %.2f\n", pib_per_capita2);
                printf("\n===================================================================================================\n");
            } else if(pontos_cidade1 == pontos_cidade2){
                // MOSTRA OS DADOS DAS DUAS CARTAS CASO HOUVER UM EMPATE
                printf("\n##### Houve um empate! #####\n");

                printf("Pontos cartas 1: %d\n Pontos cartas 2: %d\n", pontos_cidade1 - 1, pontos_cidade2 - 1);

                printf("\n***** DADOS DA CARTA 1 ***** \n");

                printf("\n===================================================================================================\n");
                printf("\nPaís: %s\n", pais1);
                printf("\nEstado: %s\n", estado1);
                printf("\nCódigo da cidade: %s\n", codigo_cidade1);
                printf("\nNome da cidade: %s\n", nome_cidade1);
                printf("\nPopulação da cidade: %lu\n", populacao1);
                printf("\nPontos turísticos da cidade: %d\n", numeros_pontos_turisticos1);
                printf("\nPIB da cidade: %.2f\n", pib1);
                printf("\nÁrea total em km² da cidade: %.2f\n", area1);
                printf("\nDensidade populacional da cidade: %.2f\n", densidade_populacional1);
                printf("\nPIB per capita da cidade: %.2f\n", pib_per_capita1);
                printf("\n===================================================================================================\n");

                printf("\n***** DADOS DA CARTA 2 ***** \n");

                printf("\n===================================================================================================\n");
                printf("\nPaís: %s\n", pais2);
                printf("\nEstado: %s\n", estado2);
                printf("\nCódigo da cidade: %s\n", codigo_cidade2);
                printf("\nNome da cidade: %s\n", nome_cidade2);
                printf("\nPopulação da cidade: %lu\n", populacao2);
                printf("\nPontos turísticos da cidade: %d\n", numeros_pontos_turisticos2);
                printf("\nPIB da cidade: %.2f\n", pib2);
                printf("\nÁrea total em km² da cidade: %.2f\n", area2);
                printf("\nDensidade populacional da cidade: %.2f\n", densidade_populacional2);
                printf("\nPIB per capita da cidade: %.2f\n", pib_per_capita2);
                printf("\n===================================================================================================\n");
            }
        }else{
            printf("===== Os valores dos atributos das cidades devem ser diferentes de zero! =====");
        }
        break;
    case 2:
        printf("========== Regras do jogo ==========\n");
        printf("Jogo SuperTrunfo, uma batalha com o tema de países\n");
        printf("Cadastre duas cartas e prepare-se para a batalha\n");
        printf("Escolha dois dos atributos cadastrados, ou deixe que a sorte decida\n");
        printf("No final a carta vencedora será a única mostrada\n");
        printf("As opções para seguir o jogo são númeradas, não escolha números que não são parte das opções, ou então o jogo irá iniciar novamente\n");
        printf("OBS: Em 'código da cidade', os valores podem ser algo do tipo A01, A02, A03, A04, B01 etc...");
        break;
    case 3:
        printf("***** JOGO ENCERRADO! *****");
        break;
    default:
        printf("##### ESCOLHA UMA OPÇÃO VÁLIDA! #####");
        break;
    }

    return 0;
}
