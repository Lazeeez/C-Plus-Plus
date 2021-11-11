/******************************************************************************
 * @file
 * @brief Implementation of the [Hamiltonian
 * Cycle](https://en.wikipedia.org/wiki/Partition_problem )
 * @details
 * In the mathematical field of graph theory, a Hamiltonian path (or traceable
 * path) is a path in an undirected or directed graph that visits each vertex
 * exactly once. A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian
 * path that is a cycle. Determining whether such paths and cycles exist in
 * graphs is the Hamiltonian path problem, which is NP-complete.
 *
 * ### Implementation of Backtracking Algorithm
 *
 * Create an empty path vector and add vertex 0 to it. Add other vertices,
 * starting from the vertex 1. Before adding a vertex, check for whether it
 * is adjacent to the previously added vertex and not already added. If we
 * find such a vertex, we add the vertex as part of the solution. If we do
 * not find a vertex then we return false.
 *
 * @author [Lajat Manekar](https://github.com/Lazeeez)
 *
 *******************************************************************************/

#include <iostream>  /// for IO Operations
#include <vector>    /// for std::vector
#include <cassert>   /// for assert

// Number of vertices in the graph
#define V 5

/******************************************************************************
 * @namespace backtracking.
 * @brief Backtracking algorithms.
 *******************************************************************************/
namespace backtracking {

/******************************************************************************
 * @namespace hamiltonianCycle.
 * @brief implementation of hamiltonian cycle algorithm.
 *******************************************************************************/
    namespace hamiltonianCycle {

        std::vector<int> resizeSolution(std::vector<int>& path);

        /******************************************************************************
         * @brief A utility function to check if the vertex v can be added at index 'pos'
         * in the Hamiltonian Cycle constructed so far (stored in vector 'path').
         * @param v Vertex.
         * @param graph Original graph.
         * @param path Hamiltonian Cycle constructed so far.
         * @param pos Position in the Hamiltonian Cycle.
         * @returns @param bool Return bool whether the vector can be partitioned or not.
         *******************************************************************************/
        bool isSafe(int v, std::vector<std::vector<bool>>& graph, std::vector<int>& path, int pos)
        {
            // Check if this vertex is an adjacent vertex of the previously added vertex.
            if (graph [path[pos - 1]][ v ] == 0) return false;

            // Check if the vertex has already been included.
            for (int i = 0; i < pos; i++) if (path[i] == v) return false;

            return true;
        }

        /******************************************************************************
         * @brief A recursive utility function to solve hamiltonian cycle problem.
         * @param graph Original graph.
         * @param path Hamiltonian Cycle constructed so far.
         * @param pos Position in the Hamiltonian Cycle.
         * @returns @param bool Return bool whether the vector can be partitioned or not.
         *******************************************************************************/
        bool hamCycleUtil(std::vector<std::vector<bool>>& graph, std::vector<int>& path, int pos)
        {
            // base case: If all vertices are included in Hamiltonian Cycle
            if (pos == V) {
                return graph[path[pos - 1]][path[0]] == 1;
            }
            // Try different vertices as a next candidate in Hamiltonian Cycle.
            // We don't try for 0 as we included 0 as starting point in hamCycle()
            for (int v = 1; v < V; v++)
            {
                // Check if this vertex can be added to Hamiltonian Cycle
                if (isSafe(v, graph, path, pos))
                {
                    path[pos] = v;
                    // recur to construct rest of the path
                    if (hamCycleUtil(graph, path, pos + 1)) return true;

                    // If adding vertex v doesn't lead to a solution, then remove it
                    path[pos] = -1;
                }
            }

            /* If no vertex can be added to  Hamiltonian Cycle constructed so far,
            then return false */
            return false;
        }

        /******************************************************************************
         * @brief This function solves the Hamiltonian Cycle problem using Backtracking.
         * It mainly uses hamCycleUtil() to solve the problem. It terminatest if there
         * is no Hamiltonian Cycle possible, otherwise returns the Hamiltonian path.
         * (Please note that there may be more than one solutions, this function prints
         * one of the feasible solutions.)
         * @param graph Original graph.
         * @returns @param vector Return a Vector that that has the Hamiltonian Path.
         *******************************************************************************/
        std::vector<int> hamCycle(std::vector<std::vector<bool>>& graph)
        {
            int *path = new int[V];
            for (int i = 0; i < V; i++) path[i] = -1;

            /* Let us put vertex 0 as the first vertex in the path. If there is a
            Hamiltonian Cycle, then the path can be started from any point of the
            cycle as the graph is undirected */
            path[0] = 0;
            if (!hamCycleUtil(graph, reinterpret_cast<std::vector<int> &>(path), 1)) {
                return {};
            }

            return resizeSolution(reinterpret_cast<std::vector<int> &>(path));
        }

        /******************************************************************************
         * @brief A utility function resize the result vector.
         * @param path Hamiltonian Cycle constructed so far.
         * @returns @param vector Return a Vector that that has the Hamiltonian Path.
         *******************************************************************************/
        std::vector<int> resizeSolution(std::vector<int>& path)
        {
            path.resize(V);
            path.push_back(path[0]);
            return path;
        }
    }   //namespace hamiltonianCycle
}   //namespace backtracking

/*******************************************************************************
 * @brief Self-test implementations
 * @returns void
 *******************************************************************************/
static void test() {
/* Let us create the following graph
    (0)---(1)---(2)
     |   /  \   |
     |  /    \  |
     | /      \ |
    (3)-------(4)
*/
    std::vector<std::vector<bool>> graph1
            {
                    { false, true,  false, true,  false },
                    { true,  false, true,  true,  true  },
                    { false, true,  false, false, true  },
                    { true,  true,  false, false, true  },
                    { false, true,  true,  true,  false }
            };
    std::vector<int> expected_result = {0, 1, 2, 4, 3, 0};
    std::vector<int> derived_result;
    derived_result = backtracking::hamiltonianCycle::hamCycle(graph1);
    std::cout << "Test1: ";
    assert(expected_result == derived_result);
    std::cout << "Passed!" << std::endl;
}

/*******************************************************************************
 * @brief Main function
 * @returns 0 on exit
 *******************************************************************************/
int main() {
    test();     // run self-test implementations
    return 0;
}

