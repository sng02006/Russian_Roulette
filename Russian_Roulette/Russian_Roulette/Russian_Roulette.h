#ifndef Russian_Roulette_H_INCLUDED
#define Russian_Roulette_H_INCLUDED

//������� ������ �Է¹��� ����ü ����
typedef struct user {
	int num, bullet;
	char *name;
	struct user *next;
}USER;

USER* game_start(int number_of_user, USER* user);
USER* create_user(int size, char name_temp[9], USER *user);
USER* dead_user(int dead_num, USER* dead, int i, USER* user);
void printlist(USER* user);

//���� ���� �Լ�
USER* game_start(int number_of_user, USER* user) {
	int revolver, bullet;
	int first;
	int dead_num = 0;//�״� ����
	USER* temp = NULL;//user ��� �����̸� ������ �о�� �� ����ϴ� ������
	USER* temp1 = NULL;//ù��° ����ڰ� �״� ��� dead_user �Լ��� �����ϱ� ���� �̸� �� ���� ������� ������ ����Ǿ��ִ� �ּҸ� �����ص�
	USER* dead = NULL;

	srand(time(NULL));

	//����ڰ� ��� ���� ������ ���� ����
	while (number_of_user >= 1) {
		bullet = revolver = rand() % number_of_user + 1;//�Ѿ��� ����ִ� ������ ��ȣ�� 1~���� ��� �� �߿� �����ϰ� ����
		printf("�Ѿ��� %d���� ����ֽ��ϴ�.\n\n", revolver);
		first = rand() % number_of_user + 1;//���� ���� ������ ����� ��ȣ�� 1~���� ��� �� �߿� �����ϰ� ����
		printf("%d�� �����ڰ� ���� ���� ������ �����մϴ�.\n\n", first);

		temp = user;

		//������ ������ ����ڱ��� �����͸� �̵�
		while (temp->num != first) {
			temp = temp->next;
		}

		while (revolver > 0) {
			if (revolver > 1) {
				printf("ƽ\n");
				printf("%d�� �����ڰ� �����Ͽ����ϴ�.\n", temp->num);
				printf("���� �����ڷ� �Ѿ�ϴ�.\n\n");
				temp = temp->next;
			}
			else {
				dead_num++;
				printf("��!!\n");
				printf("%d�� �����ڰ� %d��°�� ����Ͽ����ϴ�.\n\n", temp->num, dead_num);
				temp->bullet = bullet;//�� ��° ������ �ִ� �Ѿ˿� �׾����� ����

				//ù��° ����ڰ� �״� ��� dead_user �Լ��� �����ϱ� ���� �̸� �� ���� ������� ������ ����Ǿ��ִ� �ּҸ� �����ص�
				if (temp->num == 1)
					temp1 = user->next;
				else
					temp1 = user;

				//user���� ���� ����� ������ ���ְ� dead�� �߰�
				dead = dead_user(dead_num, dead, temp->num, user);

				user = temp1;

				number_of_user--;//����� �� ����
			}

			revolver--;

		}
		printf("�̹� ������ �����մϴ�.\n\n\n\n\n");
	}

	return dead;
}

//���� �Ҵ� �޾� node �ϳ��� ����� �Է¹��� ������ �����ϴ� �Լ�
USER* create_user(int size, char name_temp[9], USER *user) {
	USER *newptr = NULL;

	newptr = (USER*)malloc(sizeof(USER));

	newptr->num = (int*)malloc(sizeof(int));
	newptr->bullet = (int*)malloc(sizeof(int));
	newptr->name = (char*)malloc(sizeof(char)*strlen(name_temp) + 1);

	if (newptr == NULL) {
		printf("����\n");
		exit(1);
	}

	newptr->num = size;
	newptr->bullet = 0;
	strcpy(newptr->name, name_temp);
	newptr->next = newptr;

	return newptr;
}

//���� ����� ������ circular linked list���� ���ְ� dead��� linked list�� �����ϴ� �Լ�
USER* dead_user(int dead_num, USER* dead, int i, USER* user) {
	USER* del = NULL;
	USER* d_temp = NULL;
	USER* temp = NULL;
	int k = 2;

	del = user;

	//ù��° ���� ���ִ� ���
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

		//������ ���� ���ִ� ���
		if (del->next == user) {
			temp->next = user;
		}

		//������ ���Ұ� �ƴ� ���� ���ִ� ���
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

//���� ������� ������ �� ���� ������ִ� �Լ�
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
