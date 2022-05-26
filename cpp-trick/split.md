使用 sstream

```cpp
#include <sstream>
#include <string>

stringstream ss(text);
vector<stirng> words;
for(string word; ss >> word; words.emplace_back(move(word)));
```
