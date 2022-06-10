unordered_map<string, int> val2pos;
int n = wordList.size();
// map string to position
for(int i = 0; i < n; ++i)
  val2pos[wordList[i]] = i;
// build the graph
vector<vector<bool>> graph(n, vector<bool>(n, 0));
for(int i = 0; i < n; ++i) {
  auto &word = wordList[i];
  for(auto &c : word) {
    auto origin = c;
    // change the letter of word
    for(char newChar = 'a'; newChar <= 'z'; ++newChar) {
      if(newChar == origin)
        continue;
      c = newChar;
      if(auto iter = val2pos.find(word); iter != val2pos.end())
        graph[i][iter -> second] = graph[iter -> second][i] = true;
    }
    // restore the letter
    c = origin;
  }
}