#include <iostream>
using namespace std;
class RES{
  public:
    string scn_dat[1]={"\e[1mOPTIONS:\n\e[0m"};
    string scn_00[2]={"\e[36m[?]Hey...\n[?]Hey!\n\e[1m[?]HEY!!!\n\e[0m\e[35m<You wake up suddenly.>\e[0m\e[36m\n[?]Come with me now.\n\e[0m","\e[32m[1]Sure...\n\e[31m[2]Umm... No?\e[0m\n[3]Who are you?\n"};
    string scn_01[2]={"\e[36m[?]I'm the guy who's trying to help your ass. Now follow me!\n\e[0m","\e[32m[1]Okay\n\e[31m[2]No.\n\e[0m\e[2m[3]-----\n\e[0m"};
    string scn_02[2]={"\e[36m[?]Are"}
};
RES obj;
int nord;
int currscne;
bool keepGoing=true;
void switchScene(int scn,int choice){
  switch(scn){
    case 0:
      switch(choice){
        case 1:
          currscne=3;
          break;
        case 2:
          currscne=2;
          break;
        case 3:
          currscne=1;
          break;
        default:
          cerr<<"E01:INVALID_INTEGER";
          exit(EXIT_FAILURE);
      }
      break;
    case 1:
      switch(choice){
        case 1:
          currscne=3;
          break;
        case 2:
          currscne=2;
          break;
        case 3:
          cout<<"\e[3m\e[1m[i] You can't select this option...\e[0m\n";
          break;
        default:
          cerr<<"E01:INVALID_INTEGER";
          exit(EXIT_FAILURE);
      };
      break;
    default:
      cerr<<"E00:INCORRECT_SCENE_INTEGER";
      exit(EXIT_FAILURE);
  }
};
void printScene(int scn){
  switch(scn){
    case 0:
      cout<<obj.scn_00[0]<<obj.scn_dat[0]<<obj.scn_00[1];
      break;
    case 1:
      cout<<obj.scn_01[0]<<obj.scn_dat[0]<<obj.scn_01[1];
      break;
    default:
      cerr<<"E00:INCORRECT_SCENE_INTEGER";
      exit(EXIT_FAILURE);
  };
};
int main() {
  cout << "█   █  ███  ████  ████\n██  █ █   █ █   █ █   █\n█ █ █ █   █ ████  █   █\n█  ██ █   █ █   █ █   █\n█   █  ███  █   █ ████\nBy Brendan Berger\nVersion 0.0\n\n\n";
  currscne=0;
  while(keepGoing){
    printScene(currscne);
    cin>>nord;
    //cout<<"\e[1J\e[H";
    switchScene(currscne,nord);
  }
}