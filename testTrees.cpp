#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "BSTTree.h"
#include "AVLTree.h"
#include <sys/time.h>

using namespace std;
void printData(double *array)
{
printf("First test case:\n");
printf("BST: %f\n",array[0]);
printf("AVL: %f\n",array[1]);
printf("Second test case:\n");
printf("BST: %f\n",array[2]);
printf("AVL: %f\n",array[3]);
printf("Third test case:\n");
printf("BST: %f\n",array[4]);
printf("AVL:%f\n",array[5]);
}

void shuffle(int array[], int size)
{
      	srand (time(NULL));


	int k = 0;
	int l = 0;
	for(k = 0; k < size; k++)
	{
		for(l = 0; l < size; l++)
		{
		if((array[k] == array[l]) && (l != k))
			printf("Duplicate found");
		}
	}

	int temporary;
        int randomNum;
        int last;
	int j = 0;
	int tmp;
        for(j = 0; j < size; j++)
        {
        randomNum = rand() % size;
	tmp = array[randomNum];
	array[randomNum] = array[j];
	array[j] = tmp;
	}
	
	//checking duplicates
	for(k = 0; k < size; k++)
	{
		for(l = 0; l < size; l++)
		{
		if((array[k] == array[l]) && (l != k))
			printf("Duplicate found");

		}

	}
		

}

int main(int argc, char *argv[])
{
	struct timeval start, end;
	long secs, usecs;
	double mtime;
	BSTTree *bst = new BSTTree();
	AVLTree *avl = new AVLTree();
	
	char buffer[256];

	int n1;
	if(argc == 1)
	{
		std::cin.getline(buffer, 256);
	        string input(buffer);
		std:cout <<"Enter a number, N, of integers: \n";
		n1 = (int)atoi(strtok(buffer,"\n"));
	}
	else
	{
		n1 = (int)atoi(argv[1]);


	}
	printf("Iterations: %d\n",n1);

	double timingNumber[6];
	
	int numArray[n1];
	int randInsertArr[n1];
	int randDeleteArr[n1];
	
	int i;
	for(i = 0; i < n1; i++)
	{
	numArray[i] = i ;
	}

	//first testcase
	//BST
	gettimeofday(&start,NULL);
	for(i = 0; i< n1; i++)
	{	
		if(bst->insertElement(i) == false)
			return -1;
	}
	for(i = 0; i <n1; i++)
	{
		if(bst->lookupElement(i) == false)
			return -1;
	}
	for(i = 0; i <n1; i++)
	{
		if(bst->deleteElement(i) == false)
			return -1;	
	}
	gettimeofday(&end,NULL);
	secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	timingNumber[0] = ((secs)*1000 + usecs/1000.0) + .5;
	printf("BSTTree after Test 1\n");
	bst->printTree();
	delete bst;
	bst = new BSTTree();
	//AVL
	gettimeofday(&start,NULL);
	for(i = 0; i< n1; i++)
        	if(avl->insertElement(i) == false)
			return -1;
        for(i = 0; i <n1; i++)
                if(avl->lookupElement(i) == false)
			return -1;
        for(i = 0; i <n1; i++)
                if(avl->deleteElement(i) == false)
			return -1;
	gettimeofday(&end, NULL);
	secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
        timingNumber[1] = ((secs)*1000 + usecs/1000.0) + .5;
	printf("AVLTree after Test 1\n");
	avl->printTree();
	delete avl;
	avl = new AVLTree();
	

	//secondtestcase
	gettimeofday(&start, NULL);
	for(i = 0; i<n1; i++)
	{
		if(bst->insertElement(i) == false)
			return -1;
	}

	for(i = n1 - 1; i>= 0; i--)
	{
		if(bst->lookupElement(i) == false)
			return -1;
	}

	for(i = n1 -1; i>= 0; i--)
	{
			
		if(bst->deleteElement(i) == false)
			return -1;
	}
	gettimeofday(&end, NULL);
        secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	timingNumber[2] = ((secs)*1000 + usecs/1000.0) + .5;
	printf("BSTTree after Test 2\n");
	bst->printTree();
	delete bst;
	bst = new BSTTree();



	gettimeofday(&start,NULL);
	for(i = 0; i<n1; i++)
	{
                if(avl->insertElement(i) == false)
			return -1;
        }
	for(i = n1 - 1; i>= 0; i--)
	{
                if(avl->lookupElement(i) == false)
			return -1;
	}
        for(i = n1 -1; i>= 0; i--)
	{
                if(avl->deleteElement(i) == false)
			return -1;
	}
	gettimeofday(&end, NULL);
        secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	timingNumber[3] = ((secs)*1000 + usecs/1000.0) + .5;
	printf("AVLTree after Test 2\n");
	avl->printTree();
	delete avl;
	avl = new AVLTree();

	shuffle(numArray, n1);
	for(i = 0; i < n1; i++)
		randInsertArr[i] = numArray[i];
	
	shuffle(numArray,n1);

	for(i = 0; i <n1; i++)
		randDeleteArr[i] = numArray[i];


	//thirdtestcase
	gettimeofday(&start, NULL);
	for(i = 0; i <n1; i++)
	{
		if(bst->insertElement(randInsertArr[i])== false)
			return -1;
	}
	for(i = 0; i < n1;i++)
		if(bst->lookupElement(randDeleteArr[i]) == false)
			return -1;
	for(i = 0; i < n1; i++)
		if(bst->deleteElement(randDeleteArr[i]) == false)
			return -1;
	gettimeofday(&end, NULL);
	secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	timingNumber[4] = ((secs)*1000 + usecs/1000.0) + .5;

	printf("BSTTree after Test 3\n");
	bst->printTree();

	gettimeofday(&start, NULL);
	for(i = 0; i < n1; i++)
	{

		if(avl->insertElement(randInsertArr[i]) == false)
			return -1;	
		
	}
	for(i = 0; i < n1; i++)
	{
		if(avl->lookupElement(randDeleteArr[i]) == false)
			return -1;
	}

	for(i = 0; i < n1; i++)
	{

		if(avl->deleteElement(randDeleteArr[i]) == false)
			return -1;

	}
	printf("AVLTree after Test 3\n");
	avl->printTree();
        gettimeofday(&end, NULL);
	secs  = end.tv_sec  - start.tv_sec;
	usecs = end.tv_usec - start.tv_usec;
	timingNumber[5] = ((secs)*1000 + usecs/1000.0) + .5;


	printData(timingNumber);	
	return 0;
}
