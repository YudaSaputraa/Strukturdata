#include <iostream>
#include <malloc.h>
#define true 1
#define false 0
using namespace std;

struct fruit {
	string nama;
	int harga, id;
};

typedef struct typeNode *typePtr;

struct typeNode {
	fruit infoBuah;
	typePtr next;
};

typePtr kepala, ekor;

void buatList () {
	kepala = (typeNode *) malloc(sizeof(typeNode));
	ekor = (typeNode *) malloc(sizeof(typeNode));
	kepala->next = ekor;
	kepala->infoBuah.id= -9999;
	ekor->infoBuah.id = 99999;
	ekor->next = NULL;
}

int cekList () {
	if (kepala->next == ekor) {
		return (true);
	}
	else {
		return (false);	
	}
}

void sisipList (fruit IB) {
	typePtr NB, bantu;
	NB = (typeNode *) malloc(sizeof(typeNode));
	
	NB->infoBuah = IB;
	
	bantu = kepala;
	while (IB.id > bantu->next->infoBuah.id) {
		bantu = bantu->next;
	}
	NB->next = bantu->next;
	bantu->next = NB;
}

void tampilindariDepan () {
	typePtr bantu;
	bantu = kepala->next;
	while (bantu != ekor) {
		cout << "ID buah    : " << bantu->infoBuah.id << endl;
		cout << "Nama buah  : " << bantu->infoBuah.nama << endl;
		cout << "Harga buah : " << bantu->infoBuah.harga << endl;
		cout << endl;
		bantu = bantu->next;
	}
}

void hapusNode (fruit IH) {
	typePtr hapus, bantu;
	if (cekList()) {
		cout << "Yachh, list masi kosong nichh" << endl;
	} else {
		
		bantu = kepala;
		while (bantu->next != ekor && IH.nama != bantu->next->infoBuah.nama) {
			bantu = bantu->next;
		}
		if (IH.nama == bantu->next->infoBuah.nama) {
			hapus = bantu->next;
			bantu->next = hapus->next;
			free(hapus);
			cout << "Data " << IH.nama << " berhasil dihapus yachh" << endl;
		}
	}
	
	
	cout << endl;
}

int main () {
	int pilih, banyakData;
	char back;
	bool error;
	buatList();
do {
	system("cls");
	cout << "----------------------------------------------" << endl; 
	cout << "                  DATA NAMA BUAH              " << endl;
	cout << "----------------------------------------------" << endl; 		
	cout << "1. Input nama buah" << endl;
	cout << "2. Lihat nama buah" << endl;
	cout << "3. Hapus nama buah" << endl;
	cout << "Pilih : ";
	cin >> pilih;
	cout << endl;
	
	system("cls");
	switch (pilih) {
		case 1 :
			cout << "----------------------------------------------" << endl; 
			cout << "                  INPUT NAMA BUAH             " << endl;
			cout << "----------------------------------------------" << endl;
			do {
				cout << "Banyak data : ";
				cin >> banyakData;
				if (banyakData < 1) {
					cout << "Yaah, nice try! inputnya minimal 1 yaa :D" << endl;
				}
			} while (banyakData < 1);
			cout << endl;	
			for (int i = 0; i < banyakData; i++) {
				fruit IB;
				cout << "ID buah    : ";
				cin >> IB.id;
				cin.ignore();
				cout << "Nama buah  : ";
				cin >> IB.nama;
				cout << "Harga buah : ";
				cin >> IB.harga;
				cout << endl;
				sisipList(IB);
			}
			break;
		case 2 : 
			cout << "----------------------------------------------" << endl; 
			cout << "                  DATA NAMA BUAH              " << endl;
			cout << "----------------------------------------------" << endl;
			if (cekList()) {
				cout << "Hmm nice try! List masih kosong nich, diisi yaa :D" << endl << endl;
			} else {
				tampilindariDepan();				
			}
			break;
		case 3 :
			cout << "----------------------------------------------" << endl; 
			cout << "                 HAPUS NAMA BUAH              " << endl;
			cout << "----------------------------------------------" << endl;
			if (cekList()) {
				cout << "Hmm nice try! List masih kosong nich, diisi yaa :D" << endl << endl;
			} else {
				fruit IH;
				cout << "Nama buah yang ingin dihapus = ";
				cin.ignore();
				getline(cin, IH.nama);
				hapusNode(IH);
			}
			break;
		default :
			cout << "----------------------------------------------" << endl; 
			cout << "                  DATA NAMA BUAH              " << endl;
			cout << "----------------------------------------------" << endl; 
			cout << "Hmm nice try! Menu tidak tersedia :D" << endl << endl;
	}
	do {
	cout << "Kembali ke menu y/n? ";
	cin >> back;
	if (!(back == 'Y' || back == 'y' || back == 'n' || back == 'N')) {
		cout << endl;
		cout << "Hmm nice try! Menu tidak tersedia :D" << endl << endl;
	}
	} while (!(back == 'Y' || back == 'y' || back == 'n' || back == 'N'));
}	while (back == 'y' || back == 'Y');
	
}

