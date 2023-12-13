#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>

template <typename T> class AVLTree {
private:
  struct Node {
    T data;
    Node *left;
    Node *right;
    int height;

    Node(const T &value)
        : data(value), left(nullptr), right(nullptr), height(1) {}
  };

  Node *root;

  // Helper functions
  int getHeight(Node *node) {
    if (node == nullptr)
      return 0;
    return node->height;
  }

  int getBalance(Node *node) {
    if (node == nullptr)
      return 0;
    return getHeight(node->left) - getHeight(node->right);
  }

  Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x;
  }

  Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    return y;
  }

  Node *insert(Node *node, const T &value) {
    if (node == nullptr)
      return new Node(value);

    if (value < node->data)
      node->left = insert(node->left, value);
    else if (value > node->data)
      node->right = insert(node->right, value);
    else
      return node; // Duplicate values are not allowed

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && value < node->left->data)
      return rightRotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->data)
      return leftRotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->data) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->data) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }

    return node;
  }

  Node *minValueNode(Node *node) {
    Node *current = node;

    while (current->left != nullptr)
      current = current->left;

    return current;
  }

  Node *remove(Node *node, const T &value) {
    if (node == nullptr)
      return node;

    if (value < node->data)
      node->left = remove(node->left, value);
    else if (value > node->data)
      node->right = remove(node->right, value);
    else {
      if ((node->left == nullptr) || (node->right == nullptr)) {
        Node *temp = node->left ? node->left : node->right;

        if (temp == nullptr) {
          temp = node;
          node = nullptr;
        } else
          *node = *temp;

        delete temp;
      } else {
        Node *temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
      }
    }

    if (node == nullptr)
      return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0)
      return rightRotate(node);

    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0)
      return leftRotate(node);

    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }

    return node;
  }

  Node *search(Node *node, const T &value) {
    if (node == nullptr || node->data == value)
      return node;

    if (value < node->data)
      return search(node->left, value);

    return search(node->right, value);
  }

public:
  AVLTree() : root(nullptr) {}

  void insert(const T &value) { root = insert(root, value); }

  void remove(const T &value) { root = remove(root, value); }

  bool search(const T &value) { return search(root, value) != nullptr; }
};

int main() {
  AVLTree<int> t;

  char operacion;
  int numero;

  auto start_time = std::chrono::high_resolution_clock::now();

  std::string mode = "balanced";

  int contador = 0;

  std::cin >> operacion;
  while (operacion != '*') {
    std::cin >> numero;

    switch (operacion) {
    case ('d'):
      t.remove(numero);
      break;

    case ('a'):
      t.insert(numero);
      break;

    case ('s'):
      bool b = t.search(numero);
      break;
    }

    std::cin >> operacion;
  }

  auto end_time = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
      end_time - start_time);

  std::cout << "AVL " << mode << " " << duration.count() << std::endl;
}
