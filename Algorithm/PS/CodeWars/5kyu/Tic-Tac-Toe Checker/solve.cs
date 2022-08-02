using System;

public class TicTacToe
{
    public int Checker(int i)
    {
        if (i < 0) return -1;

        if (i == 3)
            return 1;

        if (i == 6)
            return 2;

        return 0;
    }

    public int IsSolved(int[,] board)
    {
        int checker = 0;
        bool hasz = false;
        // check row
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i, j] == 0)
                {
                    checker = 0;
                    hasz = true;
                    break;
                }

                checker += board[i, j];
            }

            checker = Checker(checker);
            if (checker > 0) return checker;
            else checker = 0;
        }

        checker = 0;
        // check col
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[j, i] == 0)
                {
                    checker = 0;
                    hasz = true;
                    break;
                }

                checker += board[j, i];
            }

            checker = Checker(checker);
            if (checker > 0) return checker;
            else checker = 0;
        }

        checker = 0;
        // check cross
        for (int i = 0; i < 3; i++)
        {
            if (board[i, i] == 0)
            {
                checker = 0;
                hasz = true;
                break;
            }
            checker += board[i, i];
        }

        checker = Checker(checker);
        if (checker > 0) return checker;
        else checker = 0;

        for (int i = 0, j = 2; i < 3; i++, j--)
        {
            if (board[i, j] == 0)
            {
                checker = 0;
                hasz = true;
                break;
            }

            checker += board[i, j];
        }

        checker = Checker(checker);
        if (checker > 0) return checker;

        if (hasz) return -1;
        else return 0;
    }
}