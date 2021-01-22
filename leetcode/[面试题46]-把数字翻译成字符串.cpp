class Solution {
public:
    int translateNum(int num) {
        return f(num);
    }

    int f(int num){
        if(num < 10){
            return 1;
        }
        if(num %100 <=25 && num %100 >=10){
            return f(num / 10) + f(num / 100);
        }else{
            return f(num / 10);
        }
    }
};