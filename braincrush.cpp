#define MEMORY_NUMBER 20
#define IS_CRUSH true
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
  int ptr = 0;
  vector<char> memory(MEMORY_NUMBER, 0);
  vector<char> hello = {72, 101, 108, 108, 111, 44, 32,
                        119, 111, 114, 108, 100, 33};

  // BrainCrushの場合、初期化時にメモリにHello, world!を入れておく
  if (IS_CRUSH) {
    for (int i = 0; i < 13; i++) {
      memory.at(i) = hello.at(i);
    }
  }

  string prog;
  getline(cin, prog);

  // BrainCrushの場合、終了時に[.>]が実行される
  if (IS_CRUSH) {
    prog += "[.>]";
  }

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
      // 以下、BrainCrushで追加された命令(and, or, not, xor)
      case '|':
        ptr++;
        memory.at(ptr) = memory.at(ptr) | memory.at(ptr-1);
        break;
      case '&':
        ptr++;
        memory.at(ptr) = memory.at(ptr) & memory.at(ptr-1);
        break;
      case '~':
        memory.at(ptr) = ~memory.at(ptr);
        break;
      case '^':
        ptr++;
        memory.at(ptr) = memory.at(ptr) ^ memory.at(ptr-1);
        break;
      default:
        break;
    }
  }

 
  cout << endl << "[END OF RUNNING]" << endl;
}