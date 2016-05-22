class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold <= 0 || rows < 0 || cols < 0)
			return 0;
		int count = 1;
		st1.push(0);
		st2.push(0);
		int x, y;
		bool *flag = new bool[rows*cols]();
		flag[0] = true;
		while (!st1.empty() && !st2.empty())
		{
			x = st1.top();
			y = st2.top();
			if ((x - 1) >= 0 && !flag[(x - 1)*cols + y] && checkMove(threshold, x - 1, y))
			{
				count++;
				flag[(x - 1)*cols + y] = true;
				st1.push(x - 1);
				st2.push(y);
				continue;
			}
			if ((x + 1) < rows&&!flag[(x + 1)*cols + y] && checkMove(threshold, x + 1, y))
			{
				count++;
				flag[(x + 1)*cols + y] = true;
				st1.push(x + 1);
				st2.push(y);
				continue;
			}
			if ((y - 1) >= 0 && !flag[x*cols + y - 1] && checkMove(threshold, x, y - 1))
			{
				count++;
				flag[x*cols + y - 1] = true;
				st1.push(x);
				st2.push(y - 1);
				continue;
			}
			if ((y + 1) < cols&&!flag[x*cols + y + 1] && checkMove(threshold, x, y + 1))
			{
				count++;
				flag[x*cols + y + 1] = true;
				st1.push(x);
				st2.push(y + 1);
				continue;
			}
			st1.pop();
			st2.pop();
		}
		return count;
	}
	bool checkMove(int threshold, int rows, int cols)
	{
		int sum = 0;
		while (rows != 0)
		{
			sum += rows % 10;
			rows /= 10;
		}
		while (cols != 0)
		{
			sum += cols % 10;
			cols /= 10;
		}
		if (sum > threshold)
			return false;
		else
			return true;
	}
	stack<int> st1, st2;
};
