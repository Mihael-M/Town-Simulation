#ifndef CommandProcessor_h
#define CommandProcessor_h

#include "Command.h"
#include <iostream>

class CommandProcessor{
public:
    void register_command(const std::string& name,Command* command);
    
    void process_command(std::string& input);
    
    ~CommandProcessor();
private:
    void free_dynamic();
    
    void tokenize(std::vector<std::string>& tokens,std::string& input);
    
    std::vector<std::pair<std::string, Command*>> commands;
    
};

#endif /* CommandProcessor_h */
