#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

int main() {
  std::srand(std::time(0));

  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<int> distribution(
      std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

  int randomNumber = distribution(gen);

  // int randomNumber = std::rand() % 3 + 1;

  // Inicializar el árbol
  for (int i = 0; i < 1000000; ++i) {
    cout << "a " << distribution(gen) << endl;
  }

  // Operaciones
  for (int i = 0; i < 1000000; ++i) {
    int randomOperation = std::rand() % 3 + 1;

    if (randomOperation == 1) {
      cout << "a " << distribution(gen) << endl;
    }

    else if (randomOperation == 2) {
      cout << "d " << distribution(gen) << endl;
    }

    else {
      cout << "s " << distribution(gen) << endl;
    }
  }

  cout << "*" << endl;
}
