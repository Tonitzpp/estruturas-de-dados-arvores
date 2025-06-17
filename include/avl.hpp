#pragma once
#include <utility>
#include <vector>
#include <cmath>


/**
 * @brief Classe que representa uma Árvore Binária de Busca (BST).
 *
 * Armazena elementos em ordem, permitindo operações eficientes de busca,
 * inserção e remoção.
 *
 * @tparam T Tipo dos elementos armazenados na árvore.
 */
template <class T>
class AVL {
 private:
  /**
   * @brief Estrutura interna que representa um nó da árvore.
   */
  struct TreeNode {
    T data;           ///< Valor armazenado no nó.
    TreeNode* left;   ///< Ponteiro para o filho à esquerda.
    TreeNode* right;  ///< Ponteiro para o filho à direita.
    int height;  ///< Altura do nó na árvore. Usada para balanceamento da AVL.

    /**
     * @brief Construtor que inicializa o nó com um valor.
     *
     * @param value Valor a ser armazenado no nó.
     */
    TreeNode(const T& value);

    /**
     * @brief Destrutor do nó, libera recursivamente seus filhos.
     */
    ~TreeNode();

    /**
     * @brief Retorna o nó com o maior valor da subárvore.
     *
     * @return Ponteiro para o nó com o valor máximo.
     */
    TreeNode* max();

    /**
     * @brief Retorna o nó com o menor valor da subárvore.
     *
     * @return Ponteiro para o nó com o valor mínimo.
     */
    TreeNode* min();
  };

  /**
   * @brief Retorna a altura de um nó da árvore.
   *
   * @param node Ponteiro para o nó.
   * @return Altura do nó se não for nulo, ou -1 caso seja nullptr.
   */
  int height(TreeNode* node) const;

  /**
   * @brief Atualiza o balanceamento da árvore AVL a partir de um nó.
   *
   * Recalcula a altura do nó, verifica o fator de balanceamento
   * e realiza rotações simples ou duplas conforme necessário para
   * manter as propriedades da AVL.
   *
   * @param node Referência para o ponteiro do nó a ser balanceado.
   */
  void balance(TreeNode*& node);

  /**
   * @brief Insere um valor na árvore recursivamente.
   *
   * @param node Ponteiro de referência para o nó atual.
   * @param value Valor a ser inserido.
   * @return `true` se a inserção foi bem-sucedida, `false` se o valor já
   * existia.
   */
  bool insert(TreeNode*& node, const T& value);

  /**
   * @brief Remove um valor da árvore recursivamente.
   *
   * @param node Ponteiro de referência para o nó atual.
   * @param value Valor a ser removido.
   * @return `true` se a remoção foi bem-sucedida, `false` se o valor não foi
   * encontrado.
   */
  bool remove(TreeNode*& node, const T& value);

  /**
   * @brief Verifica se a árvore contém um valor específico.
   *
   * @param node Ponteiro para o nó atual.
   * @param value Valor a ser buscado.
   * @return `true` se o valor estiver na árvore, `false` caso contrário.
   */
  bool contain(const TreeNode* const node, const T& value) const;

  /**
   * @brief Executa a travessia in-order recursiva.
   *
   * Visita a subárvore esquerda, depois o nó atual e em seguida a subárvore
   * direita. Os valores visitados são armazenados em `result`.
   *
   * @param node Ponteiro para o nó atual.
   * @param result Vetor onde os valores visitados serão armazenados.
   */
  void in_order(const TreeNode* const node, std::vector<T>& result) const;

  /**
   * @brief Executa a travessia pre-order recursiva.
   *
   * Visita o nó atual, em seguida a subárvore esquerda e depois a direita.
   * Os valores visitados são armazenados em `result`.
   *
   * @param node Ponteiro para o nó atual.
   * @param result Vetor onde os valores visitados serão armazenados.
   */
  void pre_order(const TreeNode* const node, std::vector<T>& result) const;

