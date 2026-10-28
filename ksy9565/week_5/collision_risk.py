def solution(points, routes):
    answer = 0
    
    robots = []
    for route in routes:
        start = route[0] - 1
        r, c = points[start][0], points[start][1]
        robots.append([r,c])
    
    # 로봇의 경로를 기록하는 함수
    def move(robot, route):
        record = [(robot[0], robot[1])]
        for i in route[1:]:
            i -= 1
            while True:
                if robot == points[i]:
                    break
                
                if robot[0] < points[i][0]:
                    robot[0] += 1
                elif robot[0] > points[i][0]:
                    robot[0] -= 1
                elif robot[1] < points[i][1]:
                    robot[1] += 1
                elif robot[1] > points[i][1]:
                    robot[1] -= 1
                
                record.append((robot[0], robot[1]))
                
        return record
    
    # 모든 로봇의 경로를 records에 담는다.
    # 열번호가 같으면 같은 시간
    # 같은 열번호이면서 값(좌표)도 같으면 충돌한 것임.
    maxlen = 0
    records = []
    for i in range(len(robots)):
        record = move(robots[i], routes[i])
        records.append(record)
        maxlen = max(maxlen, len(record))
    
    # 중복되는 위치의 개수 찾기: 충돌 횟수는 서로 다른 충돌 좌표의 개수임.
    for i in range(maxlen):
        num_robots = 0
        col = []
        
        # 같은 열번호 좌표를 하나의 리스트로 묶음
        for record in records:
            if i < len(record):
                col.append(record[i])
                
        for x in set(col):
            if col.count(x) > 1:
                answer += 1
        
    return answer