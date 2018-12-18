/***************************************************
 * Title : Uisng MinHeap
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class TrieNode {
public:
  vector<TrieNode *> next(26, NULL);
  string word;
  TrieNode() { this->word = NULL; }
};

void getWords(TrieNode *node, vector<string> list, int k) {
  if (node == NULL)
    return;
  if (node->word != null) {
    list->add(node->word);
  }
  if (list->size() == k)
    return;
  for (int i = 0; i < 26; i++) {
    if (node->next[i] != null) {
      getWords(node->next[i], list, k);
    }
  }
}

boolean addWord(TrieNode *root, string word) {
  TrieNode *curr = root;
  for (char c : word) {
    if (curr->next[c - 'a'] == null) {
      curr->next[c - 'a'] = new TrieNode();
    }
    curr = curr->next[c - 'a'];
  }
  curr->word = word;
  return true;
}

vector<string> topKFrequent(vector<string> words, int k) {
  // calculate frequency of each word
  map<string, int> freqMap;
  for (string word : words) {
    if (freqMap.get(word)) {

    } else {
    }
    freqMap.put(word, freqMap.getOrDefault(word, 0) + 1);
  }

  // build the buckets
  vector<TrieNode *> count(words.size() + 1, NULL);
  for (auto const &x : freqMap) {
    string key = x.first;
    string value = x.second;
    if (count[value] == NULL) {
      count[value] = new TrieNode();
    }
    addWord(count[value], key);
  }

  // get k frequent words
  vector<string> list;
  for (int f = count.size() - 1; f >= 1 && list.size() < k; f--) {
    if (count[f] == NULL) {
      continue;
    }
    getWords(count[f], list, k);
  }
  return list;
}

int main() {
  printVec(topKFrequent({"i", "love", "dipankar", "i", "love", "coding"}, 2));
  printVec(topKFrequent(
      {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"},
      4));
  return 0;
}
