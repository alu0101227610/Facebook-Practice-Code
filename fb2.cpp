#include <iostream>
 #include <vector>
// Add any extra import statements you may need here

using namespace std;

vector<int> CountSubarrays(vector <int> arr) {
  // Write your code here
  vector<int> output(arr.size(), 1);
  for (int index = 0; index < arr.size(); index++) {
      int maxValue = arr[index];
      int currentIndex = index;
      while (currentIndex >0) {
          if (arr[currentIndex-1] < maxValue) {
              currentIndex -= 1;
              output[index]++;
          } else break;
      }
      currentIndex = index;
      while (currentIndex < arr.size()-1) {
          if (arr[currentIndex+1] < maxValue) {
              currentIndex += 1;
              output[index]++;
          } else break;
      }
  }
  return output;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  vector <int> test_1{3, 4, 1, 6, 2};
  vector <int> expected_1{1, 3, 1, 5, 1};
  vector <int> output_1 = CountSubarrays(test_1);
  check(expected_1, output_1);

  vector <int> test_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{1, 2, 6, 1, 3, 1};
  vector <int> output_2 = CountSubarrays(test_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
} 