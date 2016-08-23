/*
Written By:   Ashkan Dehghan [McMaster University]
*/

#include "./Global.hh"
#include "./HEADERFILES/HeaderFileList.hh"


using namespace std;

/*
  Input:
  [1]-> Phase: LAM or HEX
  [2]-> xAB
  [3]-> xAI
  [4]-> xBI
  [5]-> NA
  [6]-> PA
*/

int main(int argc, char* argv[]){

  Allocate(1);

  InputArguments(argc,argv);

  //MOD_main( );
  MOD1( );
  //MOD2( );
  

  Allocate(0);
  return 0;
}


