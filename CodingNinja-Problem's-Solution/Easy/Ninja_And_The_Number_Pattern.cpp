void getNumberPattern(int n)
{
    // Write your code here.
    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (i == 0 || i == 2 * n - 2)
        {
            for (int j = 0; j < 2 * n - 1; j++)
            {
                cout << n;
            }
        }
        else
        {
            for (int j = 0; j < 2 * n - 1; j++)
            {
                int minDist = min(min(i, j), min((2 * n - 2 - i), (2 * n - 2 - j)));
                cout << n - minDist;
            }
        }
        cout << endl;
    }
}