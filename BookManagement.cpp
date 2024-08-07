#include <iostream>
#include <stdlib.h>

using namespace std;

struct Buku
{
	string judul, pengarang;
	int tahunTerbit;
	Buku *next;
};

Buku *head, *tail, *cur, *newNode, *del, *before;

void createSingleLinkedList(string judul, string pengarang, int tB)
{
	head = new Buku();
	head->judul = judul;
	head->pengarang = pengarang;
	head->tahunTerbit = tB;
	head->next = NULL;
	tail = head;
}

int countSingleLinkedList()
{
	cur = head;
	int jumlah = 0;
	while (cur != NULL)
	{
		jumlah++;
		cur = cur->next;
	}
	return jumlah;
}

void addFirst(string judul, string pengarang, int tB)
{
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahunTerbit = tB;
	newNode->next = head;
	head = newNode;
}

void addLast(string judul, string pengarang, int tB)
{
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahunTerbit = tB;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
}

void addMiddle(string judul, string pengarang, int tB, int posisi)
{
	if (posisi < 1 || posisi > countSingleLinkedList())
	{
		cout << "Posisi diluar jangkauan" << endl;
	}
	else if (posisi == 1)
	{
		cout << "Posisi bukan posisi tengah" << endl;
	}
	else
	{
		newNode = new Buku();
		newNode->judul = judul;
		newNode->pengarang = pengarang;
		newNode->tahunTerbit = tB;

		cur = head;
		int nomor = 1;
		while (nomor < posisi - 1)
		{
			cur = cur->next;
			nomor++;
		}
		newNode->next = cur->next;
		cur->next = newNode;
	}
}

void removeFirst()
{
	del = head;
	head = head->next;
	delete del;
}

void removeLast()
{
	del = tail;
	cur = head;
	while (cur->next != tail)
	{
		cur = cur->next;
	}
	tail = cur;
	tail->next = NULL;
	delete del;
}

void removeMiddle(int posisi)
{
	if (posisi < 1 || posisi > countSingleLinkedList())
	{
		cout << "Posisi diluar jangkauan" << endl;
	}
	else if (posisi == 1)
	{
		cout << "Posisi bukan posisi tengah" << endl;
	}
	else
	{
		int nomor = 1;
		cur = head;
		while (nomor <= posisi)
		{
			if (nomor == posisi - 1)
			{
				before = cur;
			}
			if (nomor == posisi)
			{
				del = cur;
			}
			cur = cur->next;
			nomor++;
		}
		before->next = cur;
		delete del;
	}
}

void changeFirst(string judul, string pengarang, int tB)
{
	head->judul = judul;
	head->pengarang = pengarang;
	head->tahunTerbit = tB;
}

void changeLast(string judul, string pengarang, int tB)
{
	tail->judul = judul;
	tail->pengarang = pengarang;
	tail->tahunTerbit = tB;
}

void changeMiddle(string judul, string pengarang, int tB, int posisi)
{
	if (posisi < 1 || posisi > countSingleLinkedList())
	{
		cout << "Posisi diluar jangkauan" << endl;
	}
	else if (posisi == 1 || posisi == countSingleLinkedList())
	{
		cout << "Posisi bukan posisi tengah" << endl;
	}
	else
	{
		cur = head;
		int nomor = 1;
		while (nomor < posisi)
		{
			cur = cur->next;
			nomor++;
		}
		cur->judul = judul;
		cur->pengarang = pengarang;
		cur->tahunTerbit = tB;
	}
}

void printSingleLinkedList()
{
	cout << "Jumlah data ada : " << countSingleLinkedList() << endl;    //my own experiment
	cout << "===========================" << endl;
	cur = head;

	while (cur != NULL)
	{
		cout << "Judul Buku : " << cur->judul << endl;
		cout << "Pengarang Buku : " << cur->pengarang << endl;
		cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;
		cout << "---------------------------" << endl;

		cur = cur->next;
	}
}

//-------------------------MENU CRUD PROGRAM------------------------//
void createData()
{
	cur = head;
	if (cur != NULL)
	{
		cout << "Gunakan menu 'Add' untuk menambahkan data baru!";
		cout << "\n\n" << endl;
	}
	else
	{
		system("cls");
		string judul, pengarang; 
		int tahunTerbit;
		cout << "Judul Buku      : ";
		cin >> judul;
		cout << "Pengarang Buku  : ";
		cin >> pengarang;
		cout << "Tahun Terbit    : ";
		cin >> tahunTerbit;
		createSingleLinkedList(judul, pengarang, tahunTerbit);
		cout << "List baru telah berhasil dibuat!";
		cout << "\n\n" << endl;
	}
}

void readData()
{
	if (countSingleLinkedList() == 0)
	{
		cout << "Data masih kosong!\nTidak ada yang bisa dilihat.";
	}
	else
	{
		system("cls");
		printSingleLinkedList();
	}
	cout << "\n\n" << endl;
}

