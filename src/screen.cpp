#include "../include/screen.hpp"


#include <iostream>

typedef unsigned int Int;

namespace Screen
{
            /*SCREEN OBJECT CLASS FUNCTIONS */
    extern void ScreenObjectC::reverse_colors()
    {
        std::swap(this->bgcolor, this->fgcolor);
    }

    extern void ScreenObjectC::Paint(std::uint_least32_t fgcolor, std::uint_least32_t bgcolor)
    {
        this->fgcolor = fgcolor; this->bgcolor = bgcolor;
    }

    extern void ScreenObjectC::Paint(std::uint_least32_t fgcolor)
    {
        this->fgcolor = fgcolor;
    }

    extern void ScreenObjectC::set_size(Int x, Int y)
    {
        this->size_x = x; this->size_y = y;
    }

    extern void ScreenObjectC::set_pos_xy(Int x, Int y)
    {
        this->pos_x = x; this->pos_y = y;
    }

    extern const std::pair<Int, Int> ScreenObjectC::GetPosition() const
    {
        return std::make_pair(this->pos_x, this->pos_y);
    }

    extern const std::pair<Int, Int> ScreenObjectC::GetSize() const
    {
        return std::make_pair(this->size_x, this->size_y);
    }

    extern const std::pair<std::uint_least32_t, std::uint_least32_t> ScreenObjectC::GetColor() const
    {
        return std::make_pair(this->fgcolor, this->bgcolor);
    }

    /*CELL CLASS FUNCTIONS*/
    extern void CellC::set_params(std::array<bool, 7> in_params)
    {
        for (int i = 0; i < 7; i++)
        {
            this->cell_parameters[i] = in_params[i];
        }     
    }
    extern void CellC::set_character(char character)
    {
        this->cell_symbol = character;
    }

    extern void CellC::init_default()
    {
        this->cell_symbol = '?';
        this->cell_parameters = {0, 0, 0, 0, 0, 0, 0};
    }

    extern const std::array<bool, 7> CellC::get_params() const
    {
        return this->cell_parameters;
    }

    extern char32_t CellC::get_character() const
    {
        return this->cell_symbol;
    }

    /*WINDOW CLASS FUNCTION*/
    extern void Window::SetCurCoordinates(Int x, Int y)
    {
        this->Cursor.x = x; this->Cursor.y = y;
    }

    extern void Window::MakeCellGrid()
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

    extern const std::pair<Int, Int> Window::GetWndCoords() const
    {
        return std::make_pair(this->ScreenWidth, this->ScreenHeight);
    }
    
    extern std::ostream &operator<<(std::ostream &output, const Screen::CellC &D)
    {
        output << "ScreenObject class in " << &D << ":\n";
        output << "Color:    (" << std::hex << D.fgcolor  << ", " << D.bgcolor << ")  ";
        output << "Position: (" << std::dec << D.pos_x     << ", " << D.pos_y    << ")  ";
        output << "Size:     (" << D.size_x << ", "<< D.size_y << ")\n";
        output << "Character: " << D.cell_symbol;
        return output;
    }
}
