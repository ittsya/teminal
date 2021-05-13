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
#include <mutex>

#include "../include/Matrix.hpp"
#include "../include/Counter.hpp"

typedef unsigned int Int;

#define LINE_LENGTH 256

namespace Screen
{

    class Parser
    {
    protected:

        std::string FileName;
        std::ifstream file;

        void Check();

    public:

        virtual ~Parser() {};
        Parser() {};
    };

    class BitMapParser : public Parser
    {

    private:

        std::once_flag OnceFlag;

        bool IsBitmap = false;

        void *tmp;
        matrix<unsigned char>* Bitmap = nullptr;

        std::unordered_map<std::string, std::string> info;
        std::unordered_map<std::string, Int> info_num;

        std::pair<Int, Int> GetSize();

        Counter<int> c_x, c_y;

        void Analyze(std::string &&token1, std::string &&token2, bool junk, bool token2_is_digit);
        void CreateBitMapArray(Int sizex ,Int sizey);

    public:

        BitMapParser(std::string FileName);

        ~BitMapParser();

        void Parse();







        };

}


#endif