/*
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. 
 * The number 27 is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. 
 * Instead, the number four is written as IV. Because the one is before the five we subtract it making four. 
 * The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 *		I can be placed before V (5) and X (10) to make 4 and 9. 
 *		X can be placed before L (50) and C (100) to make 40 and 90. 
 *		C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * Given an integer, convert it to a roman numeral.
 */

string intToRoman(int num) {
        string ret;
        vector <int> n;
        while (num != 0) {
            n.push_back(num % 10);
            num = (num - num % 10) / 10;
        }
        if (n.size() == 4) {
            for (int i = 0; i < n.back(); ++i) {
                ret.append("M");
            }
        }
        if (n.size() >= 3) {
            int hundred = n[2];
            if (hundred == 9) {
                ret.append("CM");
            } else if (hundred == 4) {
                ret.append("CD");
            } else if (hundred >= 5) {
                ret.append("D");
                for (int i = 0; i < hundred-5; ++i) {
                    ret.append("C");
                }
            } else if (hundred != 0) {
                for (int i = 0; i < hundred; ++i) {
                    ret.append("C");
                }
            }
        }
        if (n.size() >= 2) {
            int ten = n[1];
            if (ten == 9) {
                ret.append("XC");
            } else if (ten == 4) {
                ret.append("XL");
            } else if (ten >= 5) {
                ret.append("L");
                for (int i = 0; i < ten-5; ++i) {
                    ret.append("X");
                }
            } else if (ten != 0) {
                for (int i = 0; i < ten; ++i) {
                    ret.append("X");
                }
            }
        }
        if (n.size() >= 1) {
            int one = n[0];
            if (one == 9) {
                ret.append("IX");
            } else if (one == 4) {
                ret.append("IV");
            } else if (one >= 5) {
                ret.append("V");
                for (int i = 0; i < one-5; ++i) {
                    ret.append("I");
                }
            } else if (one != 0) {
                for (int i = 0; i < one; ++i) {
                    ret.append("I");
                }
            }
        }
        return ret;
    }

