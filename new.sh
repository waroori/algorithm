#!/bin/sh
# 새 문제 폴더를 만든다.
#   ./new.sh abc468 d   →  atcoder/abc468/D/abc468_D.cpp
#   ./new.sh abc468_d   →  같음
set -e
R=$(cd "$(dirname "$0")" && pwd)

case $# in
  2) contest="$1"; prob="$2" ;;
  1) contest="${1%%_*}"; prob="${1##*_}" ;;
  *) echo "사용법: ./new.sh <콘테스트> <문제>   예) ./new.sh abc468 d"; exit 1 ;;
esac
contest=$(printf '%s' "$contest" | tr 'A-Z' 'a-z')
prob=$(printf '%s' "$prob" | tr 'a-z' 'A-Z')
dir="$R/atcoder/$contest/$prob"
src="$dir/${contest}_${prob}.cpp"

if [ -d "$dir" ]; then
  echo "이미 있습니다: atcoder/$contest/$prob"
  exit 0
fi

mkdir -p "$dir"
cp "$R/template/main.cpp" "$src"
: > "$dir/input.txt"

cat > "$dir/README.md" <<TPL
# $(printf '%s' "$contest" | tr 'a-z' 'A-Z') $prob — 제목

| | |
|---|---|
| 문제 | https://atcoder.jp/contests/$contest/tasks/${contest}_$(printf '%s' "$prob" | tr 'A-Z' 'a-z') |
| 배점 | |
| 결과 | |
| 제출 | |
| 알고리즘 | |
| 푼 날짜 | $(date +%Y-%m-%d) |

## 문제 요약

## 접근

## 함정

## 다른 풀이
TPL

echo "만들었습니다: atcoder/$contest/$prob"
echo "  ${contest}_${prob}.cpp"
echo "  input.txt   ← 샘플 입력 붙여넣기"
echo "  README.md"
