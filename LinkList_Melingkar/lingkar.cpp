#include <iostream>
#include <malloc.h>
using namespace std;

typedef int tipeinfo;
typedef struct node *tipeptr;
struct node
{
    tipeinfo info;
    tipeptr next;
};

tipeptr kepala;

int jmlnode = 0, pilihan, angka;
char loop = 'y';

bool listkosong();
void buatlist();
void sisipnode(tipeinfo IB);
void hapusnode(tipeinfo IH);
void cetakdepan();
void cetaktengah(tipeinfo IC);

int main()
{
    buatlist();
    while (loop == 'y' || loop == 'Y')
    {
        printf("Pilihan : \n");
        printf("1. Sisip Node \n");
        printf("2. Hapus Node \n");
        printf("3. Cetak Depan \n");
        printf("4. Cetak Tengah \n");
        printf("5. Sisip Auto \n");
        printf("Input Pilhan [1...5] : ");
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            printf("==== Sisip Node ====\n\n");
            printf("Masukkan node : ");
            cin >> angka;
            sisipnode(angka);
            cetakdepan();
            cout << endl;
            break;

        case 2:
            printf("==== Hapus Node ====\n\n");
            printf("Masukkan node : ");
            cin >> angka;
            hapusnode(angka);
            cetakdepan();
            cout << endl;
            break;

        case 3:
            printf("==== Cetak Depan ====\n\n");
            cetakdepan();
            cout << endl;
            break;

        case 4:
            printf("==== Cetak Node ====\n\n");
            printf("Masukkan node : ");
            cin >> angka;
            cout << endl;
            cetaktengah(angka);
            cout << endl;
            break;

        case 5:
            printf("Auto . . . .\n ");
            for (int i = 10; i <= 50; i += 10)
            {
                sisipnode(i);
            }
            cetakdepan();
            cout << endl;
            break;

        default:
            printf("Input Salah\n");
            break;
        }

        printf("Kembali ke menu ? (y/n) : ");
        cin >> loop;
        system("cls");
    }
    return 0;
}

bool listkosong()
{
    if (kepala->next == kepala)
        return (1);
    else
        return (0);
}


void buatlist()
{
    kepala = (node *)malloc(sizeof(node));
    kepala->info = 0;
    kepala->next = kepala;
}
void sisipnode(tipeinfo IB)
{
    tipeptr NB, bantu;
    NB = (node *)malloc(sizeof(node));
    NB->info = IB;
    NB->next = NULL;
    if (listkosong())
    {
        NB->next = kepala;
        kepala->next = NB;
        jmlnode++;
        kepala->info = jmlnode;
    }
    else
    {
        bantu = kepala;
        while (bantu->next->info < IB && bantu->next != kepala)
            bantu = bantu->next;
        if (bantu->next != kepala)
        {
            NB->next = bantu->next;
            bantu->next = NB;
        }
        else
        {
            NB->next = kepala;
            bantu->next = NB;
        }
    }
    jmlnode++;
    kepala->info = jmlnode;
}

void hapusnode(tipeinfo IH)
{
    tipeptr hapus, bantu;
    if (listkosong())
        puts("Linked List masih kosong");
    else
    {
        bantu = kepala;
        while (bantu->next->info != IH && bantu->next != kepala)
            bantu = bantu->next;
        if (bantu->next != kepala)
        {
            hapus = bantu->next;
            bantu->next = hapus->next;
            free(hapus);
        }
        else
        {
            hapus = bantu->next;
            bantu->next = kepala;
            free(hapus);
        }
        jmlnode--;
        kepala->info = jmlnode;
    }
}

void cetakdepan()
{
    if (listkosong())
    {
        puts("Linked List masih kosong");
    }
    else
    {
        tipeptr bantu;
        bantu = kepala->next;
        while (bantu != kepala)
        {
            printf("%d  ", bantu->info);
            bantu = bantu->next;
        }
    }
}

void cetaktengah(tipeinfo IC) // deklarasi fungsi cetak dari tengah
{
	tipeinfo jumlah = 0;
        tipeptr bantu; // deklarasi bantu
        bantu = kepala->next; // bantu mulai dari node pertama
    
        while (bantu->info != IC && bantu->next != kepala) // mencari nilai yang akan di print
            bantu = bantu->next;

        do
        {
            if (bantu == kepala) // jika bertemu kepala
                bantu = bantu->next;
            else
            {
                printf("%d  ", bantu->info); // output nilai yang di print
                //cout << bantu->info << " ";
                bantu = bantu->next;
                jumlah = jumlah + bantu->info;
            }
        } while (bantu->info != IC); // berhenti jika kembali ke nilai yang diinginkan
        // cout << endl;
//         cout << jumlah + pilihan << endl;
}
