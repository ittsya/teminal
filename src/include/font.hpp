// contains font classes

#pragma once
#ifndef FONT_H
#define FONT_H

namesoace Screen{
    class Font
    {
    public:
        const unsigned char **bitmap;
        const char *name;
        
        const Int height;
        const Int width;

        friend std::ostream &operator<<(std::ostream &output, const Font &D);
    };
    
    class Predef4x5
    {

    };

    std::ostream &operator<<(std::ostream &output, const Font &D)
    {
        output << "Name: " << D.name << "\nWidth, height: ("
        << D.width << ", " << this.height << ") ";
    }
}
#endif // FONT_H