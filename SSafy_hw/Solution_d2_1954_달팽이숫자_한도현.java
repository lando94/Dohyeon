package hw0124;

import java.io.*;
import java.util.*;

public class Solution_d2_1954_달팽이숫자_한도현 {
	static int[][] arr = new int[10][10];
	static int[][] direction = new int[][] { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for (int t = 1; t <= tc; t++) {
			int N = sc.nextInt();
			int cnt = N - 1;
			int number = 1;
			for (int i = 0; i < N; i++) {
				arr[0][i] = number++;
			}
			int cur_y = 0, cur_x = N - 1;
			int dir = 2;
			while (cnt != 0) {
				for (int i = 0; i < cnt; i++) {
					cur_y += direction[dir][0];
					cur_x += direction[dir][1];
					arr[cur_y][cur_x] = number++;
				}
				dir = (dir + 1) % 4;
				for (int i = 0; i < cnt; i++) {
					cur_y += direction[dir][0];
					cur_x += direction[dir][1];
					arr[cur_y][cur_x] = number++;
				}
				dir = (dir + 1) % 4;
				cnt--;
			}
			System.out.println("#" + t);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
		}
	}

}
