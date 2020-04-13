//============================================================================
// Name        : memOF.cpp
// Author      : Andreas Howes
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>

/*Uncomment the line below to test un-allocated pointer*/
//	#define TEST_UNALLOCATED

using namespace std;

//simulates the i2c_read_function that adds data to a buffer
void testFun(uint8_t *test, int size){
    printf("The value of argument uint8_t *test is: %p\n", test);

    for(int i=0; i<size; i++){
        test[i]=(i+1)*10;
        printf("Adding to memory address::0x%p = value: %d\n", (void*)&test[i],test[i]);
    }
    printf("The memory location of uint8_t *test is: %p\n", &test);
}


int main()
{
    cout<<"Pointers C/C++"<<endl;

    cout << endl <<"EXAMPLE 1: Correct use of the function, passing a pointer to a declared array" << endl;

    /* EXAMPLE 1: Correct usage with array */
    uint8_t arr[5];
    printf("arr memory address: %p\n", arr);
    testFun(arr, 5);
    for(int i=0; i<5; i++)
    	printf("Content of arr[%d]: %d\n", i, arr[i]);
    /* END OF EXAMPLE 1*/


    /* EXAMPLE 2: Incorrect usage by passing an unsigned int reference and a size to read*/
    cout << endl <<"EXAMPLE 2: Incorrect use of the function passing a pointer to an unsigned int" << endl;
    uint8_t notArr;
    printf("notArr memory address: 0x%p\n", (void*)&notArr);
    testFun(&notArr, 5);
    printf("Content of notArr: %d\n\n", notArr);
    /*END OF EXAMPLE 2*/


    /* EXAMPLE 3: USING AN UN-ALLOCATED POINTER - Execution hangs, that is why its not enabled */
    cout << endl <<"EXAMPLE 3: Incorrect use of the function passing an un-allocated pointer"<< endl;
#ifdef TEST_UNALLOCATED
	uint8_t *myPointer;
	printf("myPointer memory address: 0x%p\n", myPointer);
	testFun(myPointer, 5);
	for(int i=0; i<5; i++)
			printf("Content of arr[%d]: %d\n", i, myPointer[i]);
#else
	cout << "WARNING: Un-allocated pointed example not enabled!! Use #define TEST_UNALLOCATED to enable. " << endl;
#endif
	/* END OF EXAMPLE 3*/

	/* EXAMPLE 4: Correct use of a pointer with malloc */
	cout << endl <<"EXAMPLE 4: Correct usage of pointer that has memory allocated using malloc" << endl;
	uint8_t *myAllocatedPointer;
	myAllocatedPointer = (uint8_t*)malloc((sizeof(uint8_t))*5);
	printf("myPointer memory address: 0x%p\n", myAllocatedPointer);
	testFun(myAllocatedPointer, 5);
	for(int i=0; i<5; i++)
			printf("Content of myAllocatedPointer[%d]: %d\n", i, myAllocatedPointer[i]);
	/* END OF EXAMPLE 4 */

    cout << endl << "Everything works perfectly fine so far right? Perfect. "<< endl;
    cout << "Trying to use the array 'arr' data... " << endl;
    for(int i=0; i<5; i++){
    	if(arr[i] != (i+1)*10){
    		printf("Content of arr[%d]: %d <-- Unexpected value!!\n", i, arr[i]);
    	}else{
    		printf("Content of arr[%d]: %d <-- Expected value. \n", i, arr[i]);
    	}
    }
    cout << endl << "Result of incorrect use of pointer: changed an array that happened to be placed after the 'notArr' variable in RAM memory " << endl;

    return 0;
}
