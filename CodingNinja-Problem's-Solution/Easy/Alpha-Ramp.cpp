void alphaRamp(int n) {
    // Write your code here.
    char ch = 'A';
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            cout << ch << " ";
        }
        ch = ch+1;
        cout << endl;
    }
}