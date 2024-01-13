class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int maxScore = 0;

        int i=0; int j = tokens.size()-1;

        while(i <= j) {
            if(power >= tokens[i]) {
                power = power - tokens[i];
                score++;
                i++;
                maxScore = max(maxScore,score);
            }
            else if(score >= 1) {
                power += tokens[j];
                score -= 1;
                j--;
            } else {
                return maxScore;
            }
        }

        return maxScore;
    }
};