// a4.h

//////////////////////////////////////////////////////////////////////
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include "cmpt_error.h"    // These are the only permitted includes
#include "Chatbot.h"       // for a4.h!
#include <iostream>        //
#include <fstream>         // Don't include anything else.
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <ctime>     
#include <cassert>

//
// ... put your solution code here ...
// 
using namespace std;

//chatbot 1
class User_bot : public Chatbot{
    string input;
    string msg;
public: 
    User_bot(const string& name): Chatbot(name)
    { }
    string get_msg(){ 
        cout << "Enter a line: ";
        getline(cin,input);
        return input;
    }
    void give_msg(const string& message){ 
        msg = message;
    }

};

//chatbot 2
class Single_reply_bot : public Chatbot{
    string strN;
    string strM;
public:
    Single_reply_bot(const string& name, const string& s): Chatbot(name), strM(s)
     { } 

     string get_msg(){ 
         return strM;
     }
     void give_msg(const string& strM){ 
         strN = strM;
     }
};

//chatbot 3
class Moo_bot : public Single_reply_bot{
    public:
    Moo_bot(const string& n): Single_reply_bot(n, "moo")
    { }

};

//chatbot 4
class Name_bot : public Single_reply_bot{
    public:
    Name_bot(const string& s): Single_reply_bot(s, "I am megabot!")
    { }
};

//chatbot 5
class Echo_bot : public Chatbot{
    string input;
    string msg;
    int count;
public: 
    Echo_bot (const string& name, const string& s): Chatbot(name), input(s)
    { }
    string get_msg(){ 
        
       return input;
    }
    void give_msg(const string& s){ 
        input = s;
    }
};

//chatbot 6
class Random_reply_bot : public Chatbot{
    string input;
    string msg;
    string Read;
    ifstream my_input_file;
    vector<string> VectorLine;
public :
    Random_reply_bot(const string& name, vector<string>& f) : Chatbot(name), VectorLine(f)
    { }
    Random_reply_bot(const string& name, const string& filename) : Chatbot(name), Read(filename)
    { 
        if(VectorLine.size() == 0){
            cmpt::error("No strings in this vector!");
        }
        if(!my_input_file){
            cmpt::error("File did not open");
        }
        //open the file 
        my_input_file.open(Read); 
        while(getline(my_input_file,Read)) {
           VectorLine.push_back(Read);
        }
        my_input_file.close();
    }

    string get_msg(){
        input = VectorLine[rand() % VectorLine.size()];  
        return input;
    }

    void give_msg(const string& input){
        msg = input;
    } 

};

//chatbot 7
class Datetime_bot : public Chatbot{
    vector<string> V;
    string msg;
public:
    Datetime_bot(const string&name, vector<string> vect) : Chatbot(name), V(vect)
     {    
        if(vect.size() == 0){
        cmpt::error("invalid list");
        }
    }

//refrences:
//https://stackoverflow.com/questions/3827926/what-does-stringnpos-mean-in-this-code
//https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
//https://thispointer.com/converting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/
    
    string get_msg(){
        time_t t;
        char buffer[30];
        time(&t);
        struct tm  *tstruct = localtime(&t);
    //upper lower case doesnt matter 
        for_each(msg.begin(), msg.end(),[](char &c){
            c = ::tolower(c);
        });
    //finding the strings 
        size_t string1 = msg.find("date");
        size_t string2 = msg.find("time");
        
        if(string1 != string::npos && string2 != string::npos){
            strftime(buffer, sizeof(buffer),"%I:%M%p, %Y-%m-%d", tstruct);
        }
        else if(string1 != string::npos){
            strftime(buffer, sizeof(buffer),"%Y-%m-%d", tstruct);
        }
        else if(string2 != string::npos){
            strftime(buffer, sizeof(buffer),"%I:%M%p.", tstruct);
        }
        else{
            //when date and time are not found generate the two strings
            int i = rand() % V.size();
            return V[i];
        }
       return buffer;
    }

    void give_msg(const string& s){
        msg = s;
    } 
    
};


//smart bot that replies when asked about 2 different colors and what they combine to make like:

//terminal output example:

// Enter a line: what do yellow and red make 
// (1) user: what do yellow and red make 
// (2) Smart_bot: these two colors make ORANGE.

// Enter a line: what do red and yellow make
// (3) user: what do red and yellow make
// (4) Smart_bot: these two colors make ORANGE.

// Enter a line: what do 
// (5) user: what do 
// (6) Smart_bot: I do not understand your question!

// Enter a line: what about BLACK and white
// (7) user: what about BLACK and white
// (8) Smart_bot: these two colors make GREY.

// Enter a line: hjg
// (9) user: hjg
// (10) Smart_bot: I do not understand your question!

// Enter a line: ds
// (11) user: ds
// (12) Smart_bot: Ask me about colors!

// Enter a line: and GReeN and ReD
// (13) user: and GReeN and ReD
// (14) Smart_bot: these two colors make BROWN.


//description:

//i used an array because i have to return a value and cout gave too many errors.
// also order of color names does not matter, i also made it case insensitive.

//Refrences:
//https://stackoverflow.com/questions/3827926/what-does-stringnpos-mean-in-this-code
//https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c

class Smart_bot : public Chatbot{
    vector<string> V;
    string msg;
public:
    Smart_bot(const string&name, vector<string> vect) : Chatbot(name), V(vect)
     {    
        if(vect.size() == 0){
        cmpt::error("invalid list");
        }
    }

     string get_msg(){

         for_each(msg.begin(), msg.end(),[](char &c){
            c = ::tolower(c);
        });
        
        size_t str1 = msg.find("green");
        size_t str2 = msg.find("blue");
        size_t str3 = msg.find("white");
        size_t str4 = msg.find("yellow");
        size_t str5 = msg.find("red");
        size_t str6 = msg.find("black");
       
       string Answers[6] = {"these two colors make BROWN.",
                            "these two colors make PURPLE.",
                            "these two colors make ORANGE.",
                            "these two colors make GREEN.",
                            "these two colors make PINK.",
                            "these two colors make GREY."};

        for(int i = 0; i< 6; i++){
            if(str1 != string::npos && str5 != string::npos){
                return Answers[0];
            }
            else if(str2 != string::npos && str5 != string::npos){
                return Answers[1];
            }
            else if(str5 != string::npos && str4 != string::npos){
                return Answers[2];
            }else if(str4 != string::npos && str2 != string::npos){
                return Answers[3];
            }else if(str3 != string::npos && str5 != string::npos){
                return Answers[4];
            }
            else if(str6 != string::npos && str3 != string::npos){
                return Answers[5];
            }
             else{
            int j = rand() % V.size();
            return V[j];
             }
        }
        return 0; 
     }

     void give_msg(const string& s){
        msg = s;
    } 
};








