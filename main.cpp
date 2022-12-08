#include <fstream>
#include <iostream>
#include <list>
#define TAM 100

using namespace std;

int main() {

  string binario[TAM];
  string salvar;
  string NOP = "00000000000000000000000000000000";
  fstream arquivo01, arquivo02;
  string first_six;
  string rd, rs, rt;
  int i = 0, qtdPalavras = 0;

  for (int i = 0; i < TAM; i++) {
    binario[i] = "00000000000000000000000000000000";
  }

  arquivo01.open("Entrada.txt");
  arquivo02.open("Saida.txt");

  cout << "Antes\n";
  while (arquivo01 >> salvar) {
    binario[qtdPalavras] = salvar;
    cout << binario[qtdPalavras] << endl;

    qtdPalavras++;
  }

  cout << "Depois\n";
  for (int i = 0; i <= qtdPalavras - 1; i++) {
    first_six = binario[i].substr(0, 6);

    if (first_six == "000000") {
      rd = binario[i].substr(16, 5);
    } else if (first_six == "000010" || first_six == "000011") {
      continue;
    } else {
      rd = binario[i].substr(11, 5);
    }

    for (int j = 1; j < 3; j++) {
      first_six = binario[i + j].substr(0, 6);

      if (first_six == "000000") {
        rs = binario[i + j].substr(6, 5);
        rt = binario[i + j].substr(11, 5);

        if (rd == rs || rd == rt) {
          if (j == 1) {
            arquivo02 << binario[i] << endl << NOP << endl << NOP << endl;
            cout << binario[i] << endl << NOP << endl << NOP << endl;
            j = 3;
          } else {
            arquivo02 << binario[i] << endl << NOP << endl;
            cout << binario[i] << endl << NOP << endl;
          }
        } else if (j == 2) {
          arquivo02 << binario[i] << endl;
          cout << binario[i] << endl;
        }

      } else if (first_six == "000010" || first_six == "000011") {
        continue;
      } else {
        string rs = binario[i + j].substr(6, 5);

        if (rs == rd) {
          if (j == 1) {
            arquivo02 << binario[i] << endl << NOP << endl << NOP << endl;
            cout << binario[i] << endl << NOP << endl << NOP << endl;
            j = 3;
          } else {
            arquivo02 << binario[i] << endl << NOP << endl;
            cout << binario[i] << endl << NOP << endl;
          }
        } else if (j == 2) {
          arquivo02 << binario[i] << endl;
          cout << binario[i] << endl;
        }
      }
    }
  }

}
