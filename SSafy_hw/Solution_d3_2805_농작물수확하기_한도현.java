package hw0124;

import java.io.*;
import java.util.*;

public class Solution_d3_2805_농작물수확하기_한도현 {
	static int N;
	static int[][] farm = new int[49][49];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		for (int t = 1; t <= tc; t++) {
			int N = Integer.parseInt(br.readLine());
			for (int i = 0; i < N; i++) {
				String temp = br.readLine();
				for (int j = 0; j < N; j++) {
					farm[i][j] = temp.charAt(j) - '0';
				}
			}
			int sum = 0;
			// 1,3,..... N, N-2, ... 1
			for (int i = 0; i < N; i++) {
				int j = (i <= (N / 2)) ? (N / 2 - i) : i - N / 2;
				int minus = j;
				for (; j <= N - 1 - minus; j++) {
					sum += farm[i][j];
				}
			}
			System.out.println("#"+t+" " + sum);
		}
	}
}
