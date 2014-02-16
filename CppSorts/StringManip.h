#pragma once

class StringManip
{
public:
	StringManip();

	static void ReverseString(char* str);

	static bool IsSubString(char* searchStr, char* targetStr);

	static bool IsPalindrome(char* str);

	static int GetLongestPalindromeLen(char* str);
};