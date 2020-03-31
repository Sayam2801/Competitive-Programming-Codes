package backtracking.maze;

import java.util.Scanner;

public class Maze {
    public static boolean findPath(int m[][],int n) {
    	int[][] path = {
    			{0,0,0},{0,0,0},{0,0,0}
    	};
    	return findPath(m,n,0,0,path);
    }
	private static boolean findPath(int[][] m, int n, int i, int j, int[][] path) {
		// TODO Auto-generated method stub
		if(i<0||i>=n||j<0||j>=n) {
			return false;
		}
		if(i==n-1&&j==n-1) {
			path[i][j]=1;
			for(int p=0;p<n;p++) {
				for(int t=0;t<n;t++) {
					System.out.print(path[p][t]+" ");
				}
				System.out.println();
			}
		}
		if(m[i][j]==0||path[i][j]==1) {
			return false;
		}
		path[i][j]=1;
		//Top
		findPath(m,n,i-1,j,path);
		//Bottom
		findPath(m,n,i+1,j,path);
		//Left
		findPath(m,n,i,j-1,path);
		//Right
		findPath(m,n,i,j+1,path);
		return false;
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
		int[][] maze= {
				{1,1,0},{1,1,0},{0,1,1}	
		};
		sc.close();
        findPath(maze,n);
	}

}
