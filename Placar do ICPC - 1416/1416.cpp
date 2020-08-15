#include <bits/stdc++.h>

using namespace std;

struct Problem {
  bool wasSolved;
  int timeToSolve;
  int numberOfAttempts;
  Problem(int numberOfAttempts, bool wasSolved, int timeToSolve) {
    this->numberOfAttempts = numberOfAttempts;
    this->wasSolved = wasSolved;
    this->timeToSolve = timeToSolve;
  }
};

struct Team {
  int numberOfSolvedProblems;
  int teamIndex;
  vector<Problem> teamProblems;
  Team(int teamIndex, int numberOfSolvedProblems) {
    this->teamIndex = teamIndex;
    this->numberOfSolvedProblems = numberOfSolvedProblems;
    this->teamProblems = {};
  }
};

int main() {
  int numberOfTeams;
  int numberOfProblems;

  cin >> numberOfTeams >> numberOfProblems;
  vector<Team> allTeams;

  for (int i=0; i<numberOfTeams; i++) {
    Team currentTeam = Team(i, 0);
    for (int j=0; j<numberOfProblems; j++) {
      string problem;
      cin >> problem;
      stringstream problemStream(problem);
      string segment;

      int numberOfAttempts;
      bool wasSolved;
      int timeToSolve;
      int aux = 0;
      while(getline(problemStream, segment, '/' )) {
        if (aux == 0) {
          numberOfAttempts = stoi(segment);
          aux++;
        } else {
          if (segment == "-") {
            wasSolved = false;
            timeToSolve = -1;
          } else {
            wasSolved = true;
            currentTeam.numberOfSolvedProblems++;
            timeToSolve = stoi(segment);
          }
        }
      }
      currentTeam.teamProblems.push_back(Problem(numberOfAttempts, wasSolved, timeToSolve));
    }
    allTeams.push_back(currentTeam);
  }

  for (int i=0; i<allTeams.size(); i++) {
    std::cout << "{ " << endl;
    
    std::cout << "  teamIndex: " << allTeams[i].teamIndex << endl;
    std::cout << "  numberOfSolvedProblems: " << allTeams[i].numberOfSolvedProblems << endl;
    
    std::cout << "  problems: ";
    for (int j=0; j<numberOfProblems; j++) {
      std::cout << "  { " << endl;
      std::cout << "    numberOfAttempts: " << allTeams[i].teamProblems[j].numberOfAttempts << endl;
      std::cout << "    wasSolved: " << allTeams[i].teamProblems[j].wasSolved << endl;
      std::cout << "    timeToSolve: " << allTeams[i].teamProblems[j].timeToSolve << endl;
      std::cout << "  } " << endl;
    }

    std::cout << "} " << endl;
  }

  return 0;
}