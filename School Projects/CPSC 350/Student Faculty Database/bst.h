#include <iostream>
#include <cmath>
#include <string>

using namespace std;

template <class T>
class TreeNode
{
public:
    TreeNode();
    TreeNode(T k);
    virtual ~TreeNode();

    T key; // data
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode<T> *parent;
    int leftDepth;
    int rightDepth;
    int currentSize;
};

template <class T>
TreeNode<T>::TreeNode()
{
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    key = T();
    leftDepth = 0;
    rightDepth = 0;
}

template <class T>
TreeNode<T>::TreeNode(T k)
{
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    key = k;
    leftDepth = 0;
    rightDepth = 0;
}

template <class T>
TreeNode<T>::~TreeNode()
{
    left = nullptr;
    right = nullptr;
}

template <class T>
class BST
{
public:
    BST();
    virtual ~BST();

    void insert(T value);
    bool contains(T value); // search()
    bool deleteNode(T k);
    TreeNode<T> *getSuccessor(TreeNode<T> *d);

    bool isEmpty();
    T *getMin();
    T *getMax();
    void printTree();
    void recPrint(TreeNode<T> *node);
    void updateDepths(TreeNode<T> *node);
    void checkAndRebalance(TreeNode<T> *node);
    void rebalance(TreeNode<T> *&node, T *sortedArray, int start, int end);
    void collectValues(TreeNode<T> *node, T *sortedArray, int &index);
    // TreeNode<T> *buildTree(T *sortedArray, int start, int end);
    TreeNode<T> *searchID(TreeNode<T> *root, const T &key);
    TreeNode<T> *findID(const T &key);
    TreeNode<T> *searchAdvisorID(TreeNode<T> *root, const T &key);
    TreeNode<T> *findAdvisorID(const T &key);
    void changeAdvisorRec(TreeNode<T> *node, const T &key, const int &newAdvisor);
    void changeAdvisor(const T &key, const int &newAdvisor);
    string extractID(T value);
    void bubbleSort(T arr[], int size);
    // TreeNode<T> *root;

private:
    TreeNode<T> *root;
    T *sortedArray;
    int size; 
    int currentSize;
};

template <class T>
BST<T>::BST()
{
    root = nullptr;
    currentSize = 0;
}

template <class T>
BST<T>::~BST()
{
    // Clean up tree resources
}

template <class T>
TreeNode<T> *BST<T>::searchID(TreeNode<T> *root, const T &key)
{
    TreeNode<T> *current = root;
    if (root == nullptr || root->key.substr(0, 4) == key.substr(0, 4))
    {
        return root;
    }
    else if (key < root->key.substr(0, 4))
    {
        return searchID(root->left, key);
    }
    return searchID(root->right, key);
}

template <class T>
TreeNode<T> *BST<T>::findID(const T &key)
{
    TreeNode<T> *current = root;
    return searchID(root, key);
}

template <class T>
void BST<T>::changeAdvisor(const T &key, const int &newAdvisor)
{
    changeAdvisorRec(root, key, newAdvisor);
}

template <class T>
void BST<T>::changeAdvisorRec(TreeNode<T> *node, const T &key, const int &newAdvisor)
{
    if (node == nullptr)
    {
        return;
    }

    string nodeKey = node->key;
    node->key.replace(node->key.size() - 6, 4, to_string(newAdvisor));


    changeAdvisorRec(node->left, key, newAdvisor);
    changeAdvisorRec(node->right, key, newAdvisor);
}

template <class T>
TreeNode<T> *BST<T>::searchAdvisorID(TreeNode<T> *root, const T &key)
{
    if (root == nullptr || root->key.substr(root->key.size() - 4) == key)
    {
        return root;
    }
    else if (key < root->key.substr(root->key.size() - 4))
    {
        return searchID(root->left, key);
    }
    return searchID(root->right, key);
}

template <class T>
TreeNode<T> *BST<T>::findAdvisorID(const T &key)
{
    return searchID(root, key);
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node)
{
    if (node == nullptr)
        return;

    recPrint(node->left);
    recPrint(node->right);
    cout << node->key << endl;
}

template <class T>
void BST<T>::printTree()
{
    recPrint(root);
}

template <class T>
bool BST<T>::isEmpty()
{ 
    return (root == nullptr);
}

template <class T>
T *BST<T>::getMin()
{
    if (isEmpty())
        return nullptr;

    TreeNode<T> *current = root;
    while (current->left != nullptr)
    {
        current = current->left;
    }

    return &(current->key);
}

template <class T>
T *BST<T>::getMax()
{
    if (isEmpty())
        return nullptr;

    TreeNode<T> *current = root;
    while (current->right != nullptr)
    {
        current = current->right;
    }

    return &(current->key);
}
template <class T>
string BST<T>::extractID(T value)
{

    return value.substr(0, 4);
}

