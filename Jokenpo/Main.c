#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int computador, count, jw, pw, emt, espadaj, espadap;
char res, jogador;

void menu(void)
{

    char menures;

    printf("-------------------------------------------------------------------------------\n");
    printf("                           PEDRA - PAPEL - TESOURA                             \n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\tStart\n");
    printf("\tExit\n");
    menures = getch();
    menures = toupper(menures);

    if (menures == 'S')
    {
        system("cls");
        jogo();
    }
    else if (menures == 'E')
    {
        exit(0);
    }
    else
    {
        system("cls");
        printf("\topcao invalida\n");
        menu();
    }
}

void opcaoE()
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
        printf("-------------------------------------------------------------------------------\n");
        printf("                           PEDRA - PAPEL - TESOURA                             \n");
        printf("-------------------------------------------------------------------------------\n");
        opcaoE();
        printf("\tDigite a opcao desejada: ");
        jogador = getch();
        system("cls");
        printf("rodada %d/5\n", count);
        printf("-------------------------------------------------------------------------------\n");

        if (jogador == '1')
        {
            printf("\tJogador escolheu PEDRA\n");
        }
        else if (jogador == '2')
        {
            printf("\tJogador escolheu PAPEL\n");
        }
        else if (jogador == '3')
        {
            printf("\tJogador escolheu TESOURA\n");
        }
        else if (jogador == '4')
        {
            if (espadaj < 1)
            {
                printf("\tJogador escolheu ESPADA\n");
            }
            espadaj++;
            if (espadaj > 1)
            {
                system("cls");
                printf("-------------------------------------------------------------------------------\n");
                printf("\topcao invalida\n");
                printf("\tSo pode ser usado uma vez por jogo\n");
                printf("-------------------------------------------------------------------------------\n");
                jogador = 0;
            }
        }
        else
        {
            printf("\topcao invalida\n");
            printf("-------------------------------------------------------------------------------\n");
            jogador = 0;
        }

        while (jogador == 0)
        {
            printf("Digite a opcao desejada: \n");
            opcaoE();
            jogador = getch();
            system("cls");
            printf("rodada %d/5\n", count);
            printf("-------------------------------------------------------------------------------\n");
            if (jogador == '1')
            {
                printf("\tJogador escolheu PEDRA\n");
            }
            else if (jogador == '2')
            {
                printf("\tJogador escolheu PAPEL\n");
            }
            else if (jogador == '3')
            {
                printf("\tJogador escolheu TESOURA\n");
            }
            else if (jogador == '4')
            {
                if (espadaj < 1)
                {
                    printf("\tJogador escolheu ESPADA\n");
                }
                espadaj++;
                if (espadaj > 1)
                {
                    system("cls");
                    printf("-------------------------------------------------------------------------------\n");
                    printf("\topcao invalida\n");
                    printf("\tSo pode ser usado uma vez por jogo\n");
                    printf("-------------------------------------------------------------------------------\n");
                    jogador = 0;
                }
            }
            else
            {
                printf("\topcao invalida\n");
                printf("-------------------------------------------------------------------------------\n");
                jogador = 0;
            }
        }
        // lógica do computador
        srand(time(NULL));
        computador = ("%d", rand() % 4 + 1);

        if (computador == 1)
        {
            printf("\tComputador escolheu PEDRA\n");
        }
        else if (computador == 2)
        {
            printf("\tComputador escolheu PAPEL\n");
        }
        else if (computador == 3)
        {
            printf("\tComputadorescolheu TESOURA\n");
        }
        else if (computador == 4)
        {
            if (espadap < 1)
            {
                printf("\tComputador escolheu ESPADA\n");
            }
            espadap++;
            if (espadap > 1)
            {
                computador = 0;
            }
        }
        else
        {
            printf("\topcao invalida\n");
        }

        while (computador == 0)
        {
            srand(time(NULL));
            computador = ("%d", rand() % 4 + 1);

            if (computador == 1)
            {
                printf("\tComputador escolheu PEDRA\n");
            }
            else if (computador == 2)
            {
                printf("\tComputador escolheu PAPEL\n");
            }
            else if (computador == 3)
            {
                printf("\tComputadorescolheu TESOURA\n");
            }
            else if (computador == 4)
            {
                if (espadap < 1)
                {
                    printf("\tComputador escolheu ESPADA\n");
                }
                espadap++;
                if (espadap > 1)
                {
                    computador = 0;
                }
            }
            else
            {
                printf("\topcao invalida\n");
            }
        }

        vencedor();

        count++;
    } while (count <= 5);
}

void vencedor(void)
{
    //lógica para determinar o vencedor
    printf("-------------------------------------------------------------------------------\n");
    if (jogador == '1' && computador == 1 || jogador == '2' && computador == 2 || jogador == '3' && computador == 3 && jogador == '4' && computador == 4)
    {
        printf("\tEMPATE\n\n");
        emt++;
    }
    else if ((jogador == '1' && computador == 3) || (jogador == '2' && computador == 1) ||
             (jogador == '3' && computador == 2) || (jogador == '4' && computador == 3) || (jogador == '4' && computador == 2) || (jogador == '4' && computador == 1))
    {
        printf("\tJOGADOR VENCEU\n");
        jw++;
    }
    else
    {
        printf("\tCOMPUTADOR VENCEU\n");
        pw++;
    }
}

int main(int argc, char *argv[])
{

    do
    {
        count = 1;
        jw = 0;
        pw = 0;
        emt = 0;
        espadaj = 0;
        espadap = 0;
        system("cls");
        menu();
        printf("\tJogador %d x %d Computador\n", jw, pw);
        printf("\tTeve %d empates\n", emt);
        printf("\tDeseja jogar novamente ? [S/N] \n");
        res = getch();
        res = toupper(res);
    } while (res == 'S');

    return 0;
}