  /**
   * @brief Executa a travessia post-order recursiva.
   *
   * Visita a subárvore esquerda, depois a direita e por último o nó atual.
   * Os valores visitados são armazenados em `result`.
   *
   * @param node Ponteiro para o nó atual.
   * @param result Vetor onde os valores visitados serão armazenados.
   */
  void post_order(const TreeNode* const node, std::vector<T>& result) const;

 public:
  /**
   * @brief Construtor da árvore (inicialmente vazia).
   */
  AVL();

  /**
   * @brief Destrutor da árvore, libera todos os nós.
   */
  ~AVL();

  /**
   * @brief Insere um novo valor na árvore.
   *
   * @param value Valor a ser inserido.
   * @return `true` se inserido com sucesso, `false` se o valor já existia.
   */
  bool insert(const T& value);

  /**
   * @brief Remove um valor da árvore.
   *
   * @param value Valor a ser removido.
   * @return `true` se o valor foi removido, `false` se não estava presente.
   */
  bool remove(const T& value);

  /**
   * @brief Verifica se um valor está presente na árvore.
   *
   * @param value Valor a ser verificado.
   * @return `true` se presente, `false` caso contrário.
   */
  bool contain(const T& value) const;

  /**
   * @brief Retorna os valores da árvore em ordem (in-order).
   *
   * Visita a subárvore esquerda, o nó atual e a subárvore direita.
   *
   * @return Vetor com os valores em ordem.
   */
  std::vector<T> in_order() const;

  /**
   * @brief Retorna os valores da árvore em pré-ordem (pre-order).
   *
   * Visita o nó atual, depois a subárvore esquerda e depois a direita.
   *
   * @return Vetor com os valores em pré-ordem.
   */
  std::vector<T> pre_order() const;

  /**
   * @brief Retorna os valores da árvore em pós-ordem (post-order).
   *
   * Visita a subárvore esquerda, depois a direita e por fim o nó atual.
   *
   * @return Vetor com os valores em pós-ordem.
   */
  std::vector<T> post_order() const;

  /**
   * @brief Verifica se a árvore está balanceada (propriedade da AVL).
   *
   * @return `true` se todos os nós estão balanceados, `false` caso contrário.
   */
  bool is_balanced() const { return is_balanced(root).first; }

  /**
   * @brief Verifica recursivamente se a subárvore está balanceada e retorna sua
   * altura.
   *
   * @param node Nó atual.
   * @return Par (está_balanceada, altura).
   */
  std::pair<bool, int> is_balanced(TreeNode* node) const {
    if (!node) return {true, -1};

    auto left = is_balanced(node->left);
    auto right = is_balanced(node->right);

    bool balanced =
        left.first && right.first && std::abs(left.second - right.second) <= 1;
    int node_height = 1 + std::max(left.second, right.second);

    return {balanced, node_height};
  }

 private:
  TreeNode* root;  ///< Ponteiro para a raiz da árvore.
};

template <class T>
AVL<T>::AVL() : root(nullptr) {}

template <class T>
AVL<T>::~AVL() {
  delete root;
}

template <class T>
AVL<T>::TreeNode::TreeNode(const T& value)
    : data(value), left(nullptr), right(nullptr), height(0) {}

template <class T>
AVL<T>::TreeNode::~TreeNode() {
  delete left;
  delete right;
}

template <class T>
typename AVL<T>::TreeNode* AVL<T>::TreeNode::max() {
  return right ? right->max() : this;
}

template <class T>
typename AVL<T>::TreeNode* AVL<T>::TreeNode::min() {
  return left ? left->min() : this;
}

template <class T>
int AVL<T>::height(TreeNode* node) const {
  return node ? node->height : -1;
}

