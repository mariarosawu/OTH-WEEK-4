#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk mengecek apakah suatu posisi valid pada papan catur
int is_valid(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

// Fungsi untuk mensimulasikan pergerakan bidak kuda
void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    // Pergerakan bidak kuda
    int moves[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1},
                       {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

    // Tandai posisi yang dapat dicapai oleh bidak kuda
    for (int k = 0; k < 8; k++) {
        int x = i + moves[k][0];
        int y = j + moves[k][1];
        if (is_valid(x, y)) {
            *(chessBoard + x * size + y) = 1;
        }
    }
}

// Fungsi untuk menampilkan papan catur
void printChessBoard(int size, int *chessBoard) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(chessBoard + i * size + j));
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    printf("Masukkan posisi bidak kuda (i j): ");
    scanf("%d %d", &i, &j);

    // Inisialisasi papan catur
    int size = 8;
    int *chessBoard = (int *)malloc(size * size * sizeof(int));
    if (chessBoard == NULL) {
        printf("Memori tidak cukup!\n");
        return 1;
    }

    // Reset nilai papan catur
    for (int k = 0; k < size * size; k++) {
        *(chessBoard + k) = 0;
    }

    // Simulasikan pergerakan bidak kuda
    koboImaginaryChess(i, j, size, chessBoard);

    // Tampilkan papan catur
    printf("Papan catur setelah simulasi:\n");
    printChessBoard(size, chessBoard);

    // Bebaskan memori
    free(chessBoard);

    return 0;
}