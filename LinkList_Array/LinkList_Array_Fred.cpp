#include <iostream>
#include <cstring>

using namespace std;

typedef struct
{
    char namaBuah[20];
    float hargaBuah;
    int next;
} typenode;

typenode elemen[11];
int list, akhirlist, kosong, akhirkosong;

void makeList()
{
    list = 5;
    kosong = 3;
    akhirkosong = 10;

    elemen[1].next = 8;
    elemen[2].next = 9;
    elemen[3].next = 6;
    elemen[4].next = 0;
    elemen[5].next = 7;
    elemen[6].next = 2;
    elemen[7].next = 1;
    elemen[8].next = 10;
    elemen[9].next = 4;
    elemen[10].next = 0;
}

int listkosong()
{
    if (list == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sisipnode(char baru[], float HargaB)
{
    int listnew, k, m, n;
    char x[20];

    if (baru < elemen[list].namaBuah || listkosong())
    {
        listnew = kosong;
        kosong = elemen[kosong].next;
        strcpy(elemen[listnew].namaBuah, baru);
        elemen[listnew].hargaBuah = HargaB;
        elemen[listnew].next = list;
        list = listnew;
    }
    else if (baru > elemen[akhirlist].namaBuah)
    {
        listnew = kosong;
        kosong = elemen[kosong].next;
        strcpy(elemen[listnew].namaBuah, baru);
        elemen[listnew].hargaBuah = HargaB;
        elemen[listnew].next = 0;
        elemen[akhirlist].next = listnew;
        akhirlist = listnew;
    }
    else
    {
        n = list;
        strcpy(x, elemen[n].namaBuah);
        while (baru > x)
        {
            m = n;
            n = elemen[n].next;
            strcpy(x, elemen[n].namaBuah);
        }
        k = elemen[kosong].next;
        elemen[m].next = kosong;
        strcpy(elemen[kosong].namaBuah, baru);
        elemen[kosong].hargaBuah = HargaB;
        elemen[kosong].next = n;
        kosong = k;
    }
}

void cetaklist()
{
    int n;
    n = list;

    cout << "==== Data ====\n";

    do
    {
        if (elemen[n].hargaBuah != 0)
        {
            cout << "Nama Buah\t: " << elemen[n].namaBuah << endl
                 << "Harga Buah\t: " << elemen[n].hargaBuah << endl
                 << endl;
        }
        n = elemen[n].next;
    } while (elemen[n].next != 0);
}

void hapusnode(char NaH[])
{
    int listnew, k;
    //------------------------ hapus di awal
    if (NaH == elemen[list].namaBuah)
    {
        listnew = elemen[list].next;
        k = kosong;
        kosong = list;
        list = listnew;
        elemen[kosong].next = k;
    }
}

void SisipData()
{
    char namabuah[20];
    float hargabuah;
    int jmlData;

    system("cls");
    cout << "SISIP DATA" << endl
         << "----------" << endl
         << "Banyak Data\t: ";
    cin >> jmlData;
    cout << endl
         << endl;
    for (int i = 0; i < jmlData; i++)
    {
        cout << "Buah ke-" << i + 1 << endl
             << "------" << endl;
        cout << "Nama Buah\t: ";
        cin >> namabuah;
        cout << "Harga Buah\t: ";
        cin >> hargabuah;
        cout << endl;
        sisipnode(namabuah, hargabuah);
    }
}

void HapusData()
{
    char hapusbuah[20];

    system("cls");
    cout << "HAPUS DATA" << endl
         << "----------" << endl;
    cout << "Nama Buah : ";
    cin >> hapusbuah;
    hapusnode(hapusbuah);
}

main()
{
    makeList();

    int pilihmenu;
    char back;

    do
    {
        system("cls");
        cout << "Data Nama Buah" << endl
             << "1. Sisipkan Buah" << endl
             << "2. Cetak List Buah" << endl
             << "3. Hapus Data" << endl
             << "pilih : ";
        cin >> pilihmenu;

        switch (pilihmenu)
        {
        case 1:
            SisipData();
            break;
        case 2:
            cetaklist();
            break;
        case 3:
            HapusData();
            break;
        default:
            cout << "Pilihan tidak tersedia!" << endl;
        }

        cout << "back ke menu? (y/n) ";
        cin >> back;
    } while (back == 'y' || back == 'Y');
}
