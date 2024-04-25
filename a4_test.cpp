// a4_test.cpp

//
// You can include any standard C++ files you like for testing purposes.
//
#include "a4.h"

using namespace std;

// converse is a helper function that you can use if you like. You are free to
// modify it in any way.
void converse(Chatbot* a, Chatbot* b, int max_turns = 50) {
  for(int turn = 1; turn <= max_turns; turn++) {
    string a_msg = a->get_msg();
    cout << "(" << turn << ") " << a->get_name() << ": " << a_msg << "\n";
    
    turn++;
    if (turn > max_turns) return;

    b->give_msg(a_msg);
    string b_msg = b->get_msg();

    cout << "(" << turn << ") " << b->get_name() << ": " << b_msg << "\n";
    a->give_msg(b_msg);
  } // for
}

//test case 1 
void User_bot_test (){
  cout << "\ntesting User_bot_test\n\n";
  User_bot user{"user"};
  User_bot bot{"bot"};

  converse(&bot, &user, 4);
}

//test case 2 
void Single_reply_test(){ 
  cout << "\ntesting Single_reply_test\n\n";
  User_bot user1{"user"};
  Single_reply_bot tacobot{"tacobot", "I love tacos!"};
  

  converse(&user1,&tacobot, 4);
}

//test case 3
void Moo_bot_test(){
  cout << "\ntesting Moo_bot_test\n\n";
  User_bot user{"user"};
  Moo_bot bot{"moobot"};
  
  converse(&user, &bot, 4);
}

//test case 4
void Name_bot_test(){
  cout << "\ntesting Name_bot_test\n\n";
  User_bot user{"user"};
  Name_bot bot{"megabot"};
  
  converse(&user, &bot, 4);
}

//test case 5
void Echo_bot_test(){
  cout<<"\ntesting Echo_bot_test\n\n";
  //Echo_bot bot{"repeato", };
  Echo_bot bot{"repeato", "repeato is ready to go!"};
  User_bot user{"user"};

  converse(&bot, &user, 5);
}

//test case 6
void Random_reply_test(){
  cout << "\ntesting Random_reply_test\n\n";
  vector<string> VectorLine = {"meow", "purrr", "meeeeow"};
  User_bot user{"user"};
  Random_reply_bot cat{"Mittens", VectorLine};
  cat.get_msg();

    converse(&user, &cat, 4);

    // User_bot user{"user"};
    // Random_reply_bot dog{"Fido", "dog_sounds.txt"};
    // converse(&user, &dog, 6);
}

//test case 7
void Datetime_bot_test(){
  cout << "\ntesting Datatime_bot_test\n\n";
  vector<string> V = {"Ask me about the date or time!", "I know the date and time!"};
  User_bot user{"user"};
  Datetime_bot dt_bot{"deetee", V}; 

   converse(&user, &dt_bot, 4);

}

//test smart bot
void Smart_bot_test(){
  cout << "\ntesting Smart_bot_test\n\n";
  vector<string> V = {"Ask me about colors!", "I do not understand your question!", "Please try again.."};
  User_bot user{"user"};
  Smart_bot sma{"Smart_bot", V};

  converse(&user, &sma, 10);
}

int main() {
  //
  // ... call your testing code here ...
  //

  User_bot_test();
  Single_reply_test();
  Moo_bot_test();
  Name_bot_test();
  Echo_bot_test();
  Random_reply_test();
  Datetime_bot_test();
  Smart_bot_test();

}
