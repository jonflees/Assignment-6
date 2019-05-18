#include "Sorts.h"

int sorts::createList(string fileName){

  //cout << "Reading file..." << endl;

  double aValue=1.0;
  ifstream file_(fileName);
  string line;
  size_t sz = 0;
  int numLines=0;
  while(getline(file_,line)) {
    //cout << line << endl;
    if (numLines==0){
      int hi = stoi(line);
      double myArray[hi];
      }
    else{
      double val = stod(line);
      myArray[numLines-1] = val;
      }
      numLines++;
  }
  for (int i=0; i<numLines-1; i++){
    //cout << myArray[i] << endl;
  }
  file_.close();
  return numLines;
}


void sorts::quickSort(string fileName, int beg, int end){
  int nV = createList(fileName)-1;
  cout << "QuickSort..." << endl;
  if (beg < end)
  {
      int pivot = partition(beg, end);
      quickSort2(beg, pivot-1);
      quickSort2(pivot+1, end);
  }
  /*for (int k = 0; k < nV; k++){
      cout << myArray[k] << " ";
  }
  cout << endl;*/  //lots of numbers to screen
}
void sorts::quickSort2(int beg, int end){
  if (beg < end)
  {
      int pivot = partition(beg, end);
      quickSort2(beg, pivot-1);
      quickSort2(pivot+1, end);
  }
}

void sorts::insertionSort(string fileName){
  int mV = createList(fileName)-1;
  cout << "InsertionSort..." << endl;
  double temp;
  for(int i = 1; i < mV; i++) {
      temp = myArray[i];
      int j;
      for(j = i-1; j >= 0 && myArray[j] > temp; j--) {
          myArray[j+1] = myArray[j];
      }
      myArray[j+1] = temp;
  }
  /*for (int k = 0; k < mV; k++)
    cout << myArray[k] << " ";
  cout << endl;*/  //Lots of numbers displayed
}

void sorts::bubbleSort(string fileName){
  int qV = createList(fileName)-1;
  cout << "BubbleSort..." << endl;
  double temp;
  for(int i = 0; i < qV; i++) {
      for(int j = 0; j < qV-i-1; j++) {
          if (myArray[j] > myArray[j+1]) {
            temp = myArray[j+1];
            myArray[j+1] = myArray[j];
            myArray[j] = temp;
          }
      }
  }
  /*for(int k = 0; k < qV; k++)
    cout << myArray[k] << " ";
  cout << endl; */  //Don't want to see for lots of numbers
}

void sorts::selectionSort(string fileName){
  int dV = createList(fileName)-1;
  cout << "SelectionSort..." << endl;
  double temp2;
  double tempArray[dV];
  for (int i = 0; i < dV-1; i++){
    int min = i;
    for(int j = i+1; j < dV; j++){
      if(myArray[j] < myArray[min])
        min = j;
    }
    temp2 = myArray[i];
    myArray[i] = myArray[min];
    myArray[min] = temp2;
  }
  /*for(int k = 0; k < dV; k++)
    cout << myArray[k] << " ";
  cout << endl; */  //Overflow of numbers on screen with large data set
}



int sorts::partition(int beg, int end){
  double pivot_element = myArray[beg];
  int absoluteBeg = beg;
  double temp;

  while(beg < end){
      while(myArray[beg] <= pivot_element)
          beg++;
      while(myArray[end] > pivot_element)
          end--;
      if (beg < end) {
          temp = myArray[beg];
          myArray[beg] = myArray[end];
          myArray[end] = temp;
          }
    }
  myArray[absoluteBeg] = myArray[end];
  myArray[end] = pivot_element;
  return end;
}


double sorts::fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void sorts::makeAList(){
  ofstream file_;
  file_.open("RandoDubs.txt");
  int numRandos = 10000;
  for (int i=0; i<numRandos+1; i++){
      if (i==0){
        file_ << numRandos << endl;
      }
      else{
      file_ << fRand(0.1, 99.9) << endl;
    }
  }
}
