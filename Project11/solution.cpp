#include<iostream>
#include<string>
using namespace std;
const pair<int, string> valueSymbols[] = {
{1000, "M"},
{900,  "CM"},
{500,  "D"},
{400,  "CD"},
{100,  "C"},
{90,   "XC"},
{50,   "L"},
{40,   "XL"},
{10,   "X"},
{9,    "IX"},
{5,    "V"},
{4,    "IV"},
{1,    "I"},
};
const string thousands[] = { "", "M", "MM", "MMM" };
const string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
class Solution {
public:
	string intToRoman(int num) {
		string ans;
		for (pair<int, string> values: valueSymbols) {
			while (num >= values.first) {
				num -= values.first;
				ans += values.second;
			}
			if (num == 0) {
				break;
			}
		}
		return ans;
	}
	/*
		{1000, "M"},

		{900,  "CM"},
		{500,  "D"},
		{400,  "CD"},
		{100,  "C"},

		{90,   "XC"},
		{50,   "L"},
		{40,   "XL"},
		{10,   "X"},

		{9,    "IX"},
		{5,    "V"},
		{4,    "IV"},
		{1,    "I"},
	*/
	string intToRoman22(int num) {
		string ans;
		int thousands_digit=(num/1000)%10;
		int hundreds_digit = (num / 100) % 10;
		int tens_digit = (num / 10) % 10;
		int ones_digit = num % 10;
		ans = thousands[thousands_digit] + hundreds[hundreds_digit] + tens[tens_digit] + ones[ones_digit];
		return ans;
	}
};
//int main() {
//	return 0;
//}
//thousands_digit
//hundreds_digit
//tens_digit
//ones_digit