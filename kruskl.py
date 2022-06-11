class Graph:
    
    def __init__(self, vertex):
        self.V = vertex
        self.graph = []


    def addedge(self, a, b, c):
        self.graph.append([a, b, c])


    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])


    def applyunion(self, parent, rank, u, v):
        uroot = self.find(parent, u)
        vroot = self.find(parent,v)


        if rank[uroot] < rank[vroot]:
            parent[uroot] = vroot

        elif rank[uroot] > rank[vroot]:
            parent[vroot] = uroot

        else:
            parent[vroot] = uroot
            rank[uroot] += 1


    def kruskalalgo(self):
        result = []
        i, e = 0, 0
        self.graph = sorted(self.graph, key=lambda item: item[2])
        parent = []
        rank = []


        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        while e < self.V - 1:
            a, b, c = self.graph[i]
            i = i + 1
            u = self.find(parent, a)
            v = self.find(parent, b)
            if u != v:
                e = e + 1
                result.append([a, b, c])
                self.applyunion(parent, rank, u, v)


        for a, b, weight in result:
            print("%d : %d = %d" % (a, b, weight))


g = Graph(5)

g.addedge(0, 1, 2)

g.addedge(0, 2, 5)

g.addedge(1, 2, 4)

g.addedge(1, 3, 7)

g.addedge(2, 3, 5)

g.addedge(2, 4, 1)

g.addedge(3, 4, 3)

g.kruskalalgo()