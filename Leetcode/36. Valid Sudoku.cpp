/*Valid Sudoku:Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.The Sudoku board could be partially filled, where empty cells are filled with the character '.'.*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
		if (!(check_row(board, i)
		    && (check_col(board, i))
		    && (check_box(board, i))))
			return false;
		}
		return true;
    }
    bool check_row(const vector<vector<char>> &a, int row) {
		vector<bool> used(9, false);
		for (char i : a[row]) {
			if ('.' == i)
				continue;
			int pos = i - '0' - 1;
			if (used[pos])
				return false;
			else
				used[pos] = true;
		}
		return true;
	}
	bool check_col(const vector<vector<char>> &a, int col) {
		vector<bool> used(9, false);
		for (int i = 0; i < 9; ++i) {
			if (a[i][col] == '.')
				continue;
			int pos = a[i][col] - '0' - 1;
			if (used[pos])
				return false;
			else
				used[pos] = true;
		}
		return true;
	}
    bool check_box(const vector<vector<char>> &a, int box) {
		int row_begin = box / 3 * 3;
		int col_begin = box % 3 * 3;
		vector<bool> used(9, false);
		for (int i = row_begin; i < row_begin + 3; ++i) {
			for (int j = col_begin; j < col_begin + 3; ++j) {
				if (a[i][j] == '.')
					continue;
				int pos = a[i][j] - '0' - 1;
				if (used[pos])
					return false;
				else
					used[pos] = true;
			}
		}
		return true;
	}
};