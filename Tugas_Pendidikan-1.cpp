#include <iostream>
#include <string>
using namespace std;

// Kelas Contact
class Contact {
private:
    string nama;
    string nomor_telepon;

public:
    Contact(string nama = "", string nomor_telepon = "") {
        this->nama = nama;
        this->nomor_telepon = nomor_telepon;
    }

    string getNama() {
        return nama;
    }

    string getnomor_telepon() {
        return nomor_telepon;
    }

    // Menampilkan informasi kontak
    void display() {
        cout << "Nama: " << nomor_telepon << ", Nomor Telepon: " << nomor_telepon << endl;
    }
};

// Kelas PhoneBook
class PhoneBook {
private:
    Contact contacts[8]; 
    int count;

public:
    PhoneBook() {
        count = 0;
    }

    // Menambahkan kontak baru
    void addContact(string nama, string nomor_telepon) {
        if (count < 8) {
            contacts[count] = Contact(nama, nomor_telepon);
            count++;
        } else {
            for (int i = 1; i < 8; i++) {
                contacts[i - 1] = contacts[i];
            }
            contacts[7] = Contact(nama, nomor_telepon);
        }
    }

    // Mencari kontak berdasarkan nama
    void cari_kontak(string nama) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (contacts[i].getNama() == nama) {
                contacts[i].display();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Contact not found." << endl;
        }
    }

    // Menampilkan semua kontak
    void displayContacts() {
        if (count == 0) {
            cout << "PhoneBook kosong." << endl;
        } else {
            for (int i = 0; i < count; i++) {
                contacts[i].display();
            }
        }
    }
};

// Fungsi utama
int main() {
    PhoneBook phoneBook;
    string command;

    while (true) {
        cout << "\Input command (ADD, SEARCH, EXIT): ";
        cin >> command;

        if (command == "ADD") {
            string nama, nomor_telepon;
            cout << "Masukkan nama kontak : ";
            cin >> nama;
            cout << "Masukkan nomor telepon : ";
            cin >> nomor_telepon;
            phoneBook.addContact(nama, nomor_telepon);
        } else if (command == "SEARCH") {
            string nama;
            cout << "Masukkan nama yang ingin dicari : ";
            cin >> nama;
            phoneBook.searchContact(nama);
        } else if (command == "EXIT") {
            cout << "Keluar dari program." << endl;
            break;
        } else {
            cout << "Command tidak valid. Coba lagi!" << endl;
        }
    }

    return 0;
}
