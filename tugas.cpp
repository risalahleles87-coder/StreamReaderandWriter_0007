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


// UPDATE

void updateBarang() {
    ifstream file("gudang.txt");
    vector<string> data;
    string baris;

    while (getline(file, baris)) {
        data.push_back(baris);
    }
    file.close();

    if (data.empty()) {
        cout << "Data kosong.\n";
        return;
    }

    tampilkanBarang();

    int nomor;
    cout << "\nPilih nomor barang yang akan diubah : ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size()) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    cin.ignore();

    cout << "Masukkan data baru : ";
    getline(cin, data[nomor - 1]);

    ofstream out("gudang.txt");

    for (string item : data) {
        out << item << endl;
    }

    out.close();

    cout << "Data berhasil diperbarui.\n";
}


// DELETE

void hapusBarang() {
    ifstream file("gudang.txt");
    vector<string> data;
    string baris;

    while (getline(file, baris)) {
        data.push_back(baris);
    }

    file.close();

    if (data.empty()) {
        cout << "Data kosong.\n";
        return;
    }

    tampilkanBarang();

    int nomor;
    cout << "\nPilih nomor barang yang akan dihapus : ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size()) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    data.erase(data.begin() + nomor - 1);

    ofstream out("gudang.txt");

    for (string item : data) {
        out << item << endl;
    }

    out.close();

    cout << "Data berhasil dihapus.\n";
}

// SIMULASI ETALASE

void simulasiEtalase() {
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";

    // Skenario 1
    try {
        cout << "\nSkenario 1 (Rak 1)\n";
        cout << "Barang ditemukan : "
             << toko.ambilProduk(1) << endl;
    }
    catch (string pesan) {
        cout << pesan << endl;
    }

    // Skenario 2
    try {
        cout << "\nSkenario 2 (Rak 5)\n";
        cout << "Barang ditemukan : "
             << toko.ambilProduk(5) << endl;
    }
    catch (string pesan) {
        cout << pesan << endl;
    }
}


