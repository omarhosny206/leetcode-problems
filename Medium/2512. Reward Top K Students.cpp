// https://leetcode.com/problems/reward-top-k-students/

class Solution
{
private:
    struct Comparator
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            if (a.second == b.second)
                return a.first > b.first;

            return b.second > a.second;
        }
    };

public:
    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k)
    {
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> values;
        unordered_map<int, int> score;
        unordered_set<string> positives;

        unordered_set<string> negatives;

        for (string &word : positive_feedback)
            positives.insert(word);

        for (string &word : negative_feedback)
            negatives.insert(word);

        countScore(report, student_id, score, positives, negatives);

        for (auto &pair : score)
            values.push(pair);

        while (k--)
        {
            pair<int, int> value = values.top();
            result.push_back(value.first);
            values.pop();
        }

        return result;
    }

    void countScore(vector<string> &report, vector<int> &student_id, unordered_map<int, int> &score, unordered_set<string> &positives, unordered_set<string> &negatives)
    {
        string word = "";

        for (int i = 0; i < report.size(); ++i)
        {
            word = "";

            for (char &c : report[i])
            {
                if (c == ' ')
                {
                    if (positives.find(word) != positives.end())
                        score[student_id[i]] += 3;

                    else if (negatives.find(word) != negatives.end())
                        score[student_id[i]] -= 1;

                    word = "";
                }

                else
                    word += c;
            }

            if (positives.find(word) != positives.end())
                score[student_id[i]] += 3;

            else if (negatives.find(word) != negatives.end())
                score[student_id[i]] -= 1;
        }
    }
};