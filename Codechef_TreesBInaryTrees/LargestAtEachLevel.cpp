int t;
    cin >> t;
    while(t--) {
        string x, y;
        cin >> x >> y;
        bool canMatch = true;
        
        for (int i = 0; i < x.length(); i++) {
            // Check if characters can match
            if (x[i] != y[i] && x[i] != '?' && y[i] != '?') {
                canMatch = false;
                break;
            }
        }
        
        // Output the result for each test case
        if (canMatch) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;

    /*
    7 
1 2
1 4
2 5
2 3
2 6
4 7
    
    */