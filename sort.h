#include <iostream>
using namespace std;
class sort
{
public:
  sort(string txt);
  ~sort();

  void insertSort(double arr[]);
  void selectionSort(double arr[], int n);
  void bubbleSort(double arr[]);
  void quickSort(double arr[], int low, int high);
  int partition(double arr[], int low, int high);
  
  void readToArray(string txt);
  double * arr;
  int size;
};
