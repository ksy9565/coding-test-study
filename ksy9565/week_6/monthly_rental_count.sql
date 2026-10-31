SELECT month(start_date) AS month, car_id, count(*) AS records
FROM car_rental_company_rental_history
WHERE car_id IN (SELECT car_id -- 8월~10월 사이에 총 대여 횟수 5회 이상인 car_id
                FROM car_rental_company_rental_history
                WHERE start_date >= '2022-08-01'
                    AND start_date < '2022-11-01'
                GROUP BY car_id
                HAVING count(*) >= 5)
    AND start_date >= '2022-08-01' -- car_id로 필터링 했기 때문에
    AND start_date < '2022-11-01'  -- 날짜로 한번 더 필터링 해줘야 8~10월만 남음
GROUP BY month(start_date), car_id
ORDER BY month ASC, car_id DESC;