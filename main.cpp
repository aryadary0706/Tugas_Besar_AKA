#include "ADT.h"
#include <chrono>
#include <iomanip>
using namespace std;

int main()
{
    Players data;
    Players data_classified;
    int N = 0; // Inisialisasi N
    int n = 0; // Inisialisasi n
    output result;

    cout << "              |      |               \n";
    cout << "-------------------------------------\n";
    cout << "|                GK                  |\n";
    cout << "|                                    |\n";
    cout << "|     RB     CB        CB      LB    |\n";
    cout << "|                                    |\n";
    cout << "| RWB            CDM              LWB|\n";
    cout << "|          CM           CM           |\n";
    cout << "|                                    |\n";
    cout << "|                                    |\n";
    cout << "|     RM          CAM          LM    |\n";
    cout << "|                                    |\n";
    cout << "|     RW                       LW    |\n";
    cout << "|                  CF                |\n";
    cout << "|                                    |\n";
    cout << "|                  ST                |\n";
    cout << "--------------------------------------\n";
    cout << endl;

    cout << "Masukkan Jumlah data pemain yang ingin di-searching:\n";
    cout << "1. 10 Pemain | 2. 50 Pemain | 3. 100 Pemain | 4.250 Pemain \n";
    int Ndata;
    cin >> Ndata;

    // Inisialisasi data pemain
    switch (Ndata) {
        case 1:
            init_players_1(data);
            N = 10;
            break;
        case 2:
            init_players_1(data);
            init_players_2(data);
            N = 50;
            break;
        case 3:
            init_players_1(data);
            init_players_2(data);
            init_players_3(data);
            N = 100;
            break;
        case 4:
            init_players_1(data);
            init_players_2(data);
            init_players_3(data);
            N = 250;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            return 1; // Keluar dari program jika input tidak valid
    }

    // Input pencarian
    string searchPosition;
    int searchOverall, searchValue;

    cout << "-----------------------------------------------" << endl;
    cout << "Masukkan posisi pemain yang dicari: ";
    cin >> searchPosition;

    cout << "Masukkan overall pemain yang dicari (80-91): ";
    cin >> searchOverall;

    cout << "Masukkan nilai transfer pemain yang dicari (1-200jt dan disarannkan tidak 0): \n";
    cout << "Tulis harga dengan lengkap. (ex: 120 jt = 120000000): ";
    cin >> searchValue;

    int PilihCara;
    int PilihCara2;
    cout << "Pilih cara mencari player (1.iteratif / 2.rekursif)" << endl;
    cin >> PilihCara;
    cout << "Pilih metode pencarian Player (1. sequential / 2. binary)" << endl;
    auto start = chrono::high_resolution_clock::now();
    cin >> PilihCara2;

    if (PilihCara == 1) {
        if (PilihCara2 == 1) {
            ClassificationRole(data_classified, n, data, searchPosition, searchOverall, N);
            result = SequentialSearchIterative(data_classified, searchPosition, searchOverall, searchValue, n);
        } else if (PilihCara2 == 2){
            ClassificationRole(data_classified, n, data, searchPosition, searchOverall, N);
            result = binarysearchplayerIterative(data_classified, searchPosition, searchOverall, searchValue, n);
        } else {
            result = {-1," ",-1};
        }
    } else if (PilihCara == 2) {
        if (PilihCara2 == 1) {
            int i = 0;
            ClassificationRole(data_classified, n, data, searchPosition , searchOverall, N);
            result = SequentialSearchRecursive(data_classified, searchPosition, searchOverall, searchValue, n, i);
        } else if (PilihCara2 == 2){
            int i = 0;
            ClassificationRole(data_classified, n, data, searchPosition, searchOverall, N);
            result = binarysearchplayerRecursive(data_classified, searchPosition, searchOverall, searchValue, n, i, n - 1);
        } else {
            result = {-1," ",-1};
        }
    }else{
        result = {-1," ",-1};
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end - start;

    if (result.Id != -1) {
        cout << "Pemain Rekomendasi: " << endl;
        cout << "Nama Pemain: " << result.name << endl;
        cout << "Harga Pemain: " << result.Harga << endl;
    } else {
        cout << "Pemain tidak ditemukan." << endl;
    }

    cout << "Waktu eksekusi: " << fixed << setprecision(6) << elapsed.count() << " ms" << endl;
    return 0;
}
