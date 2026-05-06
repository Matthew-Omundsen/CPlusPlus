// Name: Matthew Omundsen
// Date: 10/27/25
// Program description: Lab 6 - Bubble Sort

// bubble sort function, add counters for comparisons and swaps
// should receive a pointer to an array and be pass by reference
// lists passed should be size 10, 50, 200, and 1000
// then list of 100 in sorted, reverse, and random order
// paragraph explaining bubble sort and differences between the different lists

#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;

void bubblesort(int* &array, int size, int &swaps, int &comparisons); // function prototype
void print(int* array, int size); // function prototype

int main() {
    srand(time(0));  // seed the random number generator

    int swaps = 0;
    int comparisons = 0;

    int array1[10];
    int* ptr = array1;
    int size = sizeof(array1) / sizeof(array1[0]);
    for (int counter = 0; counter < size; counter++) {
        array1[counter] = rand() % 100 + 1; // random number between 1-100
    }
    cout << "\narray1 unsorted:" << endl;
    print(ptr, 10);
    bubblesort(ptr, size, swaps, comparisons);
    cout << "\narray1 sorted:" << endl;
    print(ptr, 10);
    cout << "Number of swaps: " << swaps << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    swaps = 0;
    comparisons = 0;
    int array2[50];
    ptr = array2;
    size = sizeof(array2) / sizeof(array2[0]);
    for (int counter = 0; counter < size; counter++) {
        array2[counter] = rand() % 100 + 1; // random number between 1-100
    }
    cout << "\narray2 unsorted:" << endl;
    print(ptr, 50); 
    bubblesort(ptr, size, swaps, comparisons);
    cout << "\narray2 sorted:" << endl;
    print(ptr, 50);
    cout << "Number of swaps: " << swaps << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    swaps = 0;
    comparisons = 0;
    int array3[200];
    ptr = array3;
    size = sizeof(array3) / sizeof(array3[0]);
    for (int counter = 0; counter < size; counter++) {
        array3[counter] = rand() % 100 + 1; // random number between 1-100
    }
    cout << "\narray3 unsorted:" << endl;
    print(ptr, 200);
    bubblesort(ptr, size, swaps, comparisons);
    cout << "\narray3 sorted:" << endl;
    print(ptr, 200);
    cout << "Number of swaps: " << swaps << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    swaps = 0;
    comparisons = 0;
    int array4[1000];
    ptr = array4;
    size = sizeof(array4) / sizeof(array4[0]);
    for (int counter = 0; counter < size; counter++) {
        array4[counter] = rand() % 100 + 1; // random number between 1-100
    }
    cout << "\narray4 unsorted:" << endl;
    print(ptr, 1000);
    bubblesort(ptr, size, swaps, comparisons);
    cout << "\narray4 sorted:" << endl;
    print(ptr, 1000);
    cout << "Number of swaps: " << swaps << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    //***************************************
    //ARRAY OF 100 PASSED IN 3 DIFFERENT WAYS
    //***************************************

    swaps = 0;
    comparisons = 0;
    int array5[100];
    ptr = array5;
    size = 100;
    for (int counter = 0; counter < 100; counter++) {
        array5[counter] = counter + 1; // 1-100 all in order in the array
    }
    cout << "\narray5 unsorted:" << endl;
    print(ptr, 100); 
    bubblesort(ptr, size, swaps, comparisons);
    cout << "\narray5 sorted:" << endl;
    print(ptr, 100);
    cout << "Number of swaps: " << swaps << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    swaps = 0;
    comparisons = 0;
    int array6[100];
    ptr = array6;
    for (int counter = 0; counter < 100; counter++) {
        array6[counter] = rand() % 100 + 1; // 1-100 all in random order
    }
    cout << "\narray6 unsorted:" << endl;
    print(ptr, 100);
    bubblesort(ptr, size, swaps, comparisons);
    cout << "\narray6 sorted:" << endl;
    print(ptr, 100);
    cout << "Number of swaps: " << swaps << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    swaps = 0;
    comparisons = 0;
    int array7[100];
    ptr = array7;
    for (int counter = 0; counter < 100; counter++) {
        array7[counter] = 100 - counter; // 1-100 all in reverse order
    }
    cout << "\narray7 unsorted:" << endl;
    print(ptr, 100);
    bubblesort(ptr, size, swaps, comparisons);
    cout << "\narray7 sorted:" << endl;
    print(ptr, 100);
    cout << "Number of swaps: " << swaps << endl;
    cout << "Number of comparisons: " << comparisons << endl;


}

void bubblesort(int* &array, int size, int &swaps, int &comparisons) { // function header
    int current = 0;
    for (current; current < size - 1; current++) {//outer loop runs once for each value in the array
        //inner loop runs less times for each iteration of outer loop depending on value of current
        for (int counter = 0; counter < size - current - 1; counter++) {
            comparisons++;
            if (array[counter] > array[counter + 1]) { // compares adjacent elements
            swap(array[counter], array[counter + 1]); // only swaps if the larger element is before the smaller element
            swaps++;
            }
        }
    } 
}
    
void print(int* array, int size) {
    for (int counter = 0; counter < size; counter++) {
        cout << array[counter] << " ";
    }
    cout << endl;
}

/* 
REFLECTION PARAGRAPH
I am so glad I got my bubblesort function to work for all of the arrays!
I learned that bubblesort will make the same number of comparisons for lists that are 
the same length, even if the numbers are in a different order before the sort. 
For example, arrays 5-7 all made 4950 comparisons, even though array5 was already in 
order before the sort. I predicted that array5 would make 0 swaps, and I was correct.
I also predicted that array7 would make as many swaps as comparisons, and I was right about 
that as well. I knew that since the numbers started in reverse order, a swap would need
to be made for every single comparison. I would be interested to learn the formula to predict 
exactly how many comparisons are made based on the size of the array. It seems to me 
that the number of swaps grows exponentially as the list gets larger and larger, which makes
sense, since bubblesort has a Big O of O(N^2).
*/




