# ✅ DataStructure-Algorithm ✅
```
C 언어를 사용해서 대소문자 구분없이 알파벳을 입력하면
대문자 소문자를 판별하여 분류하고 사전순으로 정렬하여 출력하는 프로그램 만들기
```
![대소문자 구분하는 프로그램](https://github.com/JaehyeonHeo/Study_C/blob/main/c%EC%96%B8%EC%96%B4%20%ED%8F%89%EA%B0%80/%ED%94%BC%ED%8A%B8%EB%8B%88%EC%8A%A4%EC%84%BC%ED%84%B0%20%EC%8B%A4%ED%96%89%ED%99%94%EB%A9%B4.png?raw=true "실행화면")

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/* 삽입 정렬 함수 */
void insertion_sort(char *ary) {
	int i, j, key;
	int n = 10;
	// 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
	for (i = 1; i < n; i++) {
		key = (int)ary[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사
		// 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
		// j 값은 음수가 아니어야 되고
		// key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
		for (j = i - 1; j >= 0 && ary[j] > key; j--) {
			ary[j + 1] = ary[j]; // 레코드의 오른쪽으로 이동
		}
		ary[j + 1] = key;
	}
}
/* 출력 함수 */
void print_ary(char* ary, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%c, ", ary[i]);
	}
}
int main() {
	// 입력 받을 배열선언
    char input_ary[10]; 
	// 대문자, 소문자 배열 선언
	char lower_ary[10];
	char upper_ary[10];
	// 배열에 알파벳 입력 
	for (int i = 0; i < 10; i++)
	{
		printf("%d번째방 알파벳 입력 : ", i + 1); 
		scanf(" %c", &input_ary[i]);
		if ((int)input_ary[i] < 65 || (int)input_ary[i] > 122) break;
	}
	
	// 삽입정렬 함수 호출
	insertion_sort(input_ary);
	// 소문자, 대문자 구분해서 저장(저장한 인덱스 j,k에 저장)
	int j = 0, k = 0;
	for (int i = 0; i < 10; i++)
	{
		if ((int)input_ary[i] >= 65 && (int)input_ary[i] <= 90) {
			lower_ary[j] = input_ary[i];
			j++;
		}
		else if ((int)input_ary[i] >= 97 && (int)input_ary[i] <= 122) {
			upper_ary[k] = input_ary[i];
			k++;
		}
	}
	// 출력함수 호출 
	printf("\n");
	printf("--------------------결과 출력-----------------------");
	printf("\n\n");
	printf("<<입력된 소문자 알파벳>>\n");
	print_ary(lower_ary, j); // 저장한 개수 j개 만큼 출력
	printf("\n\n");
	printf("<<입력된 대문자 알파벳>>\n");
	print_ary(upper_ary, k); // 저장한 개수 k개 만큼 출력 
	printf("\n\n");
    return 0;
}
```
