import heapq

class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        
        # [u,v,w]를 인접 리스트로 변환
        # graph[u] = (v,w)
        # [(v1,w1),
        #  (vn,wn)]
        graph = [[] for _ in range(n+1)]
        for u,v,w in times:
            graph[u].append((v,w))

        INF = 1_000_000_000 # 10억
        dist = [INF] * (n+1)

        # 우선순위 큐: 거리 기준 정렬(min heap)
        # (k로부터 최단거리, 현재노드)의 형태
        q = []
        heapq.heappush(q, (0,k))

        dist[k] = 0

        while q:
            d, curr = heapq.heappop(q)

            if dist[curr] < d: # 이미 더 짧은 거리를 발견했다면 넘김
                continue

            for next, weight in graph[curr]: # 연결된 모든 노드를 순회
                cost = d + weight

                if cost < dist[next]: # 더 짧은 거리로 갱신 후 큐에 삽입
                    dist[next] = cost
                    heapq.heappush(q, (cost, next))
        
        if INF in dist[1:]:
            return -1
        return max(dist[1:])