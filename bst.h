//
// <<Rayyan Khan>>
// U. of Illinois, Chicago
// CS 251: Fall 2019
//
// Contains the implementation of the Binary Search Tree Data Structure
// 
#pragma once

#include <iostream>
#include <algorithm>  // std::max
#include <fstream>
#include <string>

using namespace std;

template<typename TKey, typename TValue>
class binarysearchtree
{
private:
  struct NODE
  {
    TKey  Key;
		TValue Value;
    NODE* Left;
    NODE* Right;
  };

  NODE* Root;  // pointer to root node of tree (nullptr if empty)
  int   Size;  // # of nodes in the tree (0 if empty)

  // _inorder does the actual inorder traversal and output 
  // to console.  Each key is output to the console followed
  // by " ", including the last key.
  void _inorder(NODE* cur)
  {
     if (cur == nullptr)
       return;
     else
     {
        _inorder(cur->Left);
        cout << cur->Key << " \n";
        _inorder(cur->Right);
     }
  }
  
  int _height(NODE* cur) 
  {
    if (cur == NULL) {
       return -1; 
    }
    
    int Left = _height(cur->Left);
     
    int Right = _height(cur->Right);
     
    if (Left > Right) {
       return 1 + Left;
    }
     
    else {
       return 1 + Right;
    }
  }
	
	void _binarysearchtree(NODE* toCopy) {
		if (toCopy == NULL) {
			return;
		}
		
		insert(toCopy->Key, toCopy->Value);
		_binarysearchtree(toCopy->Left);
		_binarysearchtree(toCopy->Right);
	}

public:
  
  // default constructor:
  binarysearchtree()
  {
    Root = nullptr;
    Size = 0;
  }


	// copy constructor:
	binarysearchtree(binarysearchtree& other) {
		
		Root = NULL;
		Size = 0;
		_binarysearchtree(other.Root);
	}


  // Returns the # of nodes in the tree, 0 if empty.
  int size()
  {
    return Size;
  }


  // Computes and returns height of tree; height of an empty tree is
  // defined as -1.
	int height()
	{
	 return _height(Root);
	}


  // Searches the tree for the given key, returning true if found
  // and false if not.
  TValue* search(TKey key)
  {
    NODE* cur = Root;

    while (cur != nullptr)
    {
      if (key == cur->Key)  // already in tree
        return &(cur->Value);

      if (key < cur->Key)  // search left:
      {
        cur = cur->Left;
      }
      else
      {
        cur = cur->Right;
      }
    }//while  
		
    return NULL;
  }


  // Inserts the given key into the tree; if the key has already been insert then
  // the function returns without changing the tree.
  void insert(TKey key, TValue Value)
  {
    NODE* prev = nullptr;
    NODE* cur = Root;

    while (cur != nullptr)
    {
      if (key == cur->Key)  // already in tree
        return;

      if (key < cur->Key)  // search left:
      {
        prev = cur;
        cur = cur->Left;
      }
      else
      {
        prev = cur;
        cur = cur->Right;
      }
    }//while

    NODE* insertNode = new NODE;
    insertNode->Key = key;
		insertNode->Value = Value;
    insertNode->Left = NULL;
    insertNode->Right = NULL;

    if (prev == NULL) {
       Root = insertNode;
    }
    else {
       if (key < prev->Key) {
         prev->Left = insertNode;
       }
      
       else {
         prev->Right = insertNode;
       }
    }
       
    Size++;
  }


  // Performs an inorder traversal of the tree, outputting
  // the keys to the console.
  void inorder()
  {
     cout << "Inorder: ";
     
     _inorder(Root);
     
     cout << endl;
  }
};
