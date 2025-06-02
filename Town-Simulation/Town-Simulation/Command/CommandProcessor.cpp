#include <stdio.h>
#include "CommandProcessor.h"
#include <stdexcept>



void CommandProcessor::register_command(const std::string& name,unsigned arguments, Command* command)
{
    commands.push_back({name, arguments, command});
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
        if(name == commands[i].name && args.size() == commands[i].argCount){
            commands[i].command->execute(args);
            return;
        }
    }
    throw std::runtime_error("Unknown command!");
    
}
void CommandProcessor::tokenize(std::vector<std::string>& tokens, std::string& input)
{
    std::string token;
    for (size_t i = 0; i < input.size(); ++i)
    {
        if (input[i] == ' ')
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
        }
        else
        {
            token += input[i];
        }
    }
    if (!token.empty())
    {
        tokens.push_back(token);
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
        delete commands[i].command;
    }
}
