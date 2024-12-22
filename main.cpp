#include "ADT.h"

int main()
{
    Players data;
    Players data_classified;
    int N;
    int n;

    cout<<"Masukkan Jumlah data pemain yang ingin di-searching:\n";
    cout<<"1. 50 Pemain | 2. 100 Pemain | 3. 150 Pemain | 4. 200 Pemain | 5. 250 Pemain\n";
    int Ndata;
    cin>>Ndata;
    // Inisialisasi data pemain
    if (Ndata == 1){
        init_players_1(data);
        N = 50;
    }else if (Ndata == 2){
        init_players_1(data);
        init_players_2(data);
        N = 100;
    }else if (Ndata == 3){
        init_players_1(data);
        init_players_2(data);
        init_players_3(data);
        N = 150;
    }else if (Ndata == 4){
        init_players_1(data);
        init_players_2(data);
        init_players_3(data);
        init_players_4(data);
        N = 200;
    }else if (Ndata == 5){
        init_players_1(data);
        init_players_2(data);
        init_players_3(data);
        init_players_4(data);
        init_players_5(data);
        N = 250;
    }

    // Input pencarian
    string searchPosition;
    int searchOverall, searchValue;


    cout << "Masukkan posisi pemain yang dicari: ";
    cin >> searchPosition;

    cout << "Masukkan overall pemain yang dicari (82-91): ";
    cin >> searchOverall;

    cout << "Masukkan nilai transfer pemain yang dicari(1-200jt dan Tidak boleh 0): \n";
    cout<< "Tulis harga dgn lengkap. (ex : 10000000)\n";
    cin >> searchValue;


    // Pencarian pemain
    output result;
    bool ValidationPosition = false;
    result = {-1, "", -1}; //Default
     string role[15] = {"GK", "CB", "RB", "RWB", "LB", "LWB", "CDM", "CM", "LM", "RM", "CAM", "RW", "LW", "CF", "ST"};
    for (int i = 0; i < 15; i++){
        if (searchPosition == role[i]) {
            ValidationPosition = true;
            break;
        }
    }

    int PilihCara;
    int PilihCara2;
    cout<<"Pilih cara mencari player (1.iteratif / 2.rekursif)"<<endl;
    cin>>PilihCara;
    cout<<"Pilih metode pencarian Player (1. sequential / 2. binary)"<<endl;
    cin>>PilihCara2;


    if ((searchOverall >= 82 && searchOverall <= 91) && searchValue != 0 && ValidationPosition){
        if (PilihCara == 1) {
            if (PilihCara2 == 1){
                ClassificationRole(data_classified, n, data, searchPosition, searchOverall, N);
                result = SequentialSearchIterative(data_classified, searchPosition, searchOverall, searchValue, n);
            }else {
                int n = 0;
                ClassificationRole(data_classified, n, data, searchPosition, searchOverall, N);
                result = binarysearchplayerIterative(data_classified, searchPosition, searchOverall, searchValue, n);
            }
        }else if (PilihCara == 2){
            if (PilihCara2 == 1){
                int i = 0;
                ClassificationRole(data_classified, n, data, searchPosition, searchOverall, N);
                result = SequentialSearchRecursive(data, searchPosition, searchOverall, searchValue, n, i);
            }else {
                int i = 0;
                ClassificationRole(data_classified, n, data, searchPosition, searchOverall, N);
                result = binarysearchplayerRecursive(data_classified, searchPosition, searchOverall, searchValue, n, i, n-1);
            }
        }
    }

    if (result.Id != -1) {
        cout << "Pemain Rekomendasi: " <<endl;
        cout<< "Nama Pemain: "<<result.name<<endl;
        cout<<"Harga Pemain: "<<result.Harga<<endl;
    } else {
        cout << "Pemain tidak ditemukan." << endl;
    }

    return 0;
}
