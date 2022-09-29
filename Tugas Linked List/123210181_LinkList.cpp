#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct node
{
    string nama, alamat;
    int nim, id;
    node *next;
};
node *awal, *akhir, *baru, *bantu, *hapus;

int idd;

void newNode();
int cekList();
void infoNode();
void sisipDepan();
void sisipBelakang();
void sisipTengah();
void lihatData();
void hapusNode();

int main()
{
    int menu;
    char back, backMetode, metode;
    do
    {
        cout << endl;
        cout << "++++++ PROGRAM LINKED LIST nihh ++++++" << endl;
        cout << "Disini Tersedia :" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Lihat Data" << endl;
        cout << "3. Hapus data" << endl;
        cout << "Pilih Menu : ";
        cin >> menu;
        system("cls");
        switch (menu)
        {
        case 1:
            do
            {
                cout << "---- Mau Input Data Dari Sisi Mana? ---- " << endl;
                cout << "1. Input Data Depan" << endl;
                cout << "2. Input Data Belakang" << endl;
                cout << "3. Input Data Tengah" << endl;
                cout << "Saya memilih : ";
                metode = getch();
                switch (metode)
                {
                case '1':
                    sisipDepan();
                    break;
                case '2':
                    sisipBelakang();
                    break;
                case '3':
                    sisipTengah();
                    break;
                default:
                    cout << "Pilih Menu yang ada saja yaa!" << endl;
                    break;
                }
                cout << endl;
                cout << "Pilih Metode Lain ? (y/n) ";
                backMetode = getch();
                system("cls");
            } while (backMetode == 'y' || backMetode == 'Y');
            break;

        case 2:
            lihatData();
            break;
        case 3:
            hapusNode();
            break;
        default:
            break;
        }
        cout << endl;
        cout << "Kembali Ke Menu ? (y/n) ";
        cin >> back;
        system("cls");
    } while (back == 'y' || back == 'Y');
}

void newNode()
{
    awal = NULL;
    akhir = NULL;
}

int cekList()
{
    if (akhir == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infoNode()
{
    cout << "Masukkan Id\t : ";
    cin >> baru->id;
    cout << "Masukkan Nama\t : ";
    cin >> baru->nama;
    cout << "Masukkan NIM\t : ";
    cin >> baru->nim;
    cout << "Masukkan Alamat\t : ";
    cin >> baru->alamat;
}

void sisipDepan()
{
    cout << endl;
    cout << "Sisip Depan" << endl;
    baru = new node;
    infoNode();
    baru->next = awal;
    awal = baru;
    akhir = baru;
}

void sisipBelakang()
{
    cout << endl;
    cout << "Sisip Belakang" << endl;
    baru = new node;
    infoNode();
    baru->next = NULL;
    akhir->next = baru;
    akhir = baru;
}

void sisipTengah()
{
    cout << endl;
    cout << "Sisip Tengah" << endl;
    baru = new node;
    cout << "Masukkan Id\t : ";
    cin >> baru->id;
    cout << "Masukkan Nama\t : ";
    cin >> baru->nama;
    cout << "Masukkan NIM\t : ";
    cin >> baru->nim;
    cout << "Masukkan Alamat\t : ";
    cin >> baru->alamat;
    baru->next = NULL;
    bantu = awal;
    while (bantu->next->id < baru->id) // ketika false
    {
        bantu = bantu->next;
    }
    baru->next = bantu->next;
    bantu->next = baru;
}

void lihatData()
{
    bantu = awal;
    cout << "=== Data ===" << endl;
    while (bantu != NULL)
    {
        cout << endl;
        cout << "Nama\t : " << bantu->nama << endl;
        cout << "NIM\t : " << bantu->nim << endl;
        cout << "Alamat \t : " << bantu->alamat << endl;
        bantu = bantu->next;
    }
}

void hapusNode()
{

    if (cekList())
    {
        cout << "Data Masih Kosong" << endl;
    }
    else
    {
    cout << "Masukkan Id Node : ";
    cin >> idd;
        if (awal->id == idd)
        {
            hapus = awal;
            awal = hapus->next;
            free(hapus);
            cout << "Data Terhapus" << endl;
        }
        else
        {
            bantu = awal;
            while (bantu->next->id != idd && bantu->next != NULL)
            {
                bantu = bantu->next;
            }
            hapus = bantu->next;
            if (hapus == NULL)
            {
                cout << "Node Tidak Ditemukan" << endl;
            }
            else
            {
                if (hapus == akhir)
                {
                    akhir = bantu;
                    akhir->next = NULL;
                }
                else
                {
                    bantu->next = hapus->next;
                }
                free(hapus);
                system("cls");
                cout << "Data Terhapus" << endl;
            }
        }
    }
}
