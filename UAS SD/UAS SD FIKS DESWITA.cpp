#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Struktur untuk menyimpan data buku
struct Buku {
    string judul, penulis, tahun;
    
    
};

// Daftar buku
vector<Buku> daftarBuku;

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    int lebarTabel = 45;

    cout << "+";
    for (int i = 0; i < lebarTabel; ++i) cout << "-";
    cout << "+\n";

    cout << "Selamat Datang di Program CRUD  \n";

    cout << "+";
    for (int i = 0; i < lebarTabel; ++i) cout << "-";
    cout << "+\n";
    
    
    cout << " ___________________________ \n";
    cout << "|                           |\n";
    cout << "|     inputkan pilihan      |\n";
    cout << "|___________________________|\n";
	cout << "|                           |\n";
    cout << "| 1. Add Data Buku          |\n";
    cout << "| 2. Lihat Data Buku        |\n";
    cout << "| 3. Update Data Buku       |\n";
    cout << "| 4. Delete Data Buku       |\n";
    cout << "| 5. Keluar                 |\n";
    cout << "|___________________________|\n";

    cout << "+";
    for (int i = 0; i < lebarTabel; ++i) cout << "-";
    cout << "+\n";

    cout << "Silahkan ^v^ \n";

}

// Fungsi untuk menambah buku
void tambahBuku() {
    Buku bukuBaru;
    cout << "Masukkan judul buku: ";
    cin.ignore();
    getline(cin, bukuBaru.judul);
    cout << "Masukkan penulis buku: ";
    getline(cin, bukuBaru.penulis);
    cout << "Masukkan tahun terbit buku: ";
    getline(cin, bukuBaru.tahun);
    daftarBuku.push_back(bukuBaru);
    cout << "Buku '" << bukuBaru.judul << "' berhasil ditambahkan." << endl;
}

// Fungsi untuk menampilkan semua buku dalam tabel
void tampilkanBuku() {
    if (daftarBuku.empty()) {
        cout << "Tidak ada buku dalam perpustakaan." << endl;
    } else {
        cout << "\nDaftar Buku:" << endl;
        cout << left << setw(5) << "No" 
             << setw(40) << "Judul" 
             << setw(30) << "Penulis" 
			 << setw(30) << "Terbit" << endl;
        cout << string(85, '-') << endl; // Garis pisah
        for (size_t i = 0; i < daftarBuku.size(); ++i) {
            cout << left << setw(5) << (i + 1) 
                 << setw(40) << daftarBuku[i].judul 
                 << setw(30) << daftarBuku[i].penulis
				 << setw(30) << daftarBuku[i].tahun << endl;
        }
    
    }
}

void ubahBuku() {
    tampilkanBuku();
    int index;
    cout << "Masukkan nomor buku yang ingin diubah: ";
    cin >> index;
    index--; // Mengubah ke indeks 0
    if (index >= 0 && index < daftarBuku.size()) {
        cout << "Masukkan judul baru: ";
        cin.ignore();
        getline(cin, daftarBuku[index].judul);
        cout << "Masukkan penulis baru: ";
        getline(cin, daftarBuku[index].penulis);
        cout << "Masukkan tahun terbit baru: ";
        getline(cin, daftarBuku[index].tahun);
        cout << "Buku berhasil diubah." << endl;
    } else {
        cout << "Pilihan buku tidak valid." << endl;
    }
}

// Fungsi untuk menghapus buku
void hapusBuku() {
    tampilkanBuku();
    int index;
    cout << "Masukkan nomor buku yang ingin dihapus: ";
    cin >> index;
    index--; // Mengubah ke indeks 0
    if (index >= 0 && index < daftarBuku.size()) {
        daftarBuku.erase(daftarBuku.begin() + index);
        cout << "Buku berhasil dihapus." << endl;
    } else {
        cout << "Nomor buku tidak valid." << endl;
    }
}



void tampilkanHeader() {
    string header = "PERPUSTAKAAN DA UNIVERSITAS ESA UNGGUL ";
    int lebarTabel = 100; 
    int lebarHeader = header.length();
    int paddingKiri = (lebarTabel - lebarHeader) / 2;

    cout << "+";
    for (int i = 0; i < lebarTabel; ++i) cout << "-";
    cout << "+\n";

    cout << "|";
    for (int i = 0; i < paddingKiri; ++i) cout << " ";
    cout << header;
    for (int i = 0; i < lebarTabel - lebarHeader - paddingKiri; ++i) cout << " ";
    cout << "|\n";

    cout << "+";
    for (int i = 0; i < lebarTabel; ++i) cout << "-";
    cout << "+\n";
}

// Fungsi utama untuk menjalankan program
int main() {
	tampilkanHeader();
	
    cout << "Selamat datang di Perpustakaan Deswita Anggraini!" << endl;
    string peran;
    cout << "Pilih peran (admin/user): ";
    cin >> peran;

    if (peran != "admin" && peran != "user") {
        cout << "Peran tidak valid. Program akan keluar." << endl;
        return 0;
    }

    int pilihan;
    do {
        tampilkanMenu();
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (peran == "admin") {
                    tambahBuku();
                } else {
                    cout << "Hanya admin yang bisa menambah buku." << endl;
                }
                break;
            case 2:
                tampilkanBuku();
                break;
            case 3:
                if (peran == "admin") {
                    ubahBuku();
                } else {
                    cout << "Hanya admin yang bisa mengubah buku." << endl;
                }
                break;
            case 4:
                if (peran == "admin") {
                    hapusBuku();
                } else {
                    cout << "Hanya admin yang bisa menghapus buku." << endl;
                }
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program perpustakaan." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}