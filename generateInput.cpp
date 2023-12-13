#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 6) {
    cout << "Usage: nodos_inicio, operaciones" << endl;
  }

  else {
    std::srand(std::time(0));

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(
        std::numeric_limits<short>::min() * 4,
        std::numeric_limits<short>::max() * 4);

    std::uniform_int_distribution<int> distribution_2(0, 2);

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
      int operacion = distribution_2(gen);

      if (operacion == 1) {
        cout << "a " << distribution(gen) << endl;
      }

      else if (operacion == 2) {
        cout << "d " << distribution(gen) << endl;
      }

      else {
        cout << "s " << distribution(gen) << endl;
      }
    }

    cout << "*" << endl;
  }
}
