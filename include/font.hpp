// contains font classes

#pragma once
#ifndef FONT_H
#define FONT_H

namespace Screen{
    class Font
    {
    public:
        const unsigned char **bitmap;
        const char *name;
        
        const Int height;
        const Int width;
        
        friend std::ostream &operator<<(std::ostream &output, const Font &D);
    public:
        void Set();
    };
    
    std::ostream &operator<<(std::ostream &output, const Font &D)
    {
        output << "Name: " << D.name << "\nWidth, height: ("
        << D.width << ", " << D.height << ") ";
        return output;
    }

}
#endif // FONT_H