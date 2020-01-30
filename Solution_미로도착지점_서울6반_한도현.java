package hw0124;
import java.io.*;
import java.util.*;
public class Solution_미로도착지점_서울6반_한도현 {
	public static int []dy = {0,-1,0,1,0};
	public static int []dx = {0,0,1,0,-1};
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for(int t=1;t<=tc;t++){
			int N = sc.nextInt();
			int y = sc.nextInt();
			int x = sc.nextInt();
			int jumper =sc.nextInt();
			int [][]miro = new int[N+1][N+1];
			for(int i=0;i<jumper;i++){
				int temp_y = sc.nextInt();
				int temp_x = sc.nextInt();
				miro[temp_y][temp_x] = -1;
			}
			int dir_info = sc.nextInt();
			exit:while(dir_info!=0){
				int dir = sc.nextInt();
				int cnt = sc.nextInt();
				while(cnt-->0){
					int ny = y+ dy[dir];
					int nx = x + dx[dir];
					if(ny<1|| nx<1 || ny>N || nx>N || (miro[ny][nx]==-1)){
						y=x=0;
						break exit;
					}
					y= ny;
					x = nx;
				}
				dir_info--;
			}
			System.out.println("#" +t+" " + y+ " "+x);
		}
	}

}
