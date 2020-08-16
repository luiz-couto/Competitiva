#include <bits/stdc++.h>

using namespace std;

int errorPenalty = 20;

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
  int totalPenalty;
  Team(int teamIndex, int numberOfSolvedProblems) {
    this->teamIndex = teamIndex;
    this->numberOfSolvedProblems = numberOfSolvedProblems;
    this->teamProblems = {};
    this->totalPenalty = 0;
  }
};

int calculateTeamPenalty(vector<Problem> teamProblems) {
  int penalty = 0;
  for (int i=0; i<teamProblems.size(); i++) {
    int consideredTime = teamProblems[i].timeToSolve;
    if (consideredTime == -1) {
      consideredTime = 0;
    }
    int problemPenalty = consideredTime + (errorPenalty * teamProblems[i].numberOfAttempts);
    if (teamProblems[i].timeToSolve == -1) {
      problemPenalty = 0;
    }
    penalty = penalty + problemPenalty;
  }
  return penalty;
}

struct custom_sort {
  inline bool operator() (Team& team1, Team& team2) {
    if (team1.numberOfSolvedProblems != team2.numberOfSolvedProblems) {
      return (team1.numberOfSolvedProblems < team2.numberOfSolvedProblems);
    }
    int team1_penalty = calculateTeamPenalty(team1.teamProblems);
    team1.totalPenalty = team1_penalty;
    int team2_penalty = calculateTeamPenalty(team2.teamProblems);
    team2.totalPenalty = team2_penalty;
    if (team1_penalty != team2_penalty) {
      return team1_penalty < team2_penalty;
    }
    return team1.teamIndex < team2.teamIndex;
  }
};

bool isTheSameClassification(vector<Team> original, vector<Team> changed) {
  for (int i=0; i<original.size(); i++) {
    if (original[i].teamIndex != changed[i].teamIndex) {
      return false;
    }
    
    if (i != original.size() - 1) {
      if (original[i].numberOfSolvedProblems == original[i+1].numberOfSolvedProblems && original[i].totalPenalty == original[i+1].totalPenalty) {
        if (changed[i].totalPenalty != changed[i+1].totalPenalty) {
          return false;
        }
      }
    }
    
  }
  return true;
}

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

  vector<Team> allTeamsOriginal = allTeams;
  sort(allTeamsOriginal.begin(), allTeamsOriginal.end(), custom_sort());

  int inferiorLimit;
  for (int k=1; k<=20; k++) {
    errorPenalty = k;
    sort(allTeams.begin(), allTeams.end(), custom_sort());
    if (isTheSameClassification(allTeamsOriginal, allTeams)) {
      inferiorLimit = k;
      break;
    }
  }
  cout << inferiorLimit << endl;

  int superiorLimit;
  for (int k=21; k<=1000000; k++) {
    errorPenalty = k;
    sort(allTeams.begin(), allTeams.end(), custom_sort());
    if (!isTheSameClassification(allTeamsOriginal, allTeams)) {
      superiorLimit = k;
      break;
    }
    if (k == 100) {
      superiorLimit = -1;
      break;
    }
  }
  if (superiorLimit == -1) {
    cout << "*" << endl;
  } else {
    cout << superiorLimit - 1 << endl;
  }

  // for (int i=0; i<allTeams.size(); i++) {
  //   std::cout << "{ " << endl;
    
  //   std::cout << "  teamIndex: " << allTeams[i].teamIndex << endl;
  //   std::cout << "  numberOfSolvedProblems: " << allTeams[i].numberOfSolvedProblems << endl;
  //   std::cout << "  totalPenalty: " << allTeams[i].totalPenalty << endl;
    
  //   std::cout << "  problems: ";
  //   for (int j=0; j<numberOfProblems; j++) {
  //     std::cout << "  { " << endl;
  //     std::cout << "    numberOfAttempts: " << allTeams[i].teamProblems[j].numberOfAttempts << endl;
  //     std::cout << "    wasSolved: " << allTeams[i].teamProblems[j].wasSolved << endl;
  //     std::cout << "    timeToSolve: " << allTeams[i].teamProblems[j].timeToSolve << endl;
  //     std::cout << "  } " << endl;
  //   }

  //   std::cout << "} " << endl;
  // }

  // for (int i=0; i<allTeamsOriginal.size(); i++) {
  //   cout << allTeamsOriginal[i].teamIndex << ", ";
  // }
  // cout << endl;

  // for (int i=0; i<allTeams.size(); i++) {
  //   cout << allTeams[i].teamIndex << ", ";
  // }
  // cout << endl;

  return 0;
}