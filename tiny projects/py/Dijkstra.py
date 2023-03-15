#Dijkstra的本质是BFS+priorityqueue，priority就是距离起点的距离
import sys
import heapq
import math
graph={
    "A": {"B":5, "C":1},
    "B": {"A":5, "C":2, "D":1},
    "C": {"A":2, "B":5, "D":4, "E":8},
    "D": {"B":1, "C":4, "E":3, "F":6},
    "E": {"C":8, "D":3},
    "F": {"D":6}
}
#上面是个dictionary 

def init_distance(graph, s):
    distance={s:0}
    for vertex in graph:
        if vertex!=s:
            distance[vertex]=math.inf
    return distance

def Dijkstra(graph, s,e):
    pqueue=[] #priority queue
    heapq.heappush(pqueue,(0,s)) #起点加入priority queue
    visited=set() #访问过的nodes都放进set python the set is hash
   
    #要在这里做一个映射parent来存储每个点对应的前一个点，这样可以找到最短路线
    parent={s: None}
    distance={s:0} #到起始点的距离
    while(len(pqueue)>0): #只要queue不空，就那一个node出来
        pair=heapq.heappop(pqueue) #取出一个点和它的距离
        dist=pair[0]
        vertex=pair[1]
        visited.add(vertex) #只有取出来的才算visited，否则不算

        nodes=graph[vertex].keys() #和vertex连接的点
        for node in nodes:
            if node not in visited:
                if dist+graph[vertex][node]<distance[node]:
                    heapq.heappush(pqueue, (dist+graph[vertex][node], node))
                    parent[node]=vertex
                    distance[node]=dist+graph[vertex][node]
    return parent,distance

parent, distance=Dijkstra(graph, "A")
print(parent)
print(distance)
   
