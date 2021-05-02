# Screen namespace 

## Color enumeration
```
enum class COLOR : std::uint_least32_t { ... }
```
#### Description
Enum structure that contains basic hexadecimal colors, such as:
* White
* Black
* Red
* Green
* Blue
* Yellow
* Cyan
* Magenta

## ScreenObjectC::reverse_colors()
```
void reverse_colors()
```

#### Description
Reverse color of the screen, actually swap foreground and background colors

## ScreenObjectC::Paint()
```
void Paint(std::uint_least32_t fgcolor, ...)
void Paint(std::uint_least32_t fgcolor, std::uint_least32_t bgcolor, ...)

```
#### Description
Overloaded. Paint cell with given hex colors. It is prefer to use colors from Color enumaration, for example:
```
cell.Paint(Screen::COLOR::WHITE, Screen::COLOR::BLACK);
```

#### Parameters
* uint_least32_t hex foreground color
* uint_least32_t hex background color

## ScreenObjectC::set_size()
```
void set_size(size_t x, size_t y, ...);
```
#### Description
Set cell width and height

#### Parameters
* size_t x : Height of the Cell
* size_t y : Width of the Cell

## ScreenObjectC::set_pos_xy()
```
void ScreenObjectC::set_pos_xy(size_t x, size_t y, ...)
```
#### Description
Set x,y position for the cell

#### Parameters
* size_t x
* size_t y

## ScreenObjectC::GetPosition()
```
const std::pair<size_t, size_t> ScreenObjectC::GetPosition(...)
```
#### Description
Getter for x and y of the cell

#### Return
Function returns pair of size_t, size_t

## ScreenObjectC::GetSize()
```
const std::pair<size_t, size_t> ScreenObjectC::GetSize(...)
```
#### Description
Getter for width and height of the cell

#### Return
Function returns pair of size_t, size_t

## ScreenObjectC::GetPosition()
```
const std::pair<size_t, size_t> ScreenObjectC::GetPosition(...)
```
#### Description
Getter for x and y of the cell

#### Return
Function returns pair of size_t, size_t

## ScreenObjectC::GetColor()
```
const std::pair<std::uint_least32_t, std::uint_least32_t> ScreenObjectC::GetColor(...)
```
#### Description
Getter for foreground and background of the cell

#### Return
Function returns pair of uint_least32_t, uint_least32_t

## CellC::set_params()
```
void CellC::set_params(std::array<bool, 7> in_params, ...)
```
#### Description
Setter for cell parameters, actually boolean contained array:
Array element | Parameter
--------------|-----------
    ZERO      | BOLD
    FIRST     | SEMI-BOLD
    SECOND    | ITALIC
    THIRD     | OVERSTRIKE
    FOUTH     | OVERSTRIKE2
    FIFTH     | DIM
    SIXTH     | UNDERLINE

## CellC::set_character()
```
void CellC::set_character(char32_t character, ...)
```
#### Descriptiom
Set character for the cell

#### Params
* char32_t character

#### Return
Function returns nothing

## CellC::init_default()
```
inline void CellC::init_default(...)
```
#### Description
Set cell character to "?" and parameters to all false

##CellC::get_params()
```
std::array<bool, 7> CellC::get_params(...)

```
#### Description
Getter for cell parameters

#### Return
Function returns std::array<bool, 7>

## CellC::get_character()
```
char32_t CellC::get_character(...)
```

#### Description
Getter for cell character

#### Return
Function returns char32_t

## Window::SetCurCoordinates()
```
void Window::SetCurCoordinates(size_t x, size_t y, ...)
```
#### Description
Set cursor coordinates

#### Parameters
* size_t x position
* size_t y position

## Window::MakeCellGrid()
```
void Window::MakeCellGrid(...)
```

#### Description
Make cell grid, actually set cells coordinates to fill all window space
