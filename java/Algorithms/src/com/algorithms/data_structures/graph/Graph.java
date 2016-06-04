/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.algorithms.data_structures.graph;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Objects;

/**
 *
 * @author asmita
 * @param <T>
 */
public class Graph <T extends Comparable<T>> {
    
    private List <Vertex <T>> vertices = new ArrayList<>();
    private List <Edge <T>> edges = new ArrayList<>();
    
    public Graph() {
        
    }
    
    public Graph(Graph<T> g) {
        
        for (Vertex <T> v: g.getVertices()) {
            this.getVertices().add(new Vertex<>(v));
        }
        
        for (Vertex <T> v: this.getVertices()) {
            for (Edge <T> e: v.getEdges()) {
                this.getEdges().add(e);
            }
        }
    }

    public List <Vertex <T>> getVertices() {
        return vertices;
    }

    public void setVertices (List <Vertex <T>> vertices) {
        this.vertices = vertices;
    }

    public List <Edge <T>> getEdges() {
        return edges;
    }

    public void setEdges (List <Edge <T>> edges) {
        this.edges = edges;
    }
    
    
    public static class Vertex <T extends Comparable<T>> implements Comparable<Vertex<T>> {
    
        private T value = null;
        private List <Edge <T>> edges = new ArrayList<>();

        public Vertex (T value) {
            this.value = value;
        }

        public Vertex (Vertex<T> v) {
            this(v.getValue());
            this.getEdges().addAll(v.getEdges());
        }

        public T getValue() {
            return this.value;
        }

        public void addEdge(Edge<T> e) {
            edges.add(e);
        }

        public List<Edge<T>> getEdges() {
            return this.edges;
        }

        public Edge<T> getEdge(Vertex<T> v) {
            for (Edge<T> e: getEdges()) {
                if (e.getToVertex().equals(this)) {
                    return e;
                }
            }
            return null;
        }

        @Override
        public int hashCode() {
            int hash = 3;
            hash = 61 * hash + Objects.hashCode(this.value);
            hash = 61 * hash + Objects.hashCode(this.edges);
            return hash;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            final Vertex<?> other = (Vertex<?>) obj;
            if (!Objects.equals(this.value, other.value)) {
                return false;
            }
            if (!Objects.equals(this.edges, other.edges)) {
                return false;
            }
            return true;
        }

        @Override
        public int compareTo(Vertex<T> v) {
            int comp = this.getValue().compareTo(v.getValue());
            if (comp != 0)
                return comp;

            if (this.getEdges().size() < v.getEdges().size())
                return -1;
            if (this.getEdges().size() > v.getEdges().size())
                return 1;

            Iterator<Edge<T>> iter1 = this.getEdges().iterator();
            Iterator<Edge<T>> iter2 = v.getEdges().iterator();

            while (iter1.hasNext() && iter2.hasNext()) {
                Edge<T> e1 = iter1.next();
                Edge<T> e2 = iter2.next();

                if (e1.getCost() < e2.getCost())
                    return -1;
                if (e1.getCost() > e2.getCost())
                    return 1;
            }
            return 0;
        }


    }

    public static class Edge<T extends Comparable<T>> {
    
        private Vertex<T> from = null;
        private Vertex<T> to = null;
        private int cost = 0;

        public Edge(Vertex<T> from, Vertex<T> to, int cost) {
            if (from == null || to == null) {
                throw (new NullPointerException("Both from and to need to be non-null."));
            }

            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        public Edge(Edge<T> edge) {
            this(edge.from, edge.to, edge.cost);
        }

        public Vertex<T> getFromVertex() {
            return from;
        }

        public void setFromVertex(Vertex<T> from) {
            this.from = from;
        }

        public Vertex<T> getToVertex() {
            return to;
        }

        public void setToVertex(Vertex<T> to) {
            this.to = to;
        }

        public int getCost() {
            return cost;
        }

        public void setCost(int cost) {
            this.cost = cost;
        }
    }
    
    public static class Path <T extends Comparable<T>> {
    
        private List <Graph.Edge<T>> edges = new ArrayList<>();
        private int cost = 0;

        public List<Graph.Edge<T>> getEdges() {
            return edges;
        }

        public void setEdges(List<Graph.Edge<T>> edges) {
            this.edges = edges;
        }

        public int getCost() {
            return cost;
        }

        public void setCost(int cost) {
            this.cost = cost;
        }

        public void addEdge(Graph.Edge<T> e) {
            this.getEdges().add(e);
            this.cost += e.getCost();
        }
    }

    
}
