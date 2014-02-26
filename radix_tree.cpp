#include "radix_tree.h"

int32_t 
get_index_height(uint64_t index) {
	if (index < 0)
		return -1;
	int32_t height = 1;
	while ((index = (index << MAX_TREE_SLOT_BIT)) != 0) {
		++height;
	}

	return height;
}
struct radix_tree_root* 
radix_tree_init() {
    struct radix_tree_root* root;
    root = (struct radix_tree_root*)malloc(sizeof(struct radix_tree_root));
    root->root_node = (struct radix_tree_node *)malloc(sizeof(struct radix_tree_node));
    return root;
}

void* 
radix_tree_get(struct radix_tree_root* root, int64_t index) {
	struct radix_tree_node* node = root->root_node;
	int offset;
	do {	
		if (node == NULL)
			return NULL;
		offset = (~index) & RADIX_TREE_MASK;	
		if (node->slot[offset] == NULL && index!= 0)
			return NULL;
		if (index == 0)
			return node->data;
		node = node->slot[offset];
		index = index >> MAX_TREE_SLOT_BIT;
	} while (true);
}

int32_t 
radix_tree_set(struct radix_tree_root* root, int64_t index,void* item) {
	struct radix_tree_node* node = root->root_node;
	int offset;
	do {	
		if (index == 0) {
			node->data = item;
			return 0;
		}
		offset = (~index) & RADIX_TREE_MASK;	
		if (node->slot[offset] == NULL) {
			//TODO get a POOL!
			node->slot[offset] = (struct radix_tree_node*)malloc(sizeof(struct radix_tree_node));
		}
		node = node->slot[offset];
		index = index >> MAX_TREE_SLOT_BIT;
	} while (true);
}

int32_t radix_tree_delete(struct radix_tree_root* root, int64_t index) {
	struct radix_tree_node* node = root->root_node;
	int offset;
	do {	
		if (index == 0) {
			if (node->data == NULL)
				return -1;
			node->data = NULL;
			return 0;
		}
		offset = (~index) & RADIX_TREE_MASK;	
		if (node->slot[offset] == NULL) {
			return -1;
		}
		node = node->slot[offset];
		index = index >> MAX_TREE_SLOT_BIT;
	} while (true);
}
