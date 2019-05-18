#include "sort.h"
#include <fstream>
#include<string>
#include <iostream>
#include <ctime> //http://www.codebind.com/cpp-tutorial/cpp-program-display-current-date-time/
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		time_t t = time(NULL);
  	tm* timePtr = localtime(&t);

		sort op = sort(argv[1]);

		cout << "\n" << "Bubble Sort" << endl;
		cout << "Starts @: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
		op.bubbleSort(op.arr);
		cout << "Ends @: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec)<< endl;

		cout << "\n" << "Insertion Sort" << endl;
		cout << "Starts @: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
		op.insertSort(op.arr);
		cout << "Ends @: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec)<< endl;

		cout << "\n" << "Quick Sort" << endl;
		cout << "Starts @: " <<(timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
		op.quickSort(op.arr, op.arr[0], op.arr[0]);
		cout << "Ends @: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec)<<endl;

		cout << "\n" << "Selection Sort" << endl;
		cout << "Starts @: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
		op.selectionSort(op.arr, op.arr[0]);
		cout << "Ends @: " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec)<<endl;
	}
	return 0;
}
