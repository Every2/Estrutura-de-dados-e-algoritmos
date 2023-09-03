#include <iostream>
#include <cmath>

struct Node {
    int n;
    int degree;
    Node* parent;
    Node* child;
    Node* left;
    Node* right;
    char mark;
    char C;
};

class FibonacciHeap {

private:
    int nH;
    Node* H;

public:

    FibonacciHeap() {
        H =  initializeHeap();
    }

    Node* initializeHeap() {
        Node* np {nullptr};
        return np;
    }

    void link(Node *h1, Node *y, Node* z) {
        (y->left)->right = y->right;
        (y->right)->left = y->left;
        if (z->right == z)
            h1 = z;
        y->left = y;
        y->right = y;
        y->parent = z;

        if (z->child == nullptr)
            z->child = y;

        y->right = z->child;
        y->left = (z->child)->left;
        ((z->child)->left)->right = y;
        (z->child)->left = y;

        if (y->n < (z->child)->n)
            z->child = y;
        z->degree++;
    }

    Node* createNode(int value) {
        Node* x {new Node};
        x->n = value;
        return x;
    }

    Node* insert(Node* H, Node* x) {
       x->degree = 0;
       x->parent = nullptr;
       x->child = nullptr;
       x->left = x;
       x->right = x;
       x->mark = 'F';
       x->C = 'N';
        if (H != nullptr) {
            (H->left)->right = x;
            x->right = H;
            x->left = H->left;
            H->left = x;
            if (x->n < H->n)
                H = x;
        }  
        else {
            H = x;
        }       
        nH = nH + 1;
        return H;
    }

    Node* Union(Node* H1, Node* H2) {
        Node *np;
        Node *H = initializeHeap();
        H = H1;
        (H->left)->right = H2;
        (H2->left)->right = H;
        np = H->left;
        H->left = H2->left;
        H2->left = np;
        return H;
    }

    Node* extractMin(Node* H1) {
        Node *p;
        Node *ptr;
        Node *z = H1;
        p = z;
        ptr = z;
        if (z == nullptr)
            return z;

        Node *x;
        Node *np;

        x = nullptr;

        if (z->child != nullptr)
            x = z->child;

        if (x != nullptr)
        {
            ptr = x;
            do  {
                np = x->right;
                (H1->left)->right = x;
                x->right = H1;
                x->left = H1->left;
                H1->left = x;
                if (x->n < H1->n)
                    H1 = x;

                x->parent = nullptr;
                x = np;
            } while (np != ptr);
        }

        (z->left)->right = z->right;
        (z->right)->left = z->left;
        H1 = z->right;

        if (z == z->right && z->child == nullptr)
            H = nullptr;

        else {
            H1 = z->right;
            consolidate(H1);
        }
        nH = nH - 1;
        return p;
    }

    void consolidate(Node* H1) 
    {
        int d, i;
        float f = (log(nH)) / (log(2));
        int D = f;
        Node *A[100];

        for (i = 0; i <= D; i++)
          A[i] = nullptr;

        Node *x = H1;
        Node *y;
        Node *np;
        Node *pt = x;

        do
        {
          pt = pt->right;

          d = x->degree;

          while (A[d] != NULL)

          {
            y = A[d];

            if (x->n > y->n)

            {
              np = x;

              x = y;

              y = np;
            }

            if (y == H1)
              H1 = x;
            link(H1, y, x);
            if (x->right == x)
              H1 = x;
            A[d] = NULL;
            d = d + 1;
          }

          A[d] = x;
          x = x->right;

        }

        while (x != H1);
        H = NULL;
        for (int j = 0; j <= D; j++)
        {
          if (A[j] != NULL)
          {
            A[j]->left = A[j];
            A[j]->right = A[j];
            if (H != NULL)
            {
              (H->left)->right = A[j];
              A[j]->right = H;
              A[j]->left = H->left;
              H->left = A[j];
              if (A[j]->n < H->n)
                H = A[j];
            }
            else
            {
              H = A[j];
            }
            if (H == NULL)
              H = A[j];
            else if (A[j]->n < H->n)
              H = A[j];
          }
        }
    } 

    void display(Node *H)
    {
        Node *p = H;
        if (p == nullptr)
        {
            std::cout << "The Heap is Empty" << '\n';
            
        }
        std::cout << "The root nodes of Heap are: " << '\n';

        do
        {
            std::cout << p->n;
            p = p->right;
            if (p != H)
            {
                std::cout << "-->";
            }
        } while (p != H && p->right != nullptr);
        std::cout << '\n';
    }      

    Node* find(Node* H, int k)
    {
        Node *x = H;
        x->C = 'Y';
        Node *p = nullptr;
        if (x->n == k)
        {
            p = x;
            x->C = 'N';
            return p;
        }

        if (p == nullptr)
        {
            if (x->child != nullptr)
                p = find(x->child, k);
            if ((x->right)->C != 'Y')
                p = find(x->right, k);
        }

        x->C = 'N';
        return p;
    }

    int decreaseKey(Node* H1, int x, int k)
    {
        Node *y;
        if (H1 == nullptr)
        {
            std::cout << "The Heap is Empty" << '\n';
            return 0;
        }
        Node *ptr = find(H1, x);
        if (ptr == nullptr)
        {
            std::cout << "Node not found in the Heap" << '\n';
            return 1;
        }

        if (ptr->n < k)
        {
            std::cout << "Entered key greater than current key" << '\n';
            return 0;
        }
        ptr->n = k;
        y = ptr->parent;
        if (y != nullptr && ptr->n < y->n)
        {
            cut(H1, ptr, y);
            cascaseCut(H1, y);
        }

        if (ptr->n < H->n)
            H = ptr;

        return 0;
    }

    int deleteKey(Node* H1, int k)
    {
        Node *np = NULL;
        int t;
        t = decreaseKey(H1, k, -5000);
        if (!t)
            np = extractMin(H);
        if (np != NULL)
            std::cout << "Key Deleted" << '\n';
        else
            std::cout << "Key not Deleted" << '\n';
        return 0;
    }

    void cut(Node* H1, Node* x, Node *y)
    {
        if (x == x->right)
            y->child = nullptr;
        (x->left)->right = x->right;
        (x->right)->left = x->left;
        if (x == y->child)
            y->child = x->right;
        y->degree = y->degree - 1;
        x->right = x;
        x->left = x;
        (H1->left)->right = x;
        x->right = H1;
        x->left = H1->left;
        H1->left = x;
        x->parent = nullptr;
        x->mark = 'F';
    }

    void cascaseCut(Node* H1, Node *y)
    {
        Node *z = y->parent;
        if (z != NULL)
        {
            if (y->mark == 'F')
            {
                y->mark = 'T';
            }
            else
            {
                cut(H1, y, z);
                cascaseCut(H1, z);
            }
        }
    }

};
