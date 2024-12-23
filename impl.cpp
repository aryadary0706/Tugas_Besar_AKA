#include "ADT.h"


void ClassificationRole(Players &Class_position, int &j, Players DataPlayer, string position, int overall, int N) {
    j = 0;
    for (int i = 0; i < N; i++) {
        if (DataPlayer.role[i] == position && DataPlayer.Overall[i] <= overall) {
            Class_position.ID[j] = DataPlayer.ID[i];
            Class_position.nama[j] = DataPlayer.nama[i];
            Class_position.Overall[j] = DataPlayer.Overall[i];
            Class_position.role[j] = DataPlayer.role[i];
            Class_position.value[j] = DataPlayer.value[i];
            j++;
        }
    }
}


output SequentialSearchIterative(Players Dataplayer, string position, int Overall, int value, int N) {
    output CalonPemain;
    CalonPemain = {-1,"",-1};
    bool pemain_ketemu = false;
    int i = 0;

        while (!pemain_ketemu && i < N) {
            if ((Dataplayer.value[i] >= (value - (value*0.5))  && Dataplayer.value[i] <= value)) {
                CalonPemain.Id = Dataplayer.ID[i];
                CalonPemain.name = Dataplayer.nama[i];
                CalonPemain.Harga = Dataplayer.value[i];
                pemain_ketemu = true;
            }
            i++;
        }
    return CalonPemain;
}

output binarysearchplayerIterative(Players Dataplayer, string position, int Overall, int value, int N) {
    output CalonPemain;
    CalonPemain = {-1, "", -1};
    int low = 0;
    int high = N - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;


        if (Dataplayer.value[mid] > value - (value * 0.5) && Dataplayer.value[mid] <= value) {
            CalonPemain.Id = Dataplayer.ID[mid];
            CalonPemain.name = Dataplayer.nama[mid];
            CalonPemain.Harga = Dataplayer.value[mid];
            return CalonPemain;
        }


        if (Dataplayer.value[mid] < value - (value * 0.5)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }


    return CalonPemain;
}

output SequentialSearchRecursive(Players Dataplayer, string position, int Overall, int value, int N, int i) {
    output CalonPemain;
    CalonPemain = {-1, "", -1};


    if (i >= N) {
        return CalonPemain;
    }


    if (Dataplayer.value[i] >= value - (value*0.5)  && Dataplayer.value[i] <= value) {
        CalonPemain.Id = Dataplayer.ID[i];
        CalonPemain.name = Dataplayer.nama[i];
        CalonPemain.Harga = Dataplayer.value[i];
        return CalonPemain;
    }


    return SequentialSearchRecursive(Dataplayer, position, Overall, value, N, i + 1);
}

output binarysearchplayerRecursive(Players Dataplayer, string position, int Overall, int value, int N, int low, int high) {
    output CalonPemain;
    CalonPemain = {-1, "", -1};
    if (low > high) {
        return CalonPemain;
    }
    int mid = low + (high - low) / 2;

    if (Dataplayer.value[mid] > value - (value*0.5)  && Dataplayer.value[mid] <= value) {

        CalonPemain.Id = Dataplayer.ID[mid];
        CalonPemain.name = Dataplayer.nama[mid];
        CalonPemain.Harga = Dataplayer.value[mid];
        return CalonPemain;
    }

    if (Dataplayer.value[mid] <= value-(value*0.5)) {
        return binarysearchplayerRecursive(Dataplayer, position, Overall, value, N, mid + 1, high);
    } else {
        return binarysearchplayerRecursive(Dataplayer, position, Overall, value, N, low, mid - 1);
    }
}

string role[15] = {"GK", "CB", "RB", "RWB", "LB", "LWB", "CDM", "CM", "LM", "RM", "CAM", "RW", "LW", "CF", "ST"};

void init_players_1(Players &DataPemain){
    DataPemain.ID[0] = 1; DataPemain.nama[0] = "Kylian Mbappe Lottin"; DataPemain.role[0] = role[14]; DataPemain.Overall[0] = 91; DataPemain.value[0] = 181500000;
    DataPemain.ID[1] = 2; DataPemain.nama[1] = "Erling Braut Haland"; DataPemain.role[1] = role[14]; DataPemain.Overall[1] = 91; DataPemain.value[1] = 180000000;
    DataPemain.ID[2] = 3; DataPemain.nama[2] = "Vinicius José Paixão de Oliveira Junior"; DataPemain.role[2] = role[12]; DataPemain.Overall[2] = 89; DataPemain.value[2] = 158500000;
    DataPemain.ID[3] = 4; DataPemain.nama[3] = "Jamal Musiala"; DataPemain.role[3] = role[10]; DataPemain.Overall[3] = 86; DataPemain.value[3] = 134500000;
    DataPemain.ID[4] = 5; DataPemain.nama[4] = "Rodri"; DataPemain.role[4] = role[6]; DataPemain.Overall[4] = 90; DataPemain.value[4] = 129500000;
    DataPemain.ID[5] = 6; DataPemain.nama[5] = "Jude Victor William Bellingham"; DataPemain.role[5] = role[10]; DataPemain.Overall[5] = 88; DataPemain.value[5] = 128500000;
    DataPemain.ID[6] = 7; DataPemain.nama[6] = "Federico Santiago Valverde"; DataPemain.role[6] = role[7]; DataPemain.Overall[6] = 88; DataPemain.value[6] = 124000000;
    DataPemain.ID[7] = 8; DataPemain.nama[7] = "Harry Kane"; DataPemain.role[7] = role[14]; DataPemain.Overall[7] = 90; DataPemain.value[7] = 119500000;
    DataPemain.ID[8] = 9; DataPemain.nama[8] = "Florian Richard Wirtz"; DataPemain.role[8] = role[10]; DataPemain.Overall[8] = 87; DataPemain.value[8] = 118500000;
    DataPemain.ID[9] = 10; DataPemain.nama[9] = "Martin Ødegaard"; DataPemain.role[9] = role[7]; DataPemain.Overall[9] = 88; DataPemain.value[9] = 118000000;

}

