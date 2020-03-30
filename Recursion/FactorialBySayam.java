package factorial;
import java.util.Scanner;
public class Factorial {
    public static int fact(int n) {
    	if(n==0) {
    		return 1;
    	}
    	int res=fact(n-1);
    	return n*res;
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a number:");
        int n=sc.nextInt();
        int fact=fact(n);
        System.out.println("Factorial of given number:"+fact);
        sc.close();
	}

}
