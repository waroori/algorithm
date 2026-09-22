# algorithm

알고리즘 문제 풀이 기록. 풀이 코드와 함께 **왜 틀렸는지**를 남기는 것이 목적이다.

## 구조

```
atcoder/<콘테스트><문제>/
├── main.cpp     제출해서 AC 받은 소스 그대로
└── README.md    문제 요약 · 접근 · 함정 · 다른 풀이
template/
└── main.cpp     새 문제 시작용 보일러플레이트
```

작업은 별도 스크래치 파일에서 하고, **AC를 받은 뒤에** 해당 디렉터리로 복사해
커밋한다. 스크래치 파일을 덮어쓰며 푸는 습관 때문에 이전 풀이가 사라지는 것을
막기 위한 규칙이다.

## 목록

| 문제 | 배점 | 알고리즘 | 결과 | 메모 |
|---|---|---|---|---|
| [ABC176 D — Wizard in Maze](atcoder/abc176_d) | 400 | 0-1 BFS | AC 86ms | 경계 검사 순서 실수로 RE 1회 |

## 로컬 실행

```bash
g++ -O2 -std=c++17 -o main main.cpp
./main < input.txt
```

범위 밖 접근이 의심되면 샌티타이저로 돌린다. 로컬 `-O2`에서는 멀쩡히 정답이
나오면서 채점에서만 RE가 나는 경우를 여기서 잡을 수 있다.

```bash
g++ -O1 -g -std=c++17 -fsanitize=address,undefined -o main main.cpp
./main < input.txt
```

## 제출 전 체크리스트

- [ ] `freopen("input.txt", ...)` 주석 처리했는가
- [ ] 배열 접근 **전에** 경계 검사를 하는가
- [ ] 도달 불가 / 예외 케이스 출력이 맞는가
