#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>

using namespace std;

struct Players{
    int ID[250]; //ID yang dimiliki tiap pemain. Ascending ke Atas
    string nama[250];
    string role[250]; // Posisi Pemain di lapangan
    int Overall[250]; // Total perhitungan kekuatan pemain dari atribut-atribut dalam game. Detail tidak akan dijelaskan
    int value[250]; // Harga Transfer suatu pemain dalam game
};

struct output {
    int Id; //ID yang dimiliki tiap pemain. Ascending ke Atas
    string name;
    int Harga;
};

void ClassificationRole(Players &Class_position, int &j, Players DataPlayer, string position, int overall, int N);

output SequentialSearchIterative(Players Dataplayer, string position, int Overall, int value, int N);

output binarysearchplayerIterative(Players Dataplayer, string position, int Overall, int value, int N);

output binarysearchplayerRecursive(Players Dataplayer, string position, int Overall, int value, int N, int low, int high);

output SequentialSearchRecursive(Players Dataplayer, string position, int Overall, int value, int N, int i);

void init_players_1(Players &DataPemain);
void init_players_2(Players &DataPemain);
void init_players_3(Players &DataPemain);
void init_players_4(Players &DataPemain);
void init_players_5(Players &DataPemain);

#endif // ADT_H_INCLUDED
