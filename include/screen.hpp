#pragma once
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

typedef unsigned int Int;

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
    
        std::uint_least32_t fgcolor, bgcolor;
        Int                 size_x,  size_y;
        Int                 pos_x,   pos_y;

    protected:
    
        explicit ScreenObjectC(): fgcolor(COLOR::WHITE), bgcolor(COLOR::BLACK), size_x(STD_SIZE_X), size_y(STD_SIZE_Y)  {} 
        explicit ScreenObjectC(Int x, Int y) : fgcolor(COLOR::WHITE), bgcolor(COLOR::BLACK), size_x(x), size_y(y) {} 
        explicit ScreenObjectC(Int x, Int y, std::uint_least32_t fgcolor) : fgcolor(fgcolor), size_x(x), size_y(y) {} 
        explicit ScreenObjectC(Int x, Int y, std::uint_least32_t fgcolor, std::uint_least32_t bgcolor) : fgcolor(fgcolor), bgcolor(bgcolor), size_x(x), size_y(y) {} 
        explicit ScreenObjectC(Int x, Int y, std::uint_least32_t fgcolor, std::uint_least32_t bgcolor, Int posx, Int posy) : fgcolor(fgcolor), bgcolor(bgcolor), size_x(x), size_y(y), pos_x(posx), pos_y(posy) {} 
    
    public:
        /* Swap foreground and background colors */
        void reverse_colors() ;
    
        /* Set color for the object */
        void Paint(
            std::uint_least32_t fgcolor,
            std::uint_least32_t bgcolor
        );
    
        /* Set only foreground color for the object */
        void Paint(
            std::uint_least32_t fgcolor
        );
        
        /*Set size for the object */
        void set_size(
            Int x, 
            Int y
        );
    
        /*Set object x and y position */   
        void set_pos_xy(
            Int x,
            Int y
        );
    
        /* Get current oject position in (x,y) format */
        const std::pair<Int, Int> GetPosition() const ;
    
        /* Get object size in (x,y) format */
        const std::pair<Int, Int> GetSize() const ;
    
        /* Get object color in (x,y)format  */ 
        const std::pair<std::uint_least32_t, std::uint_least32_t> GetColor() const ;
    };
    
    /* Nice and shiny Cell class*/
    class CellC : public ScreenObjectC
    {
    
    private:   
    
        char                cell_symbol = ' ';
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
        void set_params(
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
        ) ;
        
        /* Set 32 bit char cahracter for cell */
        void set_character(
            char chararacter
        ) ;

        /* Init Cell with none additional text styles, and with "?" symbol in it */
        void init_default();

        /* Getter for cell params */
        const std::array<bool, 7> get_params() const ;
        
        /* Getter for cell character */
        char32_t get_character() const ;

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
        const std::pair<Int, Int> GetWndCoords() const;

        /* Set cursor coordinates */
        void SetCurCoordinates(
            Int x,
            Int y
        );

        /* Make grid of cells */
        void MakeCellGrid();
    };
}
