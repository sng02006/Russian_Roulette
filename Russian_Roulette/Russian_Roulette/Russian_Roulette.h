#ifndef Russian_Roulette_H_INCLUDED
#define Russian_Roulette_H_INCLUDED

//사용자의 정보를 입력받을 구조체 선언
typedef struct user {
	int num, bullet;
	char *name;
	struct user *next;
}USER;

USER* game_start(int number_of_user, USER* user);
USER* create_user(int size, char name_temp[9], USER *user);
USER* dead_user(int dead_num, USER* dead, int i, USER* user);
void printlist(USER* user);

//게임 진행 함수
USER* game_start(int number_of_user, USER* user) {
	int revolver, bullet;
	int first;
	int dead_num = 0;//죽는 순서
	USER* temp = NULL;//user 대신 움직이며 정보를 읽어올 때 사용하는 포인터
	USER* temp1 = NULL;//첫번째 사용자가 죽는 경우 dead_user 함수를 실행하기 전에 미리 그 다음 사용자의 정보가 저장되어있는 주소를 저장해둠
	USER* dead = NULL;

	srand(time(NULL));

	//사용자가 모두 죽을 때까지 게임 진행
	while (number_of_user >= 1) {
		bullet = revolver = rand() % number_of_user + 1;//총알이 들어있는 공간의 번호를 1~남은 사람 수 중에 랜덤하게 설정
		printf("총알이 %d번에 들어있습니다.\n\n", revolver);
		first = rand() % number_of_user + 1;//가장 먼저 시작할 사람의 번호를 1~남은 사람 수 중에 랜덤하게 설정
		printf("%d번 참가자가 가장 먼저 게임을 시작합니다.\n\n", first);

		temp = user;

		//게임을 시작할 사용자까지 포인터를 이동
		while (temp->num != first) {
			temp = temp->next;
		}

		while (revolver > 0) {
			if (revolver > 1) {
				printf("틱\n");
				printf("%d번 참가자가 생존하였습니다.\n", temp->num);
				printf("다음 참가자로 넘어갑니다.\n\n");
				temp = temp->next;
			}
			else {
				dead_num++;
				printf("탕!!\n");
				printf("%d번 참가자가 %d번째로 사망하였습니다.\n\n", temp->num, dead_num);
				temp->bullet = bullet;//몇 번째 공간에 있는 총알에 죽었는지 저장

				//첫번째 사용자가 죽는 경우 dead_user 함수를 실행하기 전에 미리 그 다음 사용자의 정보가 저장되어있는 주소를 저장해둠
				if (temp->num == 1)
					temp1 = user->next;
				else
					temp1 = user;

				//user에서 죽은 사람의 정보를 없애고 dead에 추가
				dead = dead_user(dead_num, dead, temp->num, user);

				user = temp1;

				number_of_user--;//사용자 수 감소
			}

			revolver--;

		}
		printf("이번 게임을 종료합니다.\n\n\n\n\n");
	}

	return dead;
}

//동적 할당 받아 node 하나를 만들고 입력받은 정보를 저장하는 함수
USER* create_user(int size, char name_temp[9], USER *user) {
	USER *newptr = NULL;

	newptr = (USER*)malloc(sizeof(USER));

	newptr->num = (int*)malloc(sizeof(int));
	newptr->bullet = (int*)malloc(sizeof(int));
	newptr->name = (char*)malloc(sizeof(char)*strlen(name_temp) + 1);

	if (newptr == NULL) {
		printf("에러\n");
		exit(1);
	}

	newptr->num = size;
	newptr->bullet = 0;
	strcpy(newptr->name, name_temp);
	newptr->next = newptr;

	return newptr;
}

//죽은 사람의 정보를 circular linked list에서 없애고 dead라는 linked list에 저장하는 함수
USER* dead_user(int dead_num, USER* dead, int i, USER* user) {
	USER* del = NULL;
	USER* d_temp = NULL;
	USER* temp = NULL;
	int k = 2;

	del = user;

	//첫번째 원소 없애는 경우
	if (i == 1) {
		del->num = dead_num;

		user = temp = user->next;

		if (user != user->next) {
			while (temp->next != del) {
				temp->num -= 1;
				temp = temp->next;
			}
			temp->num -= 1;

			temp->next = user;
		}
	}
	else {
		temp = user;
		del = del->next;

		while (k < i) {
			temp = temp->next;
			del = del->next;
			k++;
		}

		del->num = dead_num;

		//마지막 원소 없애는 경우
		if (del->next == user) {
			temp->next = user;
		}

		//마지막 원소가 아닌 원소 없애는 경우
		else {
			temp->next = del->next;

			temp = temp->next;

			while (temp->next != user) {
				temp->num -= 1;
				temp = temp->next;
			}

			temp->num -= 1;
		}
	}

	del->next = NULL;

	if (dead == NULL) {
		dead = del;
	}
	else {
		d_temp = dead;

		while (d_temp->next != NULL) {
			d_temp = d_temp->next;
		}

		d_temp->next = del;
	}

	return dead;
}

//죽은 사람들의 정보를 한 번에 출력해주는 함수
void printlist(USER* user) {
	USER* temp;
	temp = user;

	printf("Dead No.     Name.       bullet No.\n");
	while (temp->next != NULL) {
		printf("%2d           %s          %d\n", temp->num, temp->name, temp->bullet);
		temp = temp->next;
	}

	printf("%2d           %s          %d\n", temp->num, temp->name, temp->bullet);
	printf("\n");
}

#endif // Russian_Roulette_H_INCLUDED
