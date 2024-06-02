void nLetterTriangle(int n) {
    // Write your code here.
    for (int i=0; i<n; i++) {
        char ch = 'A';
        for (int j=0; j<=i; j++) {
            cout << ch << " ";
            ch = ch+1;
        }
        cout << endl;
    }
}