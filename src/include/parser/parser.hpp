// Recursive descent parser

#pragma once
#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <map>

#define T_INT 0
#define T_STRING 1


namespace BitParser
{

    void *expect(Int value, std::string data, Int position)
    {
        std::string token;

        switch(value)
        {
            case STRING:
                data.erase(0, position + delimeter.length());
                token = data.substr(0, position);
                return (void *)token;
        }
    }

    std::pair<Int, void*> *ParseString(std::string data. const std::string delimeter)
    {
        Int type;
        Int position = data.find(delimeter);
        if(position == std::string::npos)
        {
            // TODO;
        }

        std::string token = data.substr(0, position);

        switch(token)
        {
            case "STARTFONT":
                Int type = 0;
                return std::make_pair(type, expect(STRING, data, position));
        }
    
    }
    
    void block()
    {

    }

    void LoadFont(const *char filename)
    {
        std::ifstream file(filename);
        
        std::string data;
        std::string ident;
        
        const std::string delimeter = " ";
        
        Int num;

        if(!data) { std::cerr << "Error loading font: " << filename; }
        
        while(std::getline(file, data))
        {
            ParseString(data, delimeter);
        }
    }
}

#undef T_INT 
#undef T_STRING


#endif // PARSER_H
