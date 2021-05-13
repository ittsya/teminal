#include "../include/parser/parser.hpp"

#include "../include/debug.hpp"

#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>
#include <mutex>
#include <string_view>
#include <charconv>

#define DEBUG

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
    delete this->Bitmap;
    this->file.close();
}

void Screen::BitMapParser::Parse()
{
    Check(); // If file opens correctly

    std::string delimiter = " ";
    std::string token1, token2;
    std::string line;

    std::size_t position;

    std::vector<std::string> tokens;


    // Parse font file
    while (std::getline(this->file, line))
    {
        position = line.find(delimiter);
        token1 = line.substr(0, position);
        line.erase(0, position + delimiter.length());
        token2 = line.substr(0, position);
        Analyze(std::move(token1), std::move(token2), false, false);

    }
#ifdef DEBUG
    for(int i = 0; i < 1140; ++i) {
        std::cerr << "\n ~SIZE : [" << std::dec <<  this->info_num["PIXEL_SIZE"] << "] ";
        std::cerr << "----------";
        std::cerr << "[" << std::dec << i << "]  ";
        for (int k = 0; k < 13; ++k) {
            std::cerr << std::uppercase << std::hex  << (int) this->Bitmap->get(k, i) << " ";
        }

    }
#endif
}

void
Screen::BitMapParser::Analyze
(std::string &&token1, std::string &&token2, bool junk = false, bool token2_is_digit = false)
{

    token2_is_digit = false;
    junk = false;

    // If bitmap
    if(this->IsBitmap)
    {
        auto InToken = (unsigned char)std::strtol(token1.c_str(), NULL, 16);

        this->Bitmap->insert(InToken, c_x._COUNTER++, c_y.GetCount());

        if ((this->c_x.GetCount() ) == (int)this->Bitmap->_m_Width) {
            this->IsBitmap = false;
        }
        junk = true;
    }


    if(token1.compare("BITMAP") == 0)
    {
            std::call_once(this->OnceFlag, [&] {
                junk = true;

                Int size_x = this->info_num["PIXEL_SIZE"];
                Int size_y = this->info_num["CHARS"];
                this->Bitmap = new matrix<unsigned char>(size_x, size_y);
                this->IsBitmap = true;
                this->c_y.start(-1); this->c_x.start(0);
            });

            this->IsBitmap = true;
            junk = true;

        this->c_y.tick(1);
        this->c_x.reset(0);
    }

    // Don't track junk
    if(token1.compare(token2) == 0)
        junk = true;

    // If token is digit
    if(std::isdigit(token2[0]))
        if(std::isdigit(token2[1]))
        token2_is_digit = true;


    if (!junk)
    {
        if (!token2_is_digit) {this->info[token1] = token2;}
        if (token2_is_digit) {this->info_num[token1] = std::stoi(token2);}
    }

}



#undef LINE_LENGTH

