#include <iostream>

enum { _ = -1 };
//Creating puzzle a golobal variable so that every block can use it.
struct Puzzle
{
  int data[9][9];
} puzzle; 
/*{
  {
    { _, 7, 1, _, 9, _, 8, _, _ },
    { _, _, _, 3, _, 6, _, _, _ },
    { 4, 9, _, _, _, _, 7, _, 5 },
    { _, 1, _, 9, _, _, _, _, _ },
    { 9, _, 2, _, _, _, 6, _, 3 },
    { _, _, _, _, _, _, _, 2, _ },
    { 8, _, 5, _, _, _, _, 7, 6 },
    { _, _, _, 6, _, 7, _, _, _ },
    { _, _, 7, _, 4, _, 3, 5, _ },
  }
}*/

//Check wheather the puzzle is valid or not

bool check(const Puzzle &puzzle)
{
  for (int i = 0; i < 9; ++i)
    for (int j = 0; j < 9; ++j)
      for (int k = j + 1; k < 9; ++k)
      {
        if (puzzle.data[i][j] != 0 && puzzle.data[i][j] == puzzle.data[i][k])
          return false;
        if (puzzle.data[j][i] != 0 && puzzle.data[j][i] == puzzle.data[k][i])
          return false;
        if (puzzle.data[j % 3 + (i % 3) * 3][j / 3 + (i / 3) * 3] != 0 &&
            puzzle.data[j % 3 + (i % 3) * 3][j / 3 + (i / 3) * 3] ==
            puzzle.data[k % 3 + (i % 3) * 3][k / 3 + (i / 3) * 3])
          return false;
      }
  return true;
}

//its places the value to get the solution of sudoku

bool findSolution(Puzzle &puzzle)
{
  int x = -1;
  int y = -1;
  int min = 10;
  for (int i = 0; i < 9; ++i)
    for (int j = 0; j < 9; ++j)
    {
      if (puzzle.data[i][j] == 0)
      {
        int c = 0;
        for (int k = 1; k <= 9; ++k)
        {
          puzzle.data[i][j] = k;
          if (check(puzzle))
            ++c;
          puzzle.data[i][j] = 0;
        }
        if (min > c)
        {
          min = c;
          x = i;
          y = j;
        }
      }
    }
  if (x == -1)
    return true;
  for (int k = 1; k <= 9; ++k)
  {
    puzzle.data[x][y] = k;
    if (check(puzzle))
      if (findSolution(puzzle))
        return true;
  }
  puzzle.data[x][y] = 0;
  return false;
}

//main() function which call all the function.

int main()
{
  std::cout<<"replace the space with the zeros";
  
  //Talking input from the user.
  
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      std::cin>>puzzle.data[i][j];
    }
  }



  if (findSolution(puzzle))
  {
    for (int i = 0; i < 9; ++i)
    {
      if(i%3==0)
        std::cout << std::endl<< std::endl;  
      for (int j = 0; j < 9; ++j)
      {
        std::cout << puzzle.data[i][j] << " ";
        
        if((j+1)%3==0)
           std::cout<<"||";
      }
        std::cout << std::endl;
    }
  }
  else
    std::cout << "No solution\n";
    return 0;
}
