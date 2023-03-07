# BFS本质是树形结构，一层一层从左向右（遍历），把树结构扁平化。
#注意顺序，如果是树感觉无所谓，但是是图的话要注意连接顺序
#辅助DS就是queue，塞入起始点A，然后把连接点A取出，再把起始点相连的点塞进queue里，依次取出再依次塞入

#DFS 找一个点 然后一路走到底，走到底之后再往回走
#辅助DS是stack，塞入起始点A，pop A，pushA的连接点BC，依次pop依次push

graph={
    "A": ["B", "C"],
    "B": ["A", "C", "D"],
    "C": ["A", "B", "D"],
    "D": ["B", "C", "E", "F"],
    "E": ["C", "D"],
    "F": ["D"]
}
#上面是个dictionary 
def BFS(graph, s):
    queue=[]
    queue.append(s) #s塞入队列
    visited=set() #访问过的nodes都放进set python the set is hash
    visited.add(s)
    #要在这里做一个映射来存储每个点对应的前一个点，这样可以找到最短路线
    parent={s: None}


    while(len(queue)>0): #只要queue不空，就那一个node出来
        vertex=queue.pop(0) #取出起始点s
        #s的连接点放进去
        nodes=graph[vertex] #和vertex连接的点
        for node in nodes:
            if node not in visited:
                queue.append(node) #没见过就塞入queue
                visited.add(node)  #同时也塞入visited
                parent[node]=vertex
        print(vertex)
    return parent



def DFS(graph,s):
    stack=[]
    stack.append(s) #s塞入队列
    visited=set() #访问过的nodes都放进set python the set is hash
    visited.add(s)
    parent={s: None}
    while(len(stack)>0): #只要queue不空，就那一个node出来
        vertex=stack.pop() #stack是后进先出，pop最后元素
        #s的连接点放进去
        nodes=graph[vertex]
        for node in nodes:
            if node not in visited:
                stack.append(node) #没见过就塞入queue
                visited.add(node)  #同时也塞入visited
                parent[node]=vertex
        print(vertex)
    return parent


parent=BFS(graph,"E")
# for key in parent:
#     print(key, parent[key])

s=v='F' #到达点
row=[]
row.append(v)
while v!=None:
    # print(v)
    v=parent[v] #到达点点前一点，重置v
    row.append(v)
row.reverse()    
print(f"The shortest way to {s} is {row}")

