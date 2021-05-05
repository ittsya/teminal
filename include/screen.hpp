#pragma once 
#ifndef SCREEN_H
#define SCREEN_H

#include <cinttypes>
#include <utility>
#include <vector>
#include <bitset>
#include <array>

#define STD_SIZE_X 10
#define STD_SIZE_Y 10

#define WIDTH_AND_HEIGHT_BEYOND_EDGE 0
#define WIDTH_BEYOND_EDGE  1
#define HEIGHT_BEYOND_EDGE 2
#define WIDTH_AND_HEIGHT_UNDER_EDGE 3
#define WIDTH_UNDER_EDGE  4
#define HEIGHT_UNDER_EDGE 5
#define FN_OK 10

namespace Screen
{
    namespace COLOR
    {
        const std::uint_least32_t WHITE   = 0xFFFFFF;
        const std::uint_least32_t BLACK   = 0x000000;
        const std::uint_least32_t RED     = 0xFF0000;
        const std::uint_least32_t GREEN   = 0x00FF00;
        const std::uint_least32_t BLUE    = 0x0000FF;
        const std::uint_least32_t YELLOW  = 0xFFFF00;
        const std::uint_least32_t CYAN    = 0x00FFFF;
        const std::uint_least32_t MAGENTA = 0xFF00FF;
    };

    /* Parent class for all object on the screen, contains basic variables*/
    class ScreenObjectC
    {
    
    protected:
    
        std::uint_least32_t fgcolor_, bgcolor_;
        Int                 size_x_,  size_y_;
        Int                 pos_x,   pos_y;

        
    
    protected:
    
        explicit ScreenObjectC(): fgcolor_(COLOR::WHITE), bgcolor_(COLOR::BLACK), size_x_(STD_SIZE_X), size_y_(STD_SIZE_Y)  {} 
        explicit ScreenObjectC(Int x, Int y) : fgcolor_(COLOR::WHITE), bgcolor_(COLOR::BLACK), size_x_(x), size_y_(y) {} 
        explicit ScreenObjectC(Int x, Int y, std::uint_least32_t fgcolor) : fgcolor_(fgcolor), size_x_(x), size_y_(y) {} 
        explicit ScreenObjectC(Int x, Int y, std::uint_least32_t fgcolor, std::uint_least32_t bgcolor) : fgcolor_(fgcolor), bgcolor_(bgcolor), size_x_(x), size_y_(y) {} 
        explicit ScreenObjectC(Int x, Int y, std::uint_least32_t fgcolor, std::uint_least32_t bgcolor, Int posx, Int posy) : fgcolor_(fgcolor), bgcolor_(bgcolor), size_x_(x), size_y_(y), pos_x(posx), pos_y(posy) {} 
    
    public:
        /* Swap foreground and background colors */
        inline void reverse_colors() __attribute__((always_inline));
    
        /* Set color for the object */
        inline void Paint(
            std::uint_least32_t fgcolor,
            std::uint_least32_t bgcolor
        ) __attribute__((always_inline));
    
        /* Set only foreground color for the object */
        inline void Paint(
            std::uint_least32_t fgcolor
        ) __attribute__((always_inline));
        
        /*Set size for the object */
        inline void set_size(
            Int x, 
            Int y
        ) __attribute__((always_inline));
    
        /*Set object x and y position */   
        inline void set_pos_xy(
            Int x,
            Int y
        ) __attribute__((always_inline));
    
        /* Get current oject position in (x,y) format */
        inline std::pair<Int, Int> GetPosition() const __attribute__((always_inline, const));
    
        /* Get object size in (x,y) format */
        inline std::pair<Int, Int> GetSize() const __attribute__((always_inline, const));
    
        /* Get object color in (x,y)format  */ 
        inline std::pair<std::uint_least32_t, std::uint_least32_t> GetColor() const __attribute__((always_inline, const));
    };
    
    /* Nice and shiny Cell class*/
    class CellC : public ScreenObjectC
    {
    
    private:   
    
        char            cell_symbol = ' ';    
        std::array<bool, 7> cell_parameters; 

        friend std::ostream &operator<<(std::ostream &output, const CellC &D);
    
    public:
    
        explicit CellC() : ScreenObjectC() {}
        explicit CellC(Int x, Int y) : ScreenObjectC(x, y) {}
        explicit CellC(Int x, Int y, std::uint_least32_t fgcolor) : ScreenObjectC(x, y ,fgcolor) {}
        explicit CellC(Int x, Int y, std::uint_least32_t fgcolor, std::uint_least32_t bgcolor) : ScreenObjectC(x, y ,fgcolor, bgcolor) {}
        explicit CellC(Int x, Int y, std::uint_least32_t fgcolor, std::uint_least32_t bgcolor, Int posx, Int posy) : ScreenObjectC(x, y ,fgcolor, bgcolor, posx, posy) {}
    
    public:

        /* Set cell parameters, such as: dim, underline, overstrike etc. */
        inline void set_params(
            /*  _______________________________ 
            *  | NAME       |    NUMBER        |
            *  |            |                  |
            *  | BOLD       |      0           |
            *  | SEMI-BOLD  |      1           |
            *  | ITALIC     |      2           |
            *  | OVERSTRIKE |      3           |
            *  | OVERSTRIKE2|      4           |
            *  | DIM        |      5           |
            *  | UNDERLINE  |      6           |
            *  |____________|__________________|  
            */         
            std::array<bool, 7> in_params
        ) __attribute__((always_inline));
        
        /* Set 32 bit char cahracter for cell */
        inline void set_character(
            char chararacter
        ) __attribute__((always_inline));

