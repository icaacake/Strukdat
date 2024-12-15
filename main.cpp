#include "rs.h"
#include <iostream>
using namespace std;

int main() {
    listDokter lD;
    listPasien lP;
    listRelasi lR;
    lD.first = NULL;
    lP.first = NULL;
    lP.last = NULL;
    lR.first = NULL;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Tambah Dokter\n";
        cout << "2. Tambah Pasien\n";
        cout << "3. Tambah Relasi\n";
        cout << "4. Hapus Dokter\n";
        cout << "5. Hapus Pasien\n";
        cout << "6. Hapus Relasi\n";
        cout << "7. Tampilkan Semua Dokter\n";
        cout << "8. Tampilkan Semua Pasien\n";
        cout << "9. Tampilkan Semua Relasi\n";
        cout << "10. Cari Pasien\n";
        cout << "11. Cari Relasi\n";
        cout << "12. Edit Relasi\n";
        cout << "13. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        if (choice == 1) {
            string nama, spesialis;
            int id;
            cout << "Masukkan Nama Dokter: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan ID Dokter: ";
            cin >> id;
            cout << "Masukkan Spesialis Dokter: ";
            cin.ignore();
            getline(cin, spesialis);
            insertDokter(lD, nama, id, spesialis);
        } else if (choice == 2) {
            string nama, alamat, penyakit, obat;
            int id, usia, biaya;
            cout << "Masukkan Nama Pasien: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan ID Pasien: ";
            cin >> id;
            cout << "Masukkan Usia Pasien: ";
            cin >> usia;
            cout << "Masukkan Alamat Pasien: ";
            cin.ignore();
            getline(cin, alamat);
            cout << "Masukkan Nama Penyakit: ";
            getline(cin, penyakit);
            cout << "Masukkan Biaya: ";
            cin >> biaya;
            cout << "Masukkan Nama Obat: ";
            cin.ignore();
            getline(cin, obat);
            insertPasien(lP, id, nama, usia, alamat, penyakit, biaya, obat);
        } else if (choice == 3) {
            int idDokter, idPasien;
            cout << "Masukkan ID Dokter: ";
            cin >> idDokter;
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;
            adrDokter D = lD.first;
            while (D != NULL && D->info.idDokter != idDokter) {
                D = D->next;
            }
            adrPasien P = lP.first;
            while (P != NULL && P->info.idPasien != idPasien) {
                P = P->next;
            }
            if (D != NULL && P != NULL) {
                insertRelation(lR, D, P);
            } else {
                cout << "Dokter atau Pasien tidak ditemukan!" << endl;
            }
        } else if (choice == 4) {
            int id;
            cout << "Masukkan ID Dokter yang ingin dihapus: ";
            cin >> id;
            deleteDokter(lD, id);
        } else if (choice == 5) {
            int id;
            cout << "Masukkan ID Pasien yang ingin dihapus: ";
            cin >> id;
            deletePasien(lP, id);
        } else if (choice == 6) {
            int idDokter, idPasien;
            cout << "Masukkan ID Dokter: ";
            cin >> idDokter;
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;
            adrDokter D = lD.first;
            while (D != NULL && D->info.idDokter != idDokter) {
                D = D->next;
            }
            adrPasien P = lP.first;
            while (P != NULL && P->info.idPasien != idPasien) {
                P = P->next;
            }
            if (D != NULL && P != NULL) {
                deleteRelation(lR, D, P);
            } else {
                cout << "Dokter atau Pasien tidak ditemukan!" << endl;
            }
        } else if (choice == 7) {
            showAllDataDokter(lD);
        } else if (choice == 8) {
            showAllDataPasien(lP);
        } else if (choice == 9) {
            showAllRelation(lR);
        } else if (choice == 10) {
            int id;
            cout << "Masukkan ID Pasien: ";
            cin >> id;
            findPasien(lP, id);
        } else if (choice == 11) {
            int idDokter, idPasien;
            cout << "Masukkan ID Dokter: ";
            cin >> idDokter;
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;
            adrDokter D = lD.first;
                        while (D != NULL && D->info.idDokter != idDokter) {
                D = D->next;
            }
            adrPasien P = lP.first;
            while (P != NULL && P->info.idPasien != idPasien) {
                P = P->next;
            }
            if (D != NULL && P != NULL) {
                findRelation(lR, D, P);
            } else {
                cout << "Dokter atau Pasien tidak ditemukan!" << endl;
            }
        } else if (choice == 12) {
            int idDokter, idPasien, newIdDokter, newIdPasien;
            cout << "Masukkan ID Dokter: ";
            cin >> idDokter;
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;
            cout << "Masukkan ID Dokter Baru: ";
            cin >> newIdDokter;
            cout << "Masukkan ID Pasien Baru: ";
            cin >> newIdPasien;
            adrDokter D = lD.first;
            while (D != NULL && D->info.idDokter != idDokter) {
                D = D->next;
            }
            adrPasien P = lP.first;
            while (P != NULL && P->info.idPasien != idPasien) {
                P = P->next;
            }
            adrDokter newD = lD.first;
            while (newD != NULL && newD->info.idDokter != newIdDokter) {
                newD = newD->next;
            }
            adrPasien newP = lP.first;
            while (newP != NULL && newP->info.idPasien != newIdPasien) {
                newP = newP->next;
            }
            if (D != NULL && P != NULL && newD != NULL && newP != NULL) {
                editRelationParentChild(lR, D, P, newD, newP);
            } else {
                cout << "Dokter atau Pasien tidak ditemukan!" << endl;
            }
        } else if (choice == 13) {
            cout << "Keluar dari program." << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 13);

    return 0;
}

