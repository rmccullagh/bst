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

#include "bst.h"

static Node* __bst_new_node(int, Node*, Node*);

/* PRIVATE */
static Node* __bst_new_node(int data, Node* left, Node* right)
{
	Node* node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->left = left;
	node->right = right;
	return node;
}

static void __bst_insert(Node**, int);

static void __bst_insert(Node** node, int data)
{
	if(*node == NULL) {
		*node = __bst_new_node(data, NULL, NULL);	
	} else {
		if(data == (*node)->data) {
			return;
		}
		else if(data <= (*node)->data) {
			__bst_insert( &((*node)->left), data);
		} else {
			__bst_insert( &((*node)->right), data);
		}			
	}
}

void binary_search_tree_insert(Node** root, int value)
{
	__bst_insert(root, value);
}


static size_t __bst_size(Node*);

static size_t __bst_size(Node* node)
{
	if(node == NULL) {
		return 0;
	} else {
		return __bst_size(node->left) + 1 + __bst_size(node->right);
	}
}


size_t binary_search_tree_size(Node* root)
{

	return __bst_size(root);
}

void binary_search_tree_traverse_in_order(Node* node, traversal_cb cb)
{	
	if(node == NULL) {
		return;
	}

	binary_search_tree_traverse_in_order(node->left, cb);
	cb(node->data);
	binary_search_tree_traverse_in_order(node->right, cb);
}

static void __bst_free(Node**);
static void __bst_free(Node** node)
{
	if(*node == NULL) {
		return;
	}
	__bst_free(&((*node)->left));
	__bst_free(&((*node)->right));
	
	free(*node);
	*node = NULL;
}

void binary_search_tree_free(Node** node)
{
	__bst_free(node);
}

static int __bst_min_value(Node*);
static int __bst_min_value(Node* root)
{
	Node* node = root->left;
	while(node->left != NULL) {
		node = node->left;
	}
	return node->data;
}

int bst_min_value(Node* root)
{
	return __bst_min_value(root);
}
