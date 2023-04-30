
#include "frame.h"

// Default constructs in solved position:

frame::frame()
{
    unsigned int tableVal = 1;
    for (unsigned int i = 0; i < nrrows; ++i)
    {
        for (unsigned int j = 0; j < nrcolumns; ++j)
        {
            table[i][j] = tableVal++;
        }
    }
    table[nrrows - 1][nrcolumns - 1] = 0;
    open_place.row = nrrows - 1;
    open_place.column = nrcolumns - 1;
}

frame::frame(std::initializer_list<std::initializer_list<unsigned int>> init)
{
    unsigned int i = 0, j = 0;
    for (auto in : init)
    {
        j = 0;
        for (auto tableVal : in)
        {
            table[i][j] = tableVal;
            if (tableVal == 0)
            {
                open_place.row = i;
                open_place.column = j;
            }
            j++;
        }
        i++;
    }
}

position frame::find(unsigned int val) const
{
    for (unsigned int row = 0; row < nrrows; row++)
    {
        for (unsigned int col = 0; col < nrcolumns; col++)
        {
            if (table[row][col] == val)
            {
                return position(row, col);
            }
        }
    }
}

void frame::print(std::ostream &out) const
{
    for (unsigned int row = 0; row < nrrows; ++row)
    {
        for (unsigned int col = 0; col < nrcolumns; ++col)
        {
            out << std::setw(4) << table[row][col] << " ";
        }
        out << "\n";
    }
    out << "open place is at [ " << open_place.row << ", " << open_place.column << " ]\n";
}

bool frame::makemove(move m)
{
    if (m == move::up && open_place.row > 0)
    {
        std::swap(table[open_place.row][open_place.column], table[open_place.row - 1][open_place.column]);
        open_place.row--;
        return true;
    }
    else if (m == move::down && open_place.row < nrrows - 1)
    {
        std::swap(table[open_place.row][open_place.column], table[open_place.row + 1][open_place.column]);
        open_place.row++;
        return true;
    }
    else if (m == move::right && open_place.column < nrcolumns - 1)
    {
        std::swap(table[open_place.row][open_place.column], table[open_place.row][open_place.column + 1]);
        open_place.column++;
        return true;
    }
    else if (m == move::left && open_place.column > 0)
    {
        std::swap(table[open_place.row][open_place.column], table[open_place.row][open_place.column - 1]);
        open_place.column--;
        return true;
    }
    else
    {
        return false;
    }
}

bool frame::before::operator()(const frame &f1, const frame &f2) const
{
    for (int i = 0; i < frame::nrrows; i++)
    {
        for (int j = 0; j < frame::nrcolumns; j++)
        {
            if (f1.table[i][j] < f2.table[i][j])
            {
                return true;
            }
            else if (f1.table[i][j] > f2.table[i][j])
            {
                return false;
            }
        }
    }
    return false;
}

unsigned int frame::distance(const frame &f) const
{
    unsigned int dist = 0;
    for (unsigned int row = 0; row < nrrows; ++row)
    {
        for (unsigned int col = 0; col < nrcolumns; ++col)
        {
            if (table[row][col] != 0)
            {
                dist += ::distance(find(table[row][col]), f.find(table[row][col]));
            }
        }
    }
    return dist;
}