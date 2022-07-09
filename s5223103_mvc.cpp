#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <random>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;

class MVC
{
    int vertices, target, algorithm = -1;
    std::string graph;
/*
    Algorithm: 1 -> Random Local Search
    Algorithm: 2 -> Greedy Local Search
    Algorithm: 3 -> Simmulated Annealing
                                            */

    // creates adj_list from file
    std::unordered_map<int, std::set<int>> generate(std::string filename);

    // picks random edges to minimise cover
    std::set<int> minimise_cover(std::unordered_map<int, std::set<int>> adj_list,
                                 std::set<std::pair<int, int>> rank);
    
    // removes edges and their incidents
    void remove_edge(std::unordered_map<int, std::set<int>>& adj_list, int vertex);
   
    // checks if an edge is already in the cover
    bool visited(std::unordered_map<int, std::set<int>>& adj_list, 
                 std::set<int>& cover, int vertex);
    
    // ensure final cover is valid
    bool valid_cover(std::unordered_map<int, std::set<int>> adj_list, 
                     std::set<int> cover);

    // perform simulated annealing algorithm
    std::set<int> simulated_annealing(std::unordered_map<int, 
                                      std::set<int>>& adj_list,
                                      std::set<std::pair<int, int>>& rank);   

public:
    // constructor initialises class for every algorithm
    MVC(std::string g, int t, int a) : graph(g), target(t), algorithm(a) {}
    
    // public driver to run the algorithms
    void driver();
};

// uniform random number gen
std::random_device rand_dev;
std::mt19937 generator(rand_dev());

// user choice solver
void solve_choice(int graph, int algorithm, int target);

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        cout << "Expected Target Minimum Vertex Cover" << endl;
        exit(1);
    }

    int graph, algorithm;

    cout << "**********************************" << endl
         << "**     Minimum Vertex Cover     **" << endl
         << "**          Ethan Leet          **" << endl
         << "**********************************" << endl << endl
         << "Available Graphs: " << endl
         << "1 \t brock800_1.clq" << endl
         << "2 \t brock800_2.clq" << endl
         << "3 \t brock800_3.clq" << endl
         << "4 \t brock800_4.clq" << endl
         << "5 \t C2000.9.clq" << endl
         << "6 \t C4000.5.clq" << endl
         << "7 \t MANN_a45.clq" << endl
         << "8 \t p_hat1500-1.clq" << endl
         << "What graph would you like to run? ";
    

    while (!(cin >> graph) || (graph < 1) || (graph > 8))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input! Enter A Valid Number: ";
    }

    cout << "\nAvailable Algorithms: " << endl
         << "1 \t Randomised Local Search" << endl
         << "2 \t Greedy Local Search" << endl
         << "3 \t Simulated Annealing" << endl
         << "What algorithm would you like to run? ";
    
    while (!(cin >> algorithm) || (algorithm < 1) || (algorithm > 3))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input! Enter A Valid Number: ";
    }

    solve_choice(graph, algorithm, atoi(argv[1]));

    return 0;
}

