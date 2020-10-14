class Solution {
    static int answer = 0;
    
    public int solution(int[] numbers, int target) {
        dfs(0, 0, numbers, target);
        return answer;
    }
    
    void dfs(int sum, int idx, int[] numbers, int target) {
        if(idx == numbers.length) {
            if(sum == target) {
                answer++;
            }
            return;
        }
        dfs(sum + numbers[idx], idx+1, numbers, target);
        dfs(sum - numbers[idx], idx+1, numbers, target);
    }
}
