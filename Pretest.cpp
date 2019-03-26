/*
Nama program			: Pretest
Nama					: Fadlan Mulya Priatna
NPM						: 140810180041
Tanggal pembuatan		: 26 Maret 2019
Deskripsi progrram		: program ini berisikan kodingan pretest strukdat praktikum 5
*/

#include <iostream>

using namespace std;

struct ElemtList{
	char npm[14];
	char nama[40];
    float ipk;
    ElemtList* next;
};

typedef ElemtList* pointer;
typedef pointer List;

void createList (List& First){
	First = NULL;
}

void createElmt (pointer& pBaru){
	pBaru = new ElemtList;
	cout<<"masukkan mahasiswa"<<endl;
	cout<<"NPM\t: ";cin>>pBaru->npm;
	cout<<"Nama lengkap\t: ";cin.ignore();cin.getline(pBaru->nama,40);
    cout<<"IPK\t: ";cin>>pBaru->ipk;
	pBaru->next = NULL;
}

void insertSortNPM (List& First, pointer pBaru){
	// I.S List First mungkin kosong dan pBaru sudah terdefinisi
	// F.S List bertambah satu elemn di depan dengan pBaru
	
	if (First == NULL){			//kasus kosong
		First=pBaru;
	}
	else {							//kasus ada isi
		pBaru->next=First;			//1
		First=pBaru;				//2
	}
}

void traversal(List First){
	//I.S List mungkin kosong
	//F.S Semua elemn list didatangi dan ditampilkan mulai dari elemen pertama
	pointer pBantu;
    pBantu=First;										//catat elemen pertama
    while(pBantu != NULL){								//proses cetak
		cout<<"NPM\t: "<<pBantu->npm<<endl;
        cout<<"Nama lengkap\t: "<<pBantu->nama<<endl;
        cout<<"IPK\t: "<<pBantu->ipk<<endl;
		cout<<endl;
        pBantu=pBantu->next;					//berpindah ke berikutnya
    }
}

int main(){
	pointer p;
	List Ma08;
	int pilihan;
	
	createList(Ma08);					// list kosong
	while(1){
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1. Tambah Data"<<endl;
        cout<<"2. Traversal"<<endl;
        cout<<"3. Exit"<<endl;
        cout << "Masukkan Pilihan : "; cin >> pilihan;
        switch(pilihan){
        case 1:
            createElmt(p);
            insertSortNPM(Ma08,p);
        break;
        case 2:
            traversal(Ma08);
        break;
        case 3:
            return 0;
            break;
        }
        system("pause");
    }
}
