float _stof(string s){
    float res = 0;
    int flag = 1;
    if(s.length() > 0){
        int dp= -1;        
        for (int i = 0; i < s.length(); ++i){
            if (s[i] == '-')
                flag = -1;
            if(s[i] == '.' )
                dp = 0;            
            if(s[i] < '0' || s[i] >'9')
                continue;
            if(dp > -1)
                dp++;
            res = res*10 + s[i] - '0';
        }
        if(dp > -1)
            res = res/pow(10, dp);      
    }
    return res*flag;
}