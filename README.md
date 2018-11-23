# Russian_Roulette

1. Introduction
>- student.txt file로부터 학생들의 이름을 입력받아 circular linked list인 user에 저장됩니다.
>- 총알을 넣을 수 있는 공간이 사람 수만큼 있고, 사람이 죽으면 공간도 같이 감소합니다.
>- 각 게임마다 총알의 위치와 가장 먼저 시작하는 사람은 무작위로 지정됩니다.
>- 모든 사람이 죽을 때까지 게임을 진행합니다.
>- 사람이 죽을 때마다 차례로 linked list인 dead에 저장됩니다.
>- 게임 종료 후 죽은 순서와 이름, 몇 번째 총알에 죽었는지 한 번에 출력해줍니다.

2. Execution result
![execution_result1](https://user-images.githubusercontent.com/44752186/48939284-0fbc6c00-ef57-11e8-9c50-bca1fbab5c75.jpg)
>첫 번째 게임을 예시로 가지고 왔습니다.
>총알이 몇 번에 들어가있고, 누가 먼저 시작하는지 알려줍니다.
>게임을 진행하다가 사망자가 나오면 그 게임을 종료하고 다음 게임을 진행합니다.
![execution_result2](https://user-images.githubusercontent.com/44752186/48939294-1d71f180-ef57-11e8-9e46-a68abf1353c6.jpg)
>게임이 종료되면 Dead Number에 따라 차례로 죽은 사람의 이름과 몇 번째 총알에 죽었는지 출력합니다.

