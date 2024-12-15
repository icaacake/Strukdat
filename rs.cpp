#include "rs.h"
#include <iostream>
using namespace std;

void insertDokter(listDokter &lD, string namaDokter, int idDokter, string spesialisDokter) {
    adrDokter newElement = new elemenDokter;
    newElement->info.namaDokter = namaDokter;
    newElement->info.idDokter = idDokter;
    newElement->info.spesialisDokter = spesialisDokter;
    newElement->next = NULL;

    if (lD.first == NULL) {
        lD.first = newElement;
    } else {
        adrDokter D = lD.first;
        while (D->next != NULL) {
            D = D->next;
        }
        D->next = newElement;
    }
}

void insertPasien(listPasien &lP, int idPasien, string namaPasien, int usia, string Alamat, string namaPenyakit, int biaya, string namaObat) {
    adrPasien newElement = new elemenPasien;
    newElement->info.idPasien = idPasien;
    newElement->info.namaPasien = namaPasien;
    newElement->info.usia = usia;
    newElement->info.Alamat = Alamat;
    newElement->info.namaPenyakit = namaPenyakit;
    newElement->info.biaya = biaya;
    newElement->info.namaObat = namaObat;
    newElement->next = NULL;
    newElement->prev = NULL;

    if (lP.first == NULL) {
        lP.first = newElement;
        lP.last = newElement;
    } else {
        lP.last->next = newElement;
        newElement->prev = lP.last;
        lP.last = newElement;
    }
}

void insertRelation(listRelasi &lR, adrDokter D, adrPasien P) {
    adrRelasi newElement = new elemenRelasi;
    newElement->nextDokter = D;
    newElement->nextPasien = P;
    newElement->next = NULL;

    if (lR.first == NULL) {
        lR.first = newElement;
    } else {
        adrRelasi R = lR.first;
        while (R->next != NULL) {
            R = R->next;
        }
        R->next = newElement;
    }
}

void deleteDokter(listDokter &lD, int idDokter) {
    adrDokter D = lD.first;
    adrDokter prev = NULL;

    while (D != NULL && D->info.idDokter != idDokter) {
        prev = D;
        D = D->next;
    }

    if (D != NULL) {
        if (prev == NULL) {
            lD.first = D->next;
        } else {
            prev->next = D->next;
        }
        delete D;
        cout << "Dokter dengan ID " << idDokter << " telah dihapus" << endl;
    } else {
        cout << "Dokter dengan ID " << idDokter << " tidak ditemukan" << endl;
    }
}

void deletePasien(listPasien &lP, int idPasien) {
    adrPasien P = lP.first;
    adrPasien prev = NULL;

    while (P != NULL && P->info.idPasien != idPasien) {
        prev = P;
        P = P->next;
    }

    if (P != NULL) {
        if (prev == NULL) {
            lP.first = P->next;
        } else {
            prev->next = P->next;
        }
        delete P;
        cout << "Pasien dengan ID " << idPasien << " telah dihapus" << endl;
    } else {
        cout << "Pasien dengan ID " << idPasien << " tidak ditemukan" << endl;
    }
}

void deleteRelation(listRelasi &lR, adrDokter D, adrPasien P) {
    adrRelasi R = lR.first;
    adrRelasi prev = NULL;

    while (R != NULL && (R->nextDokter != D || R->nextPasien != P)) {
        prev = R;
        R = R->next;
    }

    if (R != NULL) {
        if (prev == NULL) {
            lR.first = R->next;
        } else {
            prev->next = R->next;
        }
        delete R;
        cout << "Relasi berhasil dihapus." << endl;
    } else {
        cout << "Relasi tidak ditemukan." << endl;
    }
}

void findPasien(const listPasien &lP, int idPasien) {
    adrPasien P = lP.first;
    while (P != NULL && P->info.idPasien != idPasien) {
        P = P->next;
    }
    if (P != NULL) {
        cout << "Pasien ditemukan: Nama = " << P->info.namaPasien << endl;
    } else {
        cout << "Pasien tidak ditemukan." << endl;
    }
    cout << "---------------------------" << endl;
}

void findRelation(const listRelasi &lR, adrDokter D, adrPasien P) {
    adrRelasi R = lR.first;
    while (R != NULL) {
        if (R->nextDokter == D && R->nextPasien == P) {
            cout << "Relasi ditemukan antara dokter dan pasien." << endl;
            cout << "---------------------------" << endl;
            return;
        }
        R = R->next;
    }
    cout << "Relasi tidak ditemukan." << endl;
    cout << "---------------------------" << endl;
}

void showAllDataDokter(listDokter &lD) {
    adrDokter D = lD.first;
    while (D != NULL) {
        cout << "ID Dokter: " << D->info.idDokter << ", Nama: " << D->info.namaDokter << ", Spesialis: " << D->info.spesialisDokter << endl;
        D = D->next;
    }
    cout << "---------------------------" << endl;
}

void showAllDataPasien(listPasien &lP) {
    adrPasien P = lP.first;
    while (P != NULL) {
        cout << "ID Pasien: " << P->info.idPasien << ", Nama: " << P->info.namaPasien << endl;
        cout << ", Usia: " << P->info.usia << ", Alamat: " << P->info.Alamat << endl;
        cout << ", Penyakit: " << P->info.namaPenyakit << ", Biaya: " << P->info.biaya << endl;
        cout << ", Obat: " << P->info.namaObat << endl;
        P = P->next;
    }
    cout << "---------------------------" << endl;
}

