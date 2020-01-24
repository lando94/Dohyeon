package hw0124;

import java.io.*;
import java.util.*;

public class Solution_d3_5356_의석이의세로로말해요_한도현 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		for (int A = 1; A <= tc; A++) {
			String[] x = new String[5];
			for (int i = 0; i < 5; i++) {
				x[i] = br.readLine();
			}
			int start = 0;
			int col = 0;
			StringBuilder ans = new StringBuilder();

			while (true) {
				boolean suc = false;
				for (int i = 0; i < 5; i++) {
					if (x[i].length() - 1 < col)
						continue;
					suc = true;
					ans.append(x[i].charAt(col));
				}
				if (suc == false)
					break;
				col++;
			}
			System.out.println("#" + A + " " +ans);
		}
	}
}