        /* Init Cell with none additional text styles, and with "?" symbol in it */
        inline void init_default();

        /* Getter for cell params */
        inline std::array<bool, 7> get_params() const __attribute__((always_inline));
        
        /* Getter for cell character */
        inline char32_t get_character() const __attribute__((always_inline)); 

    };
    
    /* Basic window class, contains Cursor structure in it, used for handling Cell arrays */
    class Window
    {
    public:
    
        struct Cursor_s
        {
            
            std::uint_least32_t fgcolor, bgcolor;
            bool is_blinking : 1;
            bool is_shown    : 1;
            bool block       : 1;
            bool underline   : 1;
            bool thick       : 1;
            Int x, y;
            
            explicit Cursor_s() : fgcolor(COLOR::BLACK), bgcolor(COLOR::WHITE), is_blinking(1), is_shown(1), block(1), x(0), y(0) {}  
        
        };       

    private:

        std::vector< std::vector<CellC> > cells;
        
        Int CellWidth,   CellHeight;
        Int ScreenWidth, ScreenHeight; 
        
        Cursor_s Cursor;
    
    public:

        explicit Window(Int ScreenW, Int ScreenH) : CellWidth(10), CellHeight(15), ScreenWidth(ScreenW), ScreenHeight(ScreenH) {}
        explicit Window(Int CellW, Int CellH, Int ScreenW, Int ScreenH) : CellWidth(CellW), CellHeight(CellH), ScreenWidth(ScreenW), ScreenHeight(ScreenH) {}
        
        /* Get Window Height and Window Width*/
        inline std::pair<Int, Int> GetWndCoords() __attribute__((always_inline));

        /* Set cursor coordinates */
        inline void SetCurCoordinates(
            Int x,
            Int y
        ) __attribute__((always_inline));

        /* Make grid of cells */
        void MakeCellGrid();
        

    };

    /*|-------------------------------------------------|*/
    /*|              function defines                   |*/
    /*|-------------------------------------------------|*/
    
            /*SCREEN OBJECT CLASS FUNCTIONS */
    inline void ScreenObjectC::reverse_colors()
    {
        std::swap(this->bgcolor_, this->fgcolor_);
    }

    inline void ScreenObjectC::Paint(std::uint_least32_t fgcolor, std::uint_least32_t bgcolor)
    {
        this->fgcolor_ = fgcolor; this->bgcolor_ = bgcolor;
    }

    inline void ScreenObjectC::Paint(std::uint_least32_t fgcolor)
    {
        this->fgcolor_ = fgcolor;
    }

    inline void ScreenObjectC::set_size(Int x, Int y)
    {
        this->size_x_ = x; this->size_y_ = y;
    }

    inline void ScreenObjectC::set_pos_xy(Int x, Int y)
    {
        this->pos_x = x; this->pos_y = y;
    }

    inline std::pair<Int, Int>  ScreenObjectC::GetPosition() const
    {
        return std::make_pair(this->pos_x, this->pos_y);
    }

    inline std::pair<Int, Int>  ScreenObjectC::GetSize() const
    {
        return std::make_pair(this->size_x_, this->size_y_);
    }

    inline std::pair<std::uint_least32_t, std::uint_least32_t> ScreenObjectC::GetColor() const
    {
        return std::make_pair(this->fgcolor_, this->bgcolor_);
    }

    /*CELL CLASS FUNCTIONS*/
    inline void CellC::set_params(std::array<bool, 7> in_params)
    {
        for (int i = 0; i < 7; i++)
        {
            this->cell_parameters[i] = in_params[i];
        }     
    }
    inline void CellC::set_character(char character)
    {
        this->cell_symbol = character;
    }

    void CellC::init_default()
    {
        this->cell_symbol = '?';
        this->cell_parameters = {0, 0, 0, 0, 0, 0, 0};
    }

    inline std::array<bool, 7> CellC::get_params() const 
    {
        return this->cell_parameters;
    }

    inline char32_t CellC::get_character() const 
    {
        return this->cell_symbol;
    }

    /*WINDOW CLASS FUNCTION*/
    inline void Window::SetCurCoordinates(Int x, Int y)
    {
        this->Cursor.x = x; this->Cursor.y = y;
    }

    void Window::MakeCellGrid()
    {   
        std::vector<CellC> CellGrid;
        
        const Int rows    = this->ScreenWidth  / this->CellWidth;
        const Int columns = this->ScreenHeight / this->CellWidth;
        
        //Set up delimeters
        Int h_del;
        Int w_del;
        
        CellC Cell; 
        
        for(Int k = 0; k < rows; k++)
        {
            w_del = this->CellWidth * k;
            for(Int m = 0; m < columns; m++)
            {
               h_del = this->CellHeight * m;
               
               Cell = CellC(this->CellHeight, this->CellWidth, COLOR::WHITE, COLOR::BLACK, w_del, h_del);     
            
               Cell.init_default();
               CellGrid.push_back(Cell);    
            }
            this->cells.push_back(CellGrid);
            CellGrid.clear();
           
        }

    }
    std::ostream &operator<<(std::ostream &output, const CellC &D)
    {
        output << "ScreenObject class in " << &D << ":\n";
        output << "Color:    (" << std::hex << D.fgcolor_  << ", " << D.bgcolor_ << ")  ";
        output << "Position: (" << std::dec << D.pos_x     << ", " << D.pos_y    << ")  ";
        output << "Size:     (" << D.size_x_ << ", "<< D.size_y_ << ")\n";
        output << "Character: " << D.cell_symbol;
        return output;
    }
}
#endif /* SCREEN_H */