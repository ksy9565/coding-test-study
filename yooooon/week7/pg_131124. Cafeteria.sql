-- https://school.programmers.co.kr/learn/courses/30/lessons/131124

SELECT m.member_name, r.review_text, r.review_date
FROM member_profile m
    JOIN rest_review r
    ON m.member_id = r.member_id
WHERE m.member_id IN (SELECT member_id
                     FROM rest_review
                     GROUP BY member_id
                     HAVING count(*) = (SELECT max(cnt)
                                       FROM (SELECT member_id, count(*) AS cnt
                                            FROM rest_review
                                            GROUP BY member_id) AS counts))
ORDER BY r.review_date ASC, r.review_text ASC;