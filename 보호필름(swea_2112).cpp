////1555 시작
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <vector>
//#include <memory.h>
//
//using namespace std;
//
//int D, W, K; //높이, 가로, 합격기준
//int film[13][20]; 
//bool selected[13][2]; // [x]행에 대하여 [y](A나 B를 선택했는지)
//int min_ans;
//void solution(int y,int cnt) {
//	if (cnt > D)  //두께 D를 넘어가는 경우는 없다
//		return;
//	if (cnt >= min_ans) return;
//	bool suc = true;
//	//모든 열에 연속된 K기준을 만족하는지 조사
//	for (int i = 0; i < W; i++) {
//		bool row_suc = false;
//		int A_cnt, B_cnt; A_cnt = B_cnt = 0;
//		for (int j = 0; j < D; j++) {
//			if (film[j][i] == 0) { //A이면
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
//		suc &= row_suc; //모든 열에 대하여 수행 했을 때 한 열이라도 실패하면 suc == flase;
//		if (!suc) break;
//	}// for i
//	if (suc) { //모든 열에 대하여 최저 기준 K를 넘겼으면 성공
//		min_ans = min(min_ans, cnt);
//		if (cnt == 0) return;
//	}
//
//	//성공 했든 안했든 완전탐색을 해주어야 함
//	//같은 위치에 대해 A로 바꾸는 경우와 B로 바꾸는 모든 경우를 생각해야함
//	for (int i = y; i < D; i++) {  //모든 행에 대하여
//		for (int j = 0; j < 2; j++) {  //j==0일 경우 A를 바꿈, 아니면 B를 바꿈
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
//			if (j == 0) { //해당 행을 0(A)으로 바꿔주기
//				for (int k = 0; k < W; k++) {
//					film[i][k] = 0;
//				}
//				selected[i][j] = true;
//				solution(i+1,cnt + 1);
//				selected[i][j] = false;
//			}
//			else { //B로 바꿔주기 
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
//		//A는 0   B는 1
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