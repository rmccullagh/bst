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

#ifndef __BST_H__
#define __BST_H__

#include "node.h"
#include "config.h"

typedef void(*traversal_cb)(int data);

void binary_search_tree_insert(Node**, int);

size_t binary_search_tree_size(Node*);

void binary_search_tree_traverse_in_order(Node*, traversal_cb);

int bst_min_value(Node*);

void binary_search_tree_free(Node**);

void binary_search_tree_search(Node*, int, int**);

#endif /* __BST_H__ */
