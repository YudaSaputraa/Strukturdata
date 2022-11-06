#include <iostream>
#include <stdio.h>
#define max 5
using namespace std;

struct mhs {
	char nama[40];
	int nim;
};


struct node {
	int belakang;
	mhs elemen[max];
};

struct node queue;
// array Antrian
// int maksimalAntrianArray = 5, qDepan = 0, qBelakang = 0;
// // ruang antrian array
// string maxQueue[5];

// isFull / cek nama antrian penuh atau tidak
bool isFullArray()
{
  if( queue.belakang == max ){
    return true;
  }else{
    return false;
  }
}

// isEmpty
bool isEmptyArray()
{
  if( queue.belakang == 0 ){
    return true;
  }else{
    return false;
  }
}


// enqueue / penambahan nama antrian
void enqueueArray(mhs IB){
  if( isFullArray() ){
    cout << "Antrian penuh!!" << endl;
  }else{
    // cek apakah datanya kosong atau tidak
      // kalau antrian kosong
      queue.belakang++;
      queue.elemen[queue.belakang] = IB;

    // //   maxQueue[0] = nim;
    //   qDepan++;
    //   qBelakang++;
    
  }

}

// dequeue / penghapusan nama depan
void dequeueArray(){
  if( isEmptyArray() ){
    cout << "Antrian kosong!!" << endl;
  }else{
    for( int i = 0; i < queue.belakang; i++ ){
      queue.elemen[i] = queue.elemen[i+1];
    }
     cout << "---- Antrian Dengan ---- " << endl;

        cout << "Nama\t : " << queue.elemen->nama << endl;
        cout << "NIM\t : " << queue.elemen->nim<< endl;

        cout << "---- Dipersilahkan Masuk ---- " << endl;
    queue.belakang--;
  }
}

// countArray / menghitung banyak nama yg ngantri
int countArray()
{

  if( isEmptyArray() ){
    return 0;
  }else if( isFullArray() ){
    return max;
  }else{
    return queue.belakang;
  }

}

// Display / View
void viewArray()
{
  cout << "Jumlah nama yg ngantri : " << countArray() << endl;
  if( isEmptyArray() ){
    cout << "Antrian kosong!!" << endl;
  }else{
    int no = 1;    
    while (no <= queue.belakang)
    {
        // if (queue.elemen != "")
        // {
             cout << no << ". " << queue.elemen[no].nama<< " - " << queue.elemen[no].nim << endl;
               
        // }else{
        //     cout<<no<<". (Kosong)"<<endl;
        // }
        no++;
        
    }
    
  }
  cout << "\n" << endl;
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
        case 4 :
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