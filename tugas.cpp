#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>

using namespace std;


// KELAS TOKO ELEKTRONIK (OOP)

class TokoElektronik {
private:
    array<string, 3> etalase;

public:
    // Constructor
    TokoElektronik() {
        etalase[0] = "Laptop Asus";
        etalase[1] = "Smartphone Samsung";
        etalase[2] = "Printer Epson";
    }

    // Method mengambil produk
    string ambilProduk(size_t nomorRak) {
        try {
            return etalase.at(nomorRak);
        }
        catch (out_of_range&) {
            throw string(
                "Gagal Mengambil Barang : Rak nomor " +
                to_string(nomorRak) +
                " kosong atau tidak tersedia!"
            );
        }
    }
};


// FUNGSI MENAMPILKAN ISI FILE

void tampilkanBarang() {
    ifstream file("gudang.txt");
    string data;

    cout << "\n===== DATA BARANG DI GUDANG =====\n";

    if (!file.is_open()) {
        cout << "Belum ada data barang.\n";
        return;
    }

    int no = 1;
    while (getline(file, data)) {
        cout << no++ << ". " << data << endl;
    }

    if (no == 1)
        cout << "Gudang kosong.\n";

    file.close();
}


// CREATE

void tambahBarang() {
    ofstream file("gudang.txt", ios::app);

    string barang;
    cin.ignore();

    cout << "Masukkan nama barang : ";
    getline(cin, barang);

    file << barang << endl;
    file.close();

    cout << "Barang berhasil ditambahkan.\n";
}


// READ

void bacaBarang() {
    tampilkanBarang();
}


