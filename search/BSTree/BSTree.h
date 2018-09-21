//
// Created by I500042 on 9/19/2018.
//

#ifndef BSTREE_BSTREE_H
#define BSTREE_BSTREE_H
using namespace std;

/**
 * 节点的结构体
 * @tparam T
 */
template<class T>
class BSTNode {
public:
    T key;
    BSTNode *left;
    BSTNode *right;
    BSTNode *parent;

    BSTNode(T value, BSTNode *l, BSTNode *r, BSTNode *parent) :
            key(value), left(l), right(r), parent() {}
};

template<class T>
class BSTree {
private:
    BSTNode<T> *mRoot;
public:
    BSTree();

    ~BSTree();

    void insert(T key);

    BSTNode<T> *search(T key);

    // traversing
    void preOrder();

    void midOrder();

    void postOrder();


    BSTNode<T>* minimumNode();

    BSTNode<T>* maximumNode();

    T minimumKey();

    T maximumKey();

    void print();

    void remove(T key);

    BSTNode<T> *predecessor(BSTNode<T> *x);

    BSTNode<T> *sucessor(BSTNode<T> *x);

    void destory();

private:
    void insert(BSTNode<T> *&tree, BSTNode<T> *z);

    BSTNode<T> *search(BSTNode<T> *&tree, T key) const;

    void preOrder(BSTNode<T> *&tree) const;

    void midOrder(BSTNode<T> *&tree) const;

    void postOrder(BSTNode<T> *&tree) const;

    BSTNode<T> *minimumNode(BSTNode<T> *&tree);

    BSTNode<T> *maximumNode(BSTNode<T> *&tree);

    void print(BSTNode<T> *&tree);

    BSTNode<T> *remove(BSTNode<T> *&tree, BSTNode<T> *z);

    void destory(BSTNode<T> *&tree);
};


/**
 * 构造函数
 * @tparam T
 */
template<class T>
BSTree<T>::BSTree():
        mRoot(NULL) {}

/**
 * 析构函数
 * @tparam T
 */
template<class T>
BSTree<T>::~BSTree() {
    destory();
}

/**
 * insert data
 * @tparam T
 * @param key
 */
template<class T>
void BSTree<T>::insert(T key) {

    BSTNode<T> *z = NULL;

    if ((z = new BSTNode<T>(key, NULL, NULL, NULL)) == NULL)
        return;
    insert(mRoot, z);
}

template<class T>
void BSTree<T>::insert(BSTNode<T>*& tree, BSTNode<T>* z) {
    BSTNode<T>* y = NULL;
    BSTNode<T>* x = tree;

    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NULL) {
        tree = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

/**
 * preOrder traversing
 * @tparam T
 * @param tree
 */

template<class T>
void BSTree<T>::preOrder() {
    preOrder(mRoot);
}

template<class T>
void BSTree<T>::preOrder(BSTNode<T> *&tree) const {
    if (tree != NULL) {
        cout << tree->key << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

/**
 * midOrder traversing
 * @tparam T
 */
template<class T>
void BSTree<T>::midOrder() {
    midOrder(mRoot);
}

template<class T>
void BSTree<T>::midOrder(BSTNode<T>*& tree) const {
    if(tree != NULL){
        midOrder(tree->left);
        cout << tree->key << " ";
        midOrder(tree->right);
    }
}

/**
 * 
 * @tparam T
 * @param key
 * @return
 */
template <class T>
BSTNode<T>* BSTree::search(T key) {
    search(mRoot,key);
}

#endif //BSTREE_BSTREE_H
