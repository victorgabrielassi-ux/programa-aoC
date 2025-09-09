#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CARTAS 4

typedef struct {
    char nome[50];
    int populacao;
    float pib;
    float area;
    int pontosTuristicos;
} Carta;

void mostrarCarta(Carta c) {
    printf("\n🃏 Carta: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Área: %.2f km²\n", c.area);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
}

int comparar(Carta c1, Carta c2, int atributo) {
    switch (atributo) {
        case 1: return c1.populacao > c2.populacao;
        case 2: return c1.pib > c2.pib;
        case 3: return c1.area > c2.area;
        case 4: return c1.pontosTuristicos > c2.pontosTuristicos;
        default: return -1;
    }
}

int main() {
    srand(time(NULL));

    Carta cartas[NUM_CARTAS] = {
        {"São Paulo", 12300000, 700.5, 1521.0, 15},
        {"Rio de Janeiro", 6748000, 500.2, 1182.3, 20},
        {"Curitiba", 1960000, 120.3, 430.5, 10},
        {"Manaus", 2210000, 80.7, 11456.0, 8}
    };

    int cartaJogador = rand() % NUM_CARTAS;
    int cartaPC = rand() % NUM_CARTAS;

    printf("🎮 Sua carta:\n");
    mostrarCarta(cartas[cartaJogador]);

    printf("\nEscolha um atributo para competir:\n");
    printf("1 - População\n2 - PIB\n3 - Área\n4 - Pontos Turísticos\n");
    int escolha;
    scanf("%d", &escolha);

    printf("\n🤖 Carta do computador:\n");
    mostrarCarta(cartas[cartaPC]);

    int resultado = comparar(cartas[cartaJogador], cartas[cartaPC], escolha);

    if (resultado == 1)
        printf("\n✅ Você venceu!\n");
    else if (resultado == 0)
        printf("\n❌ Você perdeu!\n");
    else
        printf("\n⚠️ Atributo inválido.\n");

    return 0;
}
