class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pas;
        if(rowIndex == 0) {
            pas.push_back(1);
            return pas;
        }
        else if(rowIndex == 1) {
            pas.push_back(1);
            pas.push_back(1);
            return pas;
        }
        else if(rowIndex >= 2) {
            vector<int> pas_tmp;
            pas_tmp.push_back(1);
            pas_tmp.push_back(1);
            for(int i = 2; i <= rowIndex; ++i) {
                pas.clear();
                pas.push_back(1);
                for(int j = 0; j < pas_tmp.size() - 1; ++j) {
                    pas.push_back(pas_tmp[j] + pas_tmp[j + 1]);
                }
                pas.push_back(1);
                pas_tmp = pas;
            }
            return pas;
        }
    }
};
