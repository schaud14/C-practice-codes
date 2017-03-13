	CS580U
	Lab-6

	Saurabh Abhay Chaudhari

	----Instruction to Run the code:
	
	1.Extract: 	tar -xvf Saurabh-Chaudhari-lab6.tar.gz
	2.Nevigate:	cd lab6
	3.Compile:	make compile
	4.Run:		valgrind ./lab6
	5.Clean: 	make clean


	Main Menu:
	1.Vectors
	2.Linked List
	3.Stack and Queue
	4.Exit


	---------Testing Vectors (option 1 in main menu):

	Index Starts from 0.

	Option 1 will give time for inserting 10000 items to a vector in incremental manner and uopn exiting will free the vector.(about 100001 mallocs)

	Option 2 will give time for inserting 10000 items to a vector in Geometric manner and upon exiting will free the vector.(about 16 mallocs)

	Option 3 will create a new vector with 20 elements at first time only and will display the same.

	Option 4 will ask you a index to be removed and will make it to 0. again selecting option 3 will display the same vector created in option 3 with updation done in option 4.
			(to test option 4 you will have to choose option 3 first to create the vector).

	Option 5 will free the vector created in option 3 and take you back to previous menu.



	---------Testing linked List (option 2 in main menu):

	Index Starts from 1.

	Option 1 will ask you to enter a index at which node to be inserted then the data value of the node and upon inserting the node, it will display the updated list

	Option 2 will ask you to enter a index of which node to be deleted and upon deleting the node, it will display the updated list.

	Option 3 will print the value of first node in the list.

	option 4 will ask you to data to be searched in the linked list upon successful search it will give the node at which data is present and how many iterations it took to search the data.
			 (This will give results of both forward and backward seach).

	Option 5 will take you back to main menu and will clear the linked list by calling the deletelist Function.



	---------Testing Stack and Queue (option 3 in main menu):

	Option 1 will ask you to enter the 5 elements and will push them into stack, and will pop them out one by one to get the reversed ordered elements (LIFO).

	Option 2 will ask you to enter the 5 elements and will enqueue them into queue, and will dequeue them out one by one to get the ordered elements (FIFO).


	--------Exit (option 4 in main menu):

	This will exit the program and will display the memory stats while running with valgrind.