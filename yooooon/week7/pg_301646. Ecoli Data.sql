-- https://school.programmers.co.kr/learn/courses/30/lessons/301646

SELECT COUNT(*) AS COUNT
FROM ECOLI_DATA
WHERE (GENOTYPE & 2) = 0
  AND (GENOTYPE & 5) != 0;