void showAllRelation(listRelasi &lR) {
    adrRelasi R = lR.first;
    while (R != NULL) {
        cout << "Dokter: " << R->nextDokter->info.namaDokter << " merawat Pasien: " << R->nextPasien->info.namaPasien << endl;
        R = R->next;
    }
    cout << "---------------------------" << endl;
}

void showDataDokter(listDokter lD) {
    int idDokter;
    cout << "Masukkan ID Dokter yang ingin ditampilkan: ";
    cin >> idDokter;

    adrDokter D = lD.first;
    while (D != NULL && D->info.idDokter != idDokter) {
        D = D->next;
    }

    if (D != NULL) {
        cout << "Data Dokter:\n";
        cout << "ID Dokter   : " << D->info.idDokter << endl;
        cout << "Nama Dokter : " << D->info.namaDokter << endl;
        cout << "Spesialis   : " << D->info.spesialisDokter << endl;
    } else {
        cout << "Dokter dengan ID " << idDokter << " tidak ditemukan." << endl;
    }
    cout << "---------------------------" << endl;
}

void showDataPasien(listPasien lP) {
    int idPasien;
    cout << "Masukkan ID";
        cout << "Masukkan ID Pasien yang ingin ditampilkan: ";
    cin >> idPasien;

    adrPasien P = lP.first;
    while (P != NULL && P->info.idPasien != idPasien) {
        P = P->next;
    }

    if (P != NULL) {
        cout << "Data Pasien:\n";
        cout << "ID Pasien    : " << P->info.idPasien << endl;
        cout << "Nama Pasien  : " << P->info.namaPasien << endl;
        cout << "Usia         : " << P->info.usia << endl;
        cout << "Alamat       : " << P->info.Alamat << endl;
        cout << "Penyakit     : " << P->info.namaPenyakit << endl;
        cout << "Biaya        : " << P->info.biaya << endl;
        cout << "Obat         : " << P->info.namaObat << endl;
    } else {
        cout << "Pasien dengan ID " << idPasien << " tidak ditemukan." << endl;
    }
    cout << "---------------------------" << endl;
}

void showDataRelation(listRelasi lR) {
    int idDokter, idPasien;
    cout << "Masukkan ID Dokter: ";
    cin >> idDokter;
    cout << "Masukkan ID Pasien: ";
    cin >> idPasien;

    adrRelasi R = lR.first;
    while (R != NULL) {
        if (R->nextDokter->info.idDokter == idDokter && R->nextPasien->info.idPasien == idPasien) {
            cout << "Relasi ditemukan:\n";
            cout << "Dokter: " << R->nextDokter->info.namaDokter << " (ID: " << R->nextDokter->info.idDokter << ")\n";
            cout << "Pasien: " << R->nextPasien->info.namaPasien << " (ID: " << R->nextPasien->info.idPasien << ")\n";
            cout << "---------------------------" << endl;
            return;
        }
        R = R->next;
    }
    cout << "Relasi antara Dokter dengan ID " << idDokter << " dan Pasien dengan ID " << idPasien << " tidak ditemukan." << endl;
    cout << "---------------------------" << endl;
}

void countPasien(listPasien &lP) {
    int count = 0;
    adrPasien P = lP.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    cout << "Jumlah Pasien: " << count << endl;
    cout << "---------------------------" << endl;
}

void countDokter(listDokter &lD) {
    int count = 0;
    adrDokter D = lD.first;
    while (D != NULL) {
        count++;
        D = D->next;
    }
    cout << "Jumlah Dokter: " << count << endl;
    cout << "---------------------------" << endl;
}

void countPasienTanpaDokter(listPasien &lP, listRelasi &lR) {
    int count = 0;
    adrPasien P = lP.first;
    while (P != NULL) {
        adrRelasi R = lR.first;
        bool found = false;
        while (R != NULL) {
            if (R->nextPasien == P) {
                found = true;
            }
            R = R->next;
        }
        if (!found) {
            count++;
        }
        P = P->next;
    }
    cout << "Jumlah Pasien tanpa Dokter: " << count << endl;
    cout << "---------------------------" << endl;
}

void countDokterTanpaPasien(listDokter &lD, listRelasi &lR) {
    int count = 0;
    adrDokter D = lD.first;
    while (D != NULL) {
        adrRelasi R = lR.first;
        bool found = false;
        while (R != NULL) {
            if (R->nextDokter == D) {
                found = true;
            }
            R = R->next;
        }
        if (!found) {
            count++;
        }
        D = D->next;
    }
    cout << "Jumlah Dokter tanpa Pasien: " << count << endl;
    cout << "---------------------------" << endl;
}

void editRelationParentChild(listRelasi &lR, adrDokter D, adrPasien P, adrDokter newDokter, adrPasien newPasien) {
    adrRelasi R = lR.first;
    while (R != NULL) {
        if (R->nextDokter == D && R->nextPasien == P) {
            R->nextDokter = newDokter;
            R->nextPasien = newPasien;
            cout << "Relasi berhasil diperbarui." << endl;
            cout << "---------------------------" << endl;
            return;
        }
        R = R->next;
    }
    cout << "Relasi tidak ditemukan." << endl;
    cout << "---------------------------" << endl;
}

