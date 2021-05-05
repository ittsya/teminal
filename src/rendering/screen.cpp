#include "../../include/screen.hpp"

namespace Screen
{
    
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
    
    inline std::pair<Int, Int> Window::GetWndCoords()
    {
        return std::make_pair(this->ScreenWidth, this->ScreenHeight);
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