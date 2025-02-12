class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int in_cnt = n-1;  // 每个区间的长度
        int out_cnt = 0; // 根据外部循环次数决定in_cnt长度
        int n_value = 1;
        while (in_cnt >= 0)
        {
            int tmp_value = out_cnt; //单次循环指针的位置
            for(int i = tmp_value; i<in_cnt; i++) //不对
                {
                    matrix[tmp_value][i] = n_value;
                    n_value++;
                }
            
            for(int j = tmp_value; j<in_cnt; j++)
            {
                matrix[j][i] = n_value;
                n_value++;
            }
            for(int p = tmp_value; p<in_cnt; p++)
            {
                matrix[j][in_cnt-p] = n_value;
                n_value++;
            }
            for(int q = tmp_value; q<in_cnt; q++)
            {
                matrix[in_cnt-q][in_cnt-p] = n_value;
                n_value++;
            }
            out_cnt++;
            in_cnt -= 2;
        }
    }
};