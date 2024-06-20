# Binary-B-trees
Project Name: Binarne B-drzewa
Author: Alicja Kowalska
Description
The "Binarne B-drzewa" project implements a binary search tree (BST) in C++. This project provides fundamental operations for managing a BST, including inserting, searching, deleting, and displaying nodes. Each node in the tree contains an integer key and pointers to its left and right children, ensuring efficient data organization and manipulation.

Features
Insertion (wstaw): Adds a new key to the tree, maintaining the BST property.
Search (szukaj): Locates a key in the tree and returns its position and level.
Deletion (usun): Removes a key from the tree while keeping the BST properties intact.
Display (wyswietl): Outputs the tree structure in a readable format for easy visualization.
Code Structure
Wezel Struct: Represents a node in the tree with a key and pointers to left and right children.
BinarneDrzewo Class: Encapsulates the entire BST and provides methods for insertion, search, deletion, and display.
Private Helper Functions:
wstawPomocniczo: Recursively inserts a key.
szukajPomocniczo: Recursively searches for a key and tracks its position.
usunPomocniczo: Recursively deletes a key.
znajdzMinimum: Finds the minimum key in a subtree.
wyswietlPomocniczo and drukujDrzewo: Assist in displaying the tree structure.
Usage
Compile the Code:
g++ -o binarne_b_drziwa binarne_b_drziwa.cpp
Run the Program:
./binarne_b_drziwa
Menu Options:
1. Wstaw: Insert a key into the BST.
2. Szukaj: Search for a key in the BST.
3. Usuń: Delete a key from the BST.
4. Wyświetl: Display the entire BST structure.
5. Wyjście: Exit the program.

Detailed Functionality
Insertion:
Adds new nodes while ensuring the tree remains sorted.
If the tree is empty, the new key becomes the root.
Recursively finds the correct position for the new key.
Search:
Traverses the tree to find a specific key.
Tracks the level and parent node of the key for detailed output.
Returns whether the key was found and its position in the tree.
Deletion:
Removes a node while maintaining the BST properties.
Handles cases where the node has zero, one, or two children.
Replaces the deleted node with the appropriate child or subtree.
Display:
Visually represents the tree structure using indentation.
Recursively prints the nodes in a structured format.
