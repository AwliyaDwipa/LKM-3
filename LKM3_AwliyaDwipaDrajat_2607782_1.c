/*
    Nama                : Awliya Dwipa Drajat
    NIM                 : 2607782
    Nomor Soal          : 1
    Tanggal Pengerjaan  : 12 November 2026
*/

// Memasukkan library standar untuk input/output (printf, scanf)
#include <stdio.h>

// Mendefinisikan konstanta ukuran matriks 3x3
#define BARIS 3
#define KOLOM 3

// Mendefinisikan batas suhu standar kualitas ruangan (dalam Celsius)
#define SUHU_MIN 2.0
#define SUHU_MAX 10.0

int main()
{
    // Mendeklarasikan matriks 3x3 untuk menyimpan suhu Fahrenheit
    float fahrenheit[BARIS][KOLOM];

    // Mendeklarasikan matriks 3x3 untuk menyimpan suhu Celsius hasil konversi
    float celsius[BARIS][KOLOM];

    // Mendeklarasikan variabel indeks baris (i) dan kolom (j) untuk perulangan
    int i, j;

    // Mendeklarasikan penghitung ruangan yang tidak memenuhi standar, awalnya 0
    int tidakLayak = 0;

    // ===== TAHAP 1: INPUT =====
    printf("=== Input Suhu Awal (Fahrenheit) ===\n");

    // Perulangan luar: berjalan untuk setiap baris
    for (i = 0; i < BARIS; i++)
    {
        // Perulangan dalam: berjalan untuk setiap kolom pada baris tersebut
        for (j = 0; j < KOLOM; j++)
        {
            // Menampilkan petunjuk posisi ruangan yang sedang diisi
            printf("Ruangan [%d][%d]: ", i, j);

            // Membaca suhu Fahrenheit dari pengguna dan menyimpannya ke matriks
            scanf("%f", &fahrenheit[i][j]);
        }
    }

    // ===== TAHAP 2: KONVERSI DAN PENGECEKAN =====
    for (i = 0; i < BARIS; i++)
    {
        for (j = 0; j < KOLOM; j++)
        {
            // Mengonversi Fahrenheit ke Celsius dengan rumus C = (F - 32) * 5 / 9
            celsius[i][j] = (fahrenheit[i][j] - 32) * 5 / 9;

            // Mengecek apakah suhu di luar rentang 2°C sampai 10°C
            if (celsius[i][j] < SUHU_MIN || celsius[i][j] > SUHU_MAX)
            {
                // Jika di luar rentang, tambah jumlah ruangan yang tidak layak
                tidakLayak++;
            }
        }
    }

    // ===== TAHAP 3: OUTPUT =====

    // Menampilkan matriks Fahrenheit sebagai rekap sebelum perubahan skala
    printf("\n=== Matriks Suhu Fahrenheit ===\n");
    for (i = 0; i < BARIS; i++)
    {
        for (j = 0; j < KOLOM; j++)
        {
            // Mencetak tiap elemen dengan lebar 8 karakter dan 2 angka desimal
            printf("%8.2f F", fahrenheit[i][j]);
        }
        // Pindah baris setelah satu baris matriks selesai dicetak
        printf("\n");
    }

    // Menampilkan matriks Celsius hasil konversi
    printf("\n=== Matriks Suhu Celsius ===\n");
    for (i = 0; i < BARIS; i++)
    {
        for (j = 0; j < KOLOM; j++)
        {
            printf("%8.2f C", celsius[i][j]);
        }
        printf("\n");
    }

    // Menampilkan jumlah ruangan yang tidak memenuhi standar kualitas
    printf("\nBanyak ruangan yang tidak memenuhi standar kualitas: %d\n", tidakLayak);

    // Mengakhiri program dengan status sukses
    return 0;
}