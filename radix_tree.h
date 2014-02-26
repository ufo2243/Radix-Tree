#define MAX_TREE_SLOT 64
#define MAX_TREE_SLOT_BIT 7
#define RADIX_TREE_MASK ((1UL << MAX_TREE_SLOT_BIT) - 1)
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

struct radix_tree_node {
	struct radix_tree_node* slot[MAX_TREE_SLOT];
	void* data;
};

struct radix_tree_root {
	int32_t height;
	struct radix_tree_node *root_node;
};


int32_t get_index_height(struct radix_tree_root* root, uint64_t index);

void* radix_tree_get(struct radix_tree_root* root, int64_t index);

int32_t radix_tree_set(struct radix_tree_root* root, int64_t index,void* item); 

int32_t radix_tree_delete(struct radix_tree_root* root, int64_t index);

struct radix_tree_root* radix_tree_init();