void updateData()
{
	if (countSingleLinkedList() == 0)
	{
		cout << "Data masih kosong!\nTidak ada yang bisa diupdate.";
		cout << "\n\n" << endl;
	}
	else
	{
		string judul, pengarang; 
		int tahunTerbit, posisi;
		int upd;
		do
		{
			system("cls");
			cout << "=== Update Menu ===" << endl;
			cout << "1. Update First Data" << endl;
			cout << "2. Update Middle Data" << endl;
			cout << "3. Update Last Data" << endl;
			cout << "Angka selain diatas untuk keluar" << endl;
			cout << "Masukkan pilihan : "; cin >> upd;
			switch (upd)
			{
			case 1:
				cout << "Judul Buku      : ";
				cin >> judul;
				cout << "Pengarang Buku  : ";
				cin >> pengarang;
				cout << "Tahun Terbit	 : ";
				cin >> tahunTerbit;
				changeFirst(judul, pengarang, tahunTerbit);
				cout << endl << endl;
				break;
			
			case 2:
				cout << "Judul Buku      : ";
				cin >> judul;
				cout << "Pengarang Buku  : ";
				cin >> pengarang;
				cout << "Tahun Terbit	 : ";
				cin >> tahunTerbit;
				cout << "Posisi Baru	 : ";
				cin >> posisi;
				changeMiddle(judul, pengarang, tahunTerbit, posisi);
				cout << endl << endl;
				break;

			case 3:
				cout << "Judul Buku      : ";
				cin >> judul;
				cout << "Pengarang Buku  : ";
				cin >> pengarang;
				cout << "Tahun Terbit	 : ";
				cin >> tahunTerbit;
				changeLast(judul, pengarang, tahunTerbit);
				cout << endl << endl;
				break;

			default:
				cout << "Pilihan tidak valid. Silahkan coba lagi.";
				cout << "\n\n" << endl;
				break;
			}
		} while (upd != 3);
	}
}

void deleteData()
{
	if (countSingleLinkedList() == 0)
	{
		cout << "Data masih kosong!\nTidak ada yang bisa dihapus.";
		cout << "\n\n" << endl;
	}
	else
	{ 
		int posisi;
		int del;	
		do
		{
			system("cls");
			cout << "=== Delete Menu ===" << endl;
			cout << "1. Delete First Data" << endl;
			cout << "2. Delete Middle Data" << endl;
			cout << "3. Delete Last Data" << endl;
			cout << "Angka selain diatas untuk keluar" << endl;
			cout << "Masukkan pilihan : "; cin >> del;
			switch (del)
			{
			case 1:
				removeFirst();
				cout << endl << endl;
				break;
				
			case 2:
				cout << "Posisi yang ingin dihapus : ";
				cin >> posisi;
				removeMiddle(posisi);
				cout << endl << endl;
				break;

			case 3:
				removeLast();
				cout << endl << endl;
				break;
			
			default:
				cout << "Pilihan tidak valid. Silahkan coba lagi.";
				cout << "\n\n" << endl;
				break;
			}
		} while (del != 3);
	}
}

void addData()
{
	if (countSingleLinkedList() == 0)
	{
		cout << "Data belum tersedia!\nSilahkan buat dengan menu Create.";
		cout << "\n\n" << endl;
	}
	else
	{
		string judul, pengarang;
		int tahunTerbit, posisi;
		int add;
		do
		{
			system("cls");
			cout << "=== Add Menu ===" << endl;
			cout << "1. Add First Data" << endl;
			cout << "2. Add Middle Data" << endl;
			cout << "3. Add Last Data" << endl;
			cout << "Angka selain diatas untuk keluar" << endl;
			cout << "Masukkan pilihan : "; cin >> add;
			switch (add)
			{
			case 1:
				cout << "Judul Buku      : ";
				cin >> judul;
				cout << "Pengarang Buku  : ";
				cin >> pengarang;
				cout << "Tahun Terbit	 : ";
				cin >> tahunTerbit;
				addFirst(judul, pengarang, tahunTerbit);
				cout << endl << endl;
				break;

			case 2:
				cout << "Judul Buku      : ";
				cin >> judul;
				cout << "Pengarang Buku  : ";
				cin >> pengarang;
				cout << "Tahun Terbit	 : ";
				cin >> tahunTerbit;
				cout << "Posisi Baru	 : ";
				cin >> posisi;
				addMiddle(judul, pengarang, tahunTerbit, posisi);
				cout << endl << endl;
				break;

			case 3:
				cout << "Judul Buku      : ";
				cin >> judul;
				cout << "Pengarang Buku  : ";
				cin >> pengarang;
				cout << "Tahun Terbit	 : ";
				cin >> tahunTerbit;
				addLast(judul, pengarang, tahunTerbit);
				cout << endl << endl;
				break;
			
			default:
				cout << "Pilihan tidak valid. Silahkan coba lagi.";
				cout << "\n\n" << endl;
				break;
			}
		} while (add != 3);
	}
}

void mainMenu()
{
	int pilihan;
	do
	{
		cout << "=== Menu CRUD ===" << endl;
		cout << "1. Create Data " << endl;
		cout << "2. Read Data " << endl;
		cout << "3. Update Data " << endl;
		cout << "4. Delete Data " << endl;
		cout << "5. Add Data " << endl;
		cout << "6. Exit " << endl;
		cout << "Masukkan pilihan : "; cin >> pilihan;
		switch (pilihan)
		{
		case 1:
			createData();
			break;
		case 2:
			readData();
			break;
		case 3:
			updateData();
			break;
		case 4:
			deleteData();
			break;
		case 5:
			addData();
			break;
		case 6: 
			system("cls");
			cout << "Terimakasih telah menggunakan program ini" << endl;
			cout << "Keluar dari program...." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
			cout << "\n\n" << endl;
		}	
	} while (pilihan != 6);
}

int main()
{
	mainMenu();
	return 0;
}