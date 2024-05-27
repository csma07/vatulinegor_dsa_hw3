#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

struct Point 
{
    int row;
    int column;
};

void draw(const vector<vector<char>>& field, Point current, Point start, Point end) 
{
    system("cls");
    for (const auto& row : field) 
    {
        for (char c : row) 
        {
            cout << c;
        }
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(100));
}

int main() 
{
    Point begin, end, current, previous;

    int rows = 20, columns = 40;

    vector<vector<char>> field(rows, vector<char>(columns, '-'));

    cout << "Enter A row (1-20): ";
    cin >> begin.row;

    cout << "Enter A column (1-40): ";
    cin >> begin.column;

    field[begin.row - 1][begin.column - 1] = 'A';

    cout << "Enter B row (1-20): ";
    cin >> end.row;

    cout << "Enter B column (1-40): ";
    cin >> end.column;

    field[end.row - 1][end.column - 1] = 'B';

    current = begin;
    previous = begin;

    field[current.row - 1][current.column - 1] = 'X';

    while (current.row != end.row || current.column != end.column) 
    {
        draw(field, current, begin, end);

        if (current.row < end.row) 
        {
             current.row++;
        }
        else if (current.row > end.row) 
        {
             current.row--;
        }
        else if (current.column < end.column) 
        {
            current.column++;
        }
        else if (current.column > end.column) 
        {
            current.column--;
        }

        field[previous.row - 1][previous.column - 1] = '-';
        field[current.row - 1][current.column - 1] = 'X';
        previous = current;
    }

    draw(field, current, begin, end);

    return 0;
}