void init_players_2(Players &DataPemain){
    DataPemain.ID[10] = 11; DataPemain.nama[10] = "Lautaro Javier Martínez"; DataPemain.role[10] = role[14]; DataPemain.Overall[10] = 88; DataPemain.value[10] = 116000000;
    DataPemain.ID[11] = 12; DataPemain.nama[11] = "Khvicha Kvaratskhelia"; DataPemain.role[11] = role[11]; DataPemain.Overall[11] = 86; DataPemain.value[11] = 109000000;
    DataPemain.ID[12] = 13; DataPemain.nama[12] = "Philip Walter Foden"; DataPemain.role[12] = role[11]; DataPemain.Overall[12] = 87; DataPemain.value[12] = 109000000;
    DataPemain.ID[13] = 14; DataPemain.nama[13] = "Rúben dos Santos Gato Alves Dias"; DataPemain.role[13] = role[1]; DataPemain.Overall[13] = 89; DataPemain.value[13] = 106500000;
    DataPemain.ID[14] = 15; DataPemain.nama[14] = "Pedro González López"; DataPemain.role[14] = role[7]; DataPemain.Overall[14] = 86; DataPemain.value[14] = 105000000;
    DataPemain.ID[15] = 16; DataPemain .nama[15] = "Victor James Osimhen"; DataPemain.role[15] = role[14]; DataPemain.Overall[15] = 87; DataPemain.value[15] = 104500000;
    DataPemain.ID[16] = 17; DataPemain.nama[16] = "Kevin De Bruyne"; DataPemain.role[16] = role[7]; DataPemain.Overall[16] = 91; DataPemain.value[16] = 103000000;
    DataPemain.ID[17] = 18; DataPemain.nama[17] = "Bukayo Saka"; DataPemain.role[17] = role[11]; DataPemain.Overall[17] = 86; DataPemain.value[17] = 99000000;
    DataPemain.ID[18] = 19; DataPemain.nama[18] = "Rafael da Conceição Leão"; DataPemain.role[18] = role[11]; DataPemain.Overall[18] = 86; DataPemain.value[18] = 93000000;
    DataPemain.ID[19] = 20; DataPemain.nama[19] = "Ronald Araujo"; DataPemain.role[19] = role[1]; DataPemain.Overall[19] = 86; DataPemain.value[19] = 93000000;
    DataPemain.ID[20] = 21; DataPemain.nama[20] = "Frenkie de Jong"; DataPemain.role[20] = role[7]; DataPemain.Overall[20] = 87; DataPemain.value[20] = 93000000;
    DataPemain.ID[21] = 22; DataPemain.nama[21] = "Bernardo Silva"; DataPemain.role[21] = role[7]; DataPemain.Overall[21] = 88; DataPemain.value[21] = 91500000;
    DataPemain.ID[22] = 23; DataPemain.nama[22] = "Declan Rice"; DataPemain.role[22] = role[6]; DataPemain.Overall[22] = 87; DataPemain.value[22] = 88500000;
    DataPemain.ID[23] = 24; DataPemain.nama[23] = "Gianluigi Donnarumma"; DataPemain.role[23] = role[0]; DataPemain.Overall[23] = 87; DataPemain.value[23] = 85500000;
    DataPemain.ID[24] = 25; DataPemain.nama[24] = "Mohamed Salah"; DataPemain.role[24] = role[11]; DataPemain.Overall[24] = 89; DataPemain.value[24] = 85500000;
    DataPemain.ID[25] = 26; DataPemain.nama[25] = "David Raya Martin"; DataPemain.role[25] = role[0]; DataPemain.Overall[25] = 82; DataPemain.value[25] = 84000000;
    DataPemain.ID[26] = 27; DataPemain.nama[26] = "Rodrygo Silva de Goes"; DataPemain.role[26] = role[11]; DataPemain.Overall[26] = 85; DataPemain.value[26] = 83000000;
    DataPemain.ID[27] = 28; DataPemain.nama[27] = "Gregor Kobel"; DataPemain.role[27] = role[0]; DataPemain.Overall[27] = 87; DataPemain.value[27] = 81500000;
    DataPemain.ID[28] = 29; DataPemain.nama[28] = "Trent Alexander-Arnold"; DataPemain.role[28] = role[2]; DataPemain.Overall[28] = 86; DataPemain.value[28] = 81000000;
    DataPemain.ID[29] = 30; DataPemain.nama[29] = "Éder Gabriel Militão"; DataPemain.role[29] = role[1]; DataPemain.Overall[29] = 86; DataPemain.value[29] = 80000000;
    DataPemain.ID[30] = 31; DataPemain.nama[30] = "Bruno Miguel Borges Fernandes"; DataPemain.role[30] =role[10]; DataPemain.Overall[30] = 87; DataPemain.value[30] = 80000000;
    DataPemain.ID[31] = 32; DataPemain.nama[31] = "Nicolò Barella"; DataPemain.role[31] = role[7]; DataPemain.Overall[31] = 86; DataPemain.value[31] = 79500000;
    DataPemain.ID[32] = 33; DataPemain.nama[32] = "Mike Peterson Maignan"; DataPemain.role[32] = role[0]; DataPemain.Overall[32] = 87; DataPemain.value[32] = 78000000;
    DataPemain.ID[33] = 34; DataPemain.nama[33] = "Heung Min Son"; DataPemain.role[33] = role[11]; DataPemain.Overall[33] = 87; DataPemain.value[33] = 77000000;
    DataPemain.ID[34] = 35; DataPemain.nama[34] = "Neymar da Silva Santos Júnior"; DataPemain.role[34] = role[11]; DataPemain.Overall[34] = 88; DataPemain.value[34] = 75500000;
    DataPemain.ID[35] = 36; DataPemain.nama[35] = "Masour Ousmane Dembélé"; DataPemain.role[35] = role[11]; DataPemain.Overall[35] = 86; DataPemain.value[35] = 74000000;
    DataPemain.ID[36] = 37; DataPemain.nama[36] = "Antoine Griezmann"; DataPemain.role[36] = role[14]; DataPemain.Overall[36] = 88; DataPemain.value[36] = 74000000;
    DataPemain.ID[37] = 38; DataPemain.nama[37] = "Joško Gvardiol"; DataPemain.role[37] = role[1]; DataPemain.Overall[37] = 84; DataPemain.value[37] = 73500000;
    DataPemain.ID[38] = 39; DataPemain.nama[38] = "Alessandro Bastoni"; DataPemain.role[38] = role[1]; DataPemain.Overall[38] = 85; DataPemain.value[38] = 73500000;
    DataPemain.ID[39] = 40; DataPemain.nama[39] = "Leroy Sané"; DataPemain.role[39] = role[11]; DataPemain.Overall[39] = 86; DataPemain.value[39] = 72500000;
    DataPemain.ID[40] = 41; DataPemain.nama[40] = "Enzo Fernández"; DataPemain.role[40] = role[7]; DataPemain.Overall[40] = 84; DataPemain.value[40] = 72000000;
    DataPemain.ID[41] = 42; DataPemain.nama[41] = "Pedri González"; DataPemain.role[41] = role[7]; DataPemain.Overall[41] = 84; DataPemain.value[41] = 72000000;
    DataPemain.ID[42] = 43; DataPemain.nama[42] = "William Saliba"; DataPemain.role[42] = role[1]; DataPemain.Overall[42] = 85; DataPemain.value[42] = 71000000;
    DataPemain.ID[43] = 44; DataPemain.nama[43] = "Virgil van Dijk"; DataPemain.role[43] = role[1]; DataPemain.Overall[43] = 89; DataPemain.value[43] = 70500000;
    DataPemain.ID[44] = 45; DataPemain.nama[44] = "Josko Gvardiol"; DataPemain.role[44] = role[1]; DataPemain.Overall[44] = 84; DataPemain.value[44] = 70000000;
    DataPemain.ID[45] = 46; DataPemain.nama[45] = "Gianluigi Donnarumma"; DataPemain.role[45] = role[0]; DataPemain.Overall[45] = 84; DataPemain.value[45] = 70000000;
    DataPemain.ID[46] = 47; DataPemain.nama[46] = "Joshua Kimmich"; DataPemain.role[46] = role[6]; DataPemain.Overall[46] = 87; DataPemain.value[46] = 70000000;
    DataPemain.ID[47] = 48; DataPemain.nama[47] = "Ederson Santana de Moraes"; DataPemain.role[47] = role[0]; DataPemain.Overall[47] = 88; DataPemain.value[47] = 70000000;
    DataPemain.ID[48] = 49; DataPemain.nama[48] = "Jules Koundé"; DataPemain.role[48] = role[1]; DataPemain.Overall[48] = 85; DataPemain.value[48] = 69500000;
    DataPemain.ID[49] = 50; DataPemain.nama[49] = "Christopher Nkunku"; DataPemain.role[49] = role[13]; DataPemain.Overall[49] = 85; DataPemain.value[49] = 68500000;
    DataPemain.ID[50] = 51; DataPemain.nama[50] = "Alisson Ramsés Becker"; DataPemain.role[50] = role[0]; DataPemain.Overall[50] = 89; DataPemain.value[50] = 68500000;
    DataPemain.ID[51] = 52; DataPemain.nama[51] = "Casemiro"; DataPemain.role[51] = role[6]; DataPemain.Overall[ 51] = 84; DataPemain.value[51] = 68000000;
    DataPemain.ID[52] = 53; DataPemain.nama[52] = "Rafael Leão"; DataPemain.role[52] = role[11]; DataPemain.Overall[52] = 84; DataPemain.value[52] = 68000000;
    DataPemain.ID[53] = 54; DataPemain.nama[53] = "Paulo Dybala"; DataPemain.role[53] = role[13]; DataPemain.Overall[53] = 86; DataPemain.value[53] = 68000000;
    DataPemain.ID[54] = 55; DataPemain.nama[54] = "Sergej Milinković-Savić"; DataPemain.role[54] = role[7]; DataPemain.Overall[54] = 86; DataPemain.value[54] = 68000000;
    DataPemain.ID[55] = 56; DataPemain.nama[55] = "Matthijs de Ligt"; DataPemain.role[55] = role[1]; DataPemain.Overall[55] = 84; DataPemain.value[55] = 67000000;
    DataPemain.ID[56] = 57; DataPemain.nama[56] = "Declan Rice"; DataPemain.role[56] = role[6]; DataPemain.Overall[56] = 84; DataPemain.value[56] = 67000000;
    DataPemain.ID[57] = 58; DataPemain.nama[57] = "Marcos Aoás Corrêa"; DataPemain.role[57] = role[1]; DataPemain.Overall[57] = 87; DataPemain.value[57] = 66500000;
    DataPemain.ID[58] = 59; DataPemain.nama[58] = "Theo Hernández"; DataPemain.role[58] = role[4]; DataPemain.Overall[58] = 85; DataPemain.value[58] = 66000000;
    DataPemain.ID[59] = 60; DataPemain.nama[59] = "Hakan Çalhanoğlu"; DataPemain.role[59] = role[7]; DataPemain.Overall[59] = 86; DataPemain.value[59] = 66000000;
    DataPemain.ID[60] = 61; DataPemain.nama[60] = "Alejandro Grimaldo García"; DataPemain.role[60] = role[5]; DataPemain.Overall[60] = 86; DataPemain.value[60] = 65500000;
    DataPemain.ID[61] = 62; DataPemain.nama[61] = "Rodrygo Goes"; DataPemain.role[61] = role[11]; DataPemain.Overall[61] = 84; DataPemain.value[61] = 65000000;
    DataPemain.ID[62] = 63; DataPemain.nama[62] = "Christopher Nkunku"; DataPemain.role[62] = role[10]; DataPemain.Overall[62] = 84; DataPemain.value[62] = 65000000;
    DataPemain.ID[63] = 64; DataPemain.nama[63] = "Diogo José Teixeira da Silva"; DataPemain.role[63] = role[13]; DataPemain.Overall[63] = 85; DataPemain.value[63] = 64500000;
    DataPemain.ID[64] = 65; DataPemain.nama[64] = "Dusan Vlahović"; DataPemain.role[64] = role[14]; DataPemain.Overall[64] = 84; DataPemain.value[64] = 64000000;
    DataPemain.ID[65] = 66; DataPemain.nama[65] = "James Maddison"; DataPemain.role[65] = role[10]; DataPemain.Overall[65] = 85; DataPemain.value[65] = 63500000;
    DataPemain.ID[66] = 67; DataPemain.nama[66] = "Thibaut Nicolas Marc Courtois"; DataPemain.role[66] = role[0]; DataPemain.Overall[66] = 90; DataPemain.value[66] = 63000000;
    DataPemain.ID[67] = 68; DataPemain.nama[67] = "Gleison Bremer Silva Nascimento"; DataPemain.role[67] = role[1]; DataPemain.Overall[67] = 85; DataPemain.value[67] = 62500000;
    DataPemain.ID[68] = 69; DataPemain.nama[68] = "Declan Rice"; DataPemain.role[68] = role[6]; DataPemain.Overall[68] = 84; DataPemain.value[68] = 62000000;
    DataPemain.ID[69] = 70; DataPemain.nama[69] = "João Félix"; DataPemain.role[69] = role[10]; DataPemain.Overall[69] = 84; DataPemain.value[69] = 62000000;
    DataPemain.ID[70] = 71; DataPemain.nama[70] = "Lautaro Martínez"; DataPemain.role[70] = role[14]; DataPemain.Overall[70] = 84; DataPemain.value[70] = 62000000;
    DataPemain.ID[71] = 72; DataPemain.nama[71] = "Nicolo Barella"; DataPemain.role[71] = role[7]; DataPemain.Overall[71] = 84; DataPemain.value[71] = 62000000;
    DataPemain.ID[72] = 73; DataPemain.nama[72] = "Bukayo Saka"; DataPemain.role[72] = role[11]; DataPemain.Overall[72] = 84; DataPemain.value[72] = 62000000;
    DataPemain.ID[73] = 74; DataPemain.nama[73] = "Gabriel Teodoro Martinelli Silva"; DataPemain.role[73] = role[12]; DataPemain.Overall[73] = 84; DataPemain.value[73] = 61500000;
    DataPemain.ID[74] = 75; DataPemain.nama[74] = "Jules Koundé"; DataPemain.role[74] = role[1]; DataPemain.Overall[74] = 84; DataPemain.value[74] = 61000000;
    DataPemain.ID[75] = 76; DataPemain.nama[75] = "João Cancelo"; DataPemain.role[75] = role[5]; DataPemain.Overall[75] = 84; DataPemain.value[75] = 61000000;
    DataPemain.ID[76] = 77; DataPemain.nama[76] = "Dušan Vlahović"; DataPemain.role[76] = role[14]; DataPemain.Overall[76] = 84; DataPemain.value[76] = 61000000;
    DataPemain.ID[77] = 78; DataPemain.nama[77] = "Jan Oblak"; DataPemain.role[77] = role[0]; DataPemain.Overall[77] = 88; DataPemain.value[77] = 61000000;
    DataPemain.ID[78] = 79; DataPemain.nama[78] = "Xavi Simons"; DataPemain.role[78] = role[10]; DataPemain.Overall[78] = 82; DataPemain.value[78] = 60500000;
    DataPemain.ID[79] = 80; DataPemain.nama[79] = "Federico Chiesa"; DataPemain.role[79] = role[11]; DataPemain.Overall[79] = 84; DataPemain.value[79] = 60000000;
    DataPemain.ID[80] = 81; DataPemain.nama[80] = "Gabriel dos S. Magalhães"; DataPemain.role[80] = role[1]; DataPemain.Overall[80] = 85; DataPemain.value[80] = 60000000;
    DataPemain.ID[81] = 82; DataPemain.nama[81] = "João Pedro Cavaco Cancelo"; DataPemain.role[81] =role[2]; DataPemain.Overall[81] = 86; DataPemain.value[81] = 59500000;
    DataPemain.ID[82] = 83; DataPemain.nama[82] = "Andrew Robertson"; DataPemain.role[82] = role[4]; DataPemain.Overall[82] = 86; DataPemain.value[82] = 59500000;
    DataPemain.ID[83] = 84; DataPemain.nama[83] = "Aurélien Tchouaméni"; DataPemain.role[83] = role[6]; DataPemain.Overall[83] = 84; DataPemain.value[83] = 58500000;
    DataPemain.ID[84] = 85; DataPemain.nama[84] = "Loïs Openda"; DataPemain.role[84] = role[14]; DataPemain.Overall[84] = 84; DataPemain.value[84] = 58500000;
    DataPemain.ID[85] = 86; DataPemain.nama[85] = "Gabriel Martinelli"; DataPemain.role[85] = role[11]; DataPemain.Overall[85] = 84; DataPemain.value[85] = 58000000;
    DataPemain.ID[86] = 87; DataPemain.nama[86] = "Robert Lewandowski"; DataPemain.role[86] = role[14]; DataPemain.Overall[86] = 90; DataPemain.value[86] = 58000000;
    DataPemain.ID[87] = 88; DataPemain.nama[87] = "Jack Grealish"; DataPemain.role[87] = role[12]; DataPemain.Overall[87] = 85; DataPemain.value[87] = 57500000;
    DataPemain.ID[88] = 89; DataPemain.nama[88] = "Kingsley Coman"; DataPemain.role[88] = role[8]; DataPemain.Overall[88] = 85; DataPemain.value[88] = 57500000;
    DataPemain.ID[89] = 90; DataPemain.nama[89] = "Jonathan David"; DataPemain.role[89] = role[14]; DataPemain.Overall[89] = 84; DataPemain.value[89] = 57000000;
    DataPemain.ID[90] = 91; DataPemain.nama[90] = "Martin Ødegaard"; DataPemain.role[90] = role[10]; DataPemain.Overall[90] = 84; DataPemain.value[90] = 57000000;
    DataPemain.ID[91] = 92; DataPemain.nama[91] = "Jeremie Frimpong"; DataPemain.role[91] = role[3]; DataPemain.Overall[91] = 84; DataPemain.value[91] = 57000000;
    DataPemain.ID[92] = 93; DataPemain.nama[92] = "Kim Min-Jae"; DataPemain.role[92] = role[1]; DataPemain.Overall[92] = 84; DataPemain.value[92] = 56000000;
    DataPemain.ID[93] = 94; DataPemain.nama[93] = "Darwin Núñez"; DataPemain.role[93] = role[14]; DataPemain.Overall[93] = 84; DataPemain.value[93] = 56000000;
    DataPemain.ID[94] = 95; DataPemain.nama[94] = "Sandro Tonali"; DataPemain.role[94] = role[6]; DataPemain.Overall[94] = 84; DataPemain.value[94] = 56000000;
    DataPemain.ID[95] = 96; DataPemain.nama[95] = "Bruno Guimarães Moura"; DataPemain.role[95] = role[7]; DataPemain.Overall[95] = 84; DataPemain.value[95] = 55500000;
    DataPemain.ID[96] = 97; DataPemain.nama[96] = "Antonio Rüdiger"; DataPemain.role[96] = role[1]; DataPemain.Overall[96] = 86; DataPemain.value[96] = 55500000;
    DataPemain.ID[97] = 98; DataPemain.nama[97] = "Éder Militão"; DataPemain.role[97] = role[1]; DataPemain.Overall[97] = 84; DataPemain.value[97] = 55000000;
    DataPemain.ID[98] = 99; DataPemain.nama[98] = "Domenico Berardi"; DataPemain.role[98] = role[11]; DataPemain.Overall[98] = 85; DataPemain.value[98] = 54500000;
    DataPemain.ID[99] = 100; DataPemain.nama[99] = "Marc-André ter Stegen"; DataPemain.role[99] = role[0]; DataPemain.Overall[99] = 89; DataPemain.value[99] = 54500000;
}

