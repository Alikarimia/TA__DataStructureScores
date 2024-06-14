#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
private:
    Node* root;
//inorder class
    void inorderHelper(Node* node) {
        if (node == nullptr) return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
//preorder class
    void preorderHelper(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
//postorder class
    void postorderHelper(Node* node) {
        if (node == nullptr) return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() : root(nullptr) {}
//insert
    void insert(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                break;
            } else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;
                break;
            } else {
                q.push(current->right);
            }
        }
    }
//bfs
    void BFS() {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
    }
//dfs
    void DFS() {
        if (root == nullptr) return;

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();
            cout << current->data << " ";

            if (current->right != nullptr) s.push(current->right);
            if (current->left != nullptr) s.push(current->left);
        }
    }

    void inorder() {
        inorderHelper(root);
    }

    void preorder() {
        preorderHelper(root);
    }

    void postorder() {
        postorderHelper(root);
    }

    void levelOrder() {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
    }
//find height
    int height(Node* node) {
        if (node == nullptr) return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    int getHeight() {
        return height(root);
    }
//search class
    bool search(int data) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->data == data) {
                return true;
            }

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }

        return false;
    }

    int findHeightOfNode(int data) {
        queue<Node*> q;

        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();

                if (current->data == data) {
                    return level;
                }

                if (current->left != nullptr) q.push(current->left);
                if (current->right != nullptr) q.push(current->right);
            }

            level++;
        }

        return -1; // Node not found
    }

    bool isLeaf(Node* node) {
        return (node != nullptr && node->left == nullptr && node->right == nullptr);
    }
//delete node
    void deleteNode(int data) {
        Node* target = nullptr; 
        Node* parent = nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->data == data)
                target = current;

            if (current->left != nullptr) {
                parent = current;
                q.push(current->left);
            }

            if (current->right != nullptr) {
                parent = current;
                q.push(current->right);
            }
        }

        if (target == nullptr) {
            cout << "Node with data " << data << " not found in the tree." << endl;
            return;
        }

        // If its a leaf node
        if (isLeaf(target)) {
            if (parent == nullptr)
                root = nullptr;
            else if (parent->left == target)
                parent->left = nullptr;
            else
                parent->right = nullptr;

            delete target;
            return;
        }

        // if only one child 
        if (target->left == nullptr || target->right == nullptr) {
            Node* child = (target->left != nullptr) ? target->left : target->right;

            if (parent == nullptr)
                root = child;
            else if (parent->left == target)
                parent->left = child;
            else
                parent->right = child;

            delete target;
            return;
        }

        // if only have 2 child
        Node* successorParent = target;
        Node* successor = target->right;

        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        target->data = successor->data;

        if (successorParent == target)
            successorParent->right = successor->right;
        else
            successorParent->left = successor->right;

        delete successor;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    cout << "BFS => ";
    tree.BFS();
    cout << endl;

    cout << "DFS => ";
    tree.DFS();
    cout << endl;

    cout << "Inorder => ";
    tree.inorder();
    cout << endl;

    cout << "Preorder => ";
    tree.preorder();
    cout << endl;

    cout << "Postorder => ";
    tree.postorder();
    cout << endl;

    cout << "Level Order => ";
    tree.levelOrder();
    cout << endl;

    cout << "Height of the tree=> " << tree.getHeight() << endl;

    int searchData = 3;
    cout << searchData << " is in the tree=> " << (tree.search(searchData) ? "Yes" : "No") << endl;

    int heightOfNodeData = 4;
    cout << "Height of node with data " << heightOfNodeData << "=> " << tree.findHeightOfNode(heightOfNodeData) << endl;

    int deleteData = 2;
    tree.deleteNode(deleteData);

    cout << "Inorder traversal after deleting node with data " << deleteData << " =>";

    tree.inorder();
    cout << endl;

    return 0;
}