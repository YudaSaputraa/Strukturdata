#include <iostream>
using namespace std;

struct queues
{
    string nama;
    int nim;
    queues *next;
}; queues *qDepan, *qBelakang, *queueBaru, *hapus, *bantu;

int maxQueue;

int banyakqueue();
bool queuekosong();
void cetakqueue();
void dequeue();

int main()
{
    int pilih;
    char kembali;
 
    do
    {
        cout << endl;
        cout << "Antrian Bioskop\n"
             << "Menu :\n" 
             << "1. Input Data Penonton\n"
             << "2. Daftar Antrian\n"
             << "3. Masuk Ruangan\n"
             << "4. Exit\n"
             << "Pilih : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            cout << "======================="
                 << "| Input Data Penonton |"
                 << "=======================" << endl;
            enqueue();
            break;
        case 2:
            cout << "======================"
                 << "|   Daftar Antrian   |"
                 << "======================" << endl;
            cetakqueue();
            break;
        case 3:

            dequeue();
            break;

        default:
            break;
        }
        cout << endl;
        cout << "Kembali ke Menu ? (y/n) ";
        cin >> kembali;
        system("cls");
    } while (kembali == 'y' || kembali == 'Y');
}

int banyakqueue()
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

bool queuekosong()
{
    if (banyakqueue() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool queuepenuh()
{
    if (banyakqueue() == maxQueue)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void inputdepan()
{
    cout << "Nama\t : ";
    cin >> qDepan->nama;
    cout << "NIM\t : ";
    cin >> qDepan->nim;
}

void inputbaru()
{
    cout << "Nama\t : ";
    cin >> queueBaru->nama;
    cout << "NIM\t : ";
    cin >> queueBaru->nim;
}
void enqueue()
{

    cout<<"Masukkan Jumlah Maximal Penonton :\n";
    cin>>maxQueue;

    if (queuepenuh())
    {
        cout << "Antrian Penuh!!!" << endl;
    }
    else
    {

        if (queuekosong())
        {
            qDepan = new queues();
            inputdepan();
            qDepan->next = NULL;
            qBelakang = qDepan;
        }
        else
        {
            queueBaru = new queues();

            inputbaru();
            queueBaru->next = NULL;
            qBelakang->next = queueBaru;
            qBelakang = queueBaru;
        }
    }
}

void dequeue()
{
    if (queuekosong())
    {
        cout << "Antrian Masih Kosong!" << endl;
    }
    else
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

void cetakqueue()
{
     if (queuekosong())
    {
        cout << "Data Antrian Kosong!" << endl;
    }
    else
    {
        cout << "Banyak Antrian : " << banyakqueue() << endl;
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