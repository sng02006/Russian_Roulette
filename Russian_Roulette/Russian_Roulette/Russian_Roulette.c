#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Russian_Roulette.h"

int main() {
	FILE *fp;
	int size = 0; //student.txt로부터 입력받은 사람의 수를 체크하는 변수
	char name_temp[9];
	int i = 0;

	USER* user = NULL;
	USER* new_user = NULL;
	USER* temp = NULL;
	USER* dead = NULL;

	fp = fopen("student.txt", "r");

	//student.txt가 끝날 때까지 정보를 하나씩 읽어와서 node를 만들고 circular linked list를 만드는 부분
	while (fscanf(fp, "%s", name_temp) != EOF) {
		size++;
		if (user == NULL) {
			new_user = create_user(size, name_temp, user);
			user = temp = new_user;
		}
		else {
			new_user = create_user(size, name_temp, user);
			temp->next = new_user;
			new_user->next = user;
			temp = temp->next;
		}
	}

	//게임을 실행하여 죽은 사람들의 목록을 dead에 linked list로 반환
	dead = game_start(size, user);

	//dead 차례로 출력
	printlist(dead);

	fclose(fp);

	free(dead);

	return 0;
}