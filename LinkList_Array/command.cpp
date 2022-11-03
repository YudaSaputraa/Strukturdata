#include <iostream>
using namespace std;

struct node
{
    int angka, next;
};
node elemen[12];
int list, akhirlist, kosong, akhirkosong;

void newList(){
    list = 0;
    kosong = 3;
    akhirkosong = 8;
    elemen[1].angka = 0;
    elemen[1].next = 5;
    elemen[2].angka = 0;
    elemen[2].next = 4;
    elemen[3].angka = 0;
    elemen[3].next = 7;
    elemen[4].angka = 0;
    elemen[4].next = 9;
    elemen[5].angka = 0;
    elemen[5].next = 8;
    elemen[6].angka = 0;
    elemen[6].next = 10;
    elemen[7].angka = 0;
    elemen[7].next = 2;
    elemen[8].angka = 0;
    elemen[8].next = 0;
    elemen[9].angka = 0;
    elemen[9].next = 6;
    elemen[10].angka = 0;
    elemen[10].next = 1;

}

int listKosong()
{
    if (list == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sisipNode(){
    int listbaru,infobaru, k, m, n, x;
    cout<<"Masukkan Angka : ";
    cin>>infobaru;
    if(infobaru < elemen[kosong].angka)
    {
        listbaru = kosong;
        kosong = elemen [kosong].next;
        elemen[listbaru].angka = infobaru;
        list = listbaru;
    }else if(infobaru > elemen[akhirkosong].angka){
        listbaru = kosong;
        kosong = elemen[kosong].next;
        elemen[listbaru].angka = infobaru;
        elemen[listbaru].next = 0;
        elemen[akhirkosong].next = listbaru;
        akhirlist = listbaru;
    }


}
void cetakList(){
    int n, m;
    n = list;
}
int main()
{
    newList();
    cout<<"linked list array";
    sisipNode();
}