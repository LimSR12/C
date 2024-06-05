#pragma warning(disable:4996)
#include <stdio.h>

// 4차 모의고사

int reverse_num(int);
int del_dupnum(int);

int main() {
	//// 1번
	//char data;
	//char arr[100];
	//int index = 0;

	//while (1) {
	//	scanf("%c", &data);
	//	if (data == '*') break;
	//	if (index >= 100)break;

	//	// data로 받은 문자가 a~z || A~Z 라면
	//	if ((data >= 'a' && data <= 'z') || (data >= 'A' && data <= 'Z')) {
	//		if (data >= 'a' && data <= 'z') {
	//			//printf("before : %c\n", data);
	//			data -= ('a' - 'A');
	//			//printf("after : %c\n", data);
	//		}
	//		else if (data >= 'A' && data <= 'Z') {
	//			//printf("before : %c\n", data);
	//			data += ('a' - 'A');
	//			//data += 32;
	//			//printf("after : %c\n", data);
	//		}
	//		arr[index++] = data;
	//	}
	//	else {
	//		// 저장하지 않음
	//	}
	//}

	//for (int i = 0; i < index; i++) {
	//	printf("%c", arr[i]);

	//}
	//printf("\n");
	//int count = 0;
	//for (int i = 0; i < index; i++) {
	//	int flag = 0;
	//	if ((arr[i] >= 'A' && arr[i] <= 'Z') 
	//		&& (arr[i] != 'A' && arr[i] != 'E' && arr[i] != 'I' && arr[i] != 'O' && arr[i] != 'U')) {
	//		flag++;
	//	}
	//	if ((arr[i + 1] >= 'a' && arr[i + 1] <= 'z') 
	//		&& (arr[i + 1] == 'a' || arr[i + 1] == 'e' || arr[i + 1] == 'i' || arr[i + 1] == 'o' || arr[i + 1] == 'u')) {
	//		flag++;
	//	}
	//	if ((arr[i + 2] >= 'a' && arr[i + 2] <= 'z') 
	//		&& (arr[i + 2] != 'a' && arr[i + 2] != 'e' && arr[i + 2] != 'i' && arr[i + 2] != 'o' && arr[i + 2] != 'u')){
	//		flag++;
	//	}

	//	if (flag == 3) {
	//		count++;
	//		//printf("%c%c%c", arr[i], arr[i + 1], arr[i + 2]);
	//	}
	//}

	//printf("%d", count);

	//*****************************************************
	// 2번
	// 종료시까지 N을 입력받아
	int N, M;
	int max_val = 0;
	int max_N = -1;
	int max_M = -1;

	while (1) {
		scanf("%d ", &N);
		/*printf("%d", N);*/
		if (N < 0) {
			return 0;
		}
		//printf("%d\n", reverse_num(N));
		//printf("%d", del_dupnum(N));
		M = reverse_num(N);
		M = del_dupnum(M);
		printf(" %d", M);

		// 절대값 체크
		// N - M의 크기로.
		int temp = N - M;
		if (temp < 0) temp *= -1;
		if (max_val < temp) {
			max_val = temp;
			max_N = N;
		}
	}

	printf("\n%d %d", max_N, max_val);

	return 0;
}

int reverse_num(int x) {
	int reverse = 0;
	while (x > 0) {
		reverse = reverse * 10 + x % 10;
		x /= 10;
	}
	return reverse;
}

int del_dupnum(int x) {
	// 입력받은 정수 중 중복된 숫자가 있으면 처음 나온 숫자는 유지, 그 이후에 나오는 숫자는 삭제

	// x를 쪼개

	int temp = x;
	int arr[9] = { 0, };

	int return_arr[9];
	int index = 0;
	

	// arr 에 뒤에서부터 넣음
	// 76543을 쪼개서 넣는다?
	// 000076543
	int size = 0;
	for (int i = 8; i >= 0 && temp > 0; i--) {
		arr[i] = temp % 10;
		temp /= 10;
		size++;
	}
	for (int i = 9 - size; i < 9; i++) {
		//printf("arr : %d\n", arr[i]);
		
		//이제 중복제거
		//arr[i] 를 새로운 배열에 옮겨 담을 건데
		// 옮겨담을 배열에 이미 해당 값이 존재하면 안됨
		int flag = 0;
		for (int j = 0; j < 9; j++) {
			if (return_arr[j] == arr[i]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			return_arr[index++] = arr[i];
		}
	}
	
	// 이제 배열에 담은 수를 정수로 다시 변환
	int return_val = 0;
	for (int i = 0 ; i < index; i++) {
		return_val = return_val * 10 + return_arr[i];
	}
	//printf("%d", return_val);

	return return_val;
}