//
// Created by Yujia Li  on 2020/5/30.
//

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if (A.size() == 1) {
            return {A[0] * A[0]};
        }
        int mid = A.size() - 1;
        vector<int> ret;
        int pre = A[0];

        for (int i = 1; i < A.size(); i++) {
            if (abs(A[i] > abs(pre))) {
                mid = i - 1;
                break;
            }
            pre = A[i];
        }

        ret.push_back(A[mid] * A[mid]);
        int l = mid - 1, r = mid + 1;
        const int INF = 0x3f3f3f3f;
        while (l >= 0 || r < A.size()) {
            int lv = l >= 0 ? A[l] : INF;
            int rv = r < A.size() ? A[r] : INF;

            if (abs(lv) <= abs(rv)) {
                ret.push_back(lv * lv);
                l--;
            } else {
                ret.push_back(rv * rv);
                r++;
            }
        }

        return ret;
    }
};