#include "test.h"

void creatParent(Parent &P) {
    first(P) = nil;
}

addressP creatElmParent(infoDokter info) {
    addressP p = new elmParent;
    info(p) = info;
    relasi(p) = nil;
    next(p) = nil;
    return p;
}

void insertLast(Parent &P, addressP p) {
    if (first(P) == nil) {
        first(P) = p;
    } else {
        addressP temp = first(P);
        while (next(temp) != nil) {
            temp = next(temp);
        }
        next(temp) = p;
    }
}

void showParent(Parent P) {
    addressP p = first(P);
    while (p != nil) {
        cout << "Dokter: " << info(p).nama << ", Spesialisasi: " << info(p).spesialisasi << ", Umur: " << info(p).umur << endl;
        p = next(p);
    }
}

void deleteParent(Parent &P, string nama) {
    addressP temp = first(P);
    addressP prev = nil;

    while (temp != nil && info(temp).nama != nama) {
        prev = temp;
        temp = next(temp);
    }

    if (temp != nil) {
        if (prev == nil) {
            first(P) = next(temp);
        } else {
            next(prev) = next(temp);
        }
        delete temp;
    }
}

addressP findParent(Parent P, string nama) {
    addressP p = first(P);
    while (p != nil) {
        if (info(p).nama == nama) {
            return p;
        }
        p = next(p);
    }
    return nil;
}

void creatChild(Child &C) {
    first(C) = nil;
}

addressC creatElmChild(infoPasien info) {
    addressC c = new elmChild;
    info(c) = info;
    next(c) = nil;
    return c;
}

void insertChild(Child &C, addressC c) {
    if (first(C) == nil) {
        first(C) = c;
    } else {
        addressC temp = first(C);
        while (next(temp) != nil) {
            temp = next(temp);
        }
        next(temp) = c;
    }
}

addressC findChild(Child C, string nama) {
    addressC c = first(C);
    while (c != nil) {
        if (info(c).nama == nama) {
            return c;
        }
        c = next(c);
    }
    return nil;
}

void deleteChild(string namaPasien, Child &C) {
    addressC temp = first(C);
    addressC prev = nil;

    while (temp != nil && info(temp).nama != namaPasien) {
        prev = temp;
        temp = next(temp);
    }

    if (temp != nil) {
        if (prev == nil) {
            first(C) = next(temp);
        } else {
            next(prev) = next(temp);
        }
        delete temp;
    }
}

void showChild(Child C) {
    addressC c = first(C);
    while (c != nil) {
        cout << "Pasien: " << info(c).nama << ", Penyakit: " << info(c).penyakit << ", Umur: " << info(c).umur << endl;
        c = next(c);
    }
}

addressR creatElmRelasi(addressC pasien) {
    addressR r = new elmRelasi;
    info(r) = pasien;
    next(r) = nil;
    return r;
}

void insertChildToParent(Parent &P, Child C, string namaDokter, string namaPasien) {
    addressP dokter = findParent(P, namaDokter);
    addressC pasien = findChild(C, namaPasien);

    if (dokter != nil && pasien != nil) {
        addressR r = creatElmRelasi(pasien);
        if (relasi(dokter) == nil) {
            relasi(dokter) = r;
        } else {
            addressR temp = relasi(dokter);
            while (next(temp) != nil) {
                temp = next(temp);
            }
            next(temp) = r;
        }
    }
}

void countChild(Parent P, string namaDokter) {
    addressP dokter = findParent(P, namaDokter);
    if (dokter != nil) {
        int count = 0;
        addressR r = relasi(dokter);
        while (r != nil) {
            count++;
            r = next(r);
        }
        cout << "Dokter " << namaDokter << " memiliki " << count << " pasien." << endl;
    } else {
        cout << "Dokter tidak ditemukan!" << endl;
    }
}

void showAllRelasi(Parent P) {
    addressP dokter = first(P);
    while (dokter != nil) {
        cout << "Dokter: " << info(dokter).nama << " - Relasi dengan Pasien:" << endl;
        addressR r = relasi(dokter);
        while (r != nil) {
            cout << "  Pasien: " << info(info(r)).nama << ", Penyakit: " << info(info(r)).penyakit << endl;
            r = next(r);
        }
        dokter = next(dokter);
    }
}

void showAllDokter(Parent P) {
    addressP dokter = first(P);
    while (dokter != nil) {
        cout << "Dokter: " << info(dokter).nama << ", Spesialisasi: " << info(dokter).spesialisasi << endl;
        dokter = next(dokter);
    }
}

void showAllPasien(Child C) {
    addressC pasien = first(C);
    while (pasien != nil) {
        cout << "Pasien: " << info(pasien).nama << ", Penyakit: " << info(pasien).penyakit << endl;
        pasien = next(pasien);
    }
}
