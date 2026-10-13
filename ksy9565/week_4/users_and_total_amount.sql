-- USED_GOODS_BOARD와 USED_GOODS_USER 테이블에서
-- 완료된 중고 거래의 총금액이 70만 원 이상인 사람의
-- 회원 ID, 닉네임, 총거래금액을 조회하는 SQL문을 작성해주세요.
-- 결과는 총거래금액을 기준으로 오름차순 정렬해주세요.

-- 완료된 중고거래: DONE
-- 총금액 70만원 이상인 사람: GROUP BY로 각 유저별로 묶은 후 HAVING으로 70만원 조건 필터링
-- SUM()은 GROUP BY 다음에 실행되므로 유저별로 각각 가격이 더해짐
SELECT u.user_id, u.nickname, sum(b.price) AS total_sales
FROM used_goods_board b
JOIN used_goods_user u ON b.writer_id = u.user_id
WHERE b.status = 'DONE'
GROUP BY u.user_id
HAVING sum(b.price) >= 700000
ORDER BY total_sales ASC;