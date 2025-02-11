#include <iostream>
#include <array>


// Creates & returns a pointer to a manually created array.
// The array stays even after the function closes.
float* arraySize(int& arrSize)
{
  while(arrSize <= 0)
  {
    std::cout << "Please enter the number of test scores: \n";
    std::cin >> arrSize;
    
    if(arrSize <= 0)
    {
      std::cout << "Please enter a positive number!\n";
    }
  }


  return new float [arrSize];
}


// Fills the array with desired scores
float arrayFiller(float *array, int arrSize)
{
  std::cout << "Enter each score, then hit enter: \n";
  
  float userInput;
  float scoreSums = 0.0;

  for (int i = 0; i < arrSize; i++)
  {
    std::cin >> userInput;
    array[i] = userInput;

    scoreSums += userInput;
    std::cout << "\n";
  }
  
  return scoreSums;
}


// Bubble Sorts the array. 
void arraySorter(float *array, int arrSize)
{
  for(int i = 0; i < arrSize - 1; i++)
  {
    for(int j = 0; j < arrSize - i - 1; j++)
    {
      if(array[j] > array[j + 1])
      {
        float placeHold = array[j];
        array[j] = array[j+1];
        array[j+1] = placeHold;
      }
    }
  }

}


// Neatly prints out avg's, both curved and not curved.
void arrayPrinter(float *array, int arrSize)
{
  std::cout << "The sorted scores are: \n";
  
  for(int i = 0; i < arrSize; i++)
  {
    std::cout << array[i] << std::endl;
  }
}



// Calculates AND prints averages of user input.
void avgPrinter(float *array, int arrSize, float totalScore)
{
  // Pre-curve
  float normAvg = totalScore / arrSize;
  
  //Post curve
  float curveAvg = (totalScore - array[0]) / (arrSize - 1);

  std::cout << "The average before curve: " << normAvg << "\n";
  std::cout << "The average after curve: " << curveAvg << "\n";
}


// Main function, every cpp program needs one
int main ()
{
  // Variable for ease of access
  int arrSize = 0;


  // We have defined an array in memory but need a pointer to
  // access it
  float *array = arraySize(arrSize);

  // Variable was easier than doing many pass by references.
  float totalScore = arrayFiller(array, arrSize);

  arraySorter(array, arrSize);

  avgPrinter(array, arrSize, totalScore);
  arrayPrinter(array, arrSize);

  // Clears the memory allocated for the array. 
  delete[] array;
}
