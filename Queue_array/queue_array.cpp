#include <iostream>
#include <stdio.h>
#define max 5
using namespace std;

struct mhs
{
  char nama[40];
  int nim;
};

struct node
{
  int belakang;
  mhs elemen[max];
};

struct node queue;

bool isFullArray()
{
  if (queue.belakang == max)
  {
    return true;
  }
  else
  {
    return false;
  }
}


bool isEmptyArray()
{
  if (queue.belakang == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}


void enqueueArray(mhs IB)
{
  if (isFullArray())
  {
    cout << "Antrian penuh!!" << endl;
  }
  else
  {

    queue.belakang++;
    queue.elemen[queue.belakang] = IB;

  }
}

void dequeueArray()
{
  if (isEmptyArray())
  {
    cout << "Antrian kosong!!" << endl;
  }
  else
  {
    for (int i = 0; i < queue.belakang; i++)
    {
      queue.elemen[i] = queue.elemen[i + 1];
    }
    cout << "---- Antrian Dengan ---- " << endl;

    cout << "Nama\t : " << queue.elemen->nama << endl;
    cout << "NIM\t : " << queue.elemen->nim << endl;

    cout << "---- Dipersilahkan Masuk ---- " << endl;
    queue.belakang--;
  }
}


int countArray()
{

  if (isEmptyArray())
  {
    return 0;
  }
  else if (isFullArray())
  {
    return max;
  }
  else
  {
    return queue.belakang;
  }
}

void viewArray()
{
  cout << "Jumlah nama yg ngantri : " << countArray() << endl;
  if (isEmptyArray())
  {
    cout << "Antrian kosong!!" << endl;
  }
  else
  {
    int no = 1;
    while (no <= queue.belakang)
    {
 

      cout << no << ". " << queue.elemen[no].nama << " - " << queue.elemen[no].nim << endl;

      no++;
    }
  }
  cout << "\n"
       << endl;
}

int main()
{

  int pilih;
  char back;

  do
  {
    cout << endl;
    cout << "==== PROGRAM ANTRIAN PSIKOLOGIS ====" << endl;

    cout << "Menu :" << endl;
    cout << "1. Daftar" << endl;
    cout << "2. Antrian" << endl;
    cout << "3. Masuk Ruangan" << endl;
    cout << "4. Exit" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
      cout << "---- Form Pendaftaran ----" << endl;
      mhs IB;
      cout << "Nama : ";
      cin.ignore();
      cin.getline(IB.nama, 40);
      cout << "NIM  : ";
      cin >> IB.nim;
      enqueueArray(IB);
      break;
    case 2:
      cout << "---- Data Antrian ----" << endl;
      viewArray();
      break;
    case 3:

      dequeueArray();
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
  } while (back == 'y' || back == 'Y');
}