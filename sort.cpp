#include "sort.h"
#include <fstream>

sort::sort(string txt)
{
	readToArray(txt);
}

sort::~sort(){}

void sort::selectionSort(double arr[], int n)
{
	int i;
  int j;
  int minIndex;
	double tmp;
	for ( i = 0; i < n - 1; i ++)
	{
		minIndex = i;
		for(j = i + 1;j < n; j ++) // goes through each index to see if the value to the right is bigger
		{
			if (arr[j] < arr[minIndex]) //if it is in fact bigger, swap them
			{
				minIndex = j;
			}
			if(minIndex != i) // checks that values are sorted
			{
				tmp = arr[i];
				arr[i] = arr[minIndex];
				arr[minIndex]=tmp;
			}
		}
	}
}

void sort::insertSort(double arr[])
{
	for (int j = 0; j < size; j ++)
	{
		double temp = arr[j]; //store marked item
		int k = j;
		while (k > 0 && arr[k-1] >= temp) //while value to the left is bigger, adjust
		{
			arr[k] = arr[k-1];
			k --;
		}
		arr[k] = temp;
	}
}

void sort::bubbleSort(double arr[])
{
	for (int i = 0; i < size; i ++)
	{
		int temp = 0;
		for (int j = 0; j < size; j ++)
		{
			if(arr[j] > arr[j + 1]) // compares the 2 numbers to the left and right of temp
			{
				temp = arr[j + 1]; // if the one on left is bigger, swap
				arr[j + 1] = arr[j]; //sifts
				arr[j] = temp;
			}
		}
	}
}

int sort::partition (double arr[], int low, int high)
{
    int pivot = arr[high];// pivot
    int i = (low - 1);//Location of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i ++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void sort::quickSort(double arr[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[p] is now at right place
        double pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sort::readToArray(string txt)
{

	ifstream file(txt);
	if (file) // checks to see if we are testing the correct file for numbers to sort
	{
		string line;
		getline(file,line); // the first line gives us the size of the array so we know how big to make it
		size = stoi(line);
		arr = new double[size];

		while (getline(file,line)) // loops through the rest of the file and puts the contents of the file into the game arrays (all of the X's and -'s')
		{
			for (int i = 0; i < size; i ++)
			{
				arr[i] = stod(line);
			}
		}
		file.close();
	}
}
