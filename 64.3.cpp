#include <iostream>
#include <fstream>
using namespace std;

int rozmiar = 200;
ifstream plik("dane_obrazki.txt");
char t[21][21];

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

int licz_poziomo() {
  int suma = 0;
  int licznik = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 21; j++) {
      if (t[i][j] == '1' && j != 20)
        suma++;
      if (j == 20) {
        if (suma % 2 == 0 && t[i][j] == '1')
          licznik++;
        if (suma % 2 == 1 && t[i][j] == '0')
          licznik++;
      }
    }
    suma = 0;
  }
  return licznik;
}

int licz_pionowo() {
  int suma = 0;
  int licznik = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 21; j++) {
      if (t[j][i] == '1' && j != 20)
        suma++;
      if (j == 20) {
        if (suma % 2 == 0 && t[j][i] == '1')
          licznik++;
        if (suma % 2 == 1 && t[j][i] == '0')
          licznik++;
      }
    }
    suma = 0;
  }
  return licznik;
}

int licz_zle() {
  return licz_pionowo() + licz_poziomo();
}

bool czy_poprawne() {
  if (licz_zle() == 0)
    return true;
}

bool czy_naprawialne() {
  if (licz_pionowo() < 2 && licz_poziomo() < 2)
    return true;
}

int main() {
  int poprawne = 0;
  int naprawialne = 0;
  int nienaprawialne = 0;
  int max_zla_parzystosc = 0;
  int zla_parzystosc = 0;

  for (int i = 0; i < rozmiar; i++) {
    wczytaj();
    if (czy_poprawne())
      poprawne++;
    else if (czy_naprawialne())
      naprawialne++;
    else
      nienaprawialne++;
    zla_parzystosc = licz_zle();
    if (zla_parzystosc > max_zla_parzystosc)
      max_zla_parzystosc = zla_parzystosc;
  }
  cout << "Poprawne: " << poprawne << "\n";
  cout << "Nienaprawialne: " << nienaprawialne << "\n";
  cout << "Naprawialne: " << naprawialne << "\n";
  cout << "Max. zla parzystosc: " << max_zla_parzystosc << "\n";
  return 0;
}