template <class T>
void BST<T>::bubbleSort(T arr[], int size) {
    for (int i = 0; i < size-1; ++i) {
        for (int j = 0; j < size-i-1; ++j) {
            int id1 = std::stoi(arr[j].substr(0, 4));
            int id2 = std::stoi(arr[j+1].substr(0, 4));

            if (id1 > id2) {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

template <class T>
void BST<T>::insert(T value)
{

    TreeNode<T> *node = new TreeNode<T>(value);

    if (isEmpty())
    {
        root = node;
    }
    else
    {
        // The tree had 1 or more nodes
        TreeNode<T> *current = root;
        TreeNode<T> *parent = root;

        while (true)
        {
            parent = current;

            if (value < current->key)
            {
                // We go left
                current = current->left;

                if (current == nullptr)
                {
                    // We found the insertion point
                    parent->left = node;
                    break;
                }
            }
            else
            {
                // We go right
                current = current->right;

                if (current == nullptr)
                {
                    // We found the insertion point
                    parent->right = node;
                    break;
                }
            }
        }
        updateDepths(root);
        checkAndRebalance(root);
    }
}


template <class T>
bool BST<T>::contains(T value)
{
    if (isEmpty())
        return false;

    TreeNode<T> *current = root;

    while (current->key != value)
    {
        if (value < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (current == nullptr)
            return false;
    }
    return true;
}

template <class T>
bool BST<T>::deleteNode(T k)
{

    if (isEmpty())
    {
        return false;
    }

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while (current->key != k)
    {
        parent = current;

        if (k < current->key)
        {
            isLeft = true;
            current = current->left;
        }
        else
        {
            isLeft = false;
            current = current->right;
        }

        if (current == nullptr)
        {
            return false;
        }
    }

    // if we get here that means we found the node that needs to be deleted

    /**
     * leaf node
     */
    if (current->left == nullptr && current->right == nullptr)
    {

        if (current == root)
        {
            root = nullptr;
        }
        else if (isLeft)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
    }

    /**
     * node to be deleted has 1 child
     */

    // left
    else if (current->right == nullptr)
    {
        // node has 1 child and its a left child
        if (current == root)
        {
            root = current->left;
        }
        else if (isLeft)
        {
            parent->left = current->left;
        }
        else
        {
            parent->right = current->left;
        }
    }

    // right
    else if (current->left == nullptr)
    {
        // node has 1 child and its a right child
        if (current == root)
        {
            root = current->right;
        }
        else if (isLeft)
        {
            parent->left = current->right;
        }
        else
        {
            parent->right = current->right;
        }
    }

    /**
     * has 2 children
     */

    else
    {
        TreeNode<T> *successor = getSuccessor(current);

        if (current == root)
        {
            root = successor;
        }
        else if (isLeft)
        {
            parent->left = successor;
        }
        else
        {
            parent->right = successor;
        }

        successor->left = current->left;
        current->left = nullptr;
        current->right = nullptr;

        updateDepths(root);
        checkAndRebalance(root);
    }
    delete current;
    return true;
}

template <class T>
TreeNode<T> *BST<T>::getSuccessor(TreeNode<T> *d)
{
    TreeNode<T> *sp = d; // successor parent
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right;

    while (current != nullptr)
    {
        sp = successor;
        successor = current;
        current = current->left;
    }

    // once we get here, we identified our successor
    // now we need to check if the successor is the descendant of the right child
    if (successor != d->right)
    {
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}

template <class T>
void BST<T>::updateDepths(TreeNode<T> *node)
{
    if (node == nullptr)
        return;

    if (node->left != nullptr)
    {
        updateDepths(node->left);
        node->leftDepth = max(node->left->leftDepth, node->left->rightDepth) + 1;
    }

    if (node->right != nullptr)
    {
        updateDepths(node->right);
        node->rightDepth = max(node->right->leftDepth, node->right->rightDepth) + 1;
    }
}

template <class T>
void BST<T>::checkAndRebalance(TreeNode<T> *node)
{
    if (node == nullptr)
        return;

    int balanceFactor = abs(node->leftDepth - node->rightDepth);
    if (balanceFactor > 1.5)
    {
        T *sortedArray = new T[10000];
        int index = 0;
        collectValues(node, sortedArray, index);
        rebalance(node, sortedArray, 0, index - 1);
        delete[] sortedArray;
    }

    if (node->left != nullptr)
    {
        checkAndRebalance(node->left);
    }
    if (node->right != nullptr)
    {
        checkAndRebalance(node->right);
    }
}

template <class T>
void BST<T>::rebalance(TreeNode<T> *&node, T *sortedArray, int start, int end)
{
    if (start > end)
    {
        node = nullptr;
        return;
    }

    int mid = start + (end - start) / 2;
    node = new TreeNode<T>(sortedArray[mid]);
    rebalance(node->left, sortedArray, start, mid - 1);
    rebalance(node->right, sortedArray, mid + 1, end);

    if (node->left != nullptr)
    {
        node->leftDepth = std::max(node->left->leftDepth, node->left->rightDepth) + 1;
    }
    if (node->right != nullptr)
    {
        node->rightDepth = std::max(node->right->leftDepth, node->right->rightDepth) + 1;
    }
}

template <class T>
void BST<T>::collectValues(TreeNode<T> *node, T *sortedArray, int &index)
{
    if (node == nullptr)
        return;

    collectValues(node->left, sortedArray, index);
    sortedArray[index++] = node->key;
    collectValues(node->right, sortedArray, index);
}
