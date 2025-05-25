#include <bits/stdc++.h>
using namespace std;

void printVector(vector<vector<int>>& arr) {
    for(auto a : arr) {
        for(auto n : a) {
            cout << n << " ";
        }
        cout << endl;
    }
}

void printPathsHelper(vector<vector<int>>& maze, vector<vector<int>>& solution, int x, int y) {
    int n = maze.size();
    if(x == n-1 && y == n-1) {
        printVector(solution);
        cout << endl;
        return;
    }
    
    if(x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 0 || solution[x][y] == 1) {
        return;
    }
    
    solution[x][y] = 1;
    printPathsHelper(maze, solution, x-1, y);
    printPathsHelper(maze, solution, x, y-1);
    printPathsHelper(maze, solution, x+1, y);
    printPathsHelper(maze, solution, x, y+1);
    solution[x][y] = 0;
}

bool hasPathHelper(vector<vector<int>>& maze, vector<vector<int>>& solution, int x, int y) {
    int n = maze.size();
    if(x == n-1 && y == n-1) {
        return true;
    }
    
    if(x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 0 || solution[x][y] == 1) {
        return false;
    }
    
    solution[x][y] = 1;
    
    if(hasPathHelper(maze, solution, x-1, y) || hasPathHelper(maze, solution, x, y-1) || hasPathHelper(maze, solution, x+1, y) || hasPathHelper(maze, solution, x, y+1)) {
        return true;
    }
    
    solution[x][y] == 0;
    return false;
}

bool hasPath(vector<vector<int>>& maze) {
    int n = maze.size();
    vector<vector<int>> solution(n, vector<int>(n, 0));
    return hasPathHelper(maze, solution, 0, 0);
}

void printPaths(vector<vector<int>> maze) {
    int n = maze.size();
    vector<vector<int>> solution(n, vector<int>(n, 0));
    printPathsHelper(maze, solution, 0, 0);
}

int main() {
    
    int n;
	vector<vector<int>> maze;
	cin >> n; // size of the maze
	
	for(int i = 0; i < n; i++) {
	    vector<int> row;
	    for(int j = 0; j < n; j++) {
	        int temp;
	        cin >> temp;
	        row.push_back(temp);
	    }
	    maze.push_back(row);
	}
	
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j < n; j++) {
	        cout << maze[i][j] << " ";
	    }
	    cout << endl;
	}
	
	
	printPaths(maze);

}
