#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct node // deklarasi struct yang isinya
{
    char nama[20], alamat[20];
    long long int nim;
    node *next;
};
node *kepala, *ekor, *baru, *bantu, *hapus, *awal, *akhir; // deklrasi pointer

void newNode(); // inisialisasi fungsi-fungsi
bool cekList();
void dataNode();
void sisipData();
void lihatDataMaju();
void lihatDataMundur();
void hapusNode();

int main() // main
{
    int menu;
    char back, backMetode, metode;
    newNode(); // membuat node baru ketika program dirun pertama kali
    do
    {
        cout << endl; // tampilan awal
        cout << "++++++ PROGRAM LINKED LIST Kepala & Ekor ++++++" << endl;
        cout << endl;
        cout << "Disini Tersedia :" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Lihat Data Maju" << endl;
        cout << "3. Lihat Data Mundur" << endl;
        cout << "4. Hapus data" << endl;
        cout << "Pilih Menu : ";
        cin >> menu;
        system("cls");
        switch (menu) // percabangan untuk memilih menu
        {
        case 1:
            sisipData();
            break;
        case 2:
            lihatDataMaju();
            break;
        case 3:
            lihatDataMundur();
            break;
        case 4:
            hapusNode();
            break;
        default:
            cout << "Menu tidak ada";
            break;
        }
        cout << endl;
        cout << "Kembali Ke Menu ? (y/n) ";
        cin >> back;
        system("cls");
    } while (back == 'y' || back == 'Y'); // kondisi untuk kembali ke menu

    return 0;
}

void newNode() // fungsi untuk membuat node awal
{
    kepala = new node;
    ekor = new node;
    kepala->nim = -1;
    kepala->next = ekor;
    ekor->nim = 9999999999;
    ekor->next = NULL;
}

bool cekList() // cek list apakah kosong/tidak
{
    return kepala->next == ekor;
}

void dataNode() // inputdan untuk data
{
    cout << "Masukkan NIM\t : ";
    cin >> baru->nim;
    cout << "Masukkan Nama\t : ";
    cin >> baru->nama;
    cout << "Masukkan Alamat\t : ";
    cin >> baru->alamat;
}

void sisipData() // sisip data (karena kepala ekor jadinya cuma sisip tengah)
{
    int jumlahData;
    cout << endl;
    cout << "Sisip Data" << endl;
    cout << "Masukkan Jumlah Data : ";
    cin >> jumlahData;
    for (int i = 1; i <= jumlahData; i++)
    {
        baru = new node;
        cout << endl;
        cout << "Data ke-" << i << endl;
        dataNode();
        baru->next = NULL;
        bantu = kepala;
        while (baru->nim > bantu->next->nim)
        {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void lihatDataMaju() // lihat data maju
{
    if (cekList())
    {
        cout << "Input Data Dulu!";
    }
    else
    {
        if (kepala->nim > kepala->next->nim)
        {
            awal = kepala;
            kepala = ekor;

            do
            {
                bantu = awal;
                while (bantu->next != ekor)
                    bantu = bantu->next;
                ekor->next = bantu;
                ekor = bantu;

            } while (ekor != awal);

            ekor->next = NULL;
        }
        bantu = kepala->next;
        cout << "Baca Data Maju" << endl;
        while (bantu != ekor)
        {
            cout << endl;
            cout << "NIM\t : " << bantu->nim << endl;
            cout << "Nama\t : " << bantu->nama << endl;
            cout << "Alamat\t : " << bantu->alamat << endl;
            bantu = bantu->next;
        }
    }
}

void lihatDataMundur() // lihat data mundur
{
    if (cekList())
    {
        cout << "Input Data Dulu!";
    }
    else
    {
        if (kepala->nim < kepala->next->nim)
        {
            awal = kepala;
            kepala = ekor;

            do
            {
                bantu = awal;
                while (bantu->next != ekor)
                {
                    bantu = bantu->next;
                }
                ekor->next = bantu;
                ekor = bantu;

            } while (ekor != awal);

            ekor->next = NULL;
        }
        bantu = kepala->next;
        cout << "Baca Mundur" << endl;
        while (bantu != ekor)
        {
            cout << endl;
            cout << "NIM\t : " << bantu->nim << endl;
            cout << "Nama\t : " << bantu->nama << endl;
            cout << "Alamat\t : " << bantu->alamat << endl;
            bantu = bantu->next;
        }
    }
}

void hapusNode() // hapus data (jdinya cuma hapus tengah)
{
    long int hapusNIM;
    if (cekList())
    {
        cout << "Input Data Dulu";
    }
    else
    {
        cout << "Masukkan NIM yang ingin dihapus : ";
        cin >> hapusNIM;
        bantu = kepala;
        while (bantu->next != ekor && hapusNIM != bantu->next->nim)
        {
            bantu = bantu->next;
        }
        if (hapusNIM == bantu->next->nim)
        {
            hapus = bantu->next;
            bantu->next = hapus->next;
            free(hapus);
            cout << "Data dengan NIM " << hapusNIM << " Terhapus!";
        }
        else
        {
            cout << "NIM tidak ditemukan";
        }
    }
}
