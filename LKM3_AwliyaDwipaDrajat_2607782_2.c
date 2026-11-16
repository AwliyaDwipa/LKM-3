/*
    Nama                : Awliya Dwipa Drajat
    NIM                 : 2607782
    Nomor Soal          : 2
    Tanggal Pengerjaan  : 14 November 2026
*/

// Memasukkan library standar untuk input/output
#include <stdio.h>

// Mendefinisikan ukuran matriks 3x3
#define BARIS 3
#define KOLOM 3

int main()
{
    // Matriks A: target produksi (baris = pabrik, kolom = jenis mainan)
    int produksi[BARIS][KOLOM];

    // Matriks B: kebutuhan komponen (baris = jenis mainan, kolom = baterai, roda, lampu)
    int komponen[BARIS][KOLOM];

    // Matriks C: hasil perkalian A x B (baris = pabrik, kolom = total komponen)
    int total[BARIS][KOLOM];

    // Matriks salinan dari A
    int arsip_produksi[BARIS][KOLOM];

    // Variabel indeks perulangan
    int i, j, k;

    // Penanda: 1 jika ditemukan angka 0 di matriks C, 0 jika tidak
    int adaNol = 0;

    // ===== INPUT MATRIKS A =====
    printf("=== Input Target Produksi (Matriks A) ===\n");
    for (i = 0; i < BARIS; i++)
    {
        for (j = 0; j < KOLOM; j++)
        {
            printf("Pabrik %d, mainan %d: ", i + 1, j + 1);
            scanf("%d", &produksi[i][j]);
        }
    }

    // ===== INPUT MATRIKS B =====
    printf("\n=== Input Kebutuhan Komponen (Matriks B) ===\n");
    for (i = 0; i < BARIS; i++)
    {
        for (j = 0; j < KOLOM; j++)
        {
            printf("Mainan %d, komponen %d: ", i + 1, j + 1);
            scanf("%d", &komponen[i][j]);
        }
    }

    // ===== COPY MATRIKS A KE ARSIP_PRODUKSI =====
    for (i = 0; i < BARIS; i++)
    {
        for (j = 0; j < KOLOM; j++)
        {
            arsip_produksi[i][j] = produksi[i][j];
        }
    }

    // ===== PERKALIAN MATRIKS: C = A x B =====
    for (i = 0; i < BARIS; i++)
    {
        for (j = 0; j < KOLOM; j++)
        {
            // Mengosongkan elemen sebelum dijumlahkan
            total[i][j] = 0;

            // Menjumlahkan hasil kali baris A ke-i dengan kolom B ke-j
            for (k = 0; k < BARIS; k++)
            {
                total[i][j] += produksi[i][k] * komponen[k][j];
            }

            // Mengecek apakah elemen hasil bernilai 0
            if (total[i][j] == 0)
            {
                adaNol = 1;
            }
        }
    }

    // ===== OUTPUT: ARSIP PRODUKSI =====
    printf("\n=== Arsip Produksi ===\n");
    for (i = 0; i < BARIS; i++)
    {
        for (j = 0; j < KOLOM; j++)
        {
            printf("%d\t", arsip_produksi[i][j]);
        }
        printf("\n");
    }

    // ===== OUTPUT: HASIL PERKALIAN =====
    printf("\n=== Total Kebutuhan Komponen per Pabrik ===\n");
    printf("(Baterai\tRoda\tLampu)\n");
    for (i = 0; i < BARIS; i++)
    {
        for (j = 0; j < KOLOM; j++)
        {
            printf("%d\t", total[i][j]);
        }
        printf("\n");
    }

    // ===== OUTPUT: HASIL PENCARIAN NILAI 0 =====
    if (adaNol == 1)
    {
        printf("\nAda komponen yang tidak dibutuhkan sama sekali pada pabrik tertentu.\n");
    }

    return 0;
}