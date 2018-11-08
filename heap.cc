#pragma once

#include "heap.hh"



Heap::Heap(trees_t trees)
{
	tree_list = trees;
	build_heap();
}

void Heap::build_heap()
{
	//call heapify for all nodes starting at trees.size/2 - 1
	for(int i = tree_list.size/2-1; i>=0; i--)
	{
		heapify(i);
	}
}

void Heap::heapify(int node)
{
	int left = 2*node;
	int right = 2*node + 1;

	int largest = node;

	if (left <= tree_list && tree_list[left]->key_ > tree_list[largest]->key_)
	{
		largest = left;
	}
	
	if (right <= tree_list && tree_list[right]->key_ > tree_list[largest]->key_)
	{
		largest = right;
	}

	if (tree_list[largest] != largest[i])
	{
		std::swap(tree_list[largest], largest[i]);
		heapify(largest);
	}
}

int Heap::size() const
{
	return tree_list.size();
}

void Heap::add_tree(tree_ptr_t tree)
{
	tree_list.insert(tree_list.begin(), tree);
	heapify(0);
}

Heap::tree_ptr_t Heap::pop_tree()
{
	return tree_list[0];
}
