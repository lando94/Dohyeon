#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <time.h>
#include "Windows.h"
using namespace std;

const int PN = 23;
const int HASH_SIZE = 10000;
//Ű�� �ϳ��� �ִ� 49���� �����Ͱ� �� �� ���� ==> �浹�� ���� �Ͼ�� ��� ��ó�� �ʿ� �ִ� �Ͱ�����
int table[HASH_SIZE][50]; 

int cmd[30000][2];
int my_find[30000], stl_find[30000];

const int REMOVE = 1;
const int FIND = 2;
int hash_size = 0; //0��° �����ͺ��� ����
char hash_raw[30000][100]; //�ִ� ���� 100�� ���ڿ� 30000�������̸� my_hash�� ó���� �迭
char input[30000][100]; //���� ������ stl�� map�� ó���� �迭
map<char*, int> test;

unsigned int get_key(char str[]) {
	unsigned int key = 0, p = 1;
	for (int i = 0; str[i] != 0; i++) {
		key += (str[i] * p);
		p *= PN;	
	}
	return (key%HASH_SIZE);
}

//������ 0, �ٸ��� a>b�� �� ���, a<b�� �� ���� ����
int my_strcmp(char a[], char b[]) {
	int i = 0, j = 0;
	while (a[i]) {
		if (a[i++] != b[j++]) {
			i--; j--; break;
		}
	}
	return (a[i] - b[i]);
}
//�ؽ��� str�� ���Եȴٸ� ���° ���������� ����
int contain(char str[]) {
	unsigned int key = get_key(str);
	int size = table[key][0];
	for (int i = 1; i <= size; i++) {
		int pos = table[key][i];
		if (my_strcmp(hash_raw[pos], str) == 0) {
			return pos;
		}
	}
	return -1;
}

void add(char str[]) {
	int key = get_key(str);
	int& size = table[key][0];
	
	int len = 0;
	for (len = 0; str[len] != 0; len++) {
		hash_raw[hash_size][len] = str[len];
	}
	hash_raw[hash_size][len] = 0;   //�̰� �� �־�� �ϴ��� �𸣰ڴ� �κ�

	table[key][++size] = hash_size++;
}

//�ؽ����̺����� ���������� ���������� �迭������ �������� ����
bool remove(char str[]) {
	unsigned int key = get_key(str);
	int &size = table[key][0];
	for (int i = 1; i <= size; i++) {
		int pos = table[key][i];
		if (my_strcmp(hash_raw[pos], str) == 0) {
			for (int j = i + 1; j <= size; j++) {
				table[key][j - 1] = table[key][j];
			}
			size--;
			return true;
		}
	}
	return false;
}

int make_int(int min, int max) {
	return (rand() % (max - min)) + min;
}
char make_char() {
	int val = rand() % 52;
	if (val < 26) {
		return static_cast<char>('a' + val);
	}
	return static_cast<char>('A' + val - 26);
}


int main()
{
	for (int i = 0; i < 30000; ++i) {
		int len = make_int(10, 100);
		for (int j = 0; j < len; ++j) {
			input[i][j] = make_char();
		}
		input[i][len] = 0;
		if (i > 10000) {
			cmd[i][0] = rand() % 3;
			cmd[i][1] = rand() % i;
		}
	}
	int my_hash_begin = GetTickCount();
	for (int i = 0; i < 30000; i++) {
		if (contain(input[i]) == -1)
			add(input[i]);
		if (cmd[i][0] == REMOVE) {
			if (contain(input[cmd[i][1]]) != -1) {
				remove(input[cmd[i][1]]);
			}
		}
		if (cmd[i][0] == FIND) {
			my_find[i] = contain(input[cmd[i][1]]);
		}
	}
	int my_hash_end = GetTickCount();

	int stl_hash_begin = GetTickCount();
	for (int i = 0; i < 30000; i++) {
		test[input[i]] = i;
		if (cmd[i][0] == REMOVE) {
			test.erase(input[cmd[i][1]]);
		}
		if (cmd[i][0] == FIND) {
			map<char*, int>::iterator iter = test.find(input[cmd[i][1]]);
			stl_find[i] = -1;
			if (iter != test.end()) {
				stl_find[i] = iter->second;
			}
		}
	}
	int stl_hash_end = GetTickCount();
	int my_hash_size = 0;
	for (int i = 0; i < HASH_SIZE; i++) {
		my_hash_size += table[i][0];
	}
	if (my_hash_size != test.size()) {
		printf("hash size is not same!!\n");
	}
	for (int i = 0; i < 30000; i++) {
		if (my_find[i] != stl_find[i]) 
		{
			printf("hash find function is error\n");
		}
	}
	printf("my hash time : %d\n", (my_hash_end - my_hash_begin));
	printf("stl hash time : %d\n", (stl_hash_end - stl_hash_begin));
	return 0;
}
	