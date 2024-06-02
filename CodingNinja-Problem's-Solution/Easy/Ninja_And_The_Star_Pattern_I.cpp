void getStarPattern(int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "*";
            }
        }
        else
        {
            cout << "* ";
            for (int j = 1; j <= 2 * (n - 1); j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}
