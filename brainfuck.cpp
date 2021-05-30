#define MEMORY_NUMBER 20
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
  int ptr = 0;
  vector<char> memory(MEMORY_NUMBER, 0);
  
  string prog;
  getline(cin, prog);

  char c;
  int endParenthesis = -1;
  stack<int> frontParenthesis;
  
  for (int i = 0; i < prog.length(); i++) {
    c = prog.at(i);

    switch (c) {
      case '>':
        ptr++;
        break;
      case '<':
        ptr--;
        break;
      case '+':
        memory.at(ptr)++;
        break;
      case '-':
        memory.at(ptr)--;
        break;
      case '.':
        cout << memory.at(ptr);
        break;
      case ',':
        cin >> memory.at(ptr);
        break;
      case '[':
        if (memory.at(ptr) == 0) i = endParenthesis - 1;
        frontParenthesis.push(i);
        break;
      case ']':
        endParenthesis = i;
        if (memory.at(ptr) != 0) i = frontParenthesis.top() - 1;
        frontParenthesis.pop();
        break;
      default:
        break;
    }
  }
 
  cout << endl << "[END OF RUNNING]" << endl;
}