void solve_choice(int graph, int algorithm, int target)
{/*
    Function will execute appropriate algorithm
    and graph based on user choice.
                                                */
    
    std::string brock800_1 = "brock800_1.clq",
                brock800_2 = "brock800_2.clq",
                brock800_3 = "brock800_3.clq",
                brock800_4 = "brock800_4.clq",
                C2000_9 = "C2000.9.clq",
                C4000_5 = "C4000.5.clq",
                MANN_a45 = "MANN_a45.clq",
                p_hat1500_1 = "p_hat1500-1.clq";
    
    switch(graph)
    {
        case 1:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(brock800_1, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC gls(brock800_1, target, 2);
                    gls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(brock800_1, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        case 2:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(brock800_2, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC gls(brock800_2, target, 2);
                    gls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(brock800_2, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }      
        case 3:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(brock800_3, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC gls(brock800_3, target, 2);
                    gls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(brock800_3, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        case 4:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(brock800_4, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC gls(brock800_4, target, 2);
                    gls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(brock800_4, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        case 5:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(C2000_9, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC gls(C2000_9, target, 2);
                    gls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(C2000_9, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        case 6:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(C4000_5, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC gls(C4000_5, target, 2);
                    gls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(C4000_5, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        case 7:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(MANN_a45, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC gls(MANN_a45, target, 2);
                    gls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(MANN_a45, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        case 8:
        {
            switch(algorithm)
            {
                case 1:
                {
                    MVC rls(p_hat1500_1, target, 1);
                    rls.driver();
                    break;
                }
                case 2:
                {
                    MVC gls(p_hat1500_1, target, 2);
                    gls.driver();
                    break;
                }
                case 3:
                {
                    MVC sa(p_hat1500_1, target, 3);
                    sa.driver();
                    break;
                }
            } 
            break;   
        }
        default:
        {
            cout << "Invalid Input -> Exiting!" << endl;
            exit(1);
        }
    }

}

std::unordered_map<int, std::set<int>> MVC::generate(std::string filename)
{/*
    Populate the adjacency list with file
                                            */

    std::unordered_map<int, std::set<int>> adj_list;
    std::ifstream file (filename);
    file >> vertices;

    int v, u;
    while (file >> v >> u)
    {
        adj_list[v].emplace(u);
        adj_list[u].emplace(v);
    }
    return adj_list;
}

void MVC::driver()
{/*
    Driver function to perform algorithms trial
    amount of times.
                                                    */

    if (algorithm == 1)
        cout << "Performing Random Local Search on " 
             << graph << ". Please wait...." << endl;
    else if (algorithm == 2)
        cout << "Performing Greedy Local Search on " 
             << graph << ". Please wait...." << endl;
    else
        cout << "Performing Simulated Annealing on " 
             << graph << ". Please wait...." << endl;

    std::vector<double> trial_time;
    std::vector<int> total_cover;
    int successful = 0;

    // loop for every trial
    for (int i = 0; i < 100; i++) 
    {
        auto start = std::chrono::high_resolution_clock::now(); 
        std::unordered_map<int, std::set<int>> adj_list;
        int current_size = vertices;
        std::set<int> cover, minimise;
        std::set<std::pair<int, int>> rank;

        // populate adjacency list
        adj_list = generate(graph);

        // populate ranks for greedy and SA
        if (algorithm == 2 || algorithm == 3)
        {
            for (auto& i : adj_list)
                rank.emplace(i.second.size(), i.first);
        }

        // randomised/greedy local search
        if (algorithm == 1 || algorithm == 2)
        {
            // get a minimum
            minimise = minimise_cover(adj_list, rank);

            // ensure its not in cover
            for (int v = 1; v <= adj_list.size(); v++)
                if (visited(adj_list, minimise, v))
                    minimise.erase(v);

            // if size is better than current -> update
            if (minimise.size() < current_size) 
            {
                cover = minimise;
                current_size = minimise.size();
            }
        }

        // simulated annealing
        else if (algorithm == 3)
        {
            minimise = simulated_annealing(adj_list, rank);
            
            // if size is better than current -> update
            if (minimise.size() < current_size) 
            {
                cover = minimise;
                current_size = minimise.size();
            }
        }

        // get trial time
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast
            <std::chrono::milliseconds> (stop - start).count() / 1000.;

        // ensure final cover is valid
        if (valid_cover(adj_list, cover))
        {
            // add times to accumulate for every trial
            trial_time.push_back(duration);
            total_cover.push_back(cover.size());

            // report trial statistics
            cout << "Trial " << i + 1 << "   Cover: " << cover.size() 
                << "   CPU Time(sec): " << duration << endl;

            if (cover.size() <= target)
                successful++;
        }
        else
            cout << "Trial " << i + 1 << "   Cover: FAILED"
                 << "   CPU Time(sec): " << duration << endl;
            
    }

    double average_cover, average_time;
    // no valid cover was found -> set variables for statistics
    if (total_cover.size() < 1)
    {
        average_cover = 0;
        total_cover.push_back(0);
    }

    else
    {
        // get averages across all trials
        average_time = std::accumulate(trial_time.begin(), 
                                       trial_time.end(), 0.) 
                                       / trial_time.size();
        average_cover = std::accumulate(total_cover.begin(), 
                                        total_cover.end(), 0.0) 
                                        / total_cover.size();
    }

    // report average statistics
    cout << "\nGraph: "<< graph << "\nMinimum Vertex Cover Target: " 
         << target << "\nSuccessful Trials: " << successful 
         << "\nBest Cover: " << *std::min_element(total_cover.begin(), 
         total_cover.end()) << "\nAverage Cover: " << average_cover 
         << "\nAverage Time(sec): " << average_time << endl;
}

std::set<int> MVC::minimise_cover(std::unordered_map<int, 
                                  std::set<int>> adj_list,
                                  std::set<std::pair<int, int>> rank)
{/*
    Minimise cover based on algorithm type
                                            */
    std::set<int> cover;
    
    while (!adj_list.empty())
    {
        auto v = adj_list.begin();
        
        // get max degree vertex
        if (algorithm == 2)
        {
            auto max = *rank.end();
            rank.erase(max);
        }

        // get a random vertex
        else
        {
            std::uniform_int_distribution<int> gen(0, adj_list.size() - 1);
            int random = gen(generator);
            v = adj_list.begin();
            std::advance(v, random);
        }

        // get a random edge
        std::uniform_int_distribution<int> gen_(0, v->second.size() - 1);
        int random = gen_(generator);
        auto e = v->second.begin();
        std::advance(e, random);

        // update vertex cover
        cover.emplace(v->first);
        cover.emplace(*e);

        // remove edge
        remove_edge(adj_list, v->first);
        remove_edge(adj_list, *e);

    }
    return cover;
}

void MVC::remove_edge(std::unordered_map<int, 
                      std::set<int>>& adj_list, int vertex)
{/*
    Remove all edges that are incident on some vertex.
    Also remove any redundant vertices that are present.
                                                        */
    std::set<int> redundant;

    adj_list.erase(vertex);

    for (auto& i : adj_list)
    {
        i.second.erase(vertex);

        if (i.second.empty())
            redundant.emplace(i.first);
    }

    for (int i : redundant)
        adj_list.erase(i);
}

bool MVC::visited(std::unordered_map<int, 
                  std::set<int>>& adj_list, 
                  std::set<int>& cover, int vertex)
{/*
    Checks if a vertex is already in the cover
                                                */
    for (auto i : adj_list[vertex])
        if (cover.find(i) == cover.end())
            return false;
    return true;
}

bool MVC::valid_cover(std::unordered_map<int, 
                         std::set<int>> adj_list, 
                         std::set<int> cover)
{/*
    Method checks if a valid cover exists for a
    solution by removing all edges that are
    incident. If a cover exists then all nodes 
    left in the adjacency list will have no edges.
                                                    */

    for (auto& i : cover)
        remove_edge(adj_list, i);
    
    for (auto& i : adj_list)
        if (!i.second.empty())  
            return false;
    return true;
}

std::set<int> MVC::simulated_annealing(std::unordered_map<int, 
                                       std::set<int>>& adj_list,
                                       std::set<std::pair<int, int>>& rank)
{/*
    This method performs the Simulated Annealing 
    algorithm for each trial. 
                                                    */
    std::set<int> solution;
    int cost = vertices, temp_cost;
    double new_cost, temperature = 100000, alpha = 0.80;

    // loop until temperature is below cooled threshold
    while (temperature > 0.001) 
    {
        // get a random vertex
        std::set<int> temp = minimise_cover(adj_list, rank);

        // minimise cover by deleting vertices
        for (int v = 1; v <= adj_list.size(); v++)
            if (visited(adj_list, temp, v))
                temp.erase(v);

        // get current costs
        temp_cost = temp.size();
        new_cost = temp_cost - cost;

        // there is a better solution
        if (new_cost < 0) 
        {
            solution = temp;
            cost = temp_cost;
        } 
        
        // choose a solution based on probability
        else 
        {
            // get probability based off rho
            std::uniform_int_distribution<int> gen(1, 100);
            int random = gen(generator);

            // accept solution if rho exceeds probability
            if (exp(-abs(new_cost) / temperature) > (random / 100.0)) 
            {
                solution = temp;
                cost = temp_cost;
            }
        }

        // apply cooling factor
        temperature *= alpha;
    }
    return solution;
}