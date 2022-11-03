#include <iostream>
using namespace std;


struct node
{
    int angka;
    node *next;
};
node *baru, *awal, *akhir, *bantu, *kepala, *depan, *hapus, *jumlah;


int jmlNode = 0;
void newList();
bool cekList();
void sisipNode();
void bacaDataDepan();
void bacaTengah();
void hapusNode();

int main()
{

    int pilih;
    char back;

    newList();
    do
    {
        cout << "++++ PROGRAM LINKED LIST MELINGKAR ++++" << endl;
        cout << "Pilihan Menu" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Lihat Data Depan" << endl;
        cout << "3. Lihat Data Tengah" << endl;
        cout << "4. Hapus Data"<<endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilih;
        system("cls");
        switch (pilih)
        {
        case 1:
            sisipNode();
            break;
        case 2:
            bacaDataDepan();
            break;
        case 3:
            bacaTengah();
            break;
        case 4 :
            hapusNode();
            break;
        default:
            cout<<"Pilihan Tidak adaa!";
            break;
        }
        cout << endl;
        cout << "Kembali ke Menu ? (y/n) ";
        cin >> back;
        system("cls");
    } while (back == 'y' || back == 'Y');
}

void newList()
{
    kepala = new node;
    kepala->angka = 0;
    kepala->next = kepala;
}

bool cekList()
{
    return kepala->next == kepala;
}

void sisipNode()
{
    int jumlahData;
    cout << "Masukkan Jumlah data : ";
    cin >> jumlahData;
    for (int i = 1; i <= jumlahData; i++)
    {
        baru = new node;
        cout << "input angka ke "<<i<<" : ";
        cin >> baru->angka;
        baru->next = NULL;
        if (cekList())
        {
            baru->next = kepala;
            kepala->next = baru;
            jmlNode++;
            kepala->angka = jmlNode;
        }
        else
        {
            bantu = kepala;
            while (bantu->next != kepala && baru->angka > bantu->next->angka)
            {
                bantu = bantu->next;
            }
            if (bantu->next != kepala)
            {
                baru->next = bantu->next;
                bantu->next = baru;
            }
            else
            {
                baru->next = kepala;
                bantu->next = baru;
            }
            jmlNode++;
            kepala->angka = jmlNode;
        }
    }
}

void bacaDataDepan()
{
    if (cekList())
    {
        cout << "Input Data Dulu!";
    }
    else
    {
        bantu = kepala->next;
        cout << "==== Data ====" << endl;
        while (bantu != kepala)
        {
            cout << bantu->angka << ", ";
            bantu = bantu->next;
        }
    }
    cout<<endl;
    cout<<"Banyak Node : "<<kepala->angka;
}

void bacaTengah()
{
    int angkaTangah;
    jumlah = 0;
    cout << "Input Angka Tengah : ";
    cin >> angkaTangah;
    bantu = kepala->next;
    while (bantu->angka != angkaTangah && bantu->next != kepala)
    {
        bantu = bantu->next;
    }
    do
    {
        if (bantu == kepala)
        {
            bantu = bantu->next;
        }
        else
        {
            cout  << bantu->angka<< ", ";
            bantu = bantu->next;
        }
    } while (bantu->angka != angkaTangah);
    cout<<endl;
    cout<<"Banyak Node : "<<kepala->angka;
}

void hapusNode()
{
    int infoHapus;
    if (cekList())
    {
        cout << "Input Data Dulu!";
    }
    else
    {
        cout << "Masukkan Angka : ";
        cin >> infoHapus;
        bantu = kepala;
        while (bantu->next->angka != infoHapus && bantu->next != kepala)
        {
            bantu = bantu->next;
        }
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
        jmlNode--;
        kepala->angka = jmlNode;
        cout<<endl;
        cout<<"Data "<<infoHapus<<" Terhapus!"<<endl;
    }
    bacaDataDepan();
    cout<<endl;

}