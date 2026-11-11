-- 코드를 작성해주세요
# &: 비트단위 AND 연산자
# 5의 이진수 101과 genotype의 이진수를 연산
# MySQL은 0이면 False, 나머지 True
SELECT count(*) as count
FROM ecoli_data
WHERE (genotype & 5) AND NOT (genotype & 2)