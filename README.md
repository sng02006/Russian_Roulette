# Russian_Roulette

## Introduction
---------------
>- student.txt file로부터 학생들의 이름을 입력받아 circular linked list인 user에 저장됩니다.
>- 총알을 넣을 수 있는 공간이 사람 수만큼 있고, 사람이 죽으면 공간도 같이 감소합니다.
>- 각 게임마다 총알의 위치와 가장 먼저 시작하는 사람은 무작위로 지정됩니다.
>- 모든 사람이 죽을 때까지 게임을 진행합니다.
>- 사람이 죽을 때마다 차례로 linked list인 dead에 저장됩니다.
>- 게임 종료 후 죽은 순서와 이름, 몇 번째 총알에 죽었는지 한 번에 출력해줍니다.

## Execution result
-------------------
>![execution_result1](https://user-images.githubusercontent.com/44752186/48939284-0fbc6c00-ef57-11e8-9c50-bca1fbab5c75.jpg)
>첫 번째 게임을 예시로 가지고 왔습니다.
>총알이 몇 번에 들어가있고, 누가 먼저 시작하는지 알려줍니다.
>게임을 진행하다가 사망자가 나오면 그 게임을 종료하고 다음 게임을 진행합니다.
>![execution_result2](https://user-images.githubusercontent.com/44752186/48939294-1d71f180-ef57-11e8-9e46-a68abf1353c6.jpg)
>게임이 종료되면 Dead Number에 따라 차례로 죽은 사람의 이름과 몇 번째 총알에 죽었는지 출력합니다.

## Code
-------
###source file
####main
argu       | type | 
---------- | :--: | ------------------------------------------------------
size	   | int  | student.txt로부터 이름을 하나씩 불러올 때마다 +1이 됩니다.
name_temp  | char | new user를 만들기 전에 임시로 이름을 저장해두는 변수입니다.
new_user   | USER | create_user를 통해 만들어진 node를 임시로 저장하는 변수입니다.
user       | USER | 만들어진 new_user를 차례로 저장하는 변수입니다.
temp	   | USER | user 대신 움직이면서 정보를 읽어올 때 사용하는 변수입니다.
dead       | USER | game_start에 의해 반환된 죽은 사람들의 list를 저장하는 변수입니다.

create_user로 circular linked list인 user를 만듭니다.
user를 매개변수로 game_start로 넘겨줘서 game_start에서 linked list인 dead를 반환받습니다.
printlist를 이용해 두 번째 Execution result와 같이 출력해줍니다.

###header file
####struct
struct user를 typedef로 USER라고 정의합니다.

argu	 | type |
-------- | :--: | ------------------------------------------------------------------------------
num		 | int  | 사람이 죽기 전까지는 몇 번째로 입력된 사용자인지, 죽은 이후에는 몇 번째로 죽었는지 나타내는 변수입니다.
bullet	 | USER | 몇 번째 총알에 죽었는지 저장하는 변수입니다.
name	 | USER | 사용자의 이름을 저장하는 변수입니다.
next	 | USER | 다음 node를 가리키는 변수입니다.

####create_user
매개변수로 받은 size, name_temp를 USER type의 newptr에 저장해줍니다.
-malloc으로 동적 할당을 받습니다.
-USER type로 선언한 newptr->num에 size를 저장합니다.
-newptr->bullet에는 아직 사용자가 죽지 않았으므로 0을 저장합니다.
-strcpy를 사용해서 name_temp를 newptr->name에 복사합니다.
-newptr을 반환합니다.

####game_start
매개변수로 size를 number_of_user로 전달받고, user를 전달받아 사람이 모두 죽을 때까지 게임을 진행합니다.

argu	 | type |
-------- | :--: | -----------------------------------------------------------------------------------------------------------------------------
revolver | int  | 총알이 들어있는 공간의 번호를 저장하는 변수입니다. 차례마다 1씩 감소하면서 1일 때 참가자 1명이 사망합니다.
bullet	 | int  | 총알이 들어있는 공간의 번호를 저장하는 변수입니다. revolver가 값이 변하기 때문에 사람이 죽었을 때 몇 번째 총알인지 알 수 없으므로 똑같은 번호를 하나 더 저장합니다.
first	 | int  | 게임을 가장 먼저 시작할 사람의 번호를 저장하는 변수입니다.
dead_num | USER | 몇 번째 차례에 죽었는지 저장하는 변수입니다.
temp	 | USER | user 대신 움직이면서 정보를 읽어올 때 사용하는 변수입니다.
temp1	 | USER | 첫 번째 사용자가 죽는 경우 dead_user 함수를 실행하기 전에 미리 그 다음 사용자의 정보가 저장되어있는 주소를 임시로 저장해두는 변수입니다.
dead	 | USER | 죽은 사람들의 정보를 포함하고있는 linked list입니다.

- bullet과 revolver에 1~남은 사람의 수 중에 random하게 설정합니다.
- first도 1~남은 사람의 수 중에 random하게 설정합니다.
- revolver > 1이면 temp->num번 참가자가 생존하였습니다. 다음 참가자로 넘어갑니다.를 출력하고 revolver를 1 감소시키고 다음 참가자로 차례가 넘어갑니다.
- revolver = 1이면 dead_num를 증가시키고, temp->num번 참가자가 dead_num번째로 사망하였습니다.를 출력합니다. temp->bullet에 bullet을 저장하고, dead_user로 dead에 죽은 사람의 정보를 저장합니다. 그리고 사용자의 수를 1 감소시킵니다.
- revolver < 0이면 이번 게임을 종료합니다.를 출력합니다.
- 남은 사람으로 다시 bullet과 revolver, first를 설정하고, 게임을 진행합니다.
- 남은 사람이 없으면 dead를 반환합니다.

####dead_user
매개변수로 dead_num, dead, game_start의 temp->num인 i와 user를 전달받습니다.
user에서 죽은 사람의 정보를 del에 저장하고 del과 user의 연결을 끊습니다.
그리고 del을 dead 끝에 추가합니다.

argu	 | type |
-------- | :--: | ---------------------------------------------
del		 | USER | user 중에 죽은 사람의 정보를 저장해서 dead에 저장합니다.
d_temp	 | USER | dead 대신 움직이면서 정보를 읽어올 때 사용하는 변수입니다.
temp	 | USER | user 대신 움직이면서 정보를 읽어올 때 사용하는 변수입니다.

- 없앨 원소의 num에 dead_num을 저장하고 이후 원소의 num을 1씩 감소시킵니다.
- del을 dead에 추가해주고 dead를 반환합니다.

####printlist
매개변수로 입력받은 linked list를 차례로 출력해주는 함수입니다.

