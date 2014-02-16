#include "gtest\gtest.h"

#include "StringManip.h"


TEST(StringManipTest, ReverseNull) {
	char* str = NULL;
	char* expected = NULL;
	StringManip::ReverseString(str);
	EXPECT_EQ(expected, str);
}

TEST(StringManipTest, ReverseLen0) {
	char str[] = "";
	char* expected = "";
	StringManip::ReverseString(str);
	EXPECT_EQ(0, strncmp(str, expected, 1));
}

TEST(StringManipTest, ReverseLen1) {

	char str[] = "a";
	char* expected = "a";
	StringManip::ReverseString(str);
	EXPECT_EQ(0, strncmp(str, expected, 1));
}


TEST(StringManipTest, ReverseLen2) {

	char str[] = "ab";
	char* expected = "ba";
	StringManip::ReverseString(str);
	EXPECT_EQ(0, strncmp(str, expected, 2));
}


TEST(StringManipTest, ReverseLen3) {

	char str[] = "abc";
	char* expected = "cba";
	StringManip::ReverseString(str);
	EXPECT_EQ(0, strncmp(str, expected, 3));
}

TEST(StringManipTest, ReverseLen4) {

	char str[] = "abcd";
	char* expected = "dcba";
	StringManip::ReverseString(str);
	EXPECT_EQ(0, strncmp(str, expected, 4));
}

TEST(StringManipTest, IsSubNullTarget) {

	char searchStr[] = "hi";
	bool result = StringManip::IsSubString(searchStr, NULL);
	EXPECT_EQ(false, result);
}

TEST(StringManipTest, IsSubNullSearch) {

	char targetStr[] = "hi";
	bool result = StringManip::IsSubString(NULL, targetStr);
	EXPECT_EQ(false, result);
}

TEST(StringManipTest, IsSubLongSearch) {
	char searchStr[] = "hi";
	char targetStr[] = "h";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(false, result);
}

TEST(StringManipTest, IsSubEqLen1) {
	char searchStr[] = "h";
	char targetStr[] = "h";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(true, result);
}

TEST(StringManipTest, IsSubEqLen2) {
	char searchStr[] = "hi";
	char targetStr[] = "hi";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(true, result);
}

TEST(StringManipTest, IsSubEqLen3) {
	char searchStr[] = "hi2";
	char targetStr[] = "hi2";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(true, result);
}

TEST(StringManipTest, IsSubEqSubOffset) {
	char searchStr[] = "he";
	char targetStr[] = "hello";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(true, result);
}

TEST(StringManipTest, IsSubEqNotSubOffset) {
	char searchStr[] = "hl";
	char targetStr[] = "hello";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(false, result);
}

TEST(StringManipTest, IsSubEqSubTrueA) {
	char searchStr[] = "abc";
	char targetStr[] = "abcxyz";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(true, result);
}

TEST(StringManipTest, IsSubEqSubTrueB) {
	char searchStr[] = "abc";
	char targetStr[] = "xabcyz";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(true, result);
}

TEST(StringManipTest, IsSubEqSubTrueC) {
	char searchStr[] = "abc";
	char targetStr[] = "xyabcz";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(true, result);
}

TEST(StringManipTest, IsSubEqSubTrueD) {
	char searchStr[] = "abc";
	char targetStr[] = "xyzabc";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(true, result);
}

TEST(StringManipTest, IsSubEqSubFalseA) {
	char searchStr[] = "cba";
	char targetStr[] = "abcxyz";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(false, result);
}

TEST(StringManipTest, IsSubEqSubFalseB) {
	char searchStr[] = "cba";
	char targetStr[] = "xabcyz";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(false, result);
}

TEST(StringManipTest, IsSubEqSubFalseC) {
	char searchStr[] = "cba";
	char targetStr[] = "xyabcz";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(false, result);
}

TEST(StringManipTest, IsSubEqSubFalseD) {
	char searchStr[] = "cba";
	char targetStr[] = "xyzabc";
	bool result = StringManip::IsSubString(searchStr, targetStr);
	EXPECT_EQ(false, result);
}

