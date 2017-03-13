CS580U
Lab-7

Saurabh Abhay Chaudhari

----Instruction to Run the code:

1.Extract: 	tar -xvf Saurabh-Chaudhari-lab7.tar.gz
2.Nevigate:	cd Saurabh-Chaudhari-lab7
3.Compile:	make
4.Run:		valgrind ./lab7
5.Clean: 	make clean

Note: make sure "data.txt" as input is present current directory.

Main Menu:
1. Create Tree
2. Insert Node
3. Travarsal
4. Delete Node
5. Search Node
6. Delete Tree and Exit

--------- Testing ----------

Option 1 (in Main Menu) : 
	
	This will create a binary tree using data.txt as input file.

Option 2 (in Main Menu) : 
	This will prompt for value to be inserted in Binary Tree, and if value is not present it will insert it into binary tree 
	or if value is already present it will convey the same.

Option 3 (in Main Menu) : 
	It will ask user to select choice for type of traversal of tree, upon selecting it will print tree in traversal sequence.

Option 4 (in Main Menu) : 
	This will ask user to enter the value of node to be deleted. If value is present it will delete the node. 

Option 5 (in Main Menu) : 
	This will ask user for value to be searched in binary tree, if the node with entered value is present it will
	print the values of parent and both child nodes.

Option 6 (in Main Menu) : 
	This will delete the binary tree and exit the program also it will display the memory stats while running with valgrind.