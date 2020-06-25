//
// Created by Yujia Li  on 2020/6/25.
//

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;

        while (true) {
            int mid = (left + 1ll + right) >> 1;
            int ret = guess(mid);

            if (ret == 0) {
                return mid;
            }

            if (ret == -1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

    }
};