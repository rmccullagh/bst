#include "../bst.h"
#include <assert.h>

int main()
{
        Node* root = NULL;

        binary_search_tree_insert(&root, 4);
        binary_search_tree_insert(&root, 1);
        binary_search_tree_insert(&root, 0);
        binary_search_tree_insert(&root, 2);
        binary_search_tree_insert(&root, -2);
        binary_search_tree_insert(&root, -4);

	int* found = NULL;
	
	binary_search_tree_search(root, 4, &found);
	assert(*found == 4);
	
	binary_search_tree_search(root, 1, &found);
	assert(*found == 1);
	
	binary_search_tree_search(root, 0, &found);
	assert(*found == 0);

	binary_search_tree_search(root, 2, &found);
	assert(*found == 2);
	
	binary_search_tree_search(root, -2, &found);
	assert(*found == -2);

	binary_search_tree_search(root, -4, &found);
	assert(*found == -4);

	binary_search_tree_search(root, -444, &found);
	assert(*found != -444);
	
	binary_search_tree_free(&root);

	return 0;
}
