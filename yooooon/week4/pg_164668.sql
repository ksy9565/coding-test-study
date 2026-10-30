-- https://school.programmers.co.kr/learn/courses/30/lessons/164668

# USED_GOODS_BOARD, USED_GOODS_USER
# 중고 거래의 총 금액이 70만 원 이상인 사람의 회원 ID, 닉네임, 총거래금액
# 총거래금액을 기준으로 오름차순
SELECT U.USER_ID,
        U.NICKNAME,
        SUM(B.PRICE) AS TOTAL_SALES
    FROM USED_GOODS_BOARD AS B
    JOIN USED_GOODS_USER AS U
    ON B.WRITER_ID = U.USER_ID
    WHERE B.STATUS = 'DONE'
    GROUP BY U.USER_ID, U.NICKNAME
    HAVING TOTAL_SALES >= 700000
    ORDER BY TOTAL_SALES ASC