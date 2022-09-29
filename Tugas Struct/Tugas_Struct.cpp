#include <iostream>
using namespace std;

struct data
{
  string nama, alamat;
  int nim;
} biodata[50];

int jumlah;

void _inputData();
void _LihatData();
void _cariData();
void cariNim();
void cariNama();

int main()
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

    switch (pilihan)
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
    cout << "Kembali Ke Menu ? (y/n) ";
    cin >> back;
    system("cls");
  } while (back == 'Y' || back == 'y');
}

void _inputData()
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

void _LihatData()
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

void _cariData()
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
    switch (metode)
    {
    case 1:
      cariNim();

      break;
    case 2:
      cariNama();

    default:
      break;
    }
    cout << endl;
    cout << "Ganti Metode ? (Y/N)";
    cin >> method;
    system("cls");
  } while (method == 'y' || method == 'Y');
}

void cariNim()
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

void cariNama()
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
