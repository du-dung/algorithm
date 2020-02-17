import java.util.Scanner;
 
class Solution
{
    public static void main(String args[]) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        int T;
        T=sc.nextInt();
         
        for(int test_case = 1; test_case <= T; test_case++)
        {
            test_case = sc.nextInt();
            int[] score = new int[101];
            int temp;
            for (int i = 0; i < 1000; i++) {
                temp = sc.nextInt();
                score[temp]++;
            }
      
            int ans = 0, num = 0; //ans: ÃÖºó¼ö, num: ÃÖºó¼ö°¡ µîÀåÇÑ È½¼ö
            for (int i = 0; i < 101; i++) {
                if (score[i] >= num) {
                    num = score[i];
                    ans = i;
                }
            }
            System.out.println("#"+test_case+" "+ans);
        }
    }
}