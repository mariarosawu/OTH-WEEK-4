#include <stdio.h>

// Fungsi untuk mendapatkan nilai numerik dari kartu
int nilaiKartu(char c) {
  switch(c) {
    case 'J':
      return 11;
    case 'Q':
      return 12;
    case 'K':
      return 13;
    case '1':
      return 10;
    default:
      return c - '0';
  }
}

// Fungsi untuk melakukan pertukaran dan menghitung jumlah langkah
int tukarPosisi(int n, char *kartu) {
  int langkahTukar = 0;
  for (int i = 0; i < n - 1; i++) {
    int idxMin = i;
    int nilaiMin = nilaiKartu(kartu[i]); // Simpan nilai kartu minimum
    for (int j = i + 1; j < n; j++) {
      int nilaiKartuJ = nilaiKartu(kartu[j]); // Simpan nilai kartu j
      if (nilaiKartuJ < nilaiMin) {
        idxMin = j;
        nilaiMin = nilaiKartuJ; // Update nilai kartu minimum
      }
    }
    if (idxMin != i) {
      char temp = kartu[i];
      kartu[i] = kartu[idxMin];
      kartu[idxMin] = temp;
      langkahTukar++;
    }
  }
  return langkahTukar;
}

int main() {
  int jumlahKartu;
  scanf("%d", &jumlahKartu);

  // Membaca nilai kartu-kartu dari input
  char kartu[jumlahKartu];
  for (int i = 0; i < jumlahKartu; i++) {
    scanf(" %c", &kartu[i]);
  }

  // Memanggil fungsi untuk menghitung jumlah langkah minimal pertukaran
  int jumlahLangkah = tukarPosisi(jumlahKartu, kartu);
  printf("%d\n", jumlahLangkah);

  return 0;
}