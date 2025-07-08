// Kelompok 1
#include <iostream>
#include <iomanip>
using namespace std;

//struct untuk menyimpan data publikasi
struct Publikasi{
    string judul, penulis;
    int tahun, sitasi;
};

//fungsi untuk input data publikasi
void inputData(Publikasi *arr, int n = 5){
    cout << "\nInput data publikasi" << endl;
    for (int i = 0; i < n; i++){
        cout << "\nPublikasi ke-" << (i + 1) << endl;
        cout << "Judul\t: ";
        getline(cin, (arr + i)->judul);
        cout << "Penulis\t: ";
        getline(cin, (arr + i)->penulis);
        cout << "Tahun\t: ";
        cin >> (arr + i)->tahun;
        cout << "Jumlah sitasi\t: ";
        cin >> (arr + i)->sitasi; cin.ignore();
    }
}

//fungsi untuk menampilkan data publikasi dalam bentuk tabel
void tampilkanData(const Publikasi *arr, int n){
    cout << "=====================================================================" << endl;
    cout << "| " << setw(20) << left << "Judul" 
             << "| " << setw(20) << left << "Penulis" 
             << "| " << setw(10) << left << "Tahun" 
             << "| " << setw(10) << left << "Sitasi" 
             << "|" << endl;
    cout << "+---------------------+---------------------+-----------+-----------+" << endl;
    for(int i = 0; i < n; i++){
        cout << "| " << setw(20) << left << (arr+i)->judul
             << "| " << setw(20) << left << (arr+i)->penulis
             << "| " << setw(10) << left << (arr+i)->tahun
             << "| " << setw(10) << left << (arr+i)->sitasi
             << "|" << endl;
    }
    cout << "=====================================================================" << endl;
}

//fungsi untuk mengurutkan data publikasi berdasarkan jumlah sitasi (insertion sort)
void insertionsort(Publikasi *arr, int n) {

    for (int i = 1; i < n; i++) {
        Publikasi key = *(arr + i);
        int j = i - 1;

        while (j >= 0 && (arr + j)->sitasi < key.sitasi) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }

        *(arr + j + 1) = key;
    }
}

// Fungsi utama
int main(){
    
    int jumlahData = 50;
    Publikasi data[jumlahData];// Array untuk menyimpan data publikasi
    
    while(true){

        int n;
        cout << "Masukkan jumlah publikasi: ";
        cin >> n; cin.ignore();

        // Validasi jumlah publikasi
        if (n < 5 || n > jumlahData) {
            cout << "Jumlah publikasi minimal 5 dan maxsimal 50.." << endl;
            continue;
        }

        // Input data publikasi
        inputData(data, n);
        
        // Tampilkan data sebelum diurutkan
        cout << "\nSebelum Diurutkan" << endl;
        tampilkanData(data, n);

        // Urutkan data publikasi berdasarkan jumlah sitasi
        insertionsort(data, n);

        // Tampilkan data setelah diurutkan
        cout << "\nSesudah Diurutkan" << endl;
        tampilkanData(data, n);

        // Tanya pengguna apakah ingin keluar dari program
        char ulang;
        cout << "\nKeluar program? (y/n): ";
        cin >> ulang;
        if (ulang == 'y' || ulang == 'Y') break;
    }

    return 0;
}
