# graph = {
#     0: {1: 2, 2: 4},
#     1: {3: 3},
#     2: {3: 1},
#     3: {}
# }

import heapq

def dijkstra(graph, start):
    INF = float('inf') # Define infinity as a placeholder for unvisited nodes
    dist = {vertex: INF for vertex in graph} # Initialize all distances as infinity
    dist[start] = 0 # Distance to the start node is zero
    pq = [(0, start)] # Priority queue with start node

    while pq:
        current_distance, current_vertex = heapq.heappop(pq) # Pop the vertex with the smallest distance

        if current_distance > dist[current_vertex]:
            continue # Ignore if the distance is not optimal

        # Explore neighbors
        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight # Calculate new distance

            # Relaxation step
            if distance < dist[neighbor]:
                dist[neighbor] = distance # Update distance if it's smaller
                heapq.heappush(pq, (distance, neighbor)) # Push neighbor with updated distance to the priority queue

    return dist # Return the computed shortest distances
