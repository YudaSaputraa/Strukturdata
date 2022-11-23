#include <iostream>
using namespace std;

struct data // membuat struct/record dengan nama, alamat dan nim
{
    string nama, alamat;
    int nim;
} biodata[50];

int jumlah;

void _inputData(); // deklarasi fungsi input data
void _LihatData(); // deklarasi fungsi lihat data
void _cariData();  // deklarasi fungsi cari data
void cariNim();    // deklarasi fungsi cari berdasarkan nim
void cariNama();   // deklarasi fungsi cari berdasarkan nama

int main() // main
{
    int pilihan;
    char back;
    do
    {
        cout << "Menu : " << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Lihat data" << endl;
        cout << "3. Cari data" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) // percabangan untuk memilih menu 1, 2, 3
        {
        case 1:
            _inputData();
            break;
        case 2:
            _LihatData();
            break;
        case 3:
            _cariData();
            break;
        }
        cout << endl;
        cout << "Kembali Ke Menu ? (y/n) "; // kondisi untuk kembali ke menu utama dengan looping do-while
        cin >> back;
        system("cls");
    } while (back == 'Y' || back == 'y'); // kondisi while
}

void _inputData() // fungsi input data
{
    cout << "--- Input Data ---" << endl;
    cout << "Masukkan Jumlah Data : ";
    cin >> jumlah;
    for (int i = 1; i <= jumlah; i++)
    {
        cout << endl;
        cout << "data ke-" << i << endl;
        cout << "Input Nama\t : ";
        cin >> biodata[i].nama;
        cout << "Input NIM\t : ";
        cin >> biodata[i].nim;
        cout << "Input Alamat\t : ";
        cin >> biodata[i].alamat;
    }
}

void _LihatData() // fungsi lihat data
{
    cout << endl;
    cout << "--- Data Mahasiswa ---" << endl;
    for (int x = 1; x <= jumlah; x++)
    {
        cout << endl;
        cout << "Data ke-" << x << endl;
        cout << "NIM\t: " << biodata[x].nim << endl;
        cout << "Nama\t: " << biodata[x].nama << endl;
        cout << "Alamat\t: " << biodata[x].alamat << endl;
    }
}

void _cariData() // fungsi cari data
{
    char method;
    do
    {
        int metode;
        cout << endl;
        cout << "Metode Pencarian data" << endl;
        cout << "1. Berdasarkan NIM" << endl;
        cout << "2. Berdasarkan Nama" << endl;
        cout << "Pilih Metode : ";
        cin >> metode;
        switch (metode) // percabangan untuk memilih metode pencarian data berdasarkan nim atau nama
        {
        case 1:
            cariNim(); // pemanggilan fungsi pencarian data berdasarkan nim

            break;
        case 2:
            cariNama(); // pemanggilan fungsi pencarian data berdasarkan nama

        default:
            break;
        }
        cout << endl;
        cout << "Ganti Metode ? (Y/N)"; // kondisi untuk ganti metode dengan do-while
        cin >> method;
        system("cls");
    } while (method == 'y' || method == 'Y');
}

void cariNim() // fungsi cari data dengan nim
{
    cout << endl;
    cout << "-- Cari Data Berdasarkan NIM --" << endl;
    int cariNim, i, flag = 0;
    cout << "NIM yang dicari : ";
    cin >> cariNim;
    for (i = 1; i <= jumlah; i++)
    {
        if (biodata[i].nim == cariNim)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << endl;
        cout << "Nama\t\t : " << biodata[i].nama << endl;
        cout << "NIM\t\t : " << biodata[i].nim << endl;
        cout << "Alamat\t\t : " << biodata[i].alamat << endl;
    }
    else
    {
        cout << "Tidak ada Mahasiswa yang mempunyai nim " << cariNim << endl;
    }
}

void cariNama() // fungsi cari data dengan nama
{
    cout << endl;
    cout << "-- Cari Data Berdasarkan Nama --" << endl;
    string cariNama;
    int i, flag = 0;
    cout << "Nama yang dicari : ";
    cin >> cariNama;
    for (i = 1; i <= jumlah; i++)
    {
        if (biodata[i].nama == cariNama)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << endl;
        cout << "Nama\t\t : " << biodata[i].nama << endl;
        cout << "NIM\t\t : " << biodata[i].nim << endl;
        cout << "Alamat\t\t : " << biodata[i].alamat << endl;
    }
    else
    {
        cout << "Tidak ada Mahasiswa yang bernama " << cariNama << endl;
    }
}
