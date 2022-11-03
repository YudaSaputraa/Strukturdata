#include <iostream>
using namespace std;

struct Buah{
	int harga,id;
	string nama;
	
	
};

struct node{
	Buah buahInfo;
	node *next;
};

void menu();
void create();
void print();
void kembali();
void hapus(Buah buahInfo);
void sisip(Buah buahInfo);
int kosong();
node *head, *tail, *NB, *del, *bantu;
int pilih,banyak;

int main(){
	menu();
}

void menu(){
	Buah buahInfo;
	cout<<"1.Buat Link List"<<endl;
	cout<<"2.Cetak Link List"<<endl;
	cout<<"3.Hapus node "<<endl;
	cout<<"Pilih menu : ";
	cin>>pilih;
	cout<<endl;
	switch(pilih){
	case 1 :create();
	kembali();
	break;
	case 2 :print();
	break;
	case 3 : hapus(buahInfo);
	break;	}

}


void create(){
	Buah info;
	int x;
	cout<<"Banyak Buah : ";
	cin>>banyak;
	for(x=0; x<=banyak; x++)
	{
	
		cout<<"Masukin Id : ";
		cin>>info.id;
		cin.ignore();
		cout<<"Masukin Nama : ";
		getline(cin,info.nama);
		cout<<"Masukin Harga : ";
		cin>>info.harga;
		cout<<endl;
		sisip (info);
	}
	

}

void sisip(Buah buahInfo){
	NB = new node;
	head = new node;
	NB->buahInfo.id = buahInfo.id;
	NB->buahInfo.nama = buahInfo.nama;
	NB->buahInfo.harga = buahInfo.harga;
	NB->next = NULL;
	head->buahInfo.id = -9999;
	head->buahInfo.nama = "kepala";
	head->buahInfo.harga = -9999;
	head->next=tail;
	tail->buahInfo.id = 9999;
	tail->buahInfo.nama = "ekor";
	tail->buahInfo.harga = 9999;
	tail->next=NULL;
	
	if (kosong()){
	NB->next=tail;
	head->next=NB;
	}
	else{
	bantu=head; 
  	while (bantu->next != NULL && buahInfo.id > bantu->next->buahInfo.id) 
  	bantu=bantu->next; 
  	NB->next=bantu->next;// Sisip di tengah 
  	bantu->next=NB; 
}
 
}


void print(){
	node *cur;
    cur = head->next;
    while(cur!=tail){
        cout<<"Id\t: "<<cur->buahInfo.id<<endl;
        cout<<"Nama\t: "<<cur->buahInfo.nama<<endl;
        cout<<"Harga\t: "<<cur->buahInfo.harga<<endl;
        cout<<endl;
        cur = cur->next;
    }
    kembali();
}

void kembali(){	
	
	char pilih;	
	cout<<"\nApakah ingin kembali ke menu awal (y/n) ?";	
	cin>>pilih;	
		
	if (pilih == 'Y' || pilih == 'y')	
	system("cls");
	menu ();	
	
}

void hapus( Buah buahInfo)
{
	cout<<"Masukkan id buah yang mau dihapus : ";
	cin>>buahInfo.id;
	 if (kosong())
	cout << "List masih kosong";
	else
 	{ bantu=head;
	while (bantu->next!=tail && NB->buahInfo.id!=bantu->next->buahInfo.id)
	bantu=bantu->next;
	if (NB->buahInfo.id==bantu->next->buahInfo.id)
	{ del=bantu->next;
	 bantu->next=del->next;
	 delete(del); }
	else
	cout << "Node tidak ditemukan!\n";
	 }

    kembali();
}

int kosong(){
	if(head->next==tail)
		return (true);
	else 
		return (false);
}


