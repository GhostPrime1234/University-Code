#ifndef USER_INPUT_HANDLER_H
#define USER_INPUT_HANDLER_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>


class UserInputHandler {
public:
    static void signal_callback_handler(int signum);
    static std::string getValidYearInput();
    static std::map<std::string, std::vector<std::pair<std::string, std::string>>> getInputForSemestersAndSubjects();
private:
    static void trimWhitespace(std::string& str);
};

#endif // USER_INPUT_HANDLER_H
