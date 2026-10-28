def solution(n, s, a, b, fares):
    answer = 1_000_000_000
    INF = 1_000_000_000
    
    # i -> j 거리 무한으로 초기화
    graph = [[INF] * (n+1) for _ in range(n+1)]
    
    # 자기자신은 거리 0
    for i in range(1, n+1):
        graph[i][i] = 0
    
    # 양방향으로 같은 가중치를 가짐
    for u,v,w in fares:
        graph[u][v] = w
        graph[v][u] = w
    
    # 플로이드-워셜: graph[i][j] = i -> j의 최단거리
    # 모든 노드에 대해 다른 모든 노드까지의 최단거리를 구함
    # 점화식: 경유노드 k, i->k->j의 거리가 기존 i->j보다 짧으면 갱신
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j])
    
    # s부터 k까지 합승 후 a, b로 이동하는 경우 중 가장 작은 경우
    for k in range(1,n+1):
        answer = min(answer, graph[s][k]+graph[k][a]+graph[k][b])
    
    return answer