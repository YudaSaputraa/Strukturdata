#include <iostream>
using namespace std;

struct node
{
    int angka;
    node *next;
};
node *baru, *awal, *akhir, *bantu, *kepala, *depan, *hapus;

void newList();
int cekList();
void sisipNode();
void bacaData();
void cetakListBelakang();
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
        cout << "2. Lihat Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilih;
        system("cls");
        switch (pilih)
        {
        case 1:
            sisipNode();
            break;
        case 2:
            bacaData();
            break;
        case 3:
            hapusNode();
            break;
        default:
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

int cekList()
{
    if (kepala->next == kepala)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sisipNode()
{

    baru = new node;
    cout << "input angka : ";
    cin >> baru->angka;
    baru->next = NULL;
    if (cekList())
    {
        baru->next = kepala; // sisip depan
        kepala->next = baru;
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
    }
}

void bacaData()
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
            cout << bantu->angka <<", ";
            bantu = bantu->next;
        }
    }
}

void hapusNode(){
    if(cekList()){
        cout<<"Input Data Dulu!";
    }else{
        int infoHapus;
        cout<<"Masukkan Angka : ";
        cin>>infoHapus;
        bantu = kepala;
        while(bantu -> next -> angka != infoHapus && bantu -> next != kepala){
            bantu = bantu->next;
        }
        if(bantu -> next != kepala){
            hapus = bantu -> next;
            bantu->next = hapus->next;
            free(hapus);
        }else{
            hapus = bantu -> next;
            bantu -> next = kepala;
            free(hapus);
        }
    }
}