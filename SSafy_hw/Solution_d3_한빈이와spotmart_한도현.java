package hw0124;

import java.io.*;
import java.util.*;

public class Solution_d3_한빈이와spotmart_한도현 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for (int A = 1; A <= tc; A++) {
			int N, M;
			N = sc.nextInt();
			M = sc.nextInt();
			int[] arr = new int[N + 1];
			for (int i = 0; i < N; i++) {
				arr[i] = sc.nextInt();
			}
			int ret = Integer.MIN_VALUE;
			int temp;
			for (int i = 0; i < N; i++) {
				for (int j = i + 1; j < N; j++) {
					temp = arr[i] + arr[j];
					if (temp > M)
						continue;
					ret = Math.max(temp, ret);
				}
			}
			if (ret == Integer.MIN_VALUE)
				System.out.println("#" + A + " -1");
			else
				System.out.println("#"+A+" " + ret);
		}
	}
}
