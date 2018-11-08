#pragma once

#include <vector>
#include "htree.cc"

class Heap {
 public:
	 using tree_ptr_t = std::shared_ptr<const HTree>;
	 using trees_t = std::vector<tree_ptr_t>;
	
	 // take a vector of htree pointers and construct a heap class
	 Heap(trees_t trees);
	 ~Heap();

	 // return size of heap, const function
	 int size() const;

	 // take one tree and add it to the vector
	 void add_tree(tree_ptr_t tree);

	 //returns the tree with the greatest value
	 tree_ptr_t pop_tree();

 private:
	 trees_t tree_list;
	 void build_heap();
	 void heapify(int node);
}