TEST(StringManipTest, IsPalindromeNull) {
	char str[] = "hello";
	bool result = StringManip::IsPalindrome(NULL);
	EXPECT_EQ(false, result);
}

TEST(StringManipTest, IsPalindromeLen1) {
	char str[] = "a";
	bool result = StringManip::IsPalindrome(str);
	EXPECT_EQ(true, result);
}

TEST(StringManipTest, IsPalindromeLen2True) {
	char str[] = "aa";
	bool result = StringManip::IsPalindrome(str);
	EXPECT_EQ(true, result);
}

TEST(StringManipTest, IsPalindromeLen2False) {
	char str[] = "ab";
	bool result = StringManip::IsPalindrome(str);
	EXPECT_EQ(false, result);
}

TEST(StringManipTest, IsPalindromeLen3True) {
	char str[] = "aba";
	bool result = StringManip::IsPalindrome(str);
	EXPECT_EQ(true, result);
}

TEST(StringManipTest, IsPalindromeLen3False) {
	char str[] = "abb";
	bool result = StringManip::IsPalindrome(str);
	EXPECT_EQ(false, result);
}

TEST(StringManipTest, IsPalindromeLen4True) {
	char str[] = "abba";
	bool result = StringManip::IsPalindrome(str);
	EXPECT_EQ(true, result);
}

TEST(StringManipTest, IsPalindromeLen4False) {
	char str[] = "abca";
	bool result = StringManip::IsPalindrome(str);
	EXPECT_EQ(false, result);
}

TEST(StringManipTest, GetLongestPalindromeLenNULL) {
	char str[] = "abca";
	int result = StringManip::GetLongestPalindromeLen(NULL);
	EXPECT_EQ(-1, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLen0) {
	char str[] = "";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(0, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLen1) {
	char str[] = "a";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(1, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLen2True) {
	char str[] = "aa";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(2, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLen2False) {
	char str[] = "ab";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(1, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLen3A) {
	char str[] = "abc";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(1, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLen3B) {
	char str[] = "aac";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(2, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLen3C) {
	char str[] = "aba";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(3, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongA) {
	char str[] = "abclolxyz";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(3, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongB) {
	char str[] = "ablolxyzc";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(3, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongC) {
	char str[] = "alolxyzbc";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(3, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongD) {
	char str[] = "lolxyzabc";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(3, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongE) {
	char str[] = "abcxlolyz";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(3, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongF) {
	char str[] = "abcxylolz";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(3, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongG) {
	char str[] = "abcxyzlol";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(3, result);
}
///


TEST(StringManipTest, GetLongestPalindromeLenLenLongEvenA) {
	char str[] = "abcloolxyz";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(4, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongEvenB) {
	char str[] = "abloolxyzc";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(4, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongEvenC) {
	char str[] = "aloolxyzbc";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(4, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongEvenD) {
	char str[] = "loolxyzabc";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(4, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongEvenE) {
	char str[] = "abcxloolyz";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(4, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongEvenF) {
	char str[] = "abcxyloolz";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(4, result);
}

TEST(StringManipTest, GetLongestPalindromeLenLenLongEvenG) {
	char str[] = "abcxyzlool";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(4, result);
}

TEST(StringManipTest, GetLongestPalindromeLenTotal) {
	char str[] = "abcdefedcba";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(11, result);
}

TEST(StringManipTest, GetLongestPalindromeLenTotalEven) {
	char str[] = "abcdeffedcba";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(12, result);
}

TEST(StringManipTest, GetLongestPalindromeLenTotalLeft) {
	char str[] = "zabcdefedcba";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(11, result);
}

TEST(StringManipTest, GetLongestPalindromeLenTotalRight) {
	char str[] = "abcdefedcbaz";
	int result = StringManip::GetLongestPalindromeLen(str);
	EXPECT_EQ(11, result);
}