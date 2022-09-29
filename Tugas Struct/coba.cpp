#include <iostream>
using namespace std;
struct buah
{
    string nama;
    int harga;
};
int banyak;
int main()
{
    int pilihan, banyak_buah;
    buah data[20];
    string pilih_nama;
    char back;
    do
    {

        cout << "Data Nama Buah" << endl;
        cout << "1. Input Nama Buah" << endl;
        cout << "2. Cari Nama Buah" << endl;
        cout << "Pilih : ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            cout << "Banyak Data : ";
            cin >> banyak;
            for (int i = 0; i < banyak; i++)
            {
                cout << "Nama Buah : ";
                cin >> data[i].nama;
                cout << "Harga Buah : ";
                cin >> data[i].harga;
                cout << endl;
            }
        }
        else if (pilihan == 2)
        {
            string cariNama;
            int i, flag = 0, total;
            cout << endl;
            for(int x = 0; x < banyak; x++){
            cout<<"Nama Buah : "<<data[x].nama<<endl;
            cout<<"Harga Buah : "<<data[x].harga<<endl;
            }
            cout << "Pilih Nama Buah : ";
            cin >> cariNama;
            cout<<"Banyak Buah : ";
            cin>>banyak_buah;
            for (int y=0 ; y<banyak; y++){
           total = banyak_buah * data[y].harga;
            }
            
            for (i = 0; i < banyak; i++)
            {
                if (data[i].nama == cariNama)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                cout << "harga \t\t : " << total<< endl;
            }
            else
            {
                cout << "Tidak ada Buah " << cariNama << endl;
            }
        }
        cout << "Kembali Ke Menu Utama (Y/N) :";
        cin >> back;
        system("cls");
    } while (back == 'y' || back == 'Y');
}