template <class T>
void AVL<T>::balance(TreeNode*& node) {
  if (!node) return;

  int hl = height(node->left);
  int hr = height(node->right);

  if (hl - hr > 1) {
    if (height(node->left->left) >= height(node->left->right)) {
      TreeNode* L = node->left;
      node->left = L->right;
      L->right = node;
      node->height = std::max(height(node->left), height(node->right)) + 1;
      L->height = std::max(height(L->left), height(L->right)) + 1;
      node = L;
    } else {
      TreeNode* L = node->left;
      TreeNode* LR = L->right;
      L->right = LR->left;
      node->left = LR->right;
      LR->left = L;
      LR->right = node;
      L->height = std::max(height(L->left), height(L->right)) + 1;
      node->height = std::max(height(node->left), height(node->right)) + 1;
      LR->height = std::max(height(LR->left), height(LR->right)) + 1;
      node = LR;
    }
  } else if (hr - hl > 1) {
    if (height(node->right->right) >= height(node->right->left)) {
      TreeNode* R = node->right;
      node->right = R->left;
      R->left = node;
      node->height = std::max(height(node->left), height(node->right)) + 1;
      R->height = std::max(height(R->left), height(R->right)) + 1;
      node = R;
    } else {
      TreeNode* R = node->right;
      TreeNode* RL = R->left;
      R->left = RL->right;
      node->right = RL->left;
      RL->right = R;
      RL->left = node;
      R->height = std::max(height(R->left), height(R->right)) + 1;
      node->height = std::max(height(node->left), height(node->right)) + 1;
      RL->height = std::max(height(RL->left), height(RL->right)) + 1;
      node = RL;
    }
  } else {
    node->height = std::max(hl, hr) + 1;
  }
}

template <class T>
bool AVL<T>::insert(TreeNode*& node, const T& value) {
  if (!node) {
    node = new TreeNode(value);
    return true;
  }
  if (value < node->data) {
    if (!insert(node->left, value)) return false;
  } else if (node->data < value) {
    if (!insert(node->right, value)) return false;
  } else {
    return false;
  }
  balance(node);
  return true;
}

template <class T>
bool AVL<T>::remove(TreeNode*& node, const T& value) {
  if (!node) return false;

  if (value < node->data) {
    if (!remove(node->left, value)) return false;
  } else if (node->data < value) {
    if (!remove(node->right, value)) return false;
  } else {
    if (!node->left) {
      TreeNode* tmp = node;
      node = node->right;
      tmp->left = tmp->right = nullptr;
      delete tmp;
    } else if (!node->right) {
      TreeNode* tmp = node;
      node = node->left;
      tmp->left = tmp->right = nullptr;
      delete tmp;
    } else {
      TreeNode* minNode = node->right->min();
      node->data = minNode->data;
      remove(node->right, minNode->data);
    }
  }
  if (node) balance(node);
  return true;
}

template <class T>
bool AVL<T>::contain(const TreeNode* const node, const T& value) const {
  if (!node) return false;
  if (value < node->data) return contain(node->left, value);
  if (node->data < value) return contain(node->right, value);
  return true;
}

template <class T>
void AVL<T>::in_order(const TreeNode* const node, std::vector<T>& result) const {
  if (!node) return;
  in_order(node->left, result);
  result.push_back(node->data);
  in_order(node->right, result);
}

template <class T>
void AVL<T>::pre_order(const TreeNode* const node, std::vector<T>& result) const {
  if (!node) return;
  result.push_back(node->data);
  pre_order(node->left, result);
  pre_order(node->right, result);
}

template <class T>
void AVL<T>::post_order(const TreeNode* const node, std::vector<T>& result) const {
  if (!node) return;
  post_order(node->left, result);
  post_order(node->right, result);
  result.push_back(node->data);
}

template <class T>
bool AVL<T>::insert(const T& value) {
  return insert(root, value);
}

template <class T>
bool AVL<T>::remove(const T& value) {
  return remove(root, value);
}

template <class T>
bool AVL<T>::contain(const T& value) const {
  return contain(root, value);
}

template <class T>
std::vector<T> AVL<T>::in_order() const {
  std::vector<T> result;
  in_order(root, result);
  return result;
}

template <class T>
std::vector<T> AVL<T>::pre_order() const {
  std::vector<T> result;
  pre_order(root, result);
  return result;
}

template <class T>
std::vector<T> AVL<T>::post_order() const {
  std::vector<T> result;
  post_order(root, result);
  return result;
}
