#include <stdio.h>

// Prototipos de funciones
void inicializarTablero(char tablero[3][3]);
void imprimirTablero(char tablero[3][3]);
int comprobarVictoria(char tablero[3][3]);
void hacerMovimiento(char tablero[3][3], int jugador);

int main() {
    char tablero[3][3];
    int jugador = 1;
    int movimientos = 0;
    int ganador = 0;

    inicializarTablero(tablero);

    while (movimientos < 9 && ganador == 0) {
        imprimirTablero(tablero);
        hacerMovimiento(tablero, jugador);
        movimientos++;
        ganador = comprobarVictoria(tablero);
        if (jugador == 1) {
            jugador = 2;
        } else {
            jugador = 1;
        }
    }

    imprimirTablero(tablero);

    if (ganador != 0) {
        printf("¡Jugador %d gana!\n", ganador);
    } else {
        printf("¡Es un empate!\n");
    }

    return 0;
}

// Definiciones de funciones
void inicializarTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void imprimirTablero(char tablero[3][3]) {
    printf(" %c | %c | %c \n", tablero[0][0], tablero[0][1], tablero[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tablero[1][0], tablero[1][1], tablero[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tablero[2][0], tablero[2][1], tablero[2][2]);
}

int comprobarVictoria(char tablero[3][3]) {
    // Comprobar filas y columnas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ') {
            if (tablero[i][0] == 'X') {
                return 1;
            } else {
                return 2;
            }
        }
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != ' ') {
            if (tablero[0][i] == 'X') {
                return 1;
            } else {
                return 2;
            }
        }
    }
    // Comprobar diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ') {
        if (tablero[0][0] == 'X') {
            return 1;
        } else {
            return 2;
        }
    }
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ') {
        if (tablero[0][2] == 'X') {
            return 1;
        } else {
            return 2;
        }
    }
    return 0;
}

void hacerMovimiento(char tablero[3][3], int jugador) {
    int fila, columna;
    char marca;
    if (jugador == 1) {
        marca = 'X';
    } else {
        marca = 'O';
    }
    do {
        printf("Jugador %d (%c), introduce fila y columna (0, 1 o 2): ", jugador, marca);
        scanf("%d %d", &fila, &columna);
    } while (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ');
    tablero[fila][columna] = marca;
}