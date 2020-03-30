package power;
import java.util.Scanner;
public class Power {
    public static int pow(int n,int b) {
    	if(b==0) {
    		return 1;
    	}
    	int res=pow(n,b-1);
    	return n*res;
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int b=sc.nextInt();
        int pow=pow(n,b);
        System.out.println(pow);
        sc.close();
	}

}
