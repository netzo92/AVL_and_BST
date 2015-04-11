#include <iostream>
#include <string.h>
#include "BSTTree.h"

using namespace std;

int main(int argc, char *argv[])
{
	BSTTree *tree = new BSTTree();
	//std::cout << "program start\n";

	while(1)
	{
		// std::cout << "loop start\n";

		char buffer[256];
		std::cin.getline(buffer, 256);
		string input(buffer);

		//terminate
		if(cin.eof())
		{
		//	std::cout << "terminate\n";
			break;
		}

		//insert
		if(input.compare(0,6,"insert") == 0)
		{
			// std::cout << "input is insert\n";
			strtok(buffer, " ");
		  int numToInsert = (int)atoi(strtok(NULL,"\n"));	

			bool inserted = tree->insertElement(numToInsert);
			//if(inserted == false)
                          //      cout << "Empty Tree\n";
                        if(inserted == true)
				cout << "Element inserted\n";
			else				cout << "Element already present\n";	
		}

		//lookup
		else if(input.compare(0,6,"access") == 0)
		{
			// std::cout << "input is lookup\n";
			strtok(buffer, " ");
		  int numToLookup = (int)atoi(strtok(NULL,"\n"));		
		  //	std::cout << "num to lookup is " << numToLookup << "\n";
			bool numFound = tree->lookupElement(numToLookup);
			if(numFound == true)
				cout << "Element accessed\n";
			else
				cout << "Element not found\n";			
		}

		//print
		else if(input.compare("print") == 0)
		{
			// std::cout << "input is print\n";
			tree->printTree();
		}

		//delete 
		else if(input.compare(0,7,"delete ") == 0)
		{
			// std::cout << "input is delete\n";
			strtok(buffer, " ");
			int numToDelete = (int)atoi(strtok(NULL,"\n"));
			bool deleted = tree->deleteElement(numToDelete);
			if(deleted == true)
				cout << "Element deleted\n";
			else
				cout << "Element not found\n";
		}
		
		//other inputs - make user reenter input
		else
		{
			std::cout << "invalid input\n";
		}

	}
	return 0;
}
