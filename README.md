# algorithm

알고리즘 문제 풀이 기록. 풀이 코드와 함께 **왜 틀렸는지**를 남기는 것이 목적이다.

## 구조

```
new.sh                    새 문제 폴더 생성 스크립트
template/main.cpp         보일러플레이트
.vscode/tasks.json        Cmd+Shift+B 로 빌드·실행
atcoder/<콘테스트>/<문제>/
├── <콘테스트>_<문제>.cpp   풀이 소스  (예: abc176_D.cpp)
├── input.txt             샘플 입력
└── README.md             요약 · 접근 · 함정 · 다른 풀이
```

## 새 문제 풀 때

```bash
cd ~/Desktop/algorithm
./new.sh abc468 d
```

`atcoder/abc468/D/` 가 만들어지고 `abc468_D.cpp`·빈 input.txt·README 뼈대가
들어간다. 그 `.cpp` 를 VSCode에서 열고 바로 작업한다. **복사해 오는 단계는 없다 —
처음부터 저장소 안에서 푼다.**

AC를 받으면 README를 채우고 커밋한다.

```bash
git add -A && git commit -m "ABC468 D 풀이 추가" && git push
```

최상위 목록 표에 한 줄 추가하는 것도 잊지 말 것.

## 빌드·실행

VSCode에서 풀이 `.cpp` 를 연 채로 **Cmd+Shift+B**. 그 파일이 있는 폴더에서
컴파일하고 `input.txt` 를 물려 실행한다.

터미널로 하려면:

```bash
g++ -O2 -std=c++17 -o main abc176_D.cpp && ./main < input.txt
```

범위 밖 접근이 의심되면 샌티타이저 빌드를 쓴다 (작업 목록에서 "빌드 + 실행
(샌티타이저)" 선택). 로컬 `-O2` 에서는 멀쩡히 정답이 나오면서 채점에서만 RE가
나는 경우를 여기서 잡는다.

```bash
g++ -O1 -g -std=c++17 -fsanitize=address,undefined -o main_san abc176_D.cpp && ./main_san < input.txt
```

## 제출 전 체크리스트

- [ ] `freopen("input.txt", ...)` 주석 처리했는가
- [ ] 배열 접근 **전에** 경계 검사를 하는가
- [ ] 도달 불가 / 예외 케이스 출력이 맞는가

## 목록

| 문제 | 배점 | 알고리즘 | 결과 | 메모 |
|---|---|---|---|---|
| [ABC176 D — Wizard in Maze](atcoder/abc176/D) | 400 | 0-1 BFS | AC 86ms | 경계 검사 순서 실수로 RE 1회 |
