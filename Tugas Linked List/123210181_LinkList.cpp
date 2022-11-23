#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct node // inisialisasi struct/record dengan nama, alamat, nim, id, pointer next
{
  string nama, alamat;
  int nim, id;
  node *next;
};
node *awal, *akhir, *baru, *bantu, *hapus; // inisialisasi pointer awal, akhir, baru, dll

void newNode(); // inisialisasi fungsi-fungsi
int cekList();
void infoNode();
void sisipNode();
void sisipDepan();
void sisipBelakang();
void sisipTengah();
void lihatData();
void hapusNode();

int main() // main
{
  int menu;
  char back, backMetode, metode;
  do
  {
    cout << endl;
    cout << "++++++ PROGRAM LINKED LIST nihh ++++++" << endl; // tampilan awal
    cout << "Disini Tersedia :" << endl;
    cout << "1. Input Data" << endl;
    cout << "2. Lihat Data" << endl;
    cout << "3. Hapus data" << endl;
    cout << "Pilih Menu : ";
    cin >> menu;
    system("cls");
    switch (menu) // percabangan pemilihan menu
    {
    case 1:
      sisipNode();
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
  } while (back == 'y' || back == 'Y'); // kondisi untuk kembali ke menu dengan do-while
}

void newNode() // fungsi membuat node baru
{
  awal = NULL;
  akhir = NULL;
}

int cekList() // fungsi cek list apakah kosong/tidak
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

void infoNode() // inputan untuk struct
{
  cout << "Masukkan Id\t : ";
  cin >> baru->id;
  cin.ignore();
  cout << "Masukkan Nama\t : ";
  getline(cin, baru->nama);
  cout << "Masukkan NIM\t : ";
  cin >> baru->nim;
  cout << "Masukkan Alamat\t : ";
  cin >> baru->alamat;
}

void sisipNode() // fungsi sisip node(awal, tengah akhir)
{
  cout << "-- Sisip data --" << endl;
  baru = new node;
  infoNode();
  if (cekList())
  {
    awal = baru;
    akhir = baru; // jika list kosong
  }
  else if (baru->id <= awal->id)
  {
    baru->next = awal; // sisip depan
    awal = baru;
  }
  else
  {
    bantu = awal;
    while (bantu->next != NULL && baru->id > bantu->next->id)

      bantu = bantu->next;
    baru->next = bantu->next; // sisip tengah dan akhir
    bantu->next = baru;
    if (baru->id > akhir->id)
    {
      akhir = baru;
    }
  }
}

void lihatData() // fungsi untuk mencetak data
{
  bantu = awal;
  cout << "=== Data ===" << endl;
  if (cekList()) // cek kondisi kosong atau tidak
  {
    cout << "Data masih kosong!" << endl;
  }
  else
  {
    while (bantu != NULL) // kondisi untuk mencetak
    {
      cout << endl;
      cout << "Id\t : " << bantu->id << endl; // mencetak data
      cout << "Nama\t : " << bantu->nama << endl;
      cout << "NIM\t : " << bantu->nim << endl;
      cout << "Alamat \t : " << bantu->alamat << endl;
      bantu = bantu->next;
    }
  }
}

void hapusNode() // fungsu untuk hapus node
{
  int nimm;      // variable untuk memasukkan nim yang mau dihapus
  if (cekList()) // cek list kosong/tidak
  {
    cout << "Data Masih Kosong" << endl;
  }
  else // jika tidak kosong
  {
    lihatData();
    cout << "Masukkan NIM yang mau dihapus : ";
    cin >> nimm;
    if (awal->nim == nimm) // hapus depan
    {
      hapus = awal;
      awal = hapus->next;
      free(hapus);
      cout << "Data Terhapus" << endl;
    }
    else // hapus tengah dan akhir
    {
      bantu = awal;

      while (nimm != bantu->next->nim && bantu->next->next != NULL)
        bantu = bantu->next;
      if (nimm == bantu->next->nim)
      {
        hapus = bantu->next;

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
        cout << "Data Terhapus" << endl;
      }
      else // jika data tidak tidemukan
      {
        cout << "Data tidak ditemukan!" << endl;
      }
    }
  }
}
