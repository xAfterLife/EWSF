#pragma once

class FpsBreaker
{
private:
	int* fpsLimit_ = nullptr;
	int oldLimit_ = 0;
	FpsBreaker();

public:
	static FpsBreaker& GetInstance()
	{
		static FpsBreaker instance;
		return instance;
	}

	void SetFpsLimit(int value) const;
	void ResetFpsLimit() const;
	int GetFpsLimit() const;
	int GetFpsTiming() const;
};
