class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> ivec_in;
        vector<vector<int>> ivec_out;
        if(numRows == 1) {
            ivec_in.push_back(1);
            ivec_out.push_back(ivec_in);
            return ivec_out;
        }
        else if(numRows == 2) {
            ivec_in.push_back(1);
            ivec_out.push_back(ivec_in);
            ivec_in.push_back(1);
            ivec_out.push_back(ivec_in);
            return ivec_out;
        }
        else if(numRows >= 3) {
            ivec_in.push_back(1);
            ivec_out.push_back(ivec_in);
            ivec_in.push_back(1);
            ivec_out.push_back(ivec_in);
            for(int i = 3; i <= numRows; ++i) {
                ivec_in.clear();
                ivec_in.push_back(1);
                for(int j = 0; j < i - 2; ++j) {
                    ivec_in.push_back(ivec_out[i - 2][j] + ivec_out[i - 2][j + 1]);
                }
                ivec_in.push_back(1);
                ivec_out.push_back(ivec_in);
            }
            return ivec_out;
        }
    }
};
