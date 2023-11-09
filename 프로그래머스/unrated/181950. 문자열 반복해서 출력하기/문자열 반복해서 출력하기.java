import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int n = sc.nextInt();
        
        int count = 0;
        while(count < n) {
            System.out.print(str);
            count++;
        }
    }
}