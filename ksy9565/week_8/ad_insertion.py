def solution(play_time, adv_time, logs):
    answer = ''
    
    def second(time):
        h, m, s = map(int, time.split(':'))
        return h*3600 + m*60 + s
    
    play_time_sec = second(play_time)
    adv_time_sec = second(adv_time)
    
    prefix_sum = [0]*(play_time_sec+1)
    
    for log in logs:
        start, end = log.split('-')
        start = second(start)
        end = second(end)
        prefix_sum[start] += 1
        prefix_sum[end] -= 1
    
    # i초에서의 시청자 수
    for i in range(1, play_time_sec+1):
        prefix_sum[i] += prefix_sum[i-1]
    
    # 0초~i초까지 누적 재생 시간
    for i in range(1, play_time_sec+1):
        prefix_sum[i] += prefix_sum[i-1]
    
    max_time = prefix_sum[adv_time_sec-1]
    answer = 0
    
    for right in range(adv_time_sec, play_time_sec+1):
        cur = prefix_sum[right] - prefix_sum[right-adv_time_sec]
        if cur > max_time:
            max_time = cur
            answer = right-adv_time_sec+1
    
    h = answer // 3600
    m = (answer % 3600) // 60
    s = answer % 60
    
    return f'{h:02d}:{m:02d}:{s:02d}'
    
    
    return answer
