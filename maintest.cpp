#include <iostream>
#include "test.h"

using namespace std;
int main() {
    Parent LP;  // Membuat objek Parent dengan nama LP
    creatParent(LP);  // Menginisialisasi objek Parent LP
    addressP pP;  // Deklarasi pointer addressP
    Child LC;  // Membuat objek Child dengan nama LC
    creatChild(LC);  // Menginisialisasi objek Child LC
    infoDokter dataDokter;  // Deklarasi objek infoDokter untuk menyimpan data dokter
    infoPasien dataPasien;  // Deklarasi objek infoPasien untuk menyimpan data pasien

    int menu = -1;
    while (menu != 0) {
        // Menampilkan opsi-opsi menu
        cout << "Menu: " << endl;
        cout << "1. Tambah Dokter" << endl;
        cout << "2. Tambah Pasien" << endl;
        cout << "3. Print Data Dokter" << endl;
        cout << "4. Print Data Pasien" << endl;
        cout << "5. Hapus Dokter" << endl;
        cout << "6. Hapus Pasien" << endl;
        cout << "7. Relasi Pasien ke Dokter" << endl;
        cout << "8. Jumlah Pasien Dokter" << endl;
        cout << "9. Tampilkan Semua Relasi" << endl;
        cout << "0. Exit" << endl;
        cin >> menu;

        if (menu == 1) {
            addressP newDokter; // Deklarasi pointer addressP untuk dokter baru
            string nama;
            string spesialisasi;
            int umur;
            cout << "Masukan Nama Dokter: ";
            cin >> nama;
            cout << "Masukan Spesialisasi: ";
            cin >> spesialisasi;
            cout << "Masukan Umur: ";
            cin >> umur;

            // Mengisi objek dataDokter dengan data yang diinputkan
            dataDokter.nama = nama;
            dataDokter.spesialisasi = spesialisasi;
            dataDokter.umur = umur;

            // Membuat elemen dokter baru dan memasukan ke dalam struktur Parent LP
            newDokter = creatElmParent(dataDokter);
            insertLast(LP, newDokter);

        } else if (menu == 2) {
            addressC newPasien;
            string nama;
            string penyakit;
            int umur;
            cout << "Masukan Nama Pasien: ";
            cin >> nama;
            cout << "Masukan Penyakit: ";
            cin >> penyakit;
            cout << "Masukan Umur: ";
            cin >> umur;

            // Mengisi data pasien
            dataPasien.nama = nama;
            dataPasien.penyakit = penyakit;
            dataPasien.umur = umur;
            newPasien = creatElmChild(dataPasien);
            insertChild(LC, newPasien);

        } else if (menu == 3) {
            showParent(LP);

        } else if (menu == 4) {
            showChild(LC);

        } else if (menu == 5) {
            string nama;
            cout << "Masukan Nama Dokter: ";
            cin >> nama;
            deleteParent(LP, nama);

        } else if (menu == 6) {
            string namaPasien;
            cout << "Masukan Nama Pasien: ";
            cin >> namaPasien;
            deleteChild(namaPasien, LC);

        } else if (menu == 7) {
            string namaDokter;
            string namaPasien;
            cout << "Masukan Nama Dokter: ";
            cin >> namaDokter;
            cout << "Masukan Nama Pasien: ";
            cin >> namaPasien;
            insertChildToParent(LP, LC, namaDokter, namaPasien);

        } else if (menu == 8) {
            string namaDokter;
            cout << "Masukan Nama Dokter: ";
            cin >> namaDokter;
            countChild(LP, namaDokter);

        } else if (menu == 9) {
            showAllRelasi(LP);

        } else if (menu == 0) {
            cout << "Keluar dari Program" << endl;
        } else {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    }

    return 0;
}
