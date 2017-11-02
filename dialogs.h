#ifndef _DIALOGS_H
#define _DIALOGS_H

#include <gtkmm.h>
#include <vector>

using namespace std;

class Dialogs {
  public:

    // A message is like cout, simply displaying information to the user
    static void message(string msg, string title = "Info");

	//universal form to add new container, flavor etc.
	static vector<string> form(string title, int id);
    
// A question is a message that allows the user to respond with a button
    static int question(string msg, string title = "Question",
                 vector<string> buttons = {"Cancel", "OK"});

    // A request for a line of text input
    static string input(string msg, string title = "Input", string default_text = "", 
                 string cancel_text = "CANCEL");

    // Display an image from a disk file
    static void image(string filename, string title = "Image", string msg = "");

 static void serving();

private:
	void on_add1_clicked();

};
#endif
