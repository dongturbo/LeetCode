
//这是LeetCode中提供的标准答案，代码简洁

int candy(vector<int>& ratings) {
    vector<int> candy(ratings.size(), 1);
    for(int i = 0; i < ratings.size() - 1; i++) {
        if (ratings[i] < ratings[i + 1]) {
            candy[i + 1] = candy[i] + 1;
        }
    }
    for(int i = ratings.size() - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) {
            candy[i] = candy[i + 1] + 1;
        }
    }
    return accumulate(candy.begin(), candy.end(), 0);
}

//这是我的答案，代码比较麻烦，一次循环结束，且不需要额外存储，但是判断条件比较多。
int candy(vector<int> &ratings) {
    int sum = 0, step = 1, preStep = 1;
    int level = 0, preLevel = 0; //0 初始状态，1 上升，2 下降，3 相等
    for (int i = 0; i < ratings.size() - 1; i++) {
        if (ratings[i] < ratings[i + 1]) {

            if (level != 1) {
                if (preLevel == 1 && level != 3) {
                    sum += max(step, preStep);
                }else{
                    sum+=step;
                }
                preStep = step;
                step = 1;
                preLevel = level;
                level = 1;
            } else {
                sum += step;
            }
            if(level!=0){
                step++;
            }
        } else if (ratings[i] > ratings[i + 1]) {
            if (level != 2) {
                preStep = step;
                step = 1;
                preLevel = level;
                level = 2;
            }
            sum += step;
            if(level!=0){
                step++;
            }
        } else {
            if (level != 3) {
                if (preLevel == 1) {
                    sum += max(step, preStep);
                }else{
                    sum+=step;
                }
                preStep = step;
                step = 1;
                preLevel = level;
                level = 3;
            } else {
                sum += step;
            }
        }
    }
    if (level == 2) {
        sum += max(step, preStep);
    } else {
        sum += step;
    }
    return sum;
}
