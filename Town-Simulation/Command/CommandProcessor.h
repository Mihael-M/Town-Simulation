#ifndef CommandProcessor_h
#define CommandProcessor_h

#include "Command.h"

#include <iostream>

struct CommandEntry {
    std::string name;
    unsigned argCount;
    Command* command;
};

class CommandProcessor{
public:
    void register_command(const std::string& name,unsigned arguments ,Command* command);
    
    void process_command(std::string& input);
    
    ~CommandProcessor();
private:
    void free_dynamic();
    
    void tokenize(std::vector<std::string>& tokens,std::string& input);
    
    std::vector<CommandEntry> commands;
    
};

#endif /* CommandProcessor_h */
