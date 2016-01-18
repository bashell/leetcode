class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B), area2 = (G - E) * (H - F);
        if(C <= E || A >= G || B >= H || D <= F)
            return area1 + area2;
        vector<int> v1{A, C, E, G}, v2{B, D, F, H};
        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());
        return area1 + area2 - (v1[2] - v1[1]) * (v2[2] - v2[1]);
    }
};
