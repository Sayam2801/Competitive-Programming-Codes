package towerOfHanoi;
import java.util.Scanner;
public class Complex {
    public static void TowerOfHanoi(char a,char b,char c,int n) {
    	if(n==1) {
    		System.out.println("Moving disk from "+a+" to "+c);
    		return;
    	}
    	TowerOfHanoi(a,c,b,n-1);
    	System.out.println("Moving disk from "+b+" to "+c);
    	TowerOfHanoi(a,b,c,n-1);
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.println(n);
        TowerOfHanoi('a','b','c',n);
        sc.close();
	}

}
