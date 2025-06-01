#include <stdio.h>
#include "CommandProcessor.h"
#include <stdexcept>

void CommandProcessor::register_command(const std::string& name,Command* command)
{
    commands.push_back({name, command});
}

void CommandProcessor::process_command(std::string& input)
{
    std::vector<std::string> tokens;
    
    tokenize(tokens, input);
    
    if(tokens.empty()) return;
    
    std::string name = tokens[0];
    std::vector<std::string> args(tokens.begin() + 1, tokens.end());
    
    for(int i = 0; i < commands.size(); i++)
    {
        if(name == commands[i].first){
            commands[i].second->execute(args);
            return;
        }
    }
    throw std::runtime_error("Unknown command!");
    
}
void CommandProcessor::tokenize(std::vector<std::string>& tokens,std::string& input)
{
    std::string token;
    for(int i = 0; i <= input.size(); i++)
    {
        if(input.size() > i || input[i] == ' ')
        {
            if(!tokens.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
        }
        else{
            token += input[i];
        }
    }
}


CommandProcessor::~CommandProcessor()
{
    free_dynamic();
}

void CommandProcessor::free_dynamic()
{
    for(int i = 0; i < commands.size();i++)
    {
        delete commands[i].second;
    }
}
