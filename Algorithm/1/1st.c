/* Running time + Time complexity (with Big O)*/
#include <stdio.h>
#include <time.h>

void swap(int* a, int* b) {
	int* temp;
	temp = a;
	a = b;
	b = temp;
}

/* n개의 정수로 구성된 리스트 S에 정수 x가 있는가? */
void Algorithm1(int n, const int S[], int x) {
	int location = 0;
	while (location < n && S[location] != x)
		location++;
	if (location >= n)
		location = -1; //정수 존재하지 않음
	//정수가 존재함
}

/* n개의 정수로 구성된 리스트 S의 숫자를 전부 더하라 */
int Algorithm2(int n, const int S[]) {
	int result = 0;
	for (int i = 0; i < n; i++) //2n+ 1
		result = result + S[i]; //result에 숫자 더함 //n
	return result; //결과 //1
}

/* n개의 정수로 구성된 리스트 S를 단조감소 순서로 나열하라 */
int Algorithm3(int n, int S[]) {
	for (int i = 0; i < n - 1; i++) //2(n - 1)
		for (int j = i + 1; j < n; j++) // (2n+1)/2
			if (S[j] < S[i]) //작은 수가 큰 수보다 뒤에 있을 때 //1
				swap(&S[i], &S[j]); //1
	return S;
}

int main(void) {

	int S[4] = { 4,3,2,1 };
	printf("단위: 밀리초\n");
	clock_t start1 = clock();
	Algorithm1(4, S, 3);
	clock_t end1 = clock();
	printf("예시 1: %10.20lf\n", ((double)end1 - (double)start1));
	clock_t start2 = clock();
	clock(Algorithm2(4, S));
	clock_t end2 = clock();
	printf("예시 2: %10.20lf\n", ((double)end2 - (double)start2));
	clock_t start3 = clock();
	clock(Algorithm3(4, S));
	clock_t end3 = clock();
	printf("예시 3: %10.20lf\n", ((double)end3 - (double)start3));


	return 0;
}
