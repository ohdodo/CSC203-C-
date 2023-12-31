#include <iostream>
#include <iomanip>
using namespace std;

int input(int arr[], int n){
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

struct Node
{
    int key;
    struct Node *left, *right;
};

// A utility function to create a new BST Node
struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Stores inorder traversal of the BST in arr[]
void storeSorted(Node *root, int arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}

/* A utility function to insert a new Node with given key in BST */
Node *insert(Node *node, int key)
{
    /* If the tree is empty, return a new Node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) Node pointer */
    return node;
}

// Function to print the BST in ASCII tree form
void printBST(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process the right child first
    printBST(root->right, space);

    // Print current node after appropriate spaces
    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";
    cout << root->key << "\n";

    // Process the left child
    printBST(root->left, space);
}

// This function sorts arr[0..n-1] using Tree Sort
void treeSort(int arr[], int n)
{
    struct Node *root = NULL;

    // Construct the BST
    root = insert(root, arr[0]);
    cout << "Inserting " << arr[0] << " into the BST:" << endl;
    printBST(root, 0);
    cout << endl;

    for (int i = 1; i < n; i++)
    {
        root = insert(root, arr[i]);
        cout << "Inserting " << arr[i] << " into the BST:" << endl;
        printBST(root, 0);
        cout << endl;
    }

    // Store inorder traversal of the BST in arr[]
    int i = 0;
    storeSorted(root, arr, i);
}

// Driver Program to test above functions
int main(){
    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;

    int *arr = new int[n];
    input(arr,n);

    Node* tree = NULL;
    treeSort(arr, n);

    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;

    return 0;
}