#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <conio.h>
#include <algorithm>
using namespace std;

void linear(const vector<vector<string>>& data, const string& target, int angka);
void binary(const vector<vector<string>>& data, const string& target, int angka);
string toLowerTrim(string s);



int main(){
    ifstream file("Struktur_Data_Dataset_Kelas_A_B_C - Sheet1.csv");
    if (!file.is_open()) {
        cout << "Gagal membuka file! Pastikan file ada di direktori yang sama." << endl;
        return 1;
    }
    
    string line;
    vector<vector<string>> data;

    while(getline(file, line)){
        stringstream ss(line);
        string value;
        vector<string> row;

        while(getline(ss, value, ',')){
            row.push_back(value);
        }
        
        if(!row.empty()){
            data.push_back(row);
        }
    }


    int menu;
    do{
        int pilihsearch;
        system("cls");
        cout << "PILIH MENU" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Exit" << endl;
        cout << "pilih menu: ";
        cin >> menu;
        if(menu == 1){
            do{
                system("cls");
                cout << "1. Search Berdasarkan Judul Paper" << endl;
                cout << "2. Search Berdasarkan Tahun Terbit" << endl;
                cout << "3. Search Berdasarkan Nama Penulis " << endl;
                cout << "4. Exit" << endl;
                cout << "pilih menu: ";
                cin >> pilihsearch;
                cin.ignore();
                if(pilihsearch == 1){
                    string nama;
                    cout << "Masukan Judul: ";
                    getline(cin, nama);
                    linear(data, nama, 5);
                }else if(pilihsearch == 2){
                    string nama;
                    cout << "Masukan Tahun: ";
                    getline(cin, nama);
                    linear(data, nama, 6);
                }else if(pilihsearch == 3){
                    string nama;
                    cout << "Masukan Penulis: ";
                    getline(cin, nama);
                    linear(data, nama, 7);
                }else if(pilihsearch == 4){
                    return 0;
                }else{
                    cout << "menu tidak ada";
                }
            }while(pilihsearch != 4);
        }else if(menu == 2){
            do{
                system("cls");
                cout << "1. Search Berdasarkan Judul Paper" << endl;
                cout << "2. Search Berdasarkan Tahun Terbit" << endl;
                cout << "3. Search Berdasarkan Nama Penulis " << endl;
                cout << "4. Exit" << endl;
                cout << "pilih menu: ";
                cin >> pilihsearch;
                cin.ignore();
                if(pilihsearch == 1){
                    string nama;
                    cout << "Masukan Judul: ";
                    getline(cin, nama);
                    binary(data, nama, 5);
                }else if(pilihsearch == 2){
                    string nama;
                    cout << "Masukan Tahun: ";
                    getline(cin, nama);
                    binary(data, nama, 6);
                }else if(pilihsearch == 3){
                    string nama;
                    cout << "Masukan Penulis: ";
                    getline(cin, nama);
                    binary(data, nama, 7);
                }else if(pilihsearch == 4){
                    return 0;
                }else{
                    cout << "menu tidak ada";
                }
            }while(pilihsearch != 4);
        }
    }while(menu != 3);
}

string toLowerTrim(string s) {
    // Trim leading spaces
    s.erase(0, s.find_first_not_of(" \t\r\n"));
    // Trim trailing spaces
    s.erase(s.find_last_not_of(" \t\r\n") + 1);
    // Convert to lowercase
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}


void linear(const vector<vector<string>>& data, const string& target, int angka){
    bool ketemu = false;
    int count = 1;
    string lowered = toLowerTrim(target);

    for(int a = 1; a <data.size(); ++a){
        if(angka < data[a].size() && toLowerTrim(data[a][angka]) == lowered){
            cout << count << ". Judul: " << data[a][5] << endl;
            cout << "   Tahun Terbit: " << data[a][6] << endl;
            cout << "   Penulis: " << data[a][7] << endl;
            cout << endl;
            count++;
            ketemu = true;
        }
    }
    if(!ketemu){
        cout << "data tidak ditemukan" << endl;
    }
    cout << "tekan untuk kembali";
    getch();
}

void binary(const vector<vector<string>>& data, const string& target, int angka) {
    vector<vector<string>> sortedData;

    for (int i = 1; i < data.size(); ++i) {
        if (angka < data[i].size()) {
            sortedData.push_back(data[i]);
        }
    }
    sort(sortedData.begin(), sortedData.end(), [angka](const vector<string>& a, const vector<string>& b) {
        return toLowerTrim(a[angka]) < toLowerTrim(b[angka]);
    });

    string lowered = toLowerTrim(target);
    int kiri = 0, kanan = sortedData.size() - 1;
    bool ketemu = false;
    int count = 1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        string nilai = toLowerTrim(sortedData[tengah][angka]);

        if (nilai == lowered) {
            int i = tengah;
            while (i >= 0 && toLowerTrim(sortedData[i][angka]) == lowered) i--;
            i++;

            while (i < sortedData.size() && toLowerTrim(sortedData[i][angka]) == lowered) {
                cout << count << ". Judul: " << sortedData[i][5] << endl;
                cout << "   Tahun Terbit: " << sortedData[i][6] << endl;
                cout << "   Penulis: " << sortedData[i][7] << endl;
                cout << endl;
                count++;
                i++;
            }

            ketemu = true;
            break;
        } else if (nilai < lowered) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    if (!ketemu) {
        cout << "data tidak ditemukan" << endl;
    }

    cout << "tekan untuk kembali";
    getch();
}

