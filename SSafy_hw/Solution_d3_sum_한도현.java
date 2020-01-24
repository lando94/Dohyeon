package hw0124;

import java.io.*;
import java.util.*;

public class Solution_d3_sum_한도현 {
	static int[][] arr = new int[101][101];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//System.setIn(new FileInputStream("res/sum_exam2.txt"));
		for (int a = 0; a < 10; a++) {
			int TC = Integer.parseInt(br.readLine());
			int[][][] Sum = new int[101][101][2];

			for (int i = 1; i <= 100; i++) {
				String x = br.readLine();
				StringTokenizer st = new StringTokenizer(x, " ");
				int j = 1;
				while (st.hasMoreTokens()) {
					arr[i][j] = Integer.parseInt(st.nextToken());
					Sum[i][j][0] += Sum[i][j-1][0] + arr[i][j];
					Sum[i][j][1] += Sum[i-1][j][1] + arr[i][j];
					j++;
				}
			}
			// 대각선 구하기
			int sum = 0, sum2 = 0;
			for (int i = 1, j = 1; i <= 100; i++, j++) {
				sum += arr[i][j];
			}
			for (int i = 1, j = 100; i <= 100; i++, j--) {
				sum2 += arr[i][j];
			}
			int max_sum = Math.max(sum, sum2);

			for (int i = 1; i <= 100; i++) {
				max_sum = Math.max(max_sum, Math.max(Sum[100][i][1], Sum[i][100][0]));
			}
			System.out.println("#" + TC + " " + max_sum);
		}
	}
}
