#include <stdio.h>

int search(int numbers[], int low, int high, int value)
{
    if(numbers == NULL){ //checks array existence
        printf("Array is empty!");
        return -1;
    }
	int middle = (low+high)/2; //establishes a middle (value between low and high)



	if(value == numbers[middle]) //if the target value so happens to be right in the middle, it is returned
        return middle;

    if(low+1 == high){ //if low and high end up next to each other, check each number individually
        if(value == low){
            while(numbers[low-1]==numbers[low] ) //if there are repeats, this will ensure the index of the FIRST occurance is printed
                low--;
            return low;
        }

        else if(value == high){
            while(numbers[high-1]==numbers[high] ) //if there are repeats, this will ensure the index of the FIRST occurance is printed
                high--;
            return high;
        }
        else
            return -1;
    }

    if(value < numbers[middle]) //if the middle is higher than the value, recurse in the lower half of the current dataset
        return search(numbers,low,middle,value);

    if(value > numbers[middle])
        return search(numbers,middle,high,value);//if the middle is lower than the value, recurse in the upper half of the current dataset

}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}
