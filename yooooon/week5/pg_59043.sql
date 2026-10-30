-- 코드를 입력하세요
-- 있었는데요 없었습니다
-- https://school.programmers.co.kr/learn/courses/30/lessons/59043

SELECT i.animal_id, i.name
from animal_ins as i
left join animal_outs as o
    on i.animal_id = o.animal_id
where i.datetime > o.datetime
order by i.datetime asc;