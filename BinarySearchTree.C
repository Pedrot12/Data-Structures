#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
  int value;
  struct Vertex *left;
  struct Vertex *right;
  struct Vertex *parent;
} Vertex;

typedef struct Tree {
  Vertex *root;
  int count;
} Tree;

// Function to perform a left rotation on the tree
void LeftRotation(Tree *tree, Vertex *x) {
  printf("Left rotation at %d\n", x->value);
  Vertex *parent = x->parent;
  Vertex *y = x->right;
  Vertex *b = y->left;

  if (parent != NULL) {
    if (parent->left == x) {
      parent->left = y;
    } else {
      parent->right = y;
    }
  } else {
    tree->root = y;
  }

  y->parent = parent;
  x->parent = y;
  y->left = x;
  x->right = b;

  if (b != NULL) {
    b->parent = x;
  }
}

// Function to perform a right rotation on the tree
void RightRotation(Tree *tree, Vertex *x) {
  printf("Right rotation at %d\n", x->value);
  Vertex *parent = x->parent;
  Vertex *y = x->left;
  Vertex *b = y->right;

  if (parent != NULL) {
    if (parent->right == x) {
      parent->right = y;
    } else {
      parent->left = y;
    }
  } else {
    tree->root = y;
  }

  y->parent = parent;
  x->parent = y;
  y->right = x;
  x->left = b;

  if (b != NULL) {
    b->parent = x;
  }
}

// Function to find the maximum of two integers
int MAX(int x, int y) {
  if (x >= y)
    return x;
  else
    return y;
}

// Function to calculate the height of a vertex
int height(Vertex *x) {
  if (x == NULL) {
    return -1;
  }
  return MAX(height(x->left), height(x->right)) + 1;
}

// Function to calculate the balance factor of a vertex
int balanceFactor(Vertex *x) {
  return height(x->right) - height(x->left);
}

// Function to balance the tree after an insertion or deletion
void balance(Tree *tree, Vertex *x) {
  int factor = balanceFactor(x);
  
  if (factor >= 2) {
    if (balanceFactor(x->right) >= 0) {
      LeftRotation(tree, x);
    } else {
      RightRotation(tree, x->right);
      LeftRotation(tree, x);
    }
  } else if (factor <= -2) {
    if (balanceFactor(x->left) <= 0) {
      RightRotation(tree, x);
    } else {
      LeftRotation(tree, x->left);
      RightRotation(tree, x);
    }
  }
}

// Function to insert a value into the tree
int insert(Tree *tree, int value) {
  Vertex *newVertex = malloc(sizeof(Vertex));
  newVertex->left = NULL;
  newVertex->right = NULL;
  newVertex->parent = NULL;
  newVertex->value = value;

  Vertex *previous = NULL;
  Vertex *current = tree->root;

  while (current != NULL) {
    previous = current;
    if (value <= current->value) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  newVertex->parent = previous;

  if (previous != NULL) {
    if (value <= previous->value) {
      previous->left = newVertex;
    } else {
      previous->right = newVertex;
    }
  } else {
    tree->root = newVertex;
  }

  tree->count++;

  Vertex *temp = newVertex->parent;

  while (temp != NULL) {
    balance(tree, temp);
    temp = temp->parent;
  }

  return 1;
}

// Function to remove a vertex from the tree
int removeVertex(Tree *tree, Vertex *x) {
  int children = 0;

  if (x != NULL && x->left != NULL) {
    children++;
  }
  if (x != NULL && x->right != NULL) {
    children++;
  }

  Vertex *parent = x->parent;

  if (children == 0) {
    if (parent != NULL) {
      if (parent->left == x) {
        parent->left = NULL;
      } else {
        parent->right = NULL;
      }
    } else {
      tree->root = NULL;
    }
    tree->count--;
  } else if (children == 1) {
    Vertex *child = x->left;
    if (child == NULL) {
      child = x->right;
    }

    if (parent == NULL) {
      tree->root = child;
    } else {
      if (parent->left == x) {
        parent->left = child;
      } else {
        parent->right = child;
      }
    }
    child->parent = parent;
    tree->count--;
  } else {
    Vertex *successor = x;
    successor = successor->right;

    while (successor->left != NULL) {
      successor = successor->left;
    }

    x->value = successor->value;
    return removeVertex(tree, successor);
  }

  return 1;
}

// Function to search for a value in the tree and remove it
int searchAndRemove(Tree *tree, int value) {
  Vertex *current = tree->root;
  
  while (current != NULL) {
    if (value < current->value) {
      current = current->left;
    } else if (value > current->value) {
      current = current->right;
    } else {
      return removeVertex(tree, current);
    }
  }
  
  return 0;
}

// Function to get the count of vertices in the tree
int getCount(Tree *tree) {
  return tree->count;
}

// Function to print the tree in in-order traversal
void printInOrder(Vertex *root) {
  if (root != NULL) {
    printInOrder(root->left);
    printf("%d ", root->value);
    printInOrder(root->right);
  }
}

// Function to print the tree in post-order traversal
void printPostOrder(Vertex *root) {
  if (root != NULL) {
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->value);
  }
}

// Function to test the insertion of a value into the tree
void testInsert(Tree *tree, int value) {
  if (insert(tree, value)) {
    printf("Value %d inserted into the tree\n", value);
    printf("In-order: ");
    printInOrder(tree->root);
    printf("\nPost-order: ");
    printPostOrder(tree->root);
    printf("\n ======== Total: %d Nodes ========\n", getCount(tree));
  }
}

// Function to test the removal of a value from the tree
void testRemove(Tree *tree, int value) {
  if (searchAndRemove(tree, value)) {
    printf("Value %d removed from the tree\n", value);
    printf("In-order: ");
    printInOrder(tree->root);
    printf("\nPost-order: ");
    printPostOrder(tree->root);
    printf("\n ======== Total: %d Nodes ========\n", getCount(tree));
  } else {
    printf("Value %d not found in the tree\n", value);
  }
}

int main() {
  Tree *tree = malloc(sizeof(Tree));
  tree->root = NULL;
  tree->count = 0;

  // Test case: Insertion
  testInsert(tree, 50);
  testInsert(tree, 30);
  testInsert(tree, 70);
  testInsert(tree, 20);
  testInsert(tree, 40);
  testInsert(tree, 60);
  testInsert(tree, 80);
  testInsert(tree, 55);

  // Test case: Removal
  testRemove(tree, 60);
  testRemove(tree, 30);
  testRemove(tree, 70);
  testRemove(tree, 90);

  return 0;
}
