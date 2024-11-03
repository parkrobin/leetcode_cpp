/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.


Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false


Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
*/

#include <string>
#include "cassert"

using namespace std;

/*
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        string ss = s + s;
        return ss.find(goal) != string::npos;
    }
};

int main()
{
    Solution s;
    assert(s.rotateString("abcde", "cdeab"));
    assert(!s.rotateString("abcde", "abced"));
    return 0;
}