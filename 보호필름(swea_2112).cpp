////1555 ����
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <vector>
//#include <memory.h>
//
//using namespace std;
//
//int D, W, K; //����, ����, �հݱ���
//int film[13][20]; 
//bool selected[13][2]; // [x]�࿡ ���Ͽ� [y](A�� B�� �����ߴ���)
//int min_ans;
//void solution(int y,int cnt) {
//	if (cnt > D)  //�β� D�� �Ѿ�� ���� ����
//		return;
//	if (cnt >= min_ans) return;
//	bool suc = true;
//	//��� ���� ���ӵ� K������ �����ϴ��� ����
//	for (int i = 0; i < W; i++) {
//		bool row_suc = false;
//		int A_cnt, B_cnt; A_cnt = B_cnt = 0;
//		for (int j = 0; j < D; j++) {
//			if (film[j][i] == 0) { //A�̸�
//				A_cnt++; B_cnt = 0;
//				if (A_cnt == K) {
//					row_suc = true;
//					break;
//				}
//			}
//			else {
//				B_cnt++; A_cnt = 0;
//				if (B_cnt == K) {
//					row_suc = true;
//					break;
//				}
//			}
//		} //for j
//		suc &= row_suc; //��� ���� ���Ͽ� ���� ���� �� �� ���̶� �����ϸ� suc == flase;
//		if (!suc) break;
//	}// for i
//	if (suc) { //��� ���� ���Ͽ� ���� ���� K�� �Ѱ����� ����
//		min_ans = min(min_ans, cnt);
//		if (cnt == 0) return;
//	}
//
//	//���� �ߵ� ���ߵ� ����Ž���� ���־�� ��
//	//���� ��ġ�� ���� A�� �ٲٴ� ���� B�� �ٲٴ� ��� ��츦 �����ؾ���
//	for (int i = y; i < D; i++) {  //��� �࿡ ���Ͽ�
//		for (int j = 0; j < 2; j++) {  //j==0�� ��� A�� �ٲ�, �ƴϸ� B�� �ٲ�
//			
//			if (selected[i][j]) continue;
//
//			int copy_film[13][20];
//			for (int a = 0; a < W; a++) {
//				copy_film[i][a] = film[i][a];
//				/*for (int b = 0; b < W; b++) {
//					copy_film[a][b] = film[a][b];
//				}*/
//			}
//
//			if (j == 0) { //�ش� ���� 0(A)���� �ٲ��ֱ�
//				for (int k = 0; k < W; k++) {
//					film[i][k] = 0;
//				}
//				selected[i][j] = true;
//				solution(i+1,cnt + 1);
//				selected[i][j] = false;
//			}
//			else { //B�� �ٲ��ֱ� 
//				for (int k = 0; k < W; k++) {
//					film[i][k] = 1;
//				}
//				selected[i][j] = true;
//				solution(i+1,cnt + 1);
//				selected[i][j] = false;
//			}
//
//			for (int a = 0; a < W; a++) {
//				film[i][a] = copy_film[i][a];
//				/*for (int b = 0; b < W; b++) {
//				copy_film[a][b] = film[a][b];
//				}*/
//			}
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	int test_case;
//	cin >> test_case;
//	for (int A = 1; A <= test_case; A++) {
//		cin >> D >> W >> K;
//		//A�� 0   B�� 1
//		for (int i = 0; i < D; i++) {
//			for (int j = 0; j < W; j++) {
//				cin >> film[i][j];
//			}
//		}
//		memset(selected, false, sizeof(selected));
//		min_ans = 0x7fffffff;
//		solution(0, 0);
//		printf("#%d %d\n", A, min_ans);
//	}
//}