#include <iostream>
using namespace std;

struct queues
{
    string nama;
    int nim;
    queues *next;
}; queues *qDepan, *qBelakang, *queueBaru, *hapus, *bantu;

int maxQueue = 5;

int _banyakQueue()
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

bool _kosong()
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

bool _full()
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

void _inputDepan()
{
    cout << "Nama\t : ";
    cin >> qDepan->nama;
    cout << "NIM\t : ";
    cin >> qDepan->nim;
}

void _inputBaru()
{
    cout << "Nama\t : ";
    cin >> queueBaru->nama;
    cout << "NIM\t : ";
    cin >> queueBaru->nim;
}
void _enqueue()
{

    if (_full())
    {
        cout << "Antrian Penuh!!!" << endl;
    }
    else
    {

        if (_kosong())
        {
            qDepan = new queues();
            _inputDepan();
            qDepan->next = NULL;
            qBelakang = qDepan;
        }
        else
        {
            queueBaru = new queues();

            _inputBaru();
            queueBaru->next = NULL;
            qBelakang->next = queueBaru;
            qBelakang = queueBaru;
        }
    }
}

void _dequeue()
{
    if (_kosong())
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

void _cetakQueue()
{
    if (_kosong())
    {
        cout << "Data Antrian Kosong!" << endl;
    }
    else
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
            _enqueue();
            break;
        case 2:
            cout << "---- Data Antrian ----" << endl;
            _cetakQueue();
            break;
        case 3:

            _dequeue();
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