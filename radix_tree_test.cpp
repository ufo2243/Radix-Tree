#include "radix_tree.h"
#include <iostream>

int 
main () {
    struct radix_tree_root* root;
    root = radix_tree_init(); 
    char* test="abc";
    std::cout << "test bgein ";
    radix_tree_set(root, 2, (void *)test); 
    std::cout << (char *)radix_tree_get(root, 2);
    radix_tree_delete(root, 2);
    if (radix_tree_get(root, 2) == NULL) {
        std::cout << "no index 2 ";
    }
    else {
        std::cout << "has index 2 ";
    }
    radix_tree_set(root, 2, (void *)test); 
    if (radix_tree_get(root, 2) == NULL) {
        std::cout << "no index 2 ";
    }
    else {
        std::cout << "has index 2 ";
    }

    return 0;
}
