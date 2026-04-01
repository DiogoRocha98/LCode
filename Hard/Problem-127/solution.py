from collections import defaultdict, deque
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if wordList.count(endWord) == 0:
            return 0
        
        patternDict: dict = defaultdict(list)
        wordSize: int = len(beginWord)
        for word in wordList:
            for i in range(wordSize):
                pattern = word[:i] + "*" + word[i+1:]
                patternDict[pattern].append(word)
        queue: deque = deque([(beginWord, 1)])
        visited: set[str] = {beginWord}
        
        while queue:
            curWord, level = queue.popleft()

            for i in range(wordSize):
                pattern = curWord[:i] + "*" + curWord[i+1:]
                for neighbor in patternDict[pattern]:
                    if neighbor == endWord:
                        return level + 1
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append((neighbor, level + 1))                 
        return 0
        