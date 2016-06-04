/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.asm.algorithms.graph;

import com.asm.data_structures.graph.Graph;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;

/**
 *
 * @author asmita
 */
public class Prim {
    
    private Prim() {
        
    }
    
    public static Graph.Path<Integer> getMinimumSpanningTree (Graph <Integer> graph, Graph.Vertex <Integer> start) {
        if (graph == null) {
            throw new NullPointerException("Graph must be non-null.");
        }
        
        Graph.Path<Integer> path = new Graph.Path<>();
        Set <Graph.Vertex <Integer>> unvisitedVertices = new HashSet<>();
        Queue <Graph.Edge <Integer>> availableEdges = new PriorityQueue<>();
        
        Graph.Vertex <Integer> vertex;
        
        unvisitedVertices.addAll(graph.getVertices());
        unvisitedVertices.remove(start);
        
        vertex = start;
        while (!unvisitedVertices.isEmpty()) {
            for (Graph.Edge <Integer> e: vertex.getEdges()) {
                if (unvisitedVertices.contains(e.getToVertex())) {
                    availableEdges.add(e);
                }
            }
            Graph.Edge<Integer> lowestCostEdge = availableEdges.remove();
            path.addEdge(lowestCostEdge);
            
            vertex = lowestCostEdge.getToVertex();
            unvisitedVertices.remove(vertex);
        }
        
        return path;
    }
    
}
