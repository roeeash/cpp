class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        map<char, string> morseMapping;
        string morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        char letter;
        string word;
        string res;
        set<string> setRes;

        for (int i = 0; i < 26; i++)
        {
            letter = 'a' + i;
            morseMapping[letter] = morse[i];
        }

        for (int i = 0; i < words.size(); i++)
        {
            word = words[i];

            res = "";
            for (int j = 0; j < word.size(); j++)
            {
                res += morseMapping[word[j]];
            }
            setRes.insert(res);
        }

        return setRes.size();
    }
};