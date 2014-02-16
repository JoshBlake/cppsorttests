#include "stdafx.h"

#include "StringManip.h"

#include <string.h>

StringManip::StringManip()
{
}

void StringManip::ReverseString(char* str)
{
	if (NULL == str)
		return;

	int len = strlen(str);
	
	char* end = str + len - 1;
	while (str < end)
	{
		char temp = *str;
		*str = *end;
		*end = temp;
		str++;
		end--;
	}
}

bool StringManip::IsSubString(char* searchStr, char* targetStr)
{
	if (NULL == targetStr || NULL == searchStr)
		return false;

	int targetLen = strlen(targetStr);
	int searchLen = strlen(searchStr);

	if (searchLen > targetLen)
		return false;
	
	int maxRotate = targetLen - searchLen;

	for (int i = 0; i <= maxRotate; i++)
	{
		if (strncmp(targetStr + i, searchStr, searchLen) == 0)
			return true;
	}

	return false;
}

bool StringManip::IsPalindrome(char* str)
{
	if (NULL == str)
		return false;

	int len = strlen(str);

	char* end = str + len - 1;

	while (str < end)
	{
		if (*str != *end)
			return false;
		str++;
		end--;
	}

	return true;
}

int StringManip::GetLongestPalindromeLen(char* str)
{
	if (NULL == str)
		return -1;

	int len = strlen(str);

	char* end = str + len - 1;

	int longestLen = 0;

	char* seed = str;

	while (seed <= end)
	{
		char* left = seed - 1;
		char* right = seed + 1;
		int curLen = 1;
		while (left >= str &&
			right <= end &&
			*left == *right)
		{
			curLen += 2;
			left--;
			right++;
		}

		if (curLen > longestLen)
		{
			longestLen = curLen;
		}

		left = seed;
		right = seed + 1;
		curLen = 0;
		while (left >= str &&
			right <= end &&
			*left == *right)
		{
			curLen += 2;
			left--;
			right++;
		}

		if (curLen > longestLen)
		{
			longestLen = curLen;
		}

		seed++;

		if (longestLen > (end - seed) * 2)
			break;
	}

	return longestLen;
}
