#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include <iostream>
#include <string>

#define info(P) (P)->info
#define next(P) (P)->next
#define relasi(P) (P)->relasi
#define first(L) (L).first
#define nil NULL

using namespace std;

struct Dokter {
    string nama;
    string spesialisasi;
    int umur;
};

struct Pasien {
    string nama;
    string penyakit;
    int umur;
};

typedef Dokter infoDokter;
typedef Pasien infoPasien;

typedef struct elmParent *addressP;
typedef struct elmChild *addressC;
typedef struct elmRelasi *addressR;

struct elmParent {
    infoDokter info;
    addressR relasi;
    addressP next;
};

struct elmChild {
    infoPasien info;
    addressC next;
};

struct elmRelasi {
    addressC info;
    addressR next;
};

struct Parent {
    addressP first;
};

struct Child {
    addressC first;
};

// Function declarations
void creatParent(Parent &P);
addressP creatElmParent(infoDokter info);
void insertLast(Parent &P, addressP p);
void showParent(Parent P);
void deleteParent(Parent &P, string nama);
addressP findParent(Parent P, string nama);

void creatChild(Child &C);
addressC creatElmChild(infoPasien info);
void insertChild(Child &C, addressC c);
addressC findChild(Child C, string nama);
void deleteChild(string namaPasien, Child &C);
void showChild(Child C);

addressR creatElmRelasi(addressC pasien);
void insertChildToParent(Parent &P, Child C, string namaDokter, string namaPasien);
void countChild(Parent P, string namaDokter);
void showAllRelasi(Parent P);
void showAllDokter(Parent P);
void showAllPasien(Child C);
