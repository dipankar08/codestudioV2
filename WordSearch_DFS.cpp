/***************************************************
 * Title : Word Serach using DFS
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void Lowercase(vector<vector<char>> &board, int i, int j) {
  board[i][j] = board[i][j] + ('a' - 'A');
}
void Uppercase(vector<vector<char>> &board, int i, int j) {
  board[i][j] = board[i][j] - ('a' - 'A');
}
bool searchUtil(vector<vector<char>> &board, int i, int j, string word,
                int count) {
  bool ret = false;
  if (count >= word.size()) {
    return true;
  }
  if (i > 0 && board[i - 1][j] == word[count]) {
    Lowercase(board, i, j);
    ret = ret || searchUtil(board, i - 1, j, word, count + 1);
    Uppercase(board, i, j);
  }
  if (i < board.size() - 1 && board[i + 1][j] == word[count]) {
    Lowercase(board, i, j);
    ret = ret || searchUtil(board, i + 1, j, word, count + 1);
    Uppercase(board, i, j);
  }
  if (j > 0 && board[i][j - 1] == word[count]) {
    Lowercase(board, i, j);
    ret = ret || searchUtil(board, i, j - 1, word, count + 1);
    Uppercase(board, i, j);
  }
  if (j < board[0].size() - 1 && board[i][j + 1] == word[count]) {
    Lowercase(board, i, j);
    ret = ret || searchUtil(board, i, j + 1, word, count + 1);
    Uppercase(board, i, j);
  }
  return ret;
}
bool exist(vector<vector<char>> board, string word) {
  if (word.size() == 0)
    return true;
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == word[0] && searchUtil(board, i, j, word, 1)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  cout << "result:" << exist(board, "ABCCED") << endl;
  cout << "result:" << exist(board, "ABCB") << endl;
  return 0;
}
