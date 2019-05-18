#include <iostream>
#include <fstream>
#include <ctime>
#include<string>
#ifndef SORTS_H
#define SORTS_H

using namespace std;

class sorts{
public:
  double myArray[10000];
  int numValues;

  int createList(string fileName);
  void quickSort(string fileName, int beg, int end);
  void quickSort2(int beg, int end);
  void insertionSort(string fileName);
  void bubbleSort(string fileName);
  void selectionSort(string fileName);
  int getLength();
  int partition(int beg, int end);
  double fRand(double fMin, double fMax);
  void makeAList();
};
#endif
