import java.util.Arrays;
import java.util.Scanner;
 
class Solution
{
    public static void main(String args[]) throws Exception
    {
        Scanner sc = new Scanner(System.in);
 
        int N = sc.nextInt();
        int[] num = new int[N];
        for (int i = 0; i < num.length; i++) {
            num[i] = sc.nextInt();
        }
 
        Arrays.sort(num);
        System.out.println(num[N/2]);
    }
}