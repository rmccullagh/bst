/*
 * Copyright 2015, Ryan McCullagh <me@ryanmccullagh.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author
 *     Ryan McCullagh <me@ryanmccullagh.com>
 */

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
