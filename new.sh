#!/bin/sh
# 새 문제 폴더를 만든다.
#   ./new.sh abc468 d      →  atcoder/abc468_d/
#   ./new.sh abc468_d      →  같음
set -e
R=$(cd "$(dirname "$0")" && pwd)

case $# in
  2) slug="$1_$2" ;;
  1) slug="$1" ;;
  *) echo "사용법: ./new.sh <콘테스트> <문제>   예) ./new.sh abc468 d"; exit 1 ;;
esac
slug=$(printf '%s' "$slug" | tr 'A-Z' 'a-z')
contest=${slug%%_*}
prob=$(printf '%s' "${slug##*_}" | tr 'a-z' 'A-Z')
dir="$R/atcoder/$slug"

if [ -d "$dir" ]; then
  echo "이미 있습니다: atcoder/$slug"
  exit 0
fi

mkdir -p "$dir"
cp "$R/template/main.cpp" "$dir/main.cpp"
: > "$dir/input.txt"

cat > "$dir/README.md" <<TPL
# $(printf '%s' "$contest" | tr 'a-z' 'A-Z') $prob — 제목

| | |
|---|---|
| 문제 | https://atcoder.jp/contests/$contest/tasks/$slug |
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

echo "만들었습니다: atcoder/$slug"
echo "  $dir/main.cpp"
echo "  $dir/input.txt   ← 샘플 입력 붙여넣기"
echo "  $dir/README.md"
