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

int czy_rekur() {
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      if (t[k][i] != t[k][i + 10] || t[k][i] != t[k + 10][i] || t[k][i] != t[k + 10][i + 10]) {
        return false;
      }
    }
  }
}

void zadanie() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cout << t[i][j];
    }
    cout << "\n";
  }
}

int main() {
  int licznik = 0;
  bool rekurencja = true;
  for (int i = 0; i < rozmiar; i++) {
    wczytaj();
    if (czy_rekur() && rekurencja) {
      zadanie();
      rekurencja = false;
    }
    if (czy_rekur()) 
      licznik++;
  }
  cout << "Liczba obrazkow: " << licznik << "\n";
  return 0;
}
