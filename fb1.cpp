#include <string>
#include <iostream>

using namespace std;

// Add any helper functions you may need here+

char Offset(int type, char offsetChar, int rotationFactor) {
  int move = 0;
  int result;
  switch(type) {
      case 1:
        move = rotationFactor % 10;
        result = offsetChar + move;
        if (result > 57) {
            result = result - 10;
        }
        break;
      case 2:
        move = rotationFactor % 26;
        result = offsetChar + move;
        if (result > 90) {
            result = result - 26;
        }
        break;
      case 3:
        move = rotationFactor % 26;
        result = offsetChar + move;
        if (result > 122) {
            result = result - 26;
        }
        break;
      case 0:
        result = offsetChar;
        break; 
    }
    cout << offsetChar << " " << move << " " << result << "\n";
    return result;
}

int isAlphanumeric(char input) {
  if (input > 47 && input < 58) {
    return 1; // returns interger 1 if it is a number.
  }
  if (input > 64 && input < 91) {
    return 2; // returns interger 2 if it is a capital letter.
  }
  if (input > 96 && input < 123) {
    return 3; // return interger 3 if it is a lowercase letter.
  }
  return 0; //in case it's not an alphanumeric character.
}

string rotationalCipher(string input, int rotationFactor) {
  string cipherResult = "";
  char cipheredChar;
  for(int nCharacter = 0; nCharacter < input.length(); nCharacter++) {
    int type = isAlphanumeric(input[nCharacter]);
    cipherResult.push_back(Offset(type, input[nCharacter], rotationFactor));
  }
  return cipherResult;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(string& expected, string& output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printString(expected); 
    cout << " Your output: ";
    printString(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string input_1 = "All-convoYs-9-be:Alert1.";
  int rotationFactor_1 = 4;
  string expected_1 = "Epp-gsrzsCw-3-fi:Epivx5.";
  string output_1 = rotationalCipher(input_1, rotationFactor_1);
  check(expected_1, output_1);

  string input_2 = "abcdZXYzxy-999.@";
  int rotationFactor_2 = 200;
  string expected_2 = "stuvRPQrpq-999.@";
  string output_2 = rotationalCipher(input_2, rotationFactor_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}