#include <stdio.h>
#include <stdbool.h> 

#define SIZE 8

// Tipos de peças
typedef enum {
    EMPTY, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING
} PieceType;

typedef enum {
    NONE, WHITE, BLACK
} Color;

typedef struct {
    PieceType type;
    Color color;
} Piece;

Piece board[SIZE][SIZE];

// Inicializa o tabuleiro com algumas peças
void initBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = (Piece){EMPTY, NONE};

    board[0][0] = (Piece){ROOK, WHITE};
    board[0][1] = (Piece){KNIGHT, WHITE};
    board[1][0] = (Piece){PAWN, WHITE};
    board[7][7] = (Piece){KING, BLACK};
}

// Verifica se o movimento é válido (exemplo: torre)
bool isValidMove(int x1, int y1, int x2, int y2) {
    Piece p = board[x1][y1];
    if (p.type == ROOK)
        return (x1 == x2 || y1 == y2);
    // Adicione regras para outras peças aqui
    return false;
}

// Move a peça se for válido
void movePiece(int x1, int y1, int x2, int y2) {
    if (isValidMove(x1, y1, x2, y2)) {
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = (Piece){EMPTY, NONE};
        printf("Movimento realizado!\n");
    } else {
        printf("Movimento inválido!\n");
    }
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            Piece p = board[i][j];
            char symbol = '.';
            if (p.type == PAWN) symbol = 'P';
            else if (p.type == ROOK) symbol = 'R';
            else if (p.type == KNIGHT) symbol = 'N';
            else if (p.type == BISHOP) symbol = 'B';
            else if (p.type == QUEEN) symbol = 'Q';
            else if (p.type == KING) symbol = 'K';
            printf("%c ", symbol);
        }
        printf("\n");
    }
}

int main() {
    initBoard();
    printBoard();
    movePiece(0, 0, 0, 5); // Exemplo: mover torre
    printBoard();
    return 0;
}