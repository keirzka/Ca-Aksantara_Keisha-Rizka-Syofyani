#include <iostream>
#include <string>
using namespace std;

// Kelas Contact
class Contact {
private:
    string name;
    string phoneNumber;

public:
    // Konstruktor
    Contact(string name = "", string phoneNumber = "") {
        this->name = name;
        this->phoneNumber = phoneNumber;
    }

    // Getter untuk nama
    string getName() {
        return name;
    }

    // Getter untuk nomor telepon
    string getPhoneNumber() {
        return phoneNumber;
    }

    // Menampilkan informasi kontak
    void display() {
        cout << "Name: " << name << ", Phone Number: " << phoneNumber << endl;
    }
};

// Kelas PhoneBook
class PhoneBook {
private:
    Contact contacts[8]; // Array untuk menyimpan hingga 8 kontak
    int count;           // Jumlah kontak saat ini

public:
    // Konstruktor
    PhoneBook() {
        count = 0;
    }

    // Menambahkan kontak baru
    void addContact(string name, string phoneNumber) {
        if (count < 8) {
            contacts[count] = Contact(name, phoneNumber);
            count++;
        } else {
            // Jika penuh, gantikan kontak pertama (FIFO)
            for (int i = 1; i < 8; i++) {
                contacts[i - 1] = contacts[i];
            }
            contacts[7] = Contact(name, phoneNumber);
        }
    }

    // Mencari kontak berdasarkan nama
    void searchContact(string name) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (contacts[i].getName() == name) {
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
            cout << "PhoneBook is empty." << endl;
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
        cout << "\nEnter command (ADD, SEARCH, EXIT): ";
        cin >> command;

        if (command == "ADD") {
            string name, phoneNumber;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phoneNumber;
            phoneBook.addContact(name, phoneNumber);
        } else if (command == "SEARCH") {
            string name;
            cout << "Enter name to search: ";
            cin >> name;
            phoneBook.searchContact(name);
        } else if (command == "EXIT") {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid command. Try again." << endl;
        }
    }

    return 0;
}
