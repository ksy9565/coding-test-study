-- 코드를 입력하세요
# 테스트 케이스에 오류가 있어 동점자 포함하지 않아야 정답 처리됨
# 정답 코드는 동점자 포함해야 함
# 제목도 이상해 식당 목록 아니잖아
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