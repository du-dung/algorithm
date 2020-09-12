/* 폰켓몬 Level 2
https://programmers.co.kr/learn/courses/30/lessons/1845
*/
import java.util.*;
class Solution {
    public int solution(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();
        for(int n : nums){
            set.add(n);
        }
        if(set.size() > nums.length/2){
            return nums.length/2;
        }
        return set.size();
    }
}
