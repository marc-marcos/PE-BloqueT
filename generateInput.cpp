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
  string distribucion;
  float p_inserts, p_deletes, p_busquedas;

  nodos_inicio = atoi(argv[1]);
  operaciones = atoi(argv[2]);
  distribucion = argv[3];

  if (distribucion == "balanced") {
    p_inserts = 0.33;
    p_deletes = 0.33;
    p_busquedas = 0.33;
  }

  else if (distribucion == "inserts") {
    p_inserts = 0.60;
    p_deletes = 0.20;
    p_busquedas = 0.20;
  }

  else if (distribucion == "deletes") {
    p_inserts = 0.20;
    p_deletes = 0.60;
    p_busquedas = 0.20;
  }

  else if (distribucion == "searches") {
    p_inserts = 0.20;
    p_deletes = 0.20;
    p_busquedas = 0.60;
  }

  else {
    cout << "Distribución no válida" << endl;
    return 0;
  }

  // Inicializar el árbol
  for (int i = 0; i < nodos_inicio; ++i) {
    cout << "a " << distribution(gen) << endl;
  }

  // Operaciones
  for (int i = 0; i < operaciones; ++i) {
    if (i < operaciones * p_inserts) {
      cout << "a " << distribution(gen) << endl;
    }

    else if (i >= operaciones * p_inserts and i < operaciones * (p_inserts + p_busquedas)) {
      cout << "s " << distribution(gen) << endl;
    }

    else {
      cout << "d " << distribution(gen) << endl;
    }
  }

  cout << "*" << endl;
}
