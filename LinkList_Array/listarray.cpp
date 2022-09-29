#include <iostream>
using namespace std;

int list, kosong, akhirlist, akhirkosong;
typedef struct{
	int info;
	int next;
}typenode;

typenode element[12];

//typedef struct typenode element[12];
//struct typenode{
	//int info;
	//int next;
//};

void buatlist();
bool listkosong();
void cetaklist();
void sisipnode(int IB);
void hapusnode(int IH);

int main()
{
	buatlist();
	cetaklist();
	sisipnode(20);
	cout << "sisip 20" << endl;
	cetaklist();
	hapusnode(60);
	cout << "hapus 60" << endl;
	cetaklist();
	hapusnode(20);
	cout << "hapus 20" << endl;
	cetaklist();
	return 0;
}

void buatlist(){
	list = 5;
	kosong = 3;
	akhirlist = 10;
	akhirkosong = 4;
	
	element[1].info = 25; 	element[1].next = 8;
	element[2].info =  0; 	element[2].next = 9;
	element[3].info =  0; 	element[3].next = 6;
	element[4].info =  0; 	element[4].next = 0;
	element[5].info = 10; 	element[5].next = 7;
	element[6].info =  0; 	element[6].next = 2;
	element[7].info = 15; 	element[7].next = 1;
	element[8].info = 40; 	element[8].next = 10;
	element[9].info =  0; 	element[9].next = 4;
	element[10].info = 60; 	element[10].next = 0;
}

bool listkosong(){
	if(list==0){
		return true;
	}else{
		return false;
	}
}

void cetaklist(){
	int n,m;
	n = list;
	m = kosong;
	
	cout << "Isi list : " << endl;
	do{
		cout << element[n].info << " ";
		n = element[n].next;
	}while(element[n].next != NULL);
	cout << element[akhirlist].info << endl;
	
	cout << "Index tempat kosong : " << endl;
	do{
		cout << m << " ";
		m = element[m].next;
	}while(element[m].next != NULL);
	cout << akhirkosong << endl << endl;
}

void sisipnode(int IB){
	int listbaru,n,m,x,k;
	if(IB < element[list].info){				//sisip di awal
		listbaru = kosong;
		kosong = element[kosong].next;
		element[listbaru].info = IB;
		element[listbaru].next = list;
		list = listbaru;
	}else if(IB > element[akhirlist].info){		//sisip di akhir
		listbaru = kosong;
		kosong = element[kosong].next;
		element[listbaru].info = IB;
		element[listbaru].next = 0;
		element[akhirlist].next = listbaru;
		akhirlist = listbaru;
	}else{									//sisip di tengah
		n=list;
		x=element[n].info;
		while(IB>x){
			m=n;
			n=element[n].next;
			x=element[n].info;
		}
		k=element[kosong].next;
		element[m].next=kosong;
		element[kosong].info=IB;
		element[kosong].next=n;
		kosong=k;
	}
}

void hapusnode(int IH){
	int listbaru,n,m,k;
	if(IH == element[list].info){			//hapus di awal
		listbaru=element[list].next;
		k=kosong;
		kosong=list;
		list=listbaru;
		element[kosong].next=k;
	}else if(IH == element[akhirlist].info){		//hapus di akhir
		n = list;
		while(element[n].next != 0){
			m = n;
			n = element[n].next;
		}
		element[m].next = 0;
		akhirlist = m;
		element[n].next = kosong;
		kosong = n;
	}else{								//hapus di tengah
		n = list;
		while(IH != element[n].info){
			m=n;
			n = element[n].next;
		}
		element[m].next = element[n].next;
		element[n].next = kosong;
		kosong = n;
	}
}
