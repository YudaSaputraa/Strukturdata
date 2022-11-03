#include <iostream>
using namespace std;

struct queues
{
    string nama;
    int nim;
    queues *next;
};
queues *qDepan, *qBelakang, *queueBaru, *hapus, *bantu;

int maxQueue = 5;

int _banyakQueue(){
    if (qDepan == NULL){
        return 0;
    }else{
        int banyak = 0;
        bantu = qDepan;
        while(bantu != NULL){
            bantu = bantu->next;
            banyak ++;
        }
        return banyak;
    }
}

// void _buatQueue()
// {
//     qDepan = new queues;
//     qDepan = NULL;
//     qBelakang = qDepan;
// }

bool _kosong()
{
    if(_banyakQueue == 0){
        return true;
    }else{
        return false;
    }
}

bool _full(){
    if(_banyakQueue() == maxQueue){
        return true;
    }else{
        return false;
    }
}
void _enqueue( string nama, int nim ){

  if( _full() ){
    cout << "Antrian Penuh!!!" << endl;
  }else{
    
    if( _kosong() ){
      qDepan = new queues();
      qDepan->nama = nama;
      qDepan->nim = nim;
      qDepan->next = NULL;
      qBelakang = qDepan;
    }else{
      queueBaru= new queues();
      queueBaru->nama = nama;
      queueBaru->nim = nim;
      queueBaru->next = NULL;
      qBelakang->next = queueBaru;
      qBelakang = queueBaru;
    }

  }

}

// void _enqueue(string namaa, int nimm)
// {
//     cout<<namaa;
//     cout<<nimm;
//     if(_full()){
//         cout<<"Antrian Penuh!"<<endl;
//     }else{
//             queueBaru = new queues;
//             queueBaru->nama = namaa;
//             queueBaru->nim = nimm;
//         if(_kosong()){
            
//             // qDepan->nama = namaa;
//             // qDepan->nim = nimm;
//             // qDepan->next = NULL;
//             qDepan = queueBaru;
//             // qBelakang = qDepan;
//         }else{

            
//             qBelakang->next = queueBaru;
//             qBelakang = queueBaru;
//             queueBaru->next = NULL;
//         }
//     }
    // queueBaru = new node;

    // cout << "Nama\t: ";
    // cin >> queueBaru->nama;
    // cout << "NIM\t: ";
    // cin >> queueBaru->nim;

    // if (qDepan == NULL)
    // {
    //     qDepan = queueBaru;
    // }
    // else
    // {
    //     qBelakang->next = queueBaru;
    //     qBelakang = queueBaru;
    //     qBelakang->next = NULL;
    // }
// }

void _dequeue()
{
    if (_kosong())
    {
        cout << "Antrian Masih Kosong!" << endl;
    }
    else
    {
        hapus = qDepan;
        qDepan = hapus->next;
        hapus->next = NULL;
        free(hapus);
    }
}

void _cetakQueue()
{
    if(_kosong()){
        cout<<"Data Antrian Kosong!"<<endl;

    }else{
        bantu = qDepan;
        int no = 1;
        while(no <= maxQueue){
            if(bantu != NULL){
                cout<<no<<". "<<bantu->nama <<" - "<<bantu->nim;
                bantu = bantu->next;
                
            }else{
                cout<<no<<". "<<"(Kosong)"<<endl;
            }
            no++;
    }
    }
    

}

int main()
{
    _enqueue("komang", 12323);
//     int pilih;
//     char back;
//     //  _buatQueue();
//     do
//     {
//         cout << "Program Antrian Psikologis" << endl;
//         cout << "Menu :" << endl;
//         cout << "1. Daftar" << endl;
//         cout << "2. Antrian" << endl;
//         cout << "3. Masuk Ruangan" << endl;
//         cout << "4. Exit" << endl;
//         cout << "Pilih : ";
//         cin >> pilih;
//         switch (pilih)
//         {
//         case 1:
//             cout << "---- Form Pendaftaran ----" << endl;
//             _enqueue("komang", 12323);
//             break;
//         case 2:
//             cout << "---- Data Antrian ----" << endl;
//             _cetakQueue();
//             break;
//         case 3:
//             cout << "---- Antrian Dengan ----" << endl;
//             break;

//         default:
//             break;
//         }
//         cout << endl;
//         cout << "Back to Menu ? (y/n) ";
//         cin >> back;
//         system("cls");
//     } while (back == 'y' || back == 'Y');
}