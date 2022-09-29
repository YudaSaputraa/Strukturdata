#include <iostream>
#include <conio.h>

using namespace std;

struct node{
	char nim[9], nama[40], kelas;
	float nilai;
	node *next;
}*baru, *awal=NULL, *akhir=NULL, *bantu;

void print(){
	if(awal==NULL){
		cout << "Data Kosong, Masukan Data Terlebih Dahulu !!!" << endl;
	}else{
		bantu=awal;
		while(bantu!=NULL){
			cout << "  Nama\t: " << bantu->nama << endl;
			cout << "  NIM\t: " << bantu->nim << endl;
			cout << "  Kelas\t: " << bantu->kelas << endl;
			cout << "  Nilai\t: " << bantu->nilai << endl << endl;
			bantu=bantu->next;
		}
	}
	system("pause");
}

void creatMahasiswa(){
	baru = new node;
	cout << "Isi Data Dibawah : " << endl;
	cout << "NIM\t: "; cin >> baru->nim;
	cin.ignore();
	cout << "Nama\t: "; cin.getline(baru->nama,40);
	cout << "Kelas\t: "; cin >> baru->kelas;
	cout << "Nilai\t: "; cin >> baru->nilai;
	baru->next = NULL; 
}

void sisipBelakang(){
	creatMahasiswa();
	if(awal==NULL){
		awal=baru;
	}else{
		akhir->next=baru;
	}
	akhir=baru;
	akhir->next=NULL;
	system("pause");
}

int main(){
	char pilih;
	bool ulang = false;
	do{
		system("cls");
		cout << "====================================" << endl;
		cout << "+        Program Linkd list        +" << endl;
		cout << "====================================" << endl;
		cout << "+ 1. Tambah Belakang               +" << endl;
		cout << "+ 2. Tampil semua data             +" << endl;
		cout << "+ 6. Keluar                        +" << endl;
		cout << "====================================" << endl;
		cout << "Masukan angka . . .";
		pilih = getch();
		system("cls");
		switch(pilih){
			case '1' :
				sisipBelakang();
				break;
			case '2' :
				print();
				break;
			case '6' :
				break;
		}
	}while(pilih!='6');
}
