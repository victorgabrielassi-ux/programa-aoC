#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

char playerBoard[SIZE][SIZE];
char enemyBoard[SIZE][SIZE];
char enemyHidden[SIZE][SIZE];

// Inicializa os tabuleiros
void initBoards() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            playerBoard[i][j] = '~';
            enemyBoard[i][j] = '~';
            enemyHidden[i][j] = '~';
        }

    // Navios do jogador
    playerBoard[1][1] = 'N';
    playerBoard[1][2] = 'N';
    playerBoard[1][3] = 'N';

    // Navios do inimigo
    enemyBoard[5][5] = 'N';
    enemyBoard[5][6] = 'N';
    enemyBoard[5][7] = 'N';
}

// Imprime tabuleiro com coordenadas
void printBoard(char board[SIZE][SIZE], const char* title) {
    printf("\n%s\n", title);
    printf("   ");
    for (int i = 0; i < SIZE; i++) printf(" %d ", i);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf(" %c ", 'A' + i);
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

// Jogada do jogador
void playerTurn() {
    char linha;
    int coluna;
    printf("\nSeu turno! Digite coordenadas (ex: A5): ");
    scanf(" %c%d", &linha, &coluna);
    int x = linha - 'A';

    if (x < 0 || x >= SIZE || coluna < 0 || coluna >= SIZE) {
        printf("Coordenada inválida!\n");
        return;
    }

    if (enemyBoard[x][coluna] == 'N') {
        printf("💥 Acertou!\n");
        enemyHidden[x][coluna] = 'X';
        enemyBoard[x][coluna] = 'X';
    } else if (enemyHidden[x][coluna] == '~') {
        printf("🌊 Errou!\n");
        enemyHidden[x][coluna] = 'O';
    } else {
        printf("Você já atirou aqui!\n");
    }
}

// Jogada do computador
void enemyTurn() {
    int x, y;
    do {
        x = rand() % SIZE;
        y = rand() % SIZE;
    } while (playerBoard[x][y] == 'X' || playerBoard[x][y] == 'O');

    printf("Computador atira em %c%d...\n", 'A' + x, y);

    if (playerBoard[x][y] == 'N') {
        printf("🔥 Seu navio foi atingido!\n");
        playerBoard[x][y] = 'X';
    } else {
        playerBoard[x][y] = 'O';
        printf("💨 Tiro na água.\n");
    }
}

// Verifica fim de jogo
int checkVictory(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == 'N') return 0;
    return 1;
}

int main() {
    srand(time(NULL));
    initBoards();

    while (1) {
        printBoard(playerBoard, "Seu Tabuleiro:");
        printBoard(enemyHidden, "Tabuleiro Inimigo:");

        playerTurn();
        if (checkVictory(enemyBoard)) {
            printf("\n🎉 Você venceu!\n");
            break;
        }

        enemyTurn();
        if (checkVictory(playerBoard)) {
            printf("\n💀 Você perdeu!\n");
            break;
        }
    }

    return 0;
}