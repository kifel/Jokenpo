#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define STRAM 30
#define STRAM2 35

int computador, count, jw, pw, emt, espadaj, espadap; // variaveis globais que server para todas as funçoes
char res, jogador;                                    // variaveis globais que server para todas as funçoes

int tecla() // função que reconhece as setinhas do teclado
{
    int varTecla;
    while (1)
    {
        if (kbhit())
        {
            varTecla = getch();
            return varTecla;
        }
    }
}

void criarmenulinhasuperior()
{
    int i;
    printf("\t\t%c", 201);
    for (i = 0; i < STRAM; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n", 187);
}

void criarmenulinharodape()
{
    int i;
    printf("\t\t%c", 200);
    for (i = 0; i < STRAM; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n", 188);
}

void criarmenulinhameio()
{

    int i;
    printf("\t\t%c", 204);
    for (i = 0; i < STRAM; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n", 185);
}

void menujoganovamentetop()
{
    int i;
    printf("\t%c", 218);
    for (i = 0; i < STRAM2; i++)
    {
        printf("%c", 196);
    }
    printf("%c\n", 191);
}

void menujoganovamentedown()
{
   int i;
    printf("\t%c", 192);
    for (i = 0; i < STRAM2; i++)
    {
        printf("%c", 196);
    }
    printf("%c\n", 217); 
}

void menu()
{

    int c;
    int lugar = 0; // variavel que mostra qual parte do menu o jogador se encontra
    system("cls"); // limpa a tela do console

    criarmenulinhasuperior();
    printf("\t\t%c            Jokenpo           %c\n", 186, 186);
    criarmenulinhameio();
    printf("\t\t%c          -> Start            %c\n", 186, 186);
    printf("\t\t%c             QUIT             %c\n", 186, 186);
    criarmenulinharodape();

    while (1)
    {
        if (kbhit())
        {
            system("cls");
            c = tecla();

            if (c == 80)
            { //apertou para baixo
                lugar++;
                if (lugar > 2)
                    lugar = 0;
            }
            if (c == 72)
            { //apertou para cima
                lugar--;
                if (lugar < 0)
                    lugar = 2;
            }
            if (c == 75)
            { //apertou para direita
                lugar++;
                if (lugar > 2)
                    lugar = 0;
            }
            if (c == 77)
            { //apertou para esquerda
                lugar--;
                if (lugar < 0)
                    lugar = 2;
            }
            if (c == 13)
            {                   //apertou [enter]
                if (lugar == 0) //inicia o jogo quando é escolhida o opção start
                {
                    criarmenulinhasuperior();
                    printf("\t\t%c       INICIANDO O JOGO!      %C\n", 186, 186);
                    criarmenulinharodape();
                    Sleep(2800);
                    system("cls");
                    jogo();
                    break;
                }
                else if (lugar == 1) //fecha o programa quando é escolhida a opçao sair
                {
                    system("cls"); // limpa a tela do console
                    criarmenulinhasuperior();
                    printf("\t\t%c       SAINDO DO PROGRAMA!    %C\n", 186, 186);
                    criarmenulinharodape();
                    Sleep(1000); // espera 1 s
                    exit(0);     // fecha o programa
                }
            }
            if (lugar == 0) // ao utilizar as setas do teclado a variavel lugar trocar de valor
            {               // dependendo do valor muda oque é mostrado na tela
                criarmenulinhasuperior();
                printf("\t\t%c            Jokenpo           %c\n", 186, 186);
                criarmenulinhameio();
                printf("\t\t%c          -> Start            %c\n", 186, 186);
                printf("\t\t%c             QUIT             %c\n", 186, 186);
                criarmenulinharodape();
            }
            if (lugar == 1)
            {
                criarmenulinhasuperior();
                printf("\t\t%c            Jokenpo           %c\n", 186, 186);
                criarmenulinhameio();
                printf("\t\t%c             Start            %c\n", 186, 186);
                printf("\t\t%c          -> QUIT             %c\n", 186, 186);
                criarmenulinharodape();
            }
            if (lugar == 2)
            {
                menu();
            }
        }
    }
}

void opcaoE() // função que mostra as opções de escolha
{
    printf("\t1. PEDRA\n");
    printf("\t2. PAPEL\n");
    printf("\t3. TESOURA\n");
    printf("\t4. ESPADA\n");
}

void jogo(void)
{
    do
    {
        printf("rodada %d/5\n", count); // contador do numero de rodadas
        criarmenulinhasuperior();
        printf("\t\t%c            Jokenpo           %c\n", 186, 186);
        criarmenulinharodape();
        opcaoE(); // função da opção de escolha
        printf("\tDigite a op%c%co desejada: ", 135, 132);
        jogador = getch();
        system("cls");

        if (jogador == '1') // mostra a escolha do jogador
        {
            criarmenulinhasuperior();
            printf("\t\t%c     Jogador escolheu PEDRA   %c\n", 186, 186);
        }
        else if (jogador == '2')
        {
            criarmenulinhasuperior();
            printf("\t\t%c     Jogador escolheu PAPEL   %c\n", 186, 186);
        }
        else if (jogador == '3')
        {
            criarmenulinhasuperior();
            printf("\t\t%c   Jogador escolheu TESOURA   %c\n", 186, 186);
        }
        else if (jogador == '4')
        {
            if (espadaj < 1)
            {
                criarmenulinhasuperior();
                printf("\t\t%c    Jogador escolheu ESPADA   %c\n", 186, 186);
            }
            espadaj++;
            if (espadaj > 1) //Evitar que o jogador utilize a espada mais de 1 vez
            {
                system("cls");
                criarmenulinhasuperior();
                printf("\t\t%c        op%c%co inv%clida        %c\n", 186, 135, 132, 160, 186);
                printf("\t\t%c      Espada j%c utilizada     %c\n", 186, 160, 186);
                criarmenulinharodape();
                jogador = 0; // jogador = 0 entrar um loop para refazer as escolhas
            }
        }
        else
        {
            criarmenulinhasuperior();
            printf("\t\t%c        op%c%co inv%clida        %c\n", 186, 135, 132, 160, 186);
            criarmenulinharodape();
            jogador = 0;
            0; // jogador = 0 entrar um loop para refazer as escolhas
        }

        while (jogador == 0) // loop para rafazer as escolhas do jogador caso seja invalida
        {
            printf("\nDigite a opcao desejada: \n");
            opcaoE();
            jogador = getch();
            system("cls");
            if (jogador == '1') // mostra a escolha do jogador
            {
                criarmenulinhasuperior();
                printf("\t\t%c     Jogador escolheu PEDRA   %c\n", 186, 186);
            }
            else if (jogador == '2')
            {
                criarmenulinhasuperior();
                printf("\t\t%c     Jogador escolheu PAPEL   %c\n", 186, 186);
            }
            else if (jogador == '3')
            {
                criarmenulinhasuperior();
                printf("\t\t%c   Jogador escolheu TESOURA   %c\n", 186, 186);
            }
            else if (jogador == '4')
            {
                if (espadaj < 1)
                {
                    criarmenulinhasuperior();
                    printf("\t\t%c    Jogador escolheu ESPADA   %c\n", 186, 186);
                }
                espadaj++;
                if (espadaj > 1) //Evitar que o jogador utilize a espada mais de 1 vez
                {
                    system("cls");
                    criarmenulinhasuperior();
                    printf("\t\t%c        op%c%co inv%clida        %c\n", 186, 135, 132, 160, 186);
                    printf("\t\t%c      Espada j%c utilizada     %c\n", 186, 160, 186);
                    criarmenulinharodape();
                    jogador = 0; // jogador = 0 entrar um loop para refazer as escolhas
                }
            }
            else
            {
                criarmenulinhasuperior();
                printf("\t\t%c        op%c%co inv%clida        %c\n", 186, 135, 132, 160, 186);
                criarmenulinharodape();
                jogador = 0;
                0; // jogador = 0 entrar um loop para refazer as escolhas
            }
        }
        // lógica do computador
        srand(time(NULL));
        computador = ("%d", rand() % 4 + 1); // computador escolhe um numero aleatorio

        if (computador == 1) // mostra a escolha do computador
        {
            printf("\t\t%c   Computador escolheu PEDRA  %c\n", 186, 186);
            criarmenulinharodape();
        }
        else if (computador == 2)
        {
            printf("\t\t%c   Computador escolheu PAPEL  %c\n", 186, 186);
            criarmenulinharodape();
        }
        else if (computador == 3)
        {
            printf("\t\t%c  Computador escolheu TESOURA %c\n", 186, 186);
            criarmenulinharodape();
        }
        else if (computador == 4)
        {
            if (espadap < 1)
            {
                printf("\t\t%c  Computador escolheu ESPADA  %c\n", 186, 186);
                criarmenulinharodape();
            }
            espadap++;
            if (espadap > 1)
            {
                computador = 0; // computador = 0 entrar um loop para refazer as escolhas
            }
        }
        else
        {
            criarmenulinhasuperior();
            printf("\t\t%c        op%c%co inv%clida        %c\n", 186, 135, 132, 160, 186);
            criarmenulinharodape();
        }

        while (computador == 0) // loop para rafazer as escolhas do computador caso seja invalida
        {
            srand(time(NULL));
            computador = ("%d", rand() % 4 + 1);

            if (computador == 1) // mostra a escolha do computador
            {
                printf("\t\t%c   Computador escolheu PEDRA  %c\n", 186, 186);
                criarmenulinharodape();
            }
            else if (computador == 2)
            {
                printf("\t\t%c   Computador escolheu PAPEL  %c\n", 186, 186);
                criarmenulinharodape();
            }
            else if (computador == 3)
            {
                printf("\t\t%c  Computador escolheu TESOURA %c\n", 186, 186);
                criarmenulinharodape();
            }
            else if (computador == 4)
            {
                if (espadap < 1)
                {
                    printf("\t\t%c  Computador escolheu ESPADA  %c\n", 186, 186);
                    criarmenulinharodape();
                }
                espadap++;
                if (espadap > 1)
                {
                    computador = 0; // computador = 0 entrar um loop para refazer as escolhas
                }
            }
            else
            {
                criarmenulinhasuperior();
                printf("\t\t%c        op%c%co inv%clida        %c\n", 186, 135, 132, 160, 186);
                criarmenulinharodape();
            }
        }

        vencedor(); //função que determina o vencedor

        count++;          // aumenta o numero da jogada
        Sleep(500);       // programa esperar 0,5s antes de continuar
    } while (count <= 5); // loop do programa ira acabar quando ocorrer 5 rodadas
}

void vencedor(void)
{
    //lógica para determinar o vencedor
    if (jogador == '1' && computador == 1 || jogador == '2' && computador == 2 || jogador == '3' && computador == 3 || jogador == '4' && computador == 4)
    {
        printf("\n\tEMPATE\n\n");
        emt++; //contador do numero de empates
    }
    else if ((jogador == '1' && computador == 3) || (jogador == '2' && computador == 1) ||
             (jogador == '3' && computador == 2) || (jogador == '4' && computador == 3) || (jogador == '4' && computador == 2) || (jogador == '4' && computador == 1))
    {
        printf("\n\tJOGADOR VENCEU\n\n\n");
        jw++; // contador do numero de vitorias do jogador
    }
    else
    {
        printf("\n\tCOMPUTADOR VENCEU\n\n\n");
        pw++; // contador do numero de vitorias do computado
    }
}

void jogarnovamente(void)
{
    menujoganovamentetop();
    printf("\t%c   Deseja jogar novamente ? [S/N]  %c\n", 179, 179);
    menujoganovamentedown();
    res = getch();
    res = toupper(res); // transforma a resposta para uma letra maiúscula
    if (res != 'S' && res != 'N')
    {
        system("cls");
        printf("\tResposta inv%clida\n\n\n", 160);
        jogarnovamente();
    }
}

int main(int argc, char *argv[]) //função principal
{

    do //entrar em loop se o jogador escolher jogar novamente
    {
        count = 1;     // count é o numero da jogada
        jw = 0;        // controle de quantas vezes o jogador ganhou
        pw = 0;        // controle de quantas vezes o computador ganhou
        emt = 0;       // controle de quantas vezes teve empate
        espadaj = 0;   // controle de quantas vezes a espada do jogador foi utilizado na partida
        espadap = 0;   // controle de quantas vezes a espada do computador foi utilizado na partida
        system("cls"); // limpa a tela do console
        menu();        // função menu é iniciada tendo inicio a cadeia de eventos que leva ao jogo
        Sleep(500);    // progama esperar 0,5s antes de motrar o resultado
        printf("\n\n\n\tResultado da partida\n");
        printf("\tJogador %d x %d Computador\n", jw, pw); // mostra o resultado da partida
        printf("\tTeve %d empates\n", emt);               // mostra os empates
        jogarnovamente();
    } while (res == 'S'); // se a resposta for sim ele entrar em loop iniciando o menu novamente

    return 0;
}