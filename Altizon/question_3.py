class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        word = ''
        words = []
        for char in s:
            if char != ' ':
                word += char
            else:
                words.append(word)
                word = ''
        words.append(word)
        print(words)
        truncate = ' '.join(words[0:k])
        return truncate

sol = Solution()
s = "chopper is not a tanuki"
# words =  ["cc","acd","b","ba","bac","bad","ac","d"]
k = 5
s = sol.truncateSentence(s, k)
print(s)