void init_players_3(Players &DataPemain){
    DataPemain.ID[100] = 101; DataPemain.nama[100] = "Sandro Tonali"; DataPemain.role[100] = role[6]; DataPemain.Overall[100] = 84; DataPemain.value[100] = 54000000;
    DataPemain.ID[101] = 102; DataPemain.nama[101] = "Dayot Upamecano"; DataPemain.role[101] = role[1]; DataPemain.Overall[101] = 84; DataPemain.value[101] = 54000000;
    DataPemain.ID[102] = 103; DataPemain.nama[102] = "Raphinha Dias Belloli"; DataPemain.role[102] = role[11]; DataPemain.Overall[102] = 84; DataPemain.value[102] = 54000000;
    DataPemain.ID[103] = 104; DataPemain.nama[103] = "Ibrahima Konaté"; DataPemain.role[103] = role[1]; DataPemain.Overall[103] = 84; DataPemain.value[103] = 54000000;
    DataPemain.ID[104] = 105; DataPemain.nama[104] = "Leon Goretzka"; DataPemain.role[104] = role[7]; DataPemain.Overall[104] = 85; DataPemain.value[104] = 54000000;
    DataPemain.ID[105] = 106; DataPemain.nama[105] = "Riyad Mahrez"; DataPemain.role[105] = role[9]; DataPemain.Overall[105] = 86; DataPemain.value[105] = 54000000;
    DataPemain.ID[106] = 107; DataPemain.nama[106] = "İlkay Gündoğan"; DataPemain.role[106] = role[7]; DataPemain.Overall[106] = 86; DataPemain.value[106] = 53500000;
    DataPemain.ID[107] = 108; DataPemain.nama[107] = "Cody Gakpo"; DataPemain.role[107] = role[11]; DataPemain.Overall[107] = 84; DataPemain.value[107] =  52500000;
    DataPemain.ID[108] = 109; DataPemain.nama[108] = "Ousmane Dembélé"; DataPemain.role[108] = role[11]; DataPemain.Overall[108] = 84; DataPemain.value[108] = 52500000;
    DataPemain.ID[109] = 110; DataPemain.nama[109] = "Bruno Guimarães"; DataPemain.role[109] = role[7]; DataPemain.Overall[109] = 84; DataPemain.value[109] = 52000000;
    DataPemain.ID[110] = 111; DataPemain.nama[110] = "Richarlison de Andrade"; DataPemain.role[110] = role[14]; DataPemain.Overall[110] = 84; DataPemain.value[110] = 52000000;
    DataPemain.ID[111] = 112; DataPemain.nama[111] = "Pau Torres"; DataPemain.role[111] = role[1]; DataPemain.Overall[111] = 84; DataPemain.value[111] = 52000000;
    DataPemain.ID[112] = 113; DataPemain.nama[112] = "Frenkie de Jong"; DataPemain.role[112] = role[7]; DataPemain.Overall[112] = 84; DataPemain.value[112] = 51500000;
    DataPemain.ID[113] = 114; DataPemain.nama[113] = "Nico Schlotterbeck"; DataPemain.role[113] = role[1]; DataPemain.Overall[113] = 84; DataPemain.value[113] = 51500000;
    DataPemain.ID[114] = 115; DataPemain.nama[114] = "Benjamin Sesko"; DataPemain.role[114] = role[14]; DataPemain.Overall[114] = 84; DataPemain.value[114] = 50000000;
    DataPemain.ID[115] = 116; DataPemain.nama[115] = "Lisandro Martínez"; DataPemain.role[115] = role[1]; DataPemain.Overall[115] = 84; DataPemain.value[115] = 50000000;
    DataPemain.ID[116] = 117; DataPemain.nama[116] = "Manuel Ugarte"; DataPemain.role[116] = role[6]; DataPemain.Overall[116] = 84; DataPemain.value[116] = 50000000;
    DataPemain.ID[117] = 118; DataPemain.nama[117] = "Raheem Sterling"; DataPemain.role[117] = role[8]; DataPemain.Overall[117] = 84; DataPemain.value[117] = 50000000;
    DataPemain.ID[118] = 119; DataPemain.nama[118] = "John Stones"; DataPemain.role[118] = role[1]; DataPemain.Overall[118] = 85; DataPemain.value[118] = 49500000;
    DataPemain.ID[119] = 120; DataPemain.nama[119] = "Dani Olmo"; DataPemain.role[119] = role[10]; DataPemain.Overall[119] = 84; DataPemain.value[119] = 49000000;
    DataPemain.ID[120] = 121; DataPemain.nama[120] = "Enzo Fernández"; DataPemain.role[120] = role[7]; DataPemain.Overall[120] = 82; DataPemain.value[120] = 48500000;
    DataPemain.ID[121] = 122; DataPemain.nama[121] = "Aymeric Laporte"; DataPemain.role[121] = role[1]; DataPemain.Overall[121] = 84; DataPemain.value[121] = 48000000;
    DataPemain.ID[122] = 123; DataPemain.nama[122] = "Nicholas Williams Arthuer"; DataPemain.role[122] = role[8]; DataPemain.Overall[122] = 82; DataPemain.value[122] = 47500000;
    DataPemain.ID[123] = 124; DataPemain.nama[123] = "Giovanni Di Lorenzo"; DataPemain.role[123] = role[2]; DataPemain.Overall[123] = 85; DataPemain.value[123] = 47500000;
    DataPemain.ID[124] = 125; DataPemain.nama[124] = "Unai Simón Mendibil"; DataPemain.role[124] = role[0]; DataPemain.Overall[124] = 85; DataPemain.value[124] = 47500000;
    DataPemain.ID[125] = 126; DataPemain.nama[125] = "Lucas Paquetá"; DataPemain.role[125] = role[8]; DataPemain.Overall[125] = 84; DataPemain.value[125] = 47000000;
    DataPemain.ID[126] = 127; DataPemain.nama[126] = "Kai Havertz"; DataPemain.role[126] = role[10]; DataPemain.Overall[126] = 82; DataPemain.value[126] = 46000000;
    DataPemain.ID[127] = 128; DataPemain.nama[127] = "Oihan Sancet Tirapu"; DataPemain.role[127] = role[10]; DataPemain.Overall[127] = 82; DataPemain.value[127] = 46000000;
    DataPemain.ID[128] = 129; DataPemain.nama[128] = "Joško Gvardiol"; DataPemain.role[128] = role[4]; DataPemain.Overall[128] = 82; DataPemain.value[128] = 46000000;
    DataPemain.ID[129] = 130; DataPemain.nama[129] = "Mike Maignan"; DataPemain.role[129] = role[0]; DataPemain.Overall[129] = 84; DataPemain.value[129] = 46000000;
    DataPemain.ID[130] = 131; DataPemain.nama[130] = "Viktor Gyökeres"; DataPemain.role[130] = role[14]; DataPemain.Overall[130] = 82; DataPemain.value[130] = 45000000;
    DataPemain.ID[131] = 132; DataPemain.nama[131] = "Roméo Lavia"; DataPemain.role[131] = role[6]; DataPemain.Overall[131] = 84; DataPemain.value[131] = 45000000;
    DataPemain.ID[132] = 133; DataPemain.nama[132] = "Amadou Onana"; DataPemain.role[132] = role[6]; DataPemain.Overall[132] = 84; DataPemain.value[132] = 45000000;
    DataPemain.ID[133] = 134; DataPemain.nama[133] = "Nico Schlotterbeck"; DataPemain.role[133] = role[1]; DataPemain.Overall[133] = 84; DataPemain.value[133] = 45000000;
    DataPemain.ID[134] = 135; DataPemain.nama[134] = "James Maddison"; DataPemain.role[134] = role[10]; DataPemain.Overall[134] = 84; DataPemain.value[134] = 45000000;
    DataPemain.ID[135] = 136; DataPemain.nama[135] = "Kalvin Phillips"; DataPemain.role[135] = role[6]; DataPemain.Overall[135] = 84; DataPemain.value[135] = 45000000;
    DataPemain.ID[136] = 137; DataPemain.nama[136] = "Marcos Llorente"; DataPemain.role[136] = role[6]; DataPemain.Overall[136] = 84; DataPemain.value[136] = 45000000;
    DataPemain.ID[137] = 138; DataPemain.nama[137] = "Emiliano Martínez"; DataPemain.role[137] = role[0]; DataPemain.Overall[137] = 86; DataPemain.value[137] = 45000000;
    DataPemain.ID[138] = 139; DataPemain.nama[138] = "Aleix García Serrano"; DataPemain.role[138] = role[7]; DataPemain.Overall[138] = 83; DataPemain.value[138] = 44500000;
    DataPemain.ID[139] = 140; DataPemain.nama[139] = "Serge Gnabry"; DataPemain.role[139] = role[11]; DataPemain.Overall[139] = 84; DataPemain.value[139] = 44500000;
    DataPemain.ID[140] = 141; DataPemain.nama[140] = "Sadio Mané"; DataPemain.role[140] = role[8]; DataPemain.Overall[140] = 85; DataPemain.value[140] = 44500000;
    DataPemain.ID[141] = 142; DataPemain.nama[141] = "Cody Gakpo"; DataPemain.role[141] = role[13]; DataPemain.Overall[141] = 82; DataPemain.value[141] = 44000000;
    DataPemain.ID[142] = 143; DataPemain.nama[142] = "Orkun Kökçü"; DataPemain.role[142] = role[7]; DataPemain.Overall[142] = 82; DataPemain.value[142] = 44000000;
    DataPemain.ID[143] = 144; DataPemain.nama[143] = "Sven Botman"; DataPemain.role[143] = role[1]; DataPemain.Overall[143] = 84; DataPemain.value[143] = 44000000;
    DataPemain.ID[144] = 145; DataPemain.nama[144] = "Brahim Díaz"; DataPemain.role[144] = role[10]; DataPemain.Overall[144] = 82; DataPemain.value[144] = 43500000;
    DataPemain.ID[145] = 146; DataPemain.nama[145] = "Alphonso Davies"; DataPemain.role[145] = role[4]; DataPemain.Overall[145] = 82; DataPemain.value[145] = 43500000;
    DataPemain.ID[ 146] = 147; DataPemain.nama[146] = "Dejan Kulusevski"; DataPemain.role[146] = role[11]; DataPemain.Overall[146] = 82; DataPemain.value[146] = 43500000;
    DataPemain.ID[147] = 148; DataPemain.nama[147] = "Nuno Alexandre Tavares Mendes"; DataPemain.role[147] = role[4]; DataPemain.Overall[147] = 82; DataPemain.value[147] = 43500000;
    DataPemain.ID[148] = 149; DataPemain.nama[148] = "Randal Kolo Muani"; DataPemain.role[148] = role[14]; DataPemain.Overall[148] = 82; DataPemain.value[148] = 42000000;
    DataPemain.ID[149] = 150; DataPemain.nama[149] = "Federico Dimarco"; DataPemain.role[149] = role[5]; DataPemain.Overall[149] = 83; DataPemain.value[149] = 42000000;
    DataPemain.ID[150] = 151; DataPemain.nama[150] = "Benjamin Pavard"; DataPemain.role[150] = role[1]; DataPemain.Overall[150] = 84; DataPemain.value[150] = 42000000;
    DataPemain.ID[151] = 152; DataPemain.nama[151] = "Christian Pulisic"; DataPemain.role[151] = role[11]; DataPemain.Overall[151] = 82; DataPemain.value[151] = 41500000;
    DataPemain.ID[152] = 153; DataPemain.nama[152] = "Exequiel Palacios"; DataPemain.role[152] = role[7]; DataPemain.Overall[152] = 82; DataPemain.value[152] = 41500000;
    DataPemain.ID[153] = 154; DataPemain.nama[153] = "Lorenzo Pellegrini"; DataPemain.role[153] = role[8]; DataPemain.Overall[153] = 84; DataPemain.value[153] = 41000000;
    DataPemain.ID[154] = 155; DataPemain.nama[154] = "Lionel Andres Messi Cuccitini"; DataPemain.role[154] = role[13]; DataPemain.Overall[154] = 90; DataPemain.value[154] = 41000000;
    DataPemain.ID[155] = 156; DataPemain.nama[155] = "Pedro António Pereira Gonçalves"; DataPemain.role[155] = role[12]; DataPemain.Overall[155] = 82; DataPemain.value[155] = 40500000;
    DataPemain.ID[156] = 157; DataPemain.nama[156] = "Raphaël Varane"; DataPemain.role[156] = role[1]; DataPemain.Overall[156] = 84; DataPemain.value[156] = 40000000;
    DataPemain.ID[157] = 158; DataPemain.nama[157] = "Álvaro Morata"; DataPemain.role[157] = role[14]; DataPemain.Overall[157] = 84; DataPemain.value[157] = 40000000;
    DataPemain.ID[158] = 159; DataPemain.nama[158] = "Rodrigo Bentancur"; DataPemain.role[158] = role[7]; DataPemain.Overall[158] = 82; DataPemain.value[158] = 39500000;
    DataPemain.ID[159] = 160; DataPemain.nama[159] = "Ollie Watkins"; DataPemain.role[159] = role[14]; DataPemain.Overall[159] = 83; DataPemain.value[159] = 39500000;
    DataPemain.ID[160] = 161; DataPemain.nama[160] = "Karim Benzema"; DataPemain.role[160] = role[14]; DataPemain.Overall[160] = 88; DataPemain.value[160] = 39000000;
    DataPemain.ID[161] = 162; DataPemain.nama[161] = "Manuel Locatelli"; DataPemain.role[161] = role[6]; DataPemain.Overall[161] = 82; DataPemain.value[161] = 38500000;
    DataPemain.ID[162] = 163; DataPemain.nama[162] = "Pedro Antonio Porro Sauceda"; DataPemain.role[162] = role[2]; DataPemain.Overall[162] = 82; DataPemain.value[162] = 38500000;
    DataPemain.ID[163] = 164; DataPemain.nama[163] = "Serge Gnabry"; DataPemain.role[163] = role[9]; DataPemain.Overall[163] = 83; DataPemain.value[163] = 38500000;
    DataPemain.ID[164] = 165; DataPemain.nama[164] = "Andreas Christensen"; DataPemain.role[164] = role[1]; DataPemain.Overall[164] = 83; DataPemain.value[164] = 38500000;
    DataPemain.ID[165] = 166; DataPemain.nama[165] = "Lorenzo Pellegrini"; DataPemain.role[165] = role[10]; DataPemain.Overall[165] = 83; DataPemain.value[165] = 38500000;
    DataPemain.ID[166] = 167; DataPemain.nama[166] = "André Onana"; DataPemain.role[166] = role[0]; DataPemain.Overall[166] = 38450000;
    DataPemain.ID[167] = 168; DataPemain.nama[167] = "Douglas Luiz Soares de Paulo"; DataPemain.role[167] = role[7]; DataPemain.Overall[167] = 82; DataPemain.value[167] = 38000000;
    DataPemain.ID[168] = 169; DataPemain.nama[168] = "Teun Koopmeiners"; DataPemain.role[168] = role[7]; DataPemain.Overall[168] = 82; DataPemain.value[168] = 38000000;
    DataPemain.ID[169] = 170; DataPemain.nama[169] = "Konrad Laimer"; DataPemain.role[169] = role[6]; DataPemain.Overall[169] = 83; DataPemain.value[169] = 38000000;
    DataPemain.ID[170] = 171; DataPemain.nama[170] = "Gonçalo Inácio"; DataPemain.role[170] = role[1]; DataPemain.Overall[170] = 84; DataPemain.value[170] = 38000000;
    DataPemain.ID[171] = 172; DataPemain.nama[171] = "Boubacar Kamara"; DataPemain.role[171] = role[6]; DataPemain.Overall[171] = 82; DataPemain.value[171] = 37500000;
    DataPemain.ID[172] = 173; DataPemain.nama[172] = "Kieran Trippier"; DataPemain.role[172] = role[2]; DataPemain.Overall[172] = 85; DataPemain.value[172] = 37500000;
    DataPemain.ID[173] = 174; DataPemain.nama[173] = "Carlos Henrique Venancio Casimiro"; DataPemain.role[173] = role[6]; DataPemain.Overall[173] = 85; DataPemain.value[173] = 37500000;
    DataPemain.ID[174] = 175; DataPemain.nama[174] = "Nahuel Molina"; DataPemain.role[174] = role[3]; DataPemain.Overall[174] = 82; DataPemain.value[174] = 37000000;
    DataPemain.ID[175] = 176; DataPemain.nama[175] = "David Alaba"; DataPemain.role[175] = role[1]; DataPemain.Overall[175] = 85; DataPemain.value[175] = 37000000;
    DataPemain.ID[176] = 177; DataPemain.nama[176] = "Leon Bailey"; DataPemain.role[176] = role[9]; DataPemain.Overall[176] = 82; DataPemain.value[176] = 36500000;
    DataPemain.ID[177] = 178; DataPemain.nama[177] = "Marcus Rashford"; DataPemain.role[177] = role[8]; DataPemain.Overall[177] = 82; DataPemain.value[177] = 36500000;
    DataPemain.ID[178] = 179; DataPemain.nama[178] = "Lucas Tolentino Coelho de Lima"; DataPemain.role[178] = role[8]; DataPemain.Overall[178] = 82; DataPemain.value[178] = 36500000;
    DataPemain.ID[179] = 180; DataPemain.nama[179] = "Youssef En-Nesyri"; DataPemain.role[179] = role[14]; DataPemain.Overall[179] = 82; DataPemain.value[179] = 36500000;
    DataPemain.ID[180] = 181; DataPemain.nama[180] = "Memphis Depay"; DataPemain.role[180] = role[13]; DataPemain.Overall[180] = 83; DataPemain.value[180] = 36500000;
    DataPemain.ID[181] = 182; DataPemain.nama[181] = "Niklas Süle"; DataPemain.role[181] = role[1]; DataPemain.Overall[181] = 83; DataPemain.value[181] = 36500000;
    DataPemain.ID[182] = 183; DataPemain.nama[182] = "Stanislav Lobotka"; DataPemain.role[182] = role[7]; DataPemain.Overall[182] = 83; DataPemain.value[182] = 36500000;
    DataPemain.ID[183] = 184; DataPemain.nama[183] = "Benjamin Pavard"; DataPemain.role[183] = role[1]; DataPemain.Overall[183] = 83; DataPemain.value[183] = 36500000;
    DataPemain.ID[184] = 185; DataPemain.nama[184] = "Jorginho Frello"; DataPemain.role[184] = role[7]; DataPemain.Overall[184] = 84; DataPemain.value[184] = 36500000;
    DataPemain.ID[185] = 186; DataPemain.nama[185] = "N'Golo Kanté"; DataPemain.role[185] = role[6]; DataPemain.Overall[185] = 85; DataPemain.value[185] = 36000000;
    DataPemain.ID[186] = 187; DataPemain.nama[186] = "Joelinton Apolinário de Lira"; DataPemain.role[186] = role[7]; DataPemain.Overall[186] = 82; DataPemain.value[186] = 35500000;
    DataPemain.ID[187] = 188; DataPemain.nama[187] = "Robin Le Normand"; DataPemain.role[187] = role[1]; DataPemain.Overall[187] = 82; DataPemain.value[187] = 35500000;
    DataPemain.ID[188] = 189; DataPemain.nama[188] = "Rafael A. Ferreira Silva"; DataPemain.role[188] = role[13]; DataPemain.Overall[188] = 83; DataPemain.value[188] = 35500000;
    DataPemain.ID[189] = 190; DataPemain.nama[189] = "Benjamin White"; DataPemain.role[189] = role[2]; DataPemain.Overall[189] = 82; DataPemain.value[189] = 35000000;
    DataPemain.ID[190] = 191; DataPemain.nama[190] = "Filip Kostić"; DataPemain.role[190] = role[8]; DataPemain.Overall[190] = 83; DataPemain.value[190] = 35000000;
    DataPemain.ID[191] = 192; DataPemain.nama[191] = "Jonas Hofmann"; DataPemain.role[191] = role[10]; DataPemain.Overall[191] = 83; DataPemain.value[191] = 35000000;
    DataPemain.ID[192] = 193; DataPemain.nama[192] = "José María Giménez"; DataPemain.role[192] = role[1]; DataPemain.Overall[192] = 83; DataPemain.value[192] = 34500000;
    DataPemain.ID[193] = 194; DataPemain.nama[193] = "Gabriel Fernando de Jesus"; DataPemain.role[193] = role[14]; DataPemain.Overall[193] = 82; DataPemain.value[193] = 34000000;
    DataPemain.ID[194] = 195; DataPemain.nama[194] = "Franck Yannick Kessié"; DataPemain.role[194] = role[6]; DataPemain.Overall[194] = 82; DataPemain.value[194] = 34000000;
    DataPemain.ID[195] = 196; DataPemain.nama[195] = "Marc-André ter Stegen"; DataPemain.role[195] = role[0]; DataPemain.Overall[195] = 84; DataPemain.value[195] = 34000000;
    DataPemain.ID[196] = 197; DataPemain.nama[196] = "Malcom Filipe Silva de Oliveira"; DataPemain.role[196] = role[10]; DataPemain.Overall[196] = 82; DataPemain.value[196] = 33500000;
    DataPemain.ID[197] = 198; DataPemain.nama[197] = "Pau Francisco Torres"; DataPemain.role[197] = role[1]; DataPemain.Overall[197] = 82; DataPemain.value[197] = 33500000;
    DataPemain.ID[198] = 199; DataPemain.nama[198] = "Giorgi Mamardashvili"; DataPemain.role[198] = role[0]; DataPemain.Overall[198] = 82; DataPemain.value[198] = 33500000;
    DataPemain.ID[199] = 200; DataPemain.nama[199] = "Aymeric Laporte"; DataPemain.role[199] = role[1]; DataPemain.Overall[199] = 83; DataPemain.value[199] = 33500000;
    DataPemain.ID[200] = 201; DataPemain.nama[200] = "Serhou Guirassy"; DataPemain.role[200] = role[14]; DataPemain.Overall[200] = 82; DataPemain.value[200] = 33000000;
    DataPemain.ID[201] = 202; DataPemain.nama[201] = "Patrik Schick"; DataPemain.role[201] = role[14]; DataPemain.Overall[201] = 82; DataPemain.value[201] = 33000000;
    DataPemain.ID[202] = 203; DataPemain.nama[202] = "Marco Asensio Willemsen"; DataPemain.role[ 202] = role[11]; DataPemain.Overall[202] = 82; DataPemain.value[202] = 32500000;
    DataPemain.ID[203] = 204; DataPemain.nama[203] = "Micky van de Ven"; DataPemain.role[203] = role[1]; DataPemain.Overall[203] = 84; DataPemain.value[203] = 32000000;
    DataPemain.ID[204] = 205; DataPemain.nama[204] = "Guido Rodríguez"; DataPemain.role[204] = role[6]; DataPemain.Overall[204] = 83; DataPemain.value[204] = 32000000;
    DataPemain.ID[205] = 206; DataPemain.nama[205] = "Marcos Acuña"; DataPemain.role[205] = role[4]; DataPemain.Overall[205] = 84; DataPemain.value[205] = 32000000;
    DataPemain.ID[206] = 207; DataPemain.nama[206] = "Alessio Romagnoli"; DataPemain.role[206] = role[1]; DataPemain.Overall[206] = 83; DataPemain.value[206] = 31500000;
    DataPemain.ID[207] = 208; DataPemain.nama[207] = "Ángel Correa"; DataPemain.role[207] = role[14]; DataPemain.Overall[207] = 82; DataPemain.value[207] = 31000000;
    DataPemain.ID[208] = 209; DataPemain.nama[208] = "Fábio Henrique Tavares"; DataPemain.role[208] = role[6]; DataPemain.Overall[208] = 83; DataPemain.value[208] = 31000000;
    DataPemain.ID[209] = 210; DataPemain.nama[209] = "André Onana"; DataPemain.role[209] = role[0]; DataPemain.Overall[209] = 83; DataPemain.value[209] = 31000000;
    DataPemain.ID[210] = 211; DataPemain.nama[210] = "Otávio Edmilson da Silva Monteiro"; DataPemain.role[210] = role[10]; DataPemain.Overall[210] = 82; DataPemain.value[210] = 30500000;
    DataPemain.ID[211] = 212; DataPemain.nama[211] = "Ricardo Jorge da Luz Horta"; DataPemain.role[211] = role[10]; DataPemain.Overall[211] = 82; DataPemain.value[211] = 30500000;
    DataPemain.ID[212] = 213; DataPemain.nama[212] = "Mattia Zaccagni"; DataPemain.role[212] = role[12]; DataPemain.Overall[212] = 82; DataPemain.value[212] = 30500000;
    DataPemain.ID[213] = 214; DataPemain.nama[213] = "Isaac Palazón Camacho"; DataPemain.role[213] = role[9]; DataPemain.Overall[213] = 82; DataPemain.value[213] = 30500000;
    DataPemain.ID[214] = 215; DataPemain.nama[214] = "Matthias Ginter"; DataPemain.role[214] = role[1]; DataPemain.Overall[214] = 83; DataPemain.value[214] = 30500000;
    DataPemain.ID[215] = 216; DataPemain.nama[215] = "Gerard Moreno Balagueró"; DataPemain.role[215] = role[14]; DataPemain.Overall[215] = 83; DataPemain.value[215] = 30500000;
    DataPemain.ID[216] = 217; DataPemain.nama[216] = "Marcelo Brozović"; DataPemain.role[216] = role[6]; DataPemain.Overall[216] = 83; DataPemain.value[216] = 30500000;
    DataPemain.ID[217] = 218; DataPemain.nama[217] = "Anderson Souza Conceição"; DataPemain.role[217] = role[9]; DataPemain.Overall[217] = 82; DataPemain.value[217] = 30000000;
    DataPemain.ID[218] = 219; DataPemain.nama[218] = "Iñaki Williams Arthuer"; DataPemain.role[218] = role[9]; DataPemain.Overall[218] = 82; DataPemain.value[218] = 30000000;
    DataPemain.ID[219] = 220; DataPemain.nama[219] = "Nabil Fekir"; DataPemain.role[219] = role[10]; DataPemain.Overall[219] = 82; DataPemain.value[219] = 30000000;
    DataPemain.ID[220] = 221; DataPemain.nama[220] = "Raphaël Varane"; DataPemain.role[220] = role[1]; DataPemain.Overall[220] = 83; DataPemain.value[220] = 30000000;
    DataPemain.ID[221]= 222; DataPemain.nama[221] = "Willi Orban"; DataPemain.role[221] = role[1]; DataPemain.Overall[221] = 83; DataPemain.value[221] = 30000000;
    DataPemain.ID[222] = 223; DataPemain.nama[222] = "Jeremie Frimpong"; DataPemain.role[222] = role[2]; DataPemain.Overall[222] = 84; DataPemain.value[222] = 30000000;
    DataPemain.ID[223] = 224; DataPemain.nama[223] = "Ángel Di María"; DataPemain.role[223] = role[8]; DataPemain.Overall[223] = 30000000;
    DataPemain.ID[224] = 225; DataPemain.nama[224] = "Piotr Zieliński"; DataPemain.role[224] = role[7]; DataPemain.Overall[224] = 82; DataPemain.value[224] = 29500000;
    DataPemain.ID[225] = 226; DataPemain.nama[225] = "Nathan Aké"; DataPemain.role[225] = role[1]; DataPemain.Overall[225] = 82; DataPemain.value[225] = 29000000;
    DataPemain.ID[226] = 227; DataPemain.nama[226] = "Frederico de Paula Santos"; DataPemain.role[226] = role[7]; DataPemain.Overall[226] = 82; DataPemain.value[226] = 29000000;
    DataPemain.ID[227] = 228; DataPemain.nama[227] = "Mario Hermoso Canseco"; DataPemain.role[227] = role[1]; DataPemain.Overall[227] = 82; DataPemain.value[227] = 29000000;
    DataPemain.ID[228] = 229; DataPemain.nama[228] = "Aaron Ramsdale"; DataPemain.role[228] = role[0]; DataPemain.Overall[228] = 82; DataPemain.value[228] = 29000000;
    DataPemain.ID[229] = 230; DataPemain.nama[229] = "Lucas Torreira"; DataPemain.role[229] = role[6]; DataPemain.Overall[229] = 82; DataPemain.value[229] = 28500000;
    DataPemain.ID[230] = 231; DataPemain.nama[230] = "Alex Meret"; DataPemain.role[230] = role[0]; DataPemain.Overall[230] = 82; DataPemain.value[230] = 28500000;
    DataPemain.ID[231] = 232; DataPemain.nama[231] = "Leandro Paredes"; DataPemain.role[231] = role[6]; DataPemain.Overall[231] = 84; DataPemain.value[231] = 28000000;
    DataPemain.ID[232] = 233; DataPemain.nama[232] = "José Luís Gayà Peña"; DataPemain.role[232] = role[4]; DataPemain.Overall[232] = 82; DataPemain.value[232] = 27500000;
    DataPemain.ID[233] = 234; DataPemain.nama[233] = "Ferland Mendy"; DataPemain.role[233] = role[4]; DataPemain.Overall[233] = 82; DataPemain.value[233] = 27500000;
    DataPemain.ID[234] = 235; DataPemain.nama[234] = "Raphaël Guerreiro"; DataPemain.role[234] = role[4]; DataPemain.Overall[234] = 82; DataPemain.value[234] = 27000000;
    DataPemain.ID[235] = 236; DataPemain.nama[235] = "Robert Andrich"; DataPemain.role[235] = role[6]; DataPemain.Overall[235] = 82; DataPemain.value[235] = 27000000;
    DataPemain.ID[236] = 237; DataPemain.nama[236] = "Milan Škriniar"; DataPemain.role[236] = role[1]; DataPemain.Overall[236] = 82; DataPemain.value[236] = 26500000;
    DataPemain.ID[237] = 238; DataPemain.nama[237] = "Marcos Acuña"; DataPemain.role[237] = role[4]; DataPemain.Overall[237] = 83; DataPemain.value[237] = 26500000;
    DataPemain.ID[238] = 239; DataPemain.nama[238] = "Yassine Bounou"; DataPemain.role[238] = role[0]; DataPemain.Overall[238] = 85; DataPemain.value[238] = 26500000;
    DataPemain.ID[239] = 240; DataPemain.nama[239] = "Emre Can"; DataPemain.role[239] = role[6]; DataPemain.Overall[239] = 82; DataPemain.value[239] = 26000000;
    DataPemain.ID[240] = 241; DataPemain.nama[240 ] = "Lucas Luciano Mantela Patrício"; DataPemain.role[240] = role[0]; DataPemain.Overall[240] = 82; DataPemain.value[240] = 26000000;
    DataPemain.ID[241] = 242; DataPemain.nama[241] = "Dominik Livaković"; DataPemain.role[241] = role[0]; DataPemain.Overall[241] = 82; DataPemain.value[241] = 26000000;
    DataPemain.ID[242] = 243; DataPemain.nama[242] = "David García Zubiria"; DataPemain.role[242] = role[1]; DataPemain.Overall[242] = 82; DataPemain.value[242] = 25500000;
    DataPemain.ID[243] = 244; DataPemain.nama[243] = "Luiz Frello Filho Jorge"; DataPemain.role[243] = role[6]; DataPemain.Overall[243] = 83; DataPemain.value[243] = 25500000;
    DataPemain.ID[244] = 245; DataPemain.nama[244] = "Christian Eriksen"; DataPemain.role[244] = role[10]; DataPemain.Overall[244] = 84; DataPemain.value[244] = 25000000;
    DataPemain.ID[245] = 246; DataPemain.nama[245] = "David De Gea"; DataPemain.role[245] = role[0]; DataPemain.Overall[245] = 84; DataPemain.value[245] = 23000000;
    DataPemain.ID[246] = 247; DataPemain.nama[246] = "C. Ronaldo dos Santos Aveiro"; DataPemain.role[246] = role[14]; DataPemain.Overall[246] = 86; DataPemain.value[246] = 23000000;
    DataPemain.ID[247] = 248; DataPemain.nama[247] = "Luka Modrić"; DataPemain.role[247] = role[7]; DataPemain.Overall[247] = 86; DataPemain.value[247] = 21500000;
    DataPemain.ID[248] = 249; DataPemain.nama[248] = "Fabian Schär"; DataPemain.role[248] = role[1]; DataPemain.Overall[248] = 82; DataPemain.value[248] = 21000000;
    DataPemain.ID[249] = 250; DataPemain.nama[249] = "Ivan Provedel"; DataPemain.role[249] = role[0]; DataPemain.Overall[249] = 82; DataPemain.value[249] = 21000000;
}
