#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define STRAM 30 // Constante de controle do numero de linhas do menu
#define STRAM2 35 // Constante de controle do numero de linhas do menu

int computador, jw, pw, emt; // variaveis globais que server para todas as funçoes
char jogador, res;           // variaveis globais que server para todas as funçoes

int tecla() // função que se alguma tecla esta sendo precionada 
{
    int varTecla;
    while (1)
    {
        if (kbhit())  // caso alguma tecla esteja sendo precionada
        {              // ele irar armanezar o valor da tecla na variavel 
            varTecla = getch();  // getch captura um caractere da entrada 
            return varTecla;
        }
    }
}

void criarmenulinhasuperior() // função que cria linha superior do menu
{
    int i;
    printf("\t\t%c", 201);
    for (i = 0; i < STRAM; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n", 187);
}

void criarmenulinharodape() // função que cria rodape do menu
{
    int i;
    printf("\t\t%c", 200);
    for (i = 0; i < STRAM; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n", 188);
}

void criarmenulinhameio() // função que cria linha do meio do menu
{

    int i;
    printf("\t\t%c", 204);
    for (i = 0; i < STRAM; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n", 185);
}

void menujoganovamentetop() // função que cria linha do menu de jogar novamente
{
    int i;
    printf("\t%c", 218);
    for (i = 0; i < STRAM2; i++)
    {
        printf("%c", 196);
    }
    printf("%c\n", 191);
}

void menujoganovamentedown() // função que cria linha do menu de jogar novamente
{
    int i;
    printf("\t%c", 192);
    for (i = 0; i < STRAM2; i++)
    {
        printf("%c", 196);
    }
    printf("%c\n", 217);
}

void menu() // função que faz o menu princial do jogo
{

    int c; // declaração de variáveis
    int lugar = 0; // declaração de variáveis
    system("cls"); // limpa tela do console
    criarmenulinhasuperior(); // função que cria linha superior do menu
    printf("\t\t%c            Jokenpo           %c\n", 186, 186);
    criarmenulinhameio(); // função que cria linha do meio do menu
    printf("\t\t%c          -> Start            %c\n", 186, 186);
    printf("\t\t%c             Regras           %c\n", 186, 186);
    printf("\t\t%c             Quit             %c\n", 186, 186);
    criarmenulinharodape();// função que cria rodape do menu
    printf("\n\n\n\t*Use as setas do teclado para movimenta%c%co das op%c%ces\n", 135, 132, 135, 148);
    printf("\t*Utilize o Enter para escolher uma das op%c%ces\n", 135, 148);

    while (1) // laço de repetição infinito
    {
        if (kbhit()) // se alguma tecla for precionada ele entrar dentro do if
        {
            system("cls"); // limpa tela do console
            c = tecla(); // variavel c recebe função criada anteriormente

            if (c == 80)
            { //apertou para baixo
                lugar++; // variavel receber +1 no seu valor
                if (lugar > 2) // se o lugar for maior que 2
                    lugar = 0; // ele volta para posição inicial menu
            }
            if (c == 72)
            { //apertou para cima
                lugar--; // variavel recebe -1 no seu valor
                if (lugar < 0) // se o lugar for menor que 0
                    lugar = 2; // ele volta para ultima posição do menu
            }
            if (c == 75)
            { //apertou para direita
                lugar++;  // variavel receber +1 no seu valor
                if (lugar > 2) // se o lugar for maior que 2
                    lugar = 0; // ele volta para posição inicial menu
            }
            if (c == 77)
            { //apertou para esquerda
                lugar--; // variavel recebe -1 no seu valor
                if (lugar < 0) // se o lugar for menor que 0
                    lugar = 2; // ele volta para ultima posição do menu
            }
            if (c == 13)
            { //apertou [enter]
                if (lugar == 0) // se o enter(opçao de escolha) for apertado quando o menu estiver em start
                {               // inicia o jogo
                    criarmenulinhasuperior(); // função que cria linha superior do menu
                    printf("\t\t%c       INICIANDO O JOGO!      %C\n", 186, 186);
                    criarmenulinharodape(); // função que cria rodape do menu
                    Sleep(2800); // sistema espera 2,8s antes de continuar
                    system("cls"); // limpa tela do console
                    jogo(); // inicia a função do jogo
                    break; // para a estrutira de repetição
                }
                else if (lugar == 1) // se o enter(opçao de escolha) for apertado quando o menu estiver em regras
                {                    // inicia a função regras
                    criarmenulinhasuperior(); // função que cria linha superior do menu
                    printf("\t\t%c            REGRAS            %C\n", 186, 186);
                    criarmenulinharodape(); // função que cria rodape do menu
                    regras(); // inicia a função das regras
                    break;  // para a estrutira de repetição
                }
                else if (lugar == 2) // se o enter(opçao de escolha) for apertado quando o menu estiver em quit
                {                    // inicia a função de sair
                    system("cls"); // limpa a tela do console
                    criarmenulinhasuperior(); // função que cria linha superior do menu
                    printf("\t\t%c       SAINDO DO PROGRAMA!    %C\n", 186, 186);
                    criarmenulinharodape(); // função que cria rodape do menu
                    Sleep(1000); // espera 1 s
                    exit(0);     // fecha o programa
                }
            }
            if (lugar == 0) // apos dectar a tecla apertada o programa imprime o local
            {               // aonde a seta que demonstra a opçao de escolha esta
                criarmenulinhasuperior(); // função que cria linha superior do menu
                printf("\t\t%c            Jokenpo           %c\n", 186, 186);
                criarmenulinhameio(); // função que cria linha  do meio do menu
                printf("\t\t%c          -> Start            %c\n", 186, 186);
                printf("\t\t%c             Regras           %c\n", 186, 186);
                printf("\t\t%c             Quit             %c\n", 186, 186);
                criarmenulinharodape();  // função que cria rodape do menu
                printf("\n\n\n\t*Use as setas do teclado para movimenta%c%co das op%c%ces\n", 135, 132, 135, 148);
                printf("\t*Utilize o Enter para escolher uma das op%c%ces\n", 135, 148);
            }
            if (lugar == 1)// apos dectar a tecla apertada o programa imprime o local
            {              // aonde a seta que demonstra a opçao de escolha esta
                criarmenulinhasuperior(); // função que cria linha superior do menu
                printf("\t\t%c            Jokenpo           %c\n", 186, 186);
                criarmenulinhameio(); // função que cria linha  do meio do menu
                printf("\t\t%c             Start            %c\n", 186, 186);
                printf("\t\t%c          -> Regras           %c\n", 186, 186);
                printf("\t\t%c             Quit             %c\n", 186, 186);
                criarmenulinharodape();// função que cria rodape do menu
                printf("\n\n\n\t*Use as setas do teclado para movimenta%c%co das op%c%ces\n", 135, 132, 135, 148);
                printf("\t*Utilize o Enter para escolher uma das op%c%ces\n", 135, 148);
            }
            if (lugar == 2)// apos dectar a tecla apertada o programa imprime o local
            {              // aonde a seta que demonstra a opçao de escolha esta
                criarmenulinhasuperior(); // função que cria linha superior do menu
                printf("\t\t%c            Jokenpo           %c\n", 186, 186);
                criarmenulinhameio(); // função que cria linha  do meio do menu
                printf("\t\t%c             Start            %c\n", 186, 186);
                printf("\t\t%c             Regras           %c\n", 186, 186);
                printf("\t\t%c          -> Quit             %c\n", 186, 186);
                criarmenulinharodape(); // função que cria rodape do menu
                printf("\n\n\n\t*Use as setas do teclado para movimenta%c%co das op%c%ces\n", 135, 132, 135, 148);
                printf("\t*Utilize o Enter para escolher uma das op%c%ces\n", 135, 148);
            }
        }
    }
}

void regras(void) //função que mostra as regras do jogo
{
    printf("\t\t\t\n\n- Pedra ganha da Tesoura (a amassa e quebra)\n");
    printf("\t- Tesoura ganha do Papel (o corta)\n");
    printf("\t- Papel ganha da Pedra (a embrulha)\n");
    printf("\t- Espada s%c poder%c ser usado 1 unica vez at%c o fim do jogo\n", 162, 160, 130); //utilizado codigo ASCII para caracteres especiais
    printf("\t- Cada partida ter%c 5 rodadas\n", 160); //utilizado codigo ASCII para caracteres especiais
    voltarmenu(); // função que da opçao de voltar ao menu
}

void voltarmenu() // função que volta ao menu
{
    char resegg, resregras; // declaração de variaveis

    printf("\n\nAperte esc para voltar ao menu");
    printf("\t\t\t\t\t\t\t\t-><-\n");
    resregras = getch(); // getch captura um caractere
    if (resregras != 27 && resregras != 13) // se o botao apertado for diferente de ESC ou ENTER
    {                                       // mostrar resposta invalida
        system("cls"); // limpa a tela do console
        menujoganovamentetop(); // função que cria linha superior do menu
        printf("\t%c         Resposta inv%clida         %c\n", 179, 160, 179);
        menujoganovamentedown(); // função que cria rodape do menu
        voltarmenu(); // chama função novamente para refazer a escolha de voltar ao menu
    }
    if (resregras == 27) // se o botao apertado for ESC
    {
        menu(); // ele volta para o menu
    }
    if (resregras == 13) // se o botao apertado for ENTRAR ele entar no EASTER EGG
    {
        system("cls"); // limpa tela do console
        printf("Tem CERTEZA QUE DEJESA CONTINUAR ? [S/N]\n\n");
        resegg = getch(); // getch captura um caractere
        resegg = toupper(resegg); // transforma a resposta para uma letra maiúscula
        if (resegg == 'S')
        {
            easteregg(); // função do easter egg
        }
        else if (resegg == 'N')
        {
            system("cls"); // limpa tela do console
            voltarmenu(); // volta ao menu
        }
        else
        {
            system("cls"); // limpa tela do console
            menujoganovamentetop();// função que cria linha superior do menu
            printf("\t%c         Resposta inv%clida         %c\n", 179, 160, 179);
            menujoganovamentedown();// função que cria rodape do menu
            voltarmenu();// volta ao menu
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
    char espadaj, espadap;
    int count;   
    count = 1;   // count é o numero da jogada
    jw = 0;      // controle de quantas vezes o jogador ganhou
    pw = 0;      // controle de quantas vezes o computador ganhou
    emt = 0;     // controle de quantas vezes teve empate
    espadaj = 0; // controle de quantas vezes a espada do jogador foi utilizado na partida
    espadap = 0; // controle de quantas vezes a espada do computador foi utilizado na partida

    do
    {
        printf("rodada %d/5\n", count); // contador do numero de rodadas
        criarmenulinhasuperior();// função que cria linha superior do menu
        printf("\t\t%c            Jokenpo           %c\n", 186, 186);
        criarmenulinharodape();// função que cria rodape do menu
        opcaoE(); // função da opção de escolha
        printf("\tDigite a op%c%co desejada: ", 135, 132);
        jogador = getch(); // getch captura um caractere
        system("cls"); // limpa tela do console

        if (jogador == '1') // mostra a escolha do jogador
        {
            criarmenulinhasuperior(); // função que cria linha superior do menu 
            printf("\t\t%c     Jogador escolheu PEDRA   %c\n", 186, 186);
        }
        else if (jogador == '2') // função que cria linha superior do menu 
        {
            criarmenulinhasuperior(); // função que cria linha superior do menu
            printf("\t\t%c     Jogador escolheu PAPEL   %c\n", 186, 186);
        }
        else if (jogador == '3')
        {
            criarmenulinhasuperior(); // função que cria linha superior do menu
            printf("\t\t%c   Jogador escolheu TESOURA   %c\n", 186, 186);
        }
        else if (jogador == '4')
        {
            if (espadaj < 1) // verifica se o jogador ja escolheu a opção da espada durante as 5 rodadas 
            {
                criarmenulinhasuperior(); // função que cria linha superior do menu
                printf("\t\t%c    Jogador escolheu ESPADA   %c\n", 186, 186);
            }
            espadaj++; // espada do jogador recebe +1 no seu valor
            if (espadaj > 1) //Evitar que o jogador utilize a espada mais de 1 vez
            {
                system("cls"); // limpa tela do console
                criarmenulinhasuperior(); // função que cria linha superior do menu
                printf("\t\t%c        op%c%co inv%clida        %c\n", 186, 135, 132, 160, 186);
                printf("\t\t%c      Espada j%c utilizada     %c\n", 186, 160, 186);
                criarmenulinharodape(); // função que cria rodape do menu
                jogador = 0; // jogador = 0 entrar um loop para refazer as escolhas
            }
        }
        else
        {
            criarmenulinhasuperior(); // função que cria linha superior do menu
            printf("\t\t%c        op%c%co inv%clida        %c\n", 186, 135, 132, 160, 186);
            criarmenulinharodape(); // função que cria rodape do menu
            jogador = 0; // jogador = 0 entrar um loop para refazer as escolhas
        }

        while (jogador == 0) // loop para rafazer as escolhas do jogador caso seja invalida
        {
            printf("\nDigite a opcao desejada: \n");
            opcaoE(); // função da opção de escolha
            jogador = getch();  // getch captura um caractere
            system("cls"); // limpa tela do console
            if (jogador == '1') // mostra a escolha do jogador
            {
                criarmenulinhasuperior();// função que cria linha superior do menu
                printf("\t\t%c     Jogador escolheu PEDRA   %c\n", 186, 186);
            }
            else if (jogador == '2')
            {
                criarmenulinhasuperior();// função que cria linha superior do menu
                printf("\t\t%c     Jogador escolheu PAPEL   %c\n", 186, 186);
            }
            else if (jogador == '3')
            {
                criarmenulinhasuperior();// função que cria linha superior do menu
                printf("\t\t%c   Jogador escolheu TESOURA   %c\n", 186, 186);
            }
            else if (jogador == '4')
            {
                if (espadaj < 1) // verifica se o jogador ja escolheu a opção da espada durante as 5 rodadas 
                {
                    criarmenulinhasuperior();// função que cria linha superior do menu
                    printf("\t\t%c    Jogador escolheu ESPADA   %c\n", 186, 186);
                }
                espadaj++; // espada do jogador recebe +1 no seu valor
                if (espadaj > 1) //Evitar que o jogador utilize a espada mais de 1 vez
                {
                    system("cls"); // limpa tela do console
                    criarmenulinhasuperior();// função que cria linha superior do menu
                    printf("\t\t%c        op%c%co inv%clida        %c\n", 186, 135, 132, 160, 186);
                    printf("\t\t%c      Espada j%c utilizada     %c\n", 186, 160, 186);
                    criarmenulinharodape();// função que cria rodape do menu
                    jogador = 0; // jogador = 0 entrar um loop para refazer as escolhas
                }
            }
            else
            {
                criarmenulinhasuperior();// função que cria linha superior do menu
                printf("\t\t%c        op%c%co inv%clida        %c\n", 186, 135, 132, 160, 186);
                criarmenulinharodape();// função que cria rodape do menu
                jogador = 0; // jogador = 0 entrar um loop para refazer as escolhas
            }
        }
        // lógica do computador
        srand(time(NULL));
        computador = ("%d", rand() % 4 + 1); // computador escolhe um numero aleatorio entra 1 a 4

        if (computador == 1) // mostra a escolha do computador
        {
            printf("\t\t%c   Computador escolheu PEDRA  %c\n", 186, 186);
            criarmenulinharodape();// função que cria rodape do menu
        }
        else if (computador == 2)
        {
            printf("\t\t%c   Computador escolheu PAPEL  %c\n", 186, 186);
            criarmenulinharodape();// função que cria rodape do menu
        }
        else if (computador == 3)
        {
            printf("\t\t%c  Computador escolheu TESOURA %c\n", 186, 186);
            criarmenulinharodape();// função que cria rodape do menu
        }
        else if (computador == 4)
        {
            if (espadap < 1) // verifica se o computador ja escolheu a opção da espada durante as 5 rodadas
            {
                printf("\t\t%c  Computador escolheu ESPADA  %c\n", 186, 186);
                criarmenulinharodape();// função que cria rodape do menu
            }
            espadap++; // espada do computador recebe +1 no seu valor
            if (espadap > 1) //Evitar que o computador utilize a espada mais de 1 vez
            {
                computador = 0; // computador = 0 entrar um loop para refazer as escolhas
            }
        }
        else
        {
            computador = 0; // computador = 0 entrar um loop para refazer as escolhas
        }

        while (computador == 0) // loop para rafazer as escolhas do computador caso seja invalida
        {
            computador = ("%d", rand() % 4 + 1); // computador escolhe um numero aleatorio entra 1 a 4

            if (computador == 1) // mostra a escolha do computador
            {
                printf("\t\t%c   Computador escolheu PEDRA  %c\n", 186, 186);
                criarmenulinharodape();// função que cria rodape do menu
            }
            else if (computador == 2)
            {
                printf("\t\t%c   Computador escolheu PAPEL  %c\n", 186, 186);
                criarmenulinharodape();// função que cria rodape do menu
            }
            else if (computador == 3)
            {
                printf("\t\t%c  Computador escolheu TESOURA %c\n", 186, 186);
                criarmenulinharodape();// função que cria rodape do menu
            }
            else if (computador == 4)
            {
                if (espadap < 1) // verifica se o computador ja escolheu a opção da espada durante as 5 rodadas
                {
                    printf("\t\t%c  Computador escolheu ESPADA  %c\n", 186, 186);
                    criarmenulinharodape();// função que cria rodape do menu
                }
                espadap++; // espada do computador recebe +1 no seu valor
                if (espadap > 1) //Evitar que o computador utilize a espada mais de 1 vez
                {
                    computador = 0; // computador = 0 entrar um loop para refazer as escolhas
                }
            }
            else
            {
                criarmenulinhasuperior();// função que cria linha superior do menu
                printf("\t\t%c        op%c%co inv%clida        %c\n", 186, 135, 132, 160, 186);
                criarmenulinharodape();// função que cria rodape do menu
            }
        }

        vencedor(); //função que determina o vencedor

        count++;          // aumenta o numero da jogada
        Sleep(500);       // programa esperar 0,5s antes de continuar
    } while (count <= 5); // loop do programa ira acabar quando ocorrer 5 rodadas
    resultado(); // função que mostra do resultado no final dos 5 jogos
}

void vencedor(void) // função que determina o vencedor
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

void jogarnovamente(void) // função jogar novamente
{
    menujoganovamentetop();// função que cria linha superior do menu
    printf("\t%c   Deseja jogar novamente ? [S/N]  %c\n", 179, 179);
    menujoganovamentedown();// função que cria rodape do menu
    res = getch(); // getch captura um caractere
    res = toupper(res); // transforma a resposta para uma letra maiúscula
    if (res != 'S' && res != 'N')
    {
        system("cls");
        menujoganovamentetop();// função que cria linha superior do menu
        printf("\t%c         Resposta inv%clida         %c\n", 179, 160, 179);
        menujoganovamentedown();// função que cria rodape do menu
        jogarnovamente(); //chama a função jogarnovamente quaso a resposta seja invalida para fazer uma nova escolha
    }
}

void resultado() // função que mostra o resultado da partida
{
    printf("\n\n\n\tResultado da partida\n");
    printf("\tJogador %d x %d Computador\n", jw, pw); // mostra o resultado da partida
    printf("\tTeve %d empates\n", emt);               // mostra os empates
}

void easteregg() // easter egg codigo com algumas alterações do codigo original (https://gist.github.com/gcr/1075131)
{
    int k, esc;
    double sin(), cos();

    float A = 0, B = 0, i, j, z[1760];
    char b[1760];
    system("cls");

    while (esc != 27)
    {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for (j = 0; 6.28 > j; j += 0.07)
        {
            for (i = 0; 6.28 > i; i += 0.02)
            {
                float sini = sin(i),
                      cosj = cos(j),
                      sinA = sin(A),
                      sinj = sin(j),
                      cosA = cos(A),
                      cosj2 = cosj + 2,
                      mess = 1 / (sini * cosj2 * sinA + sinj * cosA + 5),
                      cosi = cos(i),
                      cosB = cos(B),
                      sinB = sin(B),
                      t = sini * cosj2 * cosA - sinj * sinA;
                int x = 40 + 30 * mess * (cosi * cosj2 * cosB - t * sinB),
                    y = 12 + 15 * mess * (cosi * cosj2 * sinB + t * cosB),
                    o = x + 80 * y,
                    N = 8 * ((sinj * sinA - sini * cosj * cosA) * cosB - sini * cosj * sinA - sinj * cosA - cosi * cosj * sinB);
                if (22 > y && y > 0 && x > 0 && 80 > x && mess > z[o])
                {
                    z[o] = mess;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[d");
        for (k = 0; 1761 > k; k++)
            putchar(k % 80 ? b[k] : 10);
        A += 0.04;
        B += 0.02;

        printf("\n\nModified by KifelG\n");
        printf("Pressione ESC para voltar ao menu...\n");

        if (kbhit())
        {
            esc = tecla();
            if (esc == 27)
            {
                system("cls"); // limpa tela do console
                criarmenulinhasuperior();// função que cria linha superior do menu
                printf("\t\t%c       VOLTANDO AO MENU!      %C\n", 186, 186);
                criarmenulinharodape();// função que cria rodape do menu
                printf("\n\nModified by KifelG\n");
                Sleep(2800); // programa espera 2,8s antes de continuar
                menu(); // volta ao menu
            }
        }
    }
}

int main(int argc, char *argv[]) //função principal
{

    do //entrar em loop se o jogador escolher jogar novamente
    {
        system("cls"); // limpa a tela do console
        menu();        // função menu é iniciada tendo inicio a cadeia de eventos que leva ao jogo
        Sleep(500);    // progama esperar 0,5s antes de motrar o resultado
        jogarnovamente();// função de jogar novamente
    } while (res == 'S'); // se a resposta for sim ele entrar em loop iniciando o menu novamente

    system("cls"); // limpa tela do console
    criarmenulinhasuperior();// função que cria linha superior do menu
    printf("\t\t%c       SAINDO DO PROGRAMA!!   %C\n", 186, 186);
    criarmenulinharodape();// função que cria rodape do menu
    Sleep(500); // programa espera 0,5s antes de continuar
    exit(0); // pregrama fecha

    return 0;
}