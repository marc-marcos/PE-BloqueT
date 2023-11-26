#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 6) {
    cout
        << "Usage: nodos_inicio, operaciones, p_inserts, p_deletes, p_busquedas"
        << endl;
  }

  else {
    std::srand(std::time(0));

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(
        std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    int nodos_inicio, operaciones;
    int p_inserts, p_deletes, p_busquedas;

    nodos_inicio = atoi(argv[1]);
    operaciones = atoi(argv[2]);

    p_inserts = atoi(argv[3]);
    p_deletes = atoi(argv[4]);
    p_busquedas = atoi(argv[5]);

    // Inicializar el árbol
    for (int i = 0; i < nodos_inicio; ++i) {
      cout << "a " << distribution(gen) << endl;
    }

    // Operaciones
    for (int i = 0; i < operaciones; ++i) {
      if (i >= (operaciones / 100) * p_deletes &&
          i < (operaciones / 100) * (p_deletes + p_inserts)) {
        cout << "a " << distribution(gen) << endl;
      }

      else if (i < (operaciones / 100) * p_deletes) {
        cout << "d " << distribution(gen) << endl;
      }

      else {
        cout << "s " << distribution(gen) << endl;
      }
    }

    cout << "*" << endl;
  }
}
