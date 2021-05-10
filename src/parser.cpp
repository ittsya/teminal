#include "../include/parser/parser.hpp"

#include "../include/debug.hpp"

Screen::BitMapParser::BitMapParser(std::string FileName)
{
    std::string path_to_file = "../include/parser/fonts/";
    this->FileName = path_to_file.append(FileName).c_str();
}

void Screen::Parser::Check()
{
    this->file.open(this->FileName);
    if(!file) { throw std::invalid_argument("Font cant be opened");}
}


Screen::BitMapParser::~BitMapParser()
{
    this->file.close();
}

void Screen::BitMapParser::Parse()
{
    Check();

    std::string line;


    std::vector<std::string> tokens;
    std::string delimiter = " ";
    std::string token1, token2;
    std::size_t position;

    while (std::getline(this->file, line))
    {
        position = line.find(delimiter);
        token1 = line.substr(0, position);
        line.erase(0, position + delimiter.length());
        token2 = line.substr(0, position);


        Analyze(token1, token2);


    }

}

void
Screen::BitMapParser::Analyze(std::string token1, std::string token2)
{
    Int MatrixCounter;

    bool token2_is_digit = false;
    bool junk = false;

    // If bitmap
    if(token1.compare("BITMAP") == 0)
    {
        junk = true;

        auto size_y = this->info_num["CHARS"];
        auto size_x = this->info_num["PIXEL_SIZE"];

        Matrix<unsigned char> BitMap(size_x, size_y);
        for(Int i = 0; i < size_x; ++i)
        {
        }

    }

    // Don't track junk
    if(token1.compare(token2) = 0)
        junk = true;

    // If token is digit
    if(std::isdigit(token2[0]))
        if(std::isdigit(token2[1]))
            token2_is_digit = true;


    if (!junk)
    {
        if (!token2_is_digit)
        {
            // Delete Quotes if exists
            try{
                token2.erase(std::remove(token2.begin(), token2.end(), "\""), token2.end());
                if(token2.compare("") != 0)
                {
                    token2 = "NULL";
                }
            } catch (const std::exception& ex) {(void)0;}

            this->info[token1] = token2;
        }

        if (token2_is_digit)
            this->info_num[token1] = std::stoi(token2);

    }



}


#undef LINE_LENGTH

