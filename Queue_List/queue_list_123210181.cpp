#include <iostream>
#include <stdlib.h>
using namespace std;

struct queues // deklrasari struct dengan nama, nim dan pointer next
{
  string nama;
  int nim;
  queues *next;
};
queues *qDepan, *qBelakang, *queueBaru, *hapus, *bantu; // deklarasi pointer qdepan,dll

int maxQueue; // variabel untuk menyimpan maxQueue

int _banyakQueue() // fungsi untuk menghitung banyak queue
{
  if (qDepan == NULL)
  {
    return 0;
  }
  else
  {
    int banyak = 0;
    bantu = qDepan;
    while (bantu != NULL)
    {
      bantu = bantu->next;
      banyak++;
    }
    return banyak;
  }
}

bool _kosong() // fungsi untuk cek queue kosong/tidak
{
  if (_banyakQueue() == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool _full() // fungsi untuk cek apakah queue sudah penuh/belum
{
  if (_banyakQueue() == maxQueue)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void _inputDepan() // fungsi input queue depan
{
  cout << "Nama\t : ";
  cin >> qDepan->nama;
  cout << "NIM\t : ";
  cin >> qDepan->nim;
}

void _inputBaru() // input queue baru
{
  cout << "Nama\t : ";
  cin >> queueBaru->nama;
  cout << "NIM\t : ";
  cin >> queueBaru->nim;
}
void _enqueue() // input data queue
{
  if (_full()) // cek kondisi apakah queue penuh/tidak
  {
    cout << "Antrian Penuh!!!" << endl;
  }
  else // jika tidak penuh
  {

    if (_kosong()) // cek jika queue kosong
    {
      qDepan = new queues();
      _inputDepan();
      qDepan->next = NULL;
      qBelakang = qDepan;
    }
    else // queue jika tidak kosong
    {
      queueBaru = new queues();

      _inputBaru();
      queueBaru->next = NULL;
      qBelakang->next = queueBaru;
      qBelakang = queueBaru;
    }
  }
}

void _dequeue() // fungsi dequeue atau hapus data
{
  if (_kosong()) // kondisi queue jika kosong
  {
    cout << "Antrian Masih Kosong!" << endl;
  }
  else // kondisi jika queue tidak kosong
  {
    bantu = qDepan;
    cout << "---- Antrian Dengan ---- " << endl;

    cout << "Nama\t : " << bantu->nama << endl;
    cout << "NIM\t : " << bantu->nim << endl;

    cout << "---- Dipersilahkan Masuk ---- " << endl;
    hapus = qDepan;
    qDepan = hapus->next;
    hapus->next = NULL;
    free(hapus);
  }
}

void _cetakQueue() // fungsi cetak data queue
{
  if (_kosong()) // kondisi jika kosong
  {
    cout << "Data Antrian Kosong!" << endl;
  }
  else // kondisi jika queue tidak kosong
  {
    cout << "Banyak Antrian : " << _banyakQueue() << endl;
    bantu = qDepan;
    int no = 1;
    while (no <= maxQueue)
    {
      if (bantu != NULL)
      {
        cout << no << ". " << bantu->nama << " - " << bantu->nim << endl;
        bantu = bantu->next;
      }
      else
      {
        cout << no << ". "
             << "(Kosong)" << endl;
      }
      no++;
    }
  }
}

int main() // main
{
  int pilih;
  char back;
  cout << endl;
  cout << "Masukkan Maksimal data : ";
  cin >> maxQueue;

  do
  {
    system("cls");
    cout << endl; // tampilan awal
    cout << "==== PROGRAM ANTRIAN PSIKOLOGIS ====" << endl;
    cout << "Menu :" << endl;
    cout << "1. Daftar" << endl;
    cout << "2. Antrian" << endl;
    cout << "3. Masuk Ruangan" << endl;
    cout << "4. Exit" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    switch (pilih) // percabangan untuk memilih menu
    {
    case 1:
      cout << "---- Form Pendaftaran ----" << endl;
      _enqueue();
      break;
    case 2:
      cout << "---- Data Antrian ----" << endl;
      _cetakQueue();
      break;
    case 3:

      _dequeue();
      break;
    case 4:
      exit(1);
      break;
    default:
      break;
    }
    cout << endl;
    cout << "Back to Menu ? (y/n) ";
    cin >> back;
    system("cls");
  } while (back == 'y' || back == 'Y'); // kondisi untuk back to menu dengan do-while
}