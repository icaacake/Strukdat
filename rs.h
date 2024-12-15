#ifndef RS_H_INCLUDED
#define RS_H_INCLUDED
#include <iostream>
using namespace std;

struct dokter {
    string namaDokter;
    int idDokter;
    string spesialisDokter;
};

struct pasien {
    int idPasien;
    string namaPasien;
    int usia;
    string Alamat;
    string namaPenyakit;
    int biaya;
    string namaObat;
};

typedef struct elemenDokter* adrDokter;
struct elemenDokter {
    dokter info;
    adrDokter next;
};

struct listDokter {
    adrDokter first;
};

typedef struct elemenPasien* adrPasien;
struct elemenPasien {
    pasien info;
    adrPasien next;
    adrPasien prev;
};

struct listPasien {
    adrPasien first;
    adrPasien last;
};

typedef struct elemenRelasi* adrRelasi;
struct elemenRelasi {
    adrDokter nextDokter;
    adrPasien nextPasien;
    adrRelasi next;
};

struct listRelasi {
    adrRelasi first;
};

void insertDokter(listDokter &lD, string namaDokter, int idDokter, string spesialisDokter);
void insertPasien(listPasien &lP, int idPasien, string namaPasien, int usia, string Alamat, string namaPenyakit, int biaya, string namaObat);
void insertRelation(listRelasi &lR, adrDokter D, adrPasien P);
void deleteDokter(listDokter &lD, int idDokter);
void deletePasien(listPasien &lP, int idPasien);
void deleteRelation(listRelasi &lR, adrDokter D, adrPasien P);
void findPasien(const listPasien &lP, int idPasien);
void findRelation(const listRelasi &lR, adrDokter D, adrPasien P);
void showAllDataDokter(listDokter &lD);
void showAllDataPasien(listPasien &lP);
void showAllRelation(listRelasi &lR);
void showDataDokter(listDokter);
void showDataPasien(listPasien);
void showDataRelation(listRelasi);
void countPasien(listPasien &lP);
void countDokter(listDokter &lD);
void countPasienTanpaDokter(listPasien &lP, listRelasi &lR);
void countDokterTanpaPasien(listDokter &lD, listRelasi &lR);
void editRelationParentChild(listRelasi &lR, adrDokter D, adrPasien P, adrDokter newDokter, adrPasien newPasien);

#endif // RS_H_INCLUDED
