#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char *argv[]) {
  std::srand(std::time(0));

  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<int> distribution(
      std::numeric_limits<short>::min() * 8,
      std::numeric_limits<short>::max() * 8);

  std::uniform_int_distribution<int> distribution_2(0, 2);

  int nodos_inicio, operaciones;
  int p_inserts, p_deletes, p_busquedas;

  nodos_inicio = atoi(argv[1]);
  operaciones = atoi(argv[2]);

  // Inicializar el árbol
  for (int i = 0; i < nodos_inicio; ++i) {
    cout << "a " << distribution(gen) << endl;
  }

  // Operaciones
  for (int i = 0; i < operaciones; ++i) {
    if (i < operaciones * 0.33) {
      cout << "a " << distribution(gen) << endl;
    }

    else if (i >= operaciones * 0.33 and i < operaciones * 0.66) {
      cout << "s " << distribution(gen) << endl;
    }

    else {
      cout << "d " << distribution(gen) << endl;
    }
  }

  cout << "*" << endl;
}
