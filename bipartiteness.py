# Python program to find out whether a
# given graph is Bipartite or not

class Graph():

	def __init__(self, V):
		self.V = V
		self.graph = [[0 for column in range(V)] \
				for row in range(V)]
		#print(self.graph)
#function to check bipartiteness
	def isBipartite(self, source):

		colourlist = [-1]*self.V
		#starting with the source coloring it with 1 and its neighbor with 0
		colourlist[source] = 1
		#creating a queue to keep track of the visited nodes using BFS
		queue=[]

		queue.append(source)
		#traversing thw queue until empty
		while queue:
			u=queue.pop()
			#if the graph has a loop ie a node to itself
			if self.graph[u][u] == 1:
				return False
			for v in range(self.V):
				#if there is an edge between two nodes(u, v) and if v is not coloured until now
				if self.graph[u][v] == 1 and colourlist[v] == -1:
					colourlist[v] = 1-colourlist[u]
					queue.append(v)
				#if there is an edge between two nodes(u, v) and if v has same color as u
				elif self.graph[u][v] == 1 and colourlist[v] == colourlist[u]:
					return False
		return True
g = Graph(4)
g.graph=[[1, 1, 0, 1],
	[1, 0, 1, 0],
	[0, 1, 0, 1],
	[1, 0, 1, 0]
	]
#print(g.graph)
print ("Yes" if g.isBipartite(0) else "NO")
