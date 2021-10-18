#include <iostream>
using namespace std;
class RES{
  public:
    const string game_dat[9]={"\e[1mOPTIONS:\n\e[22m","\e[3m\e[1m[i] You can't select this option...\e[0m\n","E00:INCORRECT_SCENE_INTEGER","E01:INVALID_INTEGER","\e[35m\e[1mThanks for trying the prototype! Unfortunately, the fun ends here, as I still have a lot of coding to do. Be sure to check the links below every now and then to see when a new update comes out!\n\nCheck development at:\n\thttps://github.com/polygonnedpotato/nord\n\nSee you soon,\n\t--elburg.\n\e[0m","̤̫  -- mwahaha it's me! the mini furry!","\e[33m[HINT]: Green text indicates a positive option, while red indicates a negative option.\e[0m\n","\e[33m[HINT]: Bold text sometimes indicates important story elements, so it would be best to keep a good eye out.\e[0m\n","\n╔═╗╔═╗╔╦╗╔═╗  ╔═╗╦  ╦╔═╗╦═╗\n║ ╦╠═╣║║║║╣   ║ ║╚╗╔╝║╣ ╠╦╝\n╚═╝╩ ╩╩ ╩╚═╝  ╚═╝ ╚╝ ╚═╝╩╚═\n"};
    const string game_over[2]={"\e[32m[1]Return to last checkpoint\n\e[0m[2]Restart\n\e[31m[3]Exit\n","\e[1mNothing happened...\nIt was all a dream...\e[0m\n"};
    const string scn_00[2]={"\e[36m[?]Hey...\n[?]Hey!\n\e[1m[?]HEY!!!\n\e[0m\e[35m<You wake up suddenly.>\n<You look up and notice a larg dark figure. It speaks in a masculine voice...>\e[0m\e[36m\n[?]Come with me,\e[1m now\e[22m.\n\e[0m","\e[32m[1]O-Okay...\n\e[31m[2]Umm... No?\e[0m\n[3]Who are you?\n"};
    const string scn_01[2]={"\e[36m[?]I'm the guy who's trying to save you. Now follow me!\n\e[0m","\e[32m[1]Okay\n\e[31m[2]No.\n\e[0m\e[2m[3]-----\n\e[0m"};
    const string scn_02[2]={"\e[36m[?]Are you joking? Now is not the time for this! Especially considering that \e[1mthe sweep\e[22m is happening. Now come on!\e[0m\n","\e[32m[1]Okay...\n\e[0m[2]Wait what's 'the sweep'?\n[3]Who are you?\n"};
    const string scn_03[2]={"\e[35m<The dark figure pulls you up without patience.>\n<You find it hard to stabalize yourself on your feet.>\n<Without hesitation, the figure grabs ahold of your arm and pulls you along with itself.>\n<As the figure pulls you to an undisclosed location, you look around. Destrucion, fire, debris. it looks as if the entire place was severly bombed.>\n<You feel light headed.>\n<You blackout.>\e[0m\n","\e[33m[1]Continue\e[0m\n\e[2m[2]-----\n[3]-----\e[0m\n"};
    const string scn_04[2]={"\e[35m<...>\n<You wake up.>\n\e[36m[?]Oh, you're up, are you okay? I'm sorry if I acted out earlier...\n\e[0m","\e[32m[1]I-It's okay...\e[31m\n[2]Ya think?!\e[0m\n[3]...\n"};
    const string scn_05[2]={"\n\e[36m[?]Oh thank god you're okay! For a moment there I thought you were going to be the newest fatality by \e[1mthe sweep\e[22m!\n\e[0m","[1]"};
    const string scn_06[2]={};
    const string scn_hs[2]={"\e[35mPo twojej pysznej zupie\nNie ruszam dupy z klopa\nTa zupa było z mlekiem;\nNa mleko mam alergię\e[0m\n","[1]what\n[2]????\n[3]przepraszam"};
};
RES obj;
int nord,currscne,chkpnt;
bool keepGoing=true;
void runGameOver(int got){
  cout<<obj.game_dat[8]<<obj.game_over[1+got]<<obj.game_over[0];
  cin>>nord;
  switch(nord){
    case 1:
      currscne=chkpnt;
      break;
    case 2:
      currscne=0;
      break;
    case 3:
      exit(0);
  }
}
void switchScene(int scn,int choice){
  switch(scn){
    case 0: //00
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
        case 4:
          cout<<"[DEBUG]{ENTER SCENE NUM}=";
          cin>>currscne;
          break;
        case 5:
          cout<<"[DEBUG]{ENTER GAME OVER ID}=";
          cin>>nord;
          runGameOver(nord);
          break;
        default:
          cerr<<obj.game_dat[3];
          exit(1);
      }
      break;
    case 1: //01
      switch(choice){
        case 1:
          currscne=3;
          break;
        case 2:
          currscne=2;
          break;
        case 3:
          cout<<obj.game_dat[1];
          break;
        default:
          cerr<<obj.game_dat[3];
          exit(1);
      };
      break;
    case 2: //02
      switch(choice){
        case 1:
          currscne=3;
          break;
        case 2:
          currscne=3;
          cout<<"\e[3m\e[35m<You try to ask the figure, but it appears that it had other plans.>\n\e[0m";
          break;
        case 3:
          currscne=1;
          break;
        default:
          cerr<<obj.game_dat[3];
          exit(1);
      }
      break;
    case 3: //03
      switch(choice){
        case 1:
          currscne=4;
          break;
        case 2:
          cout<<obj.game_dat[1];
          break;
        case 3:
          cout<<obj.game_dat[1];
          break;
        default:
          cerr<<obj.game_dat[3];
          exit(1);
      }
      break;
    case 4: //04
      switch(choice){
        case 1:
          cout<<obj.game_dat[4];
          exit(0);
        case 2:
          cout<<obj.game_dat[1];
          break;
        case 3:
          cout<<obj.game_dat[1];
          break;
        default:
          cerr<<obj.game_dat[3];
          exit(1);
      }
    default:
      cerr<<obj.game_dat[2];
      exit(1);
  }
};
void printScene(int scn){
  cout<<endl;
  switch(scn){
    case 0: //00
      cout<<obj.scn_00[0]<<obj.game_dat[0]<<obj.scn_00[1];
      break;
    case 1: //01
      cout<<obj.scn_01[0]<<obj.game_dat[0]<<obj.scn_01[1];
      break;
    case 2: //02
      cout<<obj.scn_02[0]<<obj.game_dat[0]<<obj.scn_02[1];
      break;
    case 3: //03
      cout<<obj.scn_03[0]<<obj.game_dat[0]<<obj.scn_03[1];
      break;
    case 4: //04
      cout<<obj.scn_04[0]<<obj.game_dat[0]<<obj.scn_04[1];
      break;
    default:
      cerr<<obj.game_dat[2];
      exit(1);
  };
};
int main() {
  cout<<"█   █  ███  ████  ████\n██  █ █   █ █   █ █   █\n█ █ █ █   █ ████  █   █\n█  ██ █   █ █   █ █   █\n█   █  ███  █   █ ████\nBy elburg\nVersion 0.0\n\n\n";
  currscne=0;
  while(keepGoing){
    printScene(currscne);
    cin>>nord;
    //cout<<"\e[1J\e[H";
    switchScene(currscne,nord);
  }
}