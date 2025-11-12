// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.

//============================================
//============================================
//inicio do código


#include <stdio.h>
#include <string.h>


 //cria a estrutura de territorios: início.
   typedef struct {
                    char nome [30];
                    char cor [10];
                    int tropas;
   } territorio;
   //criar estrutura: fim.
   int cont = 0;

int main()

{
    //criar o vetor
    territorio vetorTer[5];
    //vetor criado

    int escolha=0;
    int cont =0;

    do{
    escolha=0;
    printf("============== W A R ============ \n \n");
    printf("================================= \n \n");
    printf("============== MENU ============= \n \n \n");
    printf("==> 1) APRESENTAR TERRITÓRIOS:\n");
    printf("==> 2) INCLUIR TERRITÓRIOS:\n");
    printf("==> 3) ENCERRAR:\n");

    fflush(stdin);
    scanf("%d", &escolha);
    switch(escolha){
                case(1):
                     //inicar exibicao dos dados dos territorios
                        printf("======================= W A R ===================== \n \n");
                        printf(" ============== TERRITORIOS DEFINIDOS!!!============ \n \n");
                        for(cont=1;cont<=5;cont++){
                        printf("TERRITORIO {%d}:\n NOME: %s COR: %s COM %d TROPAS\n \n",cont,vetorTer[cont].nome, vetorTer[cont].cor, vetorTer[cont].tropas);
                                                  }
                        break;

                     //fim do laço for  exibir dados
                case(2):                       
                        cont=1;
                        while(cont<=5){
                    //laço para obter os dados.
                        for(cont=1;cont<=5;cont++){
                        printf("============== W A R ============\n\n");
                    //obter nome
                        printf("DIGITE O NOME DO TERRITORIO:\n\n");
                        fflush(stdin);
                        fgets(vetorTer[cont].nome,30,stdin);
                        printf("O NOME DEFINIDO FOI: %s \n \n",vetorTer[cont].nome);

                    //obter cor
                        printf("DIGITE A COR DO TERRITORIO:\n");
                        fgets(vetorTer[cont].cor, 10, stdin);
                        printf("A COR DEFINIDA FOI: %s \n ",vetorTer[cont].cor);

                    //obter numero tropas
                        fflush(stdin);
                        printf("DIGITE O NUMERO DE TROPAS NO TERRITORIO:\n");
                        scanf(" %d", &vetorTer[cont].tropas);
                        printf("O NUMERO DE TROPAS DEFINIDO FOI: %d \n \n \n ",vetorTer[cont].tropas);
                        fflush(stdin);
                        }

                        break;
                    //fim do laço dados obtidos.
    }



    }
    }while(escolha!=3);
    return 0;
    }








//fim do codigo
//====================================
//====================================










// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
