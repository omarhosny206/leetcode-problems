// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/


class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int result = 0;
        for(int i=0; i<arr.size(); i++) {
            int sum = 0;
            int odd = 1;
            for(int j=i; j<arr.size(); j++) {
                sum += arr[j];
                if(odd % 2 != 0)
                    result += sum;
                odd++;
            }
        }
        return result;
    }
   
};