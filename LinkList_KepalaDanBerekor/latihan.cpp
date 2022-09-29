#include <iostream>
#include <malloc.h>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int number;
    node *next;
};
node *head, *tail, *newNode, *help, *first, *last, *del;

int DeleteNumber;
void createList()
{
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));
    head->number = -10;
    head->next = tail;
    tail->number = 100;
    tail->next = NULL;
}

bool listCheck()
{
    return head->next == tail;
}

void inputData()
{
    int jumlah;
    cout << "Jumlah Data : ";
    cin >> jumlah;
    for (int i = 1; i <= jumlah; i++)
    {
        newNode = new node;
        cout << "Data ke-" << i << endl;
        cout << "masukkan Data :";
        cin >> newNode->number;
        newNode->next = NULL;
        help = head;
        while (newNode->number > help->next->number)
        {
            help = help->next;
        }
        newNode->next = help->next;
        help->next = newNode;
    }
}

void printDataMaju()
{

    if (head->number > head->next->number)
    {

        first = head;
        head = last;

        do
        {
            help = first;
            while (help->next != tail)
                help = help->next;
            tail->next = help;
            tail = help;

        } while (tail != first);

        tail->next = NULL;
    }
    help = head->next;
    cout << "Baca maju" << endl;
    while (help != tail)
    {
        cout << help->number << ", ";
        help = help->next;
    }
}

void printDataMundur()
{
    if (head->number < head->next->number)
    {

        first = head;
        head = last;

        do
        {
            help = first;
            while (help->next != tail)
                help = help->next;

            tail->next = help;
            tail = help;

        } while (tail != first);

        tail->next = NULL;
    }
    help = head->next;
    cout << "Baca Mundur" << endl;
    while (help != tail)
    {
        cout << help->number << ", ";
        help = help->next;
    }
}

void deleteNode()
{
    if (listCheck())
    {
        cout << "Please Insert Data";
    }
    else
    {
        cout << "Masukkan Angka yang mau dihapus :";
        cin >> DeleteNumber;
        help = head;
        while (help->next != tail && DeleteNumber != help->next->number)
        {
            help = help->next;
        }
        if (DeleteNumber == help->next->number)
        {
            del = help->next;
            help->next = del->next;
            free(del);
            cout << "Data " << DeleteNumber << " Berhasil Dihapus" << endl;
        }
        else
        {
            cout << "Node Tidak ada";
        }
    }
}

int main()
{
    int pilih;
    char back;
    createList();
    do
    {
        cout << "PROGRAM LINKED LIST head tail" << endl;
        cout << "Pilih menu :" << endl;
        cout << "1. Input data" << endl;
        cout << "2. Lihat data maju" << endl;
        cout << "3. Lihat data mundur" << endl;
        cout << "4. del Data" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:

            inputData();
            break;
        case 2:
            printDataMaju();
            break;
        case 3:
            printDataMundur();
            break;
        case 4:
            deleteNode();
            break;
        default:
            break;
        }
        cout << endl;
        cout << "Kembali Ke Menu ? (y/n)";
        cin >> back;
        system("cls");
    } while (back == 'y' || back == 'Y');
    return 0;
}