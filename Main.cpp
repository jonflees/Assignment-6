#include "Sorts.h"

using namespace std;

int main(int argc, char** argv) {
  if(argc > 1) {
    string fileName = argv[1];
    double t1, t2;

    sorts s1;

    //s1.makeAList();  //uncomment to random generate doubles then the program will sort that list
    int nL = s1.createList(fileName)-1;

    t1 = clock();
    s1.bubbleSort(fileName);
    t2 = clock();
    cout << "Bubble Sort: " << (t2 - t1)/CLOCKS_PER_SEC << " sec" << endl;


    t1 = clock();
    s1.insertionSort(fileName);
    t2 = clock();
    cout << "Insertion Sort: " << (t2 - t1)/CLOCKS_PER_SEC << " sec" << endl;


    t1 = clock();
    s1.selectionSort(fileName);
    t2 = clock();
    cout << "Selection Sort: " << (t2 - t1)/CLOCKS_PER_SEC << " sec" << endl;


    t1 = clock();
    s1.quickSort(fileName, 0, nL-1);
    t2 = clock();
    cout << "Quick Sort: " << (t2 - t1)/CLOCKS_PER_SEC << " sec" << endl;
}
  else {
    cout << "No file entered on command line!" << endl;
  }
  return 0;
}
