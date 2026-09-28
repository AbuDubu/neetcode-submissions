class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i){
            if (i == arr.size() - 1) {
                arr[i] = -1;
                break;
            }

            int max {arr[i + 1]};
            for (int j = i + 1; j < arr.size(); ++j){
                if (arr[j] >= max){
                    max = arr[j];
                }
            }
            arr[i] = max; 
        }
        return arr;
    }
};