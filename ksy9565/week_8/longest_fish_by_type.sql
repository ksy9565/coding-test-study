# SELECT i.id, n.fish_name, i.length
# FROM fish_info i
#     JOIN fish_name_info n
#     ON i.fish_type = n.fish_type
# WHERE (i.fish_type, i.length) IN (SELECT fish_type, max(length)
#                                  FROM fish_info
#                                  GROUP BY fish_type)
# ORDER BY i.id;

SELECT i.id, n.fish_name, i.length
FROM fish_info i
    JOIN (SELECT fish_type, max(length) AS max_length
         FROM fish_info
         GROUP BY fish_type) m
    ON i.fish_type = m.fish_type
    AND i.length = m.max_length
    JOIN fish_name_info n
    ON i.fish_type = n.fish_type
ORDER BY i.id;
