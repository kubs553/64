#include <iostream>
#include <fstream>
using namespace std;

int rozmiar = 200;
ifstream plik ("dane_obrazki.txt");
char t[20][20];

void wczytaj() {
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      if (i == 20 && j == 20) 
        return; 
        plik >> t[i][j];
    }
  }
}

void wyswietl() {
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      cout << t[i][j] << " " << "\n";
    }
  }
}

int czy_rewers() {
  int czarny = 0;
  int bialy = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (t[i][j] == '0') 
        bialy++;
      if (t[i][j] == '1') 
        czarny++;
    }
  }
  return czarny > bialy;
}

int licz_czarne() {
  int licznik = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (t[i][j] == '1') 
        licznik++;
    }
  }
  return licznik;
}

int main() {
  int licznik_rewersow = 0;
  int max_czarne = 0;
  for (int n = 0; n < rozmiar; n++) {
    wczytaj();
    if (czy_rewers()) 
        licznik_rewersow++;
    if (licz_czarne() > max_czarne) 
        max_czarne = licz_czarne();
  }
  cout << "Liczba rewersow: " << licznik_rewersow << "\n";
  cout << "Najwieksza liczba czarnych piskeli: " << max_czarne << "\n";
  return 0;
}
