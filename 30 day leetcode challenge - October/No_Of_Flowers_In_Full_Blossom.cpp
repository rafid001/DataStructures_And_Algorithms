class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        int m = flowers.size();
        int n = people.size();

        vector<int> start_time(m);
        vector<int> end_time(m);

        for(int i=0; i<m; i++) {
            
            start_time[i] = flowers[i][0];
            end_time[i] = flowers[i][1];

        }

        sort(begin(start_time), end(start_time));
        sort(begin(end_time), end(end_time));

        vector<int> result(n);

        for(int i=0; i<n; i++) {

            int time = people[i];

            int bloomed_flowers = upper_bound(begin(start_time), end(start_time), time) - begin(start_time);
            int died_flowers = lower_bound(begin(end_time), end(end_time), time) - begin(end_time);

            result[i] = bloomed_flowers - died_flowers;

        }

        return result;


    }

    //BRUTE FORCE
    /*vector<int> fullBloomFlowers(vector<vector<int>>& flowers, 
    vector<int>& people) {
        
        int m = flowers.size();
        int n = people.size();

        vector<int> result(n);

        for(int i=0; i<n; i++) {
            
            for(int j=0; j<m; j++) {

                int s = flowers[j][0];
                int e = flowers[j][1];

                if(people[i] >= s && people[i] <= e) {
                    result[i]++;
                }
            }
        }

        return result;
    }*/

};