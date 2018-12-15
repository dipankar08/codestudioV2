/***************************************************
 * Title : Word Serach using DFS
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool dfs(vector<vector<char>> &board, int row, int col, const string &word,
         int start, int M, int N, int sLen) {
  char curC;
  bool res = false;
  // can't proceed farther as char mismatch.
  if ((curC = board[row][col]) != word[start]) {
    return false;
  }
  // end of the serach word. return as found.
  if (start == sLen - 1) {
    return true;
  }
  // put a start to prevent looping
  board[row][col] = '*';
  if (row > 0) {
    res = dfs(board, row - 1, col, word, start + 1, M, N, sLen);
  }
  if (!res && row < M - 1) {
    res = dfs(board, row + 1, col, word, start + 1, M, N, sLen);
  }
  if (!res && col > 0) {
    res = dfs(board, row, col - 1, word, start + 1, M, N, sLen);
  }
  if (!res && col < N - 1) {
    res = dfs(board, row, col + 1, word, start + 1, M, N, sLen);
  }
  // Ok we process all the clild recusrsion, so replace with the right value.
  board[row][col] = curC;
  return res;
}

bool exist(vector<vector<char>> &board, string word) {
  int M, N, i, j, sLen = word.size();
  if ((M = board.size()) && (N = board[0].size()) && sLen) {
    for (i = 0; i < M; ++i) {
      for (j = 0; j < N; ++j) {
        if (dfs(board, i, j, word, 0, M, N, sLen)) {
          return true;
        }
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
