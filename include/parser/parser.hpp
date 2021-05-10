#pragma once
#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>

typedef unsigned int Int;

#define LINE_LENGTH 256

namespace Screen {

    class Parser {

    protected:

        std::string FileName;
        std::ifstream file;

        void Check();

    public:


        virtual void Parse() = 0;

        virtual ~Parser() {};
        Parser() {};
    };

    class BitMapParser : public Parser
    {

    private:

        std::unordered_map<std::string, std::string> info;
        std::unordered_map<std::string, Int> info_num;



        void CreateBitMapArray(Int sizex ,Int sizey);
    public:

        BitMapParser(std::string FileName);
        ~BitMapParser();


        void Parse() override;

        void Analyze(std::string token1, std::string token2);

    };

}


#endif