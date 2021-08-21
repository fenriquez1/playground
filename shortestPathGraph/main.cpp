#include <main/Main.h>
#include <deque>
#include <set>

int shortestPathLength(std::vector<std::vector<int>> &graph)
{
    int result = 0;

    for (uint i{0}; i < graph.size(); i++)
    {
        auto g = graph;
        std::set<int> visited;
        std::deque<std::pair<int, int>> edgesOnPath;
        std::pair<int, int> edge = std::make_pair(i, g[i].at(0));
        int pathLength = 0;
        int current = edge.first;

        while (visited.size() < graph.size())
        {
            // do DFS
            if (visited.find(current) == visited.end())
            {
                visited.insert(current);
                if (visited.size() == g.size())
                {
                    break;
                }
            }

            // find the next edge in graph[0] to set as edge
            bool edgeFound = false;
            for (auto e : g[current])
            {
                if (visited.find(e) == visited.end())
                {
                    edgeFound = true;
                    edge = std::make_pair(current, e);
                    edgesOnPath.push_back(edge);
                    current = edge.second;
                    break;
                }
            }

            // if all edge nodes already in set, backtrack
            if (!edgeFound)
            {
                if (edgesOnPath.empty())
                {
                    std::cerr << "Need an edge but no edges to backtrack" << std::endl;
                }
                else
                {
                    edge = edgesOnPath.back();
                    edgesOnPath.pop_back();
                    current = edge.first;
                }
            }

            pathLength++;
        }

        if (result <= 0)
        {
            result = pathLength;
        }
        else
        {
            result = std::min(pathLength, result);
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    Main lMain(argc, argv);

    auto tokens = lMain.argsToTokens("[,]");

    // for (auto v : tokens)
    // {
    //     for (auto t : v)
    //     {
    //         std::cout << t << " ";
    //     }
    //     std::cout << std::endl;
    // }

    auto graph = lMain.tokensToInt(tokens);

    std::cout << shortestPathLength(graph) << std::endl;

    return 